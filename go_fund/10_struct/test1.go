package main

import "fmt"

type myString string

func (s myString) print() {
	fmt.Println(s)
}

type myPrintInterface interface {
	print()
}

func f3(x myPrintInterface) {
	x.(myPrintInterface).print()
}

func main() {
	var a myString = "hello"
	f3(a)
}
