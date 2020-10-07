n=int(input())
a=list(map(int,input().split()))
for i in range(n):
    min_ind=i
    for j in range(i+1,n):
        if a[j]<a[min_ind]:
            min_ind=j
    a[min_ind],a[i]=a[i],a[min_ind]
print(*a)    
