package main

import (
	"fmt"
	"time"
)

func longwait() {
	fmt.Println("Begining longWait()")
	time.Sleep(5 * 1e9)
	fmt.Println("End of longwait()")
}

func shortwait() {
	fmt.Println("Begining shortWait()")
	time.Sleep(2 * 1e9)
	fmt.Println("End of shortwait()")
}

func main() {
	fmt.Println("In main()")
	go longwait()
	go shortwait()
	fmt.Println("About to sleep in main()")
	time.Sleep(20 * 1e9)
	fmt.Println("At the end of main()")
}
