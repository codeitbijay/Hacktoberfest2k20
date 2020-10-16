def bins(ls,n,k):
    while len(ls)!=1:
        m = len(ls)//2 if len(ls)%2==0 else (len(ls)-1)//2
        if k>ls[m]:
            ls=ls[m:]
        elif k< ls[m]:
            ls= ls[:m]
    if k==ls[0]:
        return 1
    else:
        return -1


for test in range(int(input('Enter no. of test cases: '))):
    n,k = (map(int, input('Enter length of array and no. to find: ').split()))
    ls= list(map(int,input('Enter the values of the array: ').split()))
    print(bins(ls, n, k))
