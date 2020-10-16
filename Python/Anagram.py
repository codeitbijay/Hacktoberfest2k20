a=input("enter string 1:")
b=input("enter string 2:")
c=0
if len(b)==len(a):
	for i in range(len(a)):
		if a[i] not in a[:i]:
			if a[i] in b:
				if b.count(a[i])==a.count(a[i]):
					pass
				else:
					c+=1
					break
			else:
				c+=1
				break
else:
	c+=1
if c==0:
	print("they are anagram")
else:
	print("they are not anagram")
