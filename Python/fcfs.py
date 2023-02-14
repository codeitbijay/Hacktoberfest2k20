n=int(input("enter number of processes in the queue :"))
head=int(input("enter the position of head currently:"))
pr=[0]*100
seekTime=0
print("enter the positions of the processes in order :")
for i in range(n):
	pr[i]=int(input())
	if(i==0):
		seekTime=abs(head-pr[i])
	else:
		seekTime+=abs(pr[i]-pr[i-1])
print("seek Time = ",seekTime)
print("order of scheduling :\n")
print(head," ->",end=" ")
for i in range(n):
	print(pr[i]," ->",end=" ")
print("end\n")
