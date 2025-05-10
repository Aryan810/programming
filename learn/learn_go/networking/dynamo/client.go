package main

import (
	"encoding/json"
	"fmt"
	"io"
	"net"
	"net/http"
	"strconv"
	"time"
)

type ServerAddr struct {
	Address string `json:"address"`
	Port    int `json:"port"`
	Status  bool `json:"status"`
}

type Client struct {
	status      bool
	apiendpoint string
	addr        string
	port        int
	quitc       chan struct{}
	inp         chan string
	out         chan string
	name string
}

func newClient(apiendpoint string, name string) *Client {
	return &Client{
		status:      false,
		apiendpoint: apiendpoint,
		quitc:       make(chan struct{}),
		inp:         make(chan string),
		out:         make(chan string),
		name: name,
	}
}

func (c *Client) Update() error {
	for {
		client := &http.Client{
			Timeout: 10 * time.Second,
		}
		req, err := http.NewRequest("GET", c.apiendpoint, nil)

		if err != nil {
			fmt.Println("Error Creating request ( to api ): ", err)
			continue
		}

		// req.Header.Set("User-Agent", "DynamoClient/1.0")
		resp, err := client.Do(req)

		if err != nil {
			fmt.Println("Error connecting to api for url: ", err)
			time.Sleep(500 * time.Millisecond)
			fmt.Println("Retrying to connect to api !")
		}

		// defer req.Body.Close()
		body, err := io.ReadAll(resp.Body)
		if err != nil {
			fmt.Println("Error reading req. body of api request: ", err)
			continue
		}
		fmt.Println(string(body))
		var saddr ServerAddr
		err = json.Unmarshal(body[1:len(body)-1], &saddr)
		c.addr = saddr.Address
		c.port = saddr.Port
		c.status = saddr.Status
		fmt.Printf("GOT SERVER ADDRESS: %s %d %t\n", c.addr, c.port, c.status);
		if !c.status {
			time.Sleep(10 * time.Second)
			continue
		}
		fmt.Println("HERE!")
		// req.Body.Close()
		break
	}
	return nil
}

func (c *Client) getInp(conn net.Conn) error {
	buffer := make([]byte, 1024)
	n, err := conn.Read(buffer)
	fmt.Printf("Got %d bytes from server: %s", n, string(buffer));
	if (err != nil){
		fmt.Println("Server read error: ", err);
		return err
	}
	c.inp <- string(buffer);
	return nil
}

func (c *Client) sendOutput(conn net.Conn) error {
	_, err := conn.Write([]byte(<-c.out));
	if (err != nil){
		fmt.Println("Server write error: ", err);
		return err
	}
	return nil
}

func (c *Client) mainloop() error {
	// establish connection with server
	conn, err := net.Dial("tcp", c.addr + ":" + strconv.Itoa(c.port))
	if err != nil {
		fmt.Println("Error connecting to server: ", err);
		c.quitc <- struct{}{}
		return err;
	}
	c.out <- c.name;
	c.sendOutput(conn);
	for {
		c.getInp(conn);
		fmt.Println("Input from Server: ", <-c.inp);
	}
}

func (c *Client) Reach() error {
	c.Update()
	go c.mainloop()
	<-c.quitc
	return nil
}

func main() {
	client := newClient("https://aryansapi.vercel.app/api/dynamo", "Aryan Gupta")
	client.Reach()
}
