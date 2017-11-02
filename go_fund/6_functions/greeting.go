package main

func main() {
	//	println("In main before calling greeting")
	//	greeting()
	//	println("In main after calling greeting")
	Greeting("hello:", "Joe", "Anna", "Eillen")
}

func greeting() {
	println("In greeting: Hi!!!")
}

func Greeting(prefix string, who ...string) {
	println(who)
}
