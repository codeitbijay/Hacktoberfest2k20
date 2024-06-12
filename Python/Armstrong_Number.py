#Program to check whether the number is an armstrong number or not
#eg:153 is an Armstrong number. 
#153 = (1*1*1)+ (5*5*5)+(3*3*3)
#407=(4*4*4)+(0*0*0)+(7*7*7*)
#1634=(1*1*1*1)+(6*6*6*6)+(3*3*3*3)+(4*4*4*4)
#8208=(8*8*8*8)+(2*2*2*2)+(0*0*0*0)+(8*8*8*8)
#9474=(9*9*9*9)+(4*4*4*4)+(7*7*7*7)+(4*4*4*4)



#CODE

#Ask user to enter the number for checking
number=int(input("Enter the number you want to check armstrong:  "))

order=len(str(number))

#Initialise sum as 0
sum=0

temp=number
while temp>0:
    num=temp%10
    sum+=num**order
    temp//=10

if (number==sum):
    print("The number you have entered is an Armstrong number.")
else:
    print("The number you have entered is not an Armstrong number.")


#Example:
#Enter the number you want to check armstrong:  407
#The number you have entered is an Armstrong number.
