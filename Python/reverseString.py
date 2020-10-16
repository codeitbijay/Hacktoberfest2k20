# Python code to reverse a string 
# using recursion 

def reverse(s): 
	if len(s) == 0: 
		return s 
	else: 
		return reverse(s[1:]) + s[0] 

s = "Geeksforgeeks"

print ("The original string is : ",end="") 
print (s) 

print ("The reversed string(using recursion) is : ",end="") 
print (reverse(s)) 
