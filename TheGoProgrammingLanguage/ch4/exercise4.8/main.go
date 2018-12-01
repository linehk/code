package main

import (
	"bufio"
	"fmt"
	"io"
	"os"
	"unicode"
)

func main() {
	var numberCount, letterCount, elseCount int
	in := bufio.NewReader(os.Stdin)
	for {
		r, _, err := in.ReadRune() // return rune, nbytes, error
		if err == io.EOF {
			break
		}
		if err != nil {
			fmt.Fprintf(os.Stderr, "%v\n", err)
			os.Exit(1)
		}
		if unicode.IsNumber(r) {
			numberCount++
		} else if unicode.IsLetter(r) {
			letterCount++
		} else {
			elseCount++
		}
	}
	fmt.Printf("numberCount = %d, letterCount = %d, elseCount = %d\n", numberCount,
		letterCount, elseCount)
}
