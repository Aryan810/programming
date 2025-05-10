package main

import (
	"bytes"
	"encoding/json"
	"fmt"
	"net/http"
)

func main() {
	// Define the data to be sent in JSON format
	data := 

	// Convert map to JSON
	jsonData, err := json.Marshal(data)
	if err != nil {
		fmt.Println("Error encoding JSON:", err)
		return
	}
	fmt.Println(jsonData);
	// Make the POST request
	resp, err := http.Post("https://example.com/api", "application/json", bytes.NewBuffer(jsonData))
	if err != nil {
		fmt.Println("Error making POST request:", err)
		return
	}
	defer resp.Body.Close()

	// Print response status
	fmt.Println("Response Status:", resp.Status)
}