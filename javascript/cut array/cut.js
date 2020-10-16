let array = [5, 4, 3, 2, 1]

console.log(cut(array, 0, 2))

function cut(arr, startIndex, endIndex){
    if(endIndex < startIndex || endIndex >= arr.length){
        return 'Invalid index'
    }
    let result = []
    for(let i = startIndex; i <= endIndex; i++){
        result.push(arr[i])
    }
    return result
}