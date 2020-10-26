def display():
    if(len(Bufferlist)==0):
        print("Nothing is available to consume. No of items produced is 0")
    else:
        print("No of items produced and that consumer can consume: ",len(Bufferlist))
        print("Number of items required to be full:",n-len(Bufferlist))

def wait(w):
		while(w<0):
			pass
		w-=1
		return(w)
def signal(s):
		s+=1
		return(s)

def producer(i):
	global Bufferlist, mutex,producednumber
	mutex = wait(mutex)
	Bufferlist.append(i)
	mutex = signal(mutex)
	producednumber=producednumber+1
	print("\n\nProducer produced item number ",producednumber)
	print(f"Process added(Produced)")

def consumer(i):
	global Bufferlist,mutex,consumenumber
	mutex = wait(mutex)
	value = Bufferlist.pop(Bufferlist.index(i))
	mutex = signal(mutex)
	consumenumber=consumenumber+1
	print("\n\nConsumer consumed item number ",consumenumber)
	print(f"The process has been removed(Consumed) and consumed ")


print("\n\n********************PRODUCER-CONSUMER problem********************\n\n")
n = int(input("BufferSize: "))
Bufferlist= []
mutex = 1
producednumber=0
consumenumber=0
while(1):
	print("\n************\n1.Produce\n2.Consume\n3.Display\n4.Exit:\n**********\n")
	choice = int(input("Enter choice---->"))
	if(choice==1):
		if(mutex==1 and len(Bufferlist)!=n):
			producer(1)
			
			

		else:
			print("\nIt is now full\n")
	elif(choice==2):
		if(mutex==1 and len(Bufferlist)!=0):
			consumer(1)
		else:
			print("\nIt is now empty\n")

	elif(choice==3):
		display()
	else:
		exit()


