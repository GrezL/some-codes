package main

import (
	"fmt"
	"sync"
)

type Info struct {
	mu  sync.Mutex
	Str string
}

func Update(info *Info) {
	info.mu.Lock()

	info.Str = "test"
	info.mu.Unlock()
}

func main() {
	a := new(Info)
	Update(a)
	fmt.Printf("Object a has attr Str: %s\n", a.Str)
}
