package main

import "fmt"

func f(a [3]int)   { fmt.Println(a) }
func fp(a *[3]int) { fmt.Println(a) }

var arr1 [3]int
var arr2 = new([3]int)

func main() {
	var ar [3]int
	f(ar)
	fp(&ar)

	arr1 := *arr2
	arr1[2] = 100
	fmt.Println(arr1)
	fmt.Println(arr2)
}
