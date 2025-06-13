package main

import (
	"bufio"
	"bytes"

	// "encoding/json"
	"fmt"
	"io"
	"log"
	"net"
	"net/http"
	"os"
	"os/signal"
	"strings"
	"syscall"
)

type client struct {
	addr string
	name string
}

type clientConn struct {
	client   client
	conn     net.Conn
	quitc    chan bool
	connOpen bool
}

type message struct {
	client client
	val    []byte
}

type cmd struct {
	addr string
	name string
	val  []byte
}

type Server struct {
	listenAddr string
	ln         net.Listener
	quitch     chan struct{}
	outc       chan message
	cmdc       chan cmd
}

func newServer(listenAddr string) *Server {
	return &Server{
		listenAddr: listenAddr,
		quitch:     make(chan struct{}),
		outc:       make(chan message, 10),
		cmdc:       make(chan cmd, 10),
	}
}

func (s *Server) outputLoop() error {
	for msg := range s.outc {

		fmt.Printf("\n<output{%d}> from <%s>: \n", len(msg.val), msg.client.name);
		fmt.Printf(string(msg.val));
		fmt.Printf("\n");
	}
	return nil;
}

func (s *Server) Start() error {
	ln, err := net.Listen("tcp", s.listenAddr)
	if err != nil {
		return err
	}
	defer ln.Close()
	s.ln = ln

	go s.outputLoop()
	go s.acceptLoop()
	fmt.Println("waiting for quit channel !")
	<-s.quitch
	fmt.Println("Out of quit ch.")
	close(s.cmdc)
	close(s.outc)
	os.Exit(0)

	return nil
}

func (s *Server) acceptLoop() {
	for {
		conn, err := s.ln.Accept()
		if err != nil {
			fmt.Println("Accept error: ", err)
			continue
		}
		client_name := make([]byte, 1024)
		fmt.Println("Reading client name...")
		_, err = conn.Read(client_name)
		fmt.Println("New connection from ", conn.RemoteAddr(), " with ", string(client_name))
		// conn.Write([]byte("Thanks for connecting to " + s.listenAddr))
		// println("Name of %s : %s", )
		go s.mainLoop(&clientConn{
			conn: conn,
			client: client{
				addr: conn.RemoteAddr().String(),
				name: string(client_name),
			},
			quitc:    make(chan bool),
			connOpen: true,
		})
		// <-s.quitch
	}
}

func (s *Server) mainLoop(client_conn *clientConn) {
	conn := (*client_conn).conn
	defer conn.Close()

	go func() {
		for {
			buf := make([]byte, 2048)
			n, err := conn.Read(buf)
			if err == io.EOF {
				fmt.Println("Connection Closed with ", (*client_conn).client.name, " due to ", err)
				client_conn.connOpen = false
				client_conn.quitc <- true
				break
			}
			if err != nil {
				fmt.Println("Read error: ", err)
				client_conn.connOpen = false
				client_conn.quitc <- true
				break
			}
			fmt.Println(buf);
			// conn.Write([]byte("HELLO BRO ! HOW ARE YOU !"));
			s.outc <- message{val: buf[:n], client: client{addr: conn.RemoteAddr().String(), name: (*client_conn).client.name}}
			fmt.Printf("GOT %d bytes from %s", n, (*client_conn).client.name)
			if string([]byte(strings.TrimRight(string(buf[:n]), "\r\n"))) == "halt" {
				fmt.Println("Closing connection with ", conn.RemoteAddr().String())
				conn.Close()
				client_conn.quitc <- true
				client_conn.connOpen = false
				break
			}
		}
	}()

	go func() {
		for cmd_to_send := range s.cmdc {
			if client_conn.connOpen == false {
				break
			}
			if cmd_to_send.addr == client_conn.client.addr {
				_, err := client_conn.conn.Write([]byte(cmd_to_send.val))
				if err != nil {
					fmt.Println("Error while sending command to ", client_conn.client.name, " !: ", err)
				}
				if string(cmd_to_send.val) == "quit" {
					client_conn.connOpen = false
					client_conn.quitc <- true
					break
				}
			}
		}
	}()

	// takes input and send to cmd channel which then will get sent to server.
	go func() {
		reader := bufio.NewReader(os.Stdin)
		fmt.Printf("Press enter to communicate with %s...\n", client_conn.client.name);
		bufio.NewReader(os.Stdin).ReadString('\n')
		for client_conn.connOpen {
			var temp cmd
			fmt.Printf("\n%s > ", client_conn.client.name)
			user_inp, _ := reader.ReadString('\n')
			temp.val = []byte(strings.TrimSpace(user_inp))
			// fmt.Println(temp.val)
			// fmt.Println(string(temp.val));
			temp.addr = client_conn.client.addr
			temp.name = client_conn.client.name
			s.cmdc <- temp
		}
	}()
	<-client_conn.quitc
	fmt.Println("Exited from the mainloop of this client !")

}

func Update(apiendpoint string, address string, port int, status bool) error {
	for {
		// Define the data to be sent in JSON format
		jsonData := fmt.Sprintf(`{ "address": "%s", "port": %d, "status": %t}`, address, port, status)
		fmt.Println("JSON DATA: " + jsonData)

		// Make the POST request
		resp, err := http.Post(apiendpoint, "application/json", bytes.NewBuffer([]byte(jsonData)))
		if err != nil {
			fmt.Println("Error making POST request:", err)
			fmt.Println("Retrying...")
			continue
		}
		defer resp.Body.Close()
		// Print response status
		fmt.Println("Response Status form api:", resp.Status)
		break
	}
	return nil
}

func main() {

	sigs := make(chan os.Signal, 1)
	// Run a goroutine to handle the signal

	signal.Notify(sigs, syscall.SIGINT, syscall.SIGTERM)

	// // getting server address data
	var address string
	var port int
	fmt.Printf("Enter visible server Address to client: ")
	fmt.Scanf("%s", &address)
	fmt.Printf("\nEnter visible server Port to client: ")
	fmt.Scanf("%d", &port)
	var lport string
	fmt.Printf("\nEnter local port where client connects: ")
	fmt.Scanf("%s", &lport)
	fmt.Printf("\n")

	// post to the api that server got active at this address !
	Update("https://aryansapi.vercel.app/api/dynamo", address, port, true)

	go func() {
		sig := <-sigs
		fmt.Println("\nLogging to DB that server is turned off ! got signal:", sig)
		Update("https://aryansapi.vercel.app/api/dynamo", address, port, false)
		os.Exit(0) // Ensure graceful shutdown
	}()

	server := newServer(":" + lport)

	// go func() {
	// 	for
	// }

	// go func() {
	// 	for msg := range server.outc {
	// 		fmt.Printf("Output from %s: %s", string(msg.client.name), string(msg.val))
	// 	}
	// }()

	log.Fatal(server.Start())
}
