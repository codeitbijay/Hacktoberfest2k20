import Foundation

let allValues: [Int] = [0, 2, 3, 4, 10, 40, 44]
let indexAtTarget: Int = searchIndexAtValue(allValues, 10)

func searchIndexAtValue<T: Comparable>(_ array: [T], _ target: T) -> Int {
    let maximumIndex: Int = array.count > 0 ? array.count - 1 : 0
    return binarySearch(array: array, target: target, minIndex: 0, maxIndex: maximumIndex)
}

private func binarySearch<T: Comparable>(array: [T], target: T, minIndex: Int, maxIndex: Int) -> Int {
    if minIndex > maxIndex {
        return -1
    }
    
    let midIndex = minIndex + (maxIndex - minIndex) / 2
    
    if array[midIndex] == target {
        return midIndex
    } else if array[midIndex] > target {
        return binarySearch(array: array, target: target, minIndex: minIndex, maxIndex: midIndex - 1)
    } else {
        return binarySearch(array: array, target: target, minIndex: midIndex + 1, maxIndex: maxIndex)
    }
}

print("Normal Array: \(allValues)")
print("Index of value: \(indexAtTarget == -1 ? "No index" : indexAtTarget.description)")