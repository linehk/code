package main

import (
	"bytes"
	"fmt"
)

func main() {
	fmt.Println(comma("12345"))
}

func comma(s string) string {
	var buf bytes.Buffer
	l := len(s)
	if l <= 3 {
		return s
	}
	buf.WriteByte(s[0])
	for i := 1; i < l; i++ {
		if (l-i)%3 == 0 {
			buf.WriteByte(',')
		}
		buf.WriteByte(s[i])
	}
	return buf.String()
}
