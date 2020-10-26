#include <stdio.h>

//Program to reverse a given number

int main()
{
    int num, d;

    printf("Enter the number to be reversed: ");
    scanf("%d", &num);

    do 
    {
        d = num % 10;
        num /= 10;

        printf("%d", d);
    }while(num  > 0);

    printf("\n");

    return 0;
}