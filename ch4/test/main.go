package main

import (
	"fmt"
)

func main() {
	months := [...]string{1: "jan", 2: "feb", 3: "mar", 4: "apr", 5: "may",
		6: "jun", 7: "july", 8: "aug", 9: "sep", 10: "oct",
		11: "nov", 12: "dec"}

	Q2 := months[4:7]
	summer := months[6:9]
	fmt.Println(Q2)
	fmt.Println(summer)

	for _, s := range summer {
		for _, q := range Q2 {
			if s == q {
				fmt.Printf("%s appears in both\n", s)
			}
		}
	}

	fmt.Println(cap(summer))
	fmt.Println(len(summer))

	end := summer[:5]
	fmt.Println(end)
}
