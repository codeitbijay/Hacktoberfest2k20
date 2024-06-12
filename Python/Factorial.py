# Factorial of a number
#FACTORIAL USING RECURSIVE METHOD.
def factorial(num):
    if num < 0:
        return "negative numbers factorial doesn't exists."
    elif num == 0:
        return 1
    elif num == 1:
        return num
    else:
        return num*factorial(num-1)
num = int(input())
print('Factorial: {}'.format(factorial(num)))
#end of code.

#ANOTHER METHOD USING LOOP TO FIND FACTORIAL.
num = int(input("  Enter a number =  "))
fac = 1 
for i in range(1, num + 1):
	fac = fac * i
print(" The factorial of ", num, " is ", fac)
#end of code.
