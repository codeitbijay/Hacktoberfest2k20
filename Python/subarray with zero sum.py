t=int(input())
while t>0:
    n=int(input())
    a=list(map(int,input().split()))
    s=set()
    temp=0
    flag=0
    for i in range(len(a)):
        temp=temp+a[i]
        
        if temp in s or temp==0:
            flag=1
            break
        else:
            s.add(temp)
        
    if flag==1:
        print('Yes')
    else:
        print('No')
    t=t-1
        
