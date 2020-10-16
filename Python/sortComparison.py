#Emre Biçer
#github.com/emrebicer

import timeit
import random
import math

arrToSort = [];
arrToSort2 = [];
arrToSort3 = [];
arrToSort4 = [];
arrToSort5 = [];

howManyNumbersToSort = 1000


for i in range(howManyNumbersToSort):
    recNum = random.randint(-howManyNumbersToSort,howManyNumbersToSort)
    arrToSort.append(recNum)
    arrToSort2.append(recNum)
    arrToSort3.append(recNum)
    arrToSort4.append(recNum)
    arrToSort5.append(recNum)

#insertion sort
def insertionSort(arr):
    A = arr
    i = 1
    while i < len(A):
        j = i
        while j>0 and A[j-1]>A[j]:
            #swap 2 varibales in python...
            A[j],A[j-1] = A[j-1],A[j]
            j = j - 1
        i = i + 1
    return reverseArr(A)

#quick sort(recursive)
def quickSort(arr,low='DEFAULT',high='DEFAULT'):
    A = arr
    if low=='DEFAULT':
        low = 0
        high = len(A)-1

    if low<high:
        pi = partition(A,low,high)
        quickSort(A,low,pi-1)
        quickSort(A,pi+1,high)

    return reverseArr(A)

def partition(arr,low,high):
    pivot = arr[high]
    i = low - 1
    for j in range(low,high):
        if arr[j]<=pivot:
            i = i + 1
            arr[i],arr[j] = arr[j],arr[i]
    arr[i+1],arr[high] = arr[high],arr[i+1]
    return (i+1)


#merge sort(recursive)
def mergeSort(arr):
    A = arr
    if len(A)<= 1:
        return A
    left = []
    right = []

    for i in range(len(A)):
        if i< len(A)/2:
            left.append(A[i])
        else:
            right.append(A[i])

    left = mergeSort(left)
    right = mergeSort(right)

    return merge(left,right)

def merge(le,ri):
    left = le
    right = ri

    result = []
    while len(left)!=0 and len(right)!=0:
        if left[0] > right[0]:
            result.append(left[0])
            del left[0]
        else:
            result.append(right[0])
            del right[0]

    while len(left)!=0:
        result.append(left[0])
        del left[0]
    while len(right)!=0:
        result.append(right[0])
        del right[0]

    return result

#bubble sort
def bubbleSort(arr):
    A = arr
    swapped = True
    while swapped:
        swapped = False
        for i in range(len(A)-1):
            if A[i]>A[i+1]:
                A[i],A[i+1] = A[i+1],A[i]
                swapped = True

    return reverseArr(A)

#python .sort() function
def pySelfSortFunc(arr):
    sortedArr = arr
    sortedArr.sort()
    return reverseArr(sortedArr)

#that function reverse an array [1,2,3] ---> [3,2,1]
def reverseArr(arr):
    return list(reversed(arr))





print("############## .sort() (python function) ##############")
start = timeit.default_timer()
(pySelfSortFunc(arrToSort))
stop = timeit.default_timer()
print('Time: ', stop - start)


print("############## insertionSort() ##############")
start = timeit.default_timer()
(insertionSort(arrToSort2))
stop = timeit.default_timer()
print('Time: ', stop - start)

print("############## quickSort() ##############")
start = timeit.default_timer()
(quickSort(arrToSort3))
stop = timeit.default_timer()
print('Time: ', stop - start)

print("############## mergeSort() ##############")
start = timeit.default_timer()
(mergeSort(arrToSort4))
stop = timeit.default_timer()
print('Time: ', stop - start)

print("############## bubbleSort() ##############")
start = timeit.default_timer()
(bubbleSort(arrToSort5))
stop = timeit.default_timer()
print('Time: ', stop - start)


