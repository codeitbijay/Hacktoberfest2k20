#include <stdio.h>
#include <stdlib.h>
 
int main()
{
    int num, rem, sum=0;
 
    printf("Enter a number to check for neon Number: ");
    scanf("%d",&num);
    
    int square = num*num;
 
    while(square!=0){
        rem = square % 10;
        sum += rem;
        square /= 10;
    }
 
    if(sum == num)
        printf("Neon Number \n");
    else
        printf("Not a Neon Number \n");
 
    return 0;
}
