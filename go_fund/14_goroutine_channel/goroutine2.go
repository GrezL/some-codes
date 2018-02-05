package main

import "fmt"

func main() {
	ch := make(chan string)
	strList := []string{"Washington", "Tripoli", "London", "Beijing", "Tokio"}

	for _, loc := range strList {
		go sendData(ch, loc)
		fmt.Println(loc)
	}
	go getData(ch)
}

func sendData(ch chan string, loc string) {
	ch <- loc
}

func getData(ch chan string) {
	for {
		input := <-ch
		fmt.Printf("%s", input)
	}
}
