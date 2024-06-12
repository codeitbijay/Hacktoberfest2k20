'''
This code is an example solution to create an staircase generator
using a numerical input that represents the base and height
of a triangle.
Example input:
5
Example output:
    #
   ##
  ###
 ####
#####
Generate a triangle generator with the base and height being the same as the input.
'''
n = int(input("Enter N value for your triangle's base and height "))
def staircase(n):
    n = n+1
    for i in range(1,n):
        spaces = (n-i)-1
        print(' '*spaces+'#'*i)
staircase(n)