package main

import (
	"fmt"
	"reflect"
)

func main() {
	a := "hello"
	fmt.Printf("%s\n", reflect.TypeOf(a))
	fmt.Printf("%s\n", reflect.ValueOf(a))

	var b int = 65
	fmt.Printf("%s", string(b))
}
