package main

import "fmt"

func Fibo(n int) int {
    if n<=1 {
        return n
    }
    return Fibo(n-1)+ Fibo(n-2)
}

func main(){
    var n int
    for n = 0; n<10;n++{
    fmt.Print(Fibo(n)," ")
    }
}