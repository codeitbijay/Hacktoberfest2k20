def countvol(s):
    v="aeiou"
    c=0
    for i in s:
        if i in v:
            c=c+1
    return c

def work(n,e):
    no=['zero','one','two','three','four','five','six','seven','eight','nine','ten','eleven','twelve','thirteen','fourteen','fifteen','sixteen','seventeen','eighteen','nineteen','twenty','thirty','forty','fifty','sixty','seventy','eighty','ninety','hundred']
    pair=[]
    p=0
    k=0
    for i in e:
        s=int(i)
        if s>=0 and s<=20:
            t=countvol(no[s])
        elif s>20 and s<30:
            t=countvol(no[20])+countvol(no[int(i[1])])
        elif s>=30 and s<40:
            t=countvol(no[21])+countvol(no[int(i[1])])
        elif s>=40 and s<50:
            t=countvol(no[22])+countvol(no[int(i[1])])
        elif s>=50 and s<60:
            t=countvol(no[23])+countvol(no[int(i[1])])
        elif s>=60 and s<70:
            t=countvol(no[24])+countvol(no[int(i[1])])
        elif s>=70 and s<80:
            t=countvol(no[25])+countvol(no[int(i[1])])
        elif s>=80 and s<90:
            t=countvol(no[26])+countvol(no[int(i[1])])
        elif s>=90 and s<100:
            t=countvol(no[27])+countvol(no[int(i[1])])
        elif s==100:
            t=countvol(no[28])
        k=k+t
    for r in e:
        for c in e:
            if ([r,c] not in pair) and ([c,r] not in pair):
                pair.append([r,c])
    for r in pair:
        if (int(r[0])+int(r[1])==k):
            p=p+1
    if p>=0 and p<=20:
        print(no[p])
    elif p>20 and p<30:
        print(no[20]+int(no[(str(p)[1])]))
    elif p>=30 and p<40:
        print(no[21]+int(no[(str(p)[1])]))
    elif p>=40 and p<50:
        print(no[22]+int(no[(str(p)[1])]))
    elif p>=50 and p<60:
        print(no[23]+int(no[(str(p)[1])]))
    elif p>=60 and p<70:
        print(no[24]+int(no[(str(p)[1])]))
    elif p>=70 and p<80:
        print(no[25]+int(no[(str(p)[1])]))
    elif p>=80 and p<90:
        print(no[26]+int(no[(str(p)[1])]))
    elif p>=90 and p<100:
        print(no[27]+int(no[(str(p)[1])]))
    elif p==100:
        print(no[28])
    elif p>100:
        print("Greater Than Hundred")



n1=int(input("Number of elements\n"))
n2=input("Enter n elements followed by space")
e1=n2.split()
work(n1,e1)




