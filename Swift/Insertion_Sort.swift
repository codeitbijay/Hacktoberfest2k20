import Foundation


func insertionSort<T: Comparable>(_ input: [T], by comparison: (T, T) -> Bool) -> [T]
{
    var items = input

    for index in 1..<items.count
    {
        let value = items[index]
        var position = index

        while position > 0 && comparison(items[position - 1], value) {
            items[position] = items[position - 1]
            position -= 1
        }

        items[position] = value
    }

    return items
}
