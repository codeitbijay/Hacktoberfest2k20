def bubbleSort(arr):
    n = len(arr)
    for i in range(n - 1):
        for j in range(0, n - i - 1):
            if arr[j] > arr[j + 1]:
                arr[j], arr[j + 1] = arr[j + 1], arr[j]


arr = input().rstrip().split()
bubbleSort(arr)

print("Sorted array:")
for i in range(len(arr)):
    print(int(arr[i]), end=" ")