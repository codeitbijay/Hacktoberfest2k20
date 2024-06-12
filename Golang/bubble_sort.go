package main
 
import (
    "fmt"
)
 
func main() {
    slice := []int{3, 4, 5, 2 ,4}
    fmt.Printf("\n--- Unsorted --- \n %v", slice)
    bubblesort(slice)
    fmt.Printf("\n--- Sorted --- \n %v ", slice)
}

func bubblesort(items []int) {
    var (
        n = len(items)
        sorted = false
    )
    for !sorted {
        swapped := false
        for i := 0; i < n-1; i++ {
            if items[i] > items[i+1] {
                items[i+1], items[i] = items[i], items[i+1]
                swapped = true
            }
        }
        if !swapped {
            sorted = true
        }
        n = n - 1
    }
}
