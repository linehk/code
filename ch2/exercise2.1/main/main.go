package main

import (
	"fmt"

	"gopl-code/ch2/exercise2.1"
)

func main() {
	var c tempconv.Celsius = 100
	fmt.Println(tempconv.CToK(c))
	fmt.Println(tempconv.CToF(c))

	var f tempconv.Fahrenheit = 212
	fmt.Println(tempconv.FToK(f))
	fmt.Println(tempconv.FToC(f))
}
