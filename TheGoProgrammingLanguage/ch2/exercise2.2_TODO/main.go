package main

import (
	"bufio"
	"flag"
	"fmt"
	"os"
	"strconv"
)

var temp = flag.Float64("temp", 0, "tempconv")
var length = flag.Float64("length", 0, "lengthconv")
var weight = flag.Float64("weight", 0, "weightconv")

func main() {
	flag.Parse()
	if *temp == 0 {
		input := bufio.NewScanner(os.Stdin)
		for input.Scan() {
			var err error
			*temp, err = strconv.ParseFloat(input.Text(), 64)
			if err != nil {
				fmt.Errorf("%v", err)
			}
			fmt.Printf("%s = %s, %s\n", Celsius(*temp), CToK(Celsius(*temp)), CToF(Celsius(*temp)))
		}
	} else if *length == 0 {
		input := bufio.NewScanner(os.Stdin)
		for input.Scan() {
			var err error
			*length, err = strconv.ParseFloat(input.Text(), 64)
			if err != nil {
				fmt.Errorf("%v", err)
			}
			fmt.Printf("%s = %s, %s\n", Celsius(*temp), CToK(Celsius(*temp)), CToF(Celsius(*temp)))
		}
	} else if *weight == 0 {
		input := bufio.NewScanner(os.Stdin)
		for input.Scan() {
			var err error
			*weight, err = strconv.ParseFloat(input.Text(), 64)
			if err != nil {
				fmt.Errorf("%v", err)
			}
			fmt.Printf("%s = %s\n", Kilogram(*weight), KToP(Kilogram(*weight)))
		}
	}
	fmt.Printf("%s = %s, %s\n", Celsius(*temp), CToK(Celsius(*temp)), CToF(Celsius(*temp)))
	fmt.Printf("%s = %s\n", Meter(*length), MToF(Meter(*length)))
	fmt.Printf("%s = %s\n", Kilogram(*weight), KToP(Kilogram(*weight)))
}
