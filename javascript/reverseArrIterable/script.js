// regularly iterating over an arr is one thing, but what if we want to do it backwards?
// here are 3 methods to do so

// 1 iterate backwards over arr
let arr0 = [4, 3, 2, 1];
for (let i = arr0.length -1; i >= 0; i--) {
    console.log(arr0[i]);
}

//2 use reverse func
let arr1 = [3, 2, 1]
for (let x of arr1.reverse()) {
    console.log(x);
}

//3 define our own iterator
let arr3 = [6, 5, 4, 3, 2, 1];
let y = arr3.length;

let iterator = {
    next: function () {
        y--;
        return {
            done : y < 0,
            value : arr3[y]
        }
    }
}
iterator[Symbol.iterator] = function () {
    return this;
}

for (let i of iterator) {
    console.log(y);
}
// take a look at the [Symbol.iterator] docs here for more insight - https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Iteration_protocols 
// and feel free to fork/ clone this to play around with it yourself! :) 