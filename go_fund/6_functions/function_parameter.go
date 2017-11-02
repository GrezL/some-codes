package main

import "fmt"

func main() {
	callback(3, 4, Add)
}

func Add(a, b int) {
	fmt.Printf("The sum of %d and %d is: %d\n", a, b, a+b)
}
func callback(y, z int, f func(int, int)) {
	f(y, z)
}
