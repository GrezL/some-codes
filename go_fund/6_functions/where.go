package main

import (
	"runtime"
	"log"
)

where := func(){
	_, file, line, _ := runtime.Caller(1)
	log.Printf("%s:%d", file, line)
}
