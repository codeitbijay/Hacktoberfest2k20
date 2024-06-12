import timeit

def mergeSort(a):
    if len(a) > 1:
        m = len(a) // 2
        l = a[:m]
        r = a[m:]

        mergeSort(l)
        mergeSort(r)

        i = j = k = 0

        while i < len(l) and j < len(r):
            if l[i] < r[j]:
                a[k] = l[i]
                i += 1
            else:
                a[k] = r[j]
                j += 1
            k += 1

        while i < len(l):
            a[k] = l[i]
            i += 1
            k += 1

        while j < len(r):
            a[k] = r[j]
            j += 1
            k += 1


a = [12, 11, 13, 5, 6, 1, 7]

n = len(a)

print ("Input array is", end="\n")
for i in range(n):
    print(f"{a[i]}", end=" ")
print()

start = timeit.default_timer()
mergeSort(a)
stop = timeit.default_timer()
print('\nTime taken to perform mergesort: ', stop - start)
print()


print("Sorted array is:")
for i in range(n):
    print(f"{a[i]}", end=" ")
