#A simple python program to calculate simple interest with the given values of principal, time and rate of interest.

def simple_interest(p,t,r): 
    si = (p * t * r)/100
    print(f"The Simple Interest is {si}") 
      
pri = int(input("Principal: "))
tim = int(input("Time: "))
rat = int(input("Rate Of Interest: "))

simple_interest(pri, tim, rat)
