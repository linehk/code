package main

import (
	"errors"
	"fmt"
)

type Name string

func (i *Name) String() string {
	return fmt.Sprint(*i)
}

func (i *Name) Set(value string) error {
	if len(*i) > 0 {
		return errors.New("name flag already set")
	}

	*i = Name("eddycjy:" + value)
	return nil
}
