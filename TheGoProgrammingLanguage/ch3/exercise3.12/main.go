package main

import (
	"fmt"
	"sort"
	"strings"
)

func main() {
	fmt.Println(isCrash("abcd", "bcad"))
}

func isCrash(s1, s2 string) bool {
	var buf1 []string
	var buf2 []string
	for _, v := range s1 {
		buf1 = append(buf1, string(v))
	}
	for _, v := range s2 {
		buf2 = append(buf2, string(v))
	}
	sort.Strings(buf1)
	sort.Strings(buf2)

	if strings.Join(buf1, "") == strings.Join(buf2, "") {
		return true
	}
	return false
}
