package main

import (
    "fmt"
    "strings"
)

func main() {
    s := []string{"s", "ds", "asdasd", "asda"}
	t := strings.Join(s, " ");
	fmt.Println(t);
}