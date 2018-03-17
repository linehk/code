package main

import (
	"fmt"
)

func main() {
	s := "abc"
	b := []byte(s)
	fmt.Println(b)
	s2 := string(b)
	fmt.Println(s2)
}
