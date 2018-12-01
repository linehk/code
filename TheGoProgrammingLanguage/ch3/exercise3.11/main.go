package main

import (
	"bytes"
	"fmt"
)

func main() {
	fmt.Println(comma("-12345"))
}

func comma(s string) string {
	var buf bytes.Buffer
	var last string
	if s[0] == '+' {
		buf.WriteByte('+')
		s = s[1:]
	} else if s[0] == '-' {
		buf.WriteByte('-')
		s = s[1:]
	}
	for i := 0; i < len(s); i++ {
		if s[i] == '.' {
			last = s[i:]
			s = s[:i]
		}
	}

	l := len(s)

	if l <= 3 {
		buf.WriteString(s)
		buf.WriteString(last)
		return buf.String()
	}

	buf.WriteByte(s[0])
	for i := 1; i < l; i++ {
		if (l-i)%3 == 0 {
			buf.WriteByte(',')
		}
		buf.WriteByte(s[i])
	}
	buf.WriteString(last)
	return buf.String()
}
