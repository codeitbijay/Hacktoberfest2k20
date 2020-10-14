#include<stdio.h>
#include<conio.h>
 
int main()
{
    int num,num1,rem,sum=0;

 
    printf("Enter a number: ");
    scanf("%d",&num);
 
    num1 = num;
 
    while(num1!=0)
    {
        rem=num1%10;
        sum+=rem;
        num1=num1/10;
    }
 
    if(num%sum==0)
        printf("NIVEN NUMBER \n");
    else
        printf("NOT A NIVEN NUMBER");
 
    return 0;
}
