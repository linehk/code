package main

import (
	"log"

	"github.com/linehk/bookcode/go-programming-tour-book/tour/cmd"
)

func main() {
	err := cmd.Execute()
	if err != nil {
		log.Fatalf("cmd.Execute err: %v", err)
	}
}
