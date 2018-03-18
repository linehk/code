package main

import (
	"bufio"
	"crypto/sha256"
	"crypto/sha512"
	"flag"
	"fmt"
	"os"
)

var f = flag.String("flag", "SHA256", "help")

func main() {
	input := bufio.NewScanner(os.Stdin)
	flag.Parse()
	if *f == "SHA256" {
		for input.Scan() {
			s := sha256.Sum256([]byte(input.Text()))
			fmt.Printf("%x\n", s)
		}
	}
	if *f == "SHA384" {
		for input.Scan() {
			s := sha512.Sum384([]byte(input.Text()))
			fmt.Printf("%x\n", s)
		}
	}
	if *f == "SHA512" {
		for input.Scan() {
			s := sha512.Sum512([]byte(input.Text()))
			fmt.Printf("%x\n", s)
		}
	}
}
