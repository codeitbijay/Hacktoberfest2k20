let array = [1, 2, 3, 4, 5, 6, 7, 8, 9]

//sort the array if not already sorted
array.sort(function(a, b){return a - b});

//the value to be searched(i.e, the index of the given number)
let value = 4
let index = exponentialSearch(array, value);

//printing the value of indes
console.log(index)


function exponentialSearch(arr, val){
    len=arr.length

    //if the required element is the first one return 0
    if(arr[0]==val)return 0

    ind=1

    //while we dont find a suitable range, keep on changing the interval
    while(ind<len && arr[ind]<=val) ind*=2

    //upon finding the suitable interval, perform a binary search
    return binarySearch(arr, ind/2, Math.min(ind, len), val)
}

//function for performing a binary search
function binarySearch(arr, left, right, val){
    if(left <= right){
        let mid = Math.ceil((left + right)/2)
        let mid_val = arr[mid];
        if(mid_val == val){
          return mid;
        } else if(val < mid_val){
            right = mid - 1;
        } else{
            left = mid + 1;
        }
        return binarySearch(arr, left, right, val);
    }
    return -1;
} 