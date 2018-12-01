// Echo2 prints its commamd-line arguments.
package echo

import (
	"fmt"
	"os"
)

func Echo2() {
	s, sep := "", ""
	for _, arg := range os.Args[1:] {
		s += sep + arg
		sep = " "
	}
	fmt.Println(s)
}
