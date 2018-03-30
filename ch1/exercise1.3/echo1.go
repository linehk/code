// Echo1 prints its command-line arguments.
package echo

import (
	"fmt"
	"os"
)

func Echo1() {
	var s, sep string
	for i := 1; i < len(os.Args); i++ {
		s += sep + os.Args[i]
		sep = " "
	}
	fmt.Println(s)
}
