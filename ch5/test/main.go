package main

import (
	"bufio"
	"fmt"
	"io"
	"os"
)

func main() {
	fmt.Println(readfile())
}

func readfile() error {
	in := bufio.NewReader(os.Stdin)
	for {
		_, _, err := in.ReadRune()
		if err == io.EOF {
			break
		}
		if err != nil {
			return fmt.Errorf("read failed: %v", err)
		}
	}
	return nil
}
