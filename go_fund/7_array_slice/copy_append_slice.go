package main

import "fmt"

func main() {
	sl_from := []int{1, 2, 3}
	sl_to := make([]int, 10)

	n := copy(sl_to, sl_from)
	fmt.Println(sl_to)
	fmt.Printf("Copied %d elements\n", n)
	fmt.Printf("length of sl_to: %d, capacity of sl_to: %d\n", len(sl_to), cap(sl_to))
	fmt.Printf("length of sl_from: %d, capacity of sl_from: %d\n", len(sl_from), cap(sl_from))

	sl3 := []int{1, 2, 3}
	sl3 = append(sl3, 4, 5, 6)
	fmt.Println(sl3)
}
