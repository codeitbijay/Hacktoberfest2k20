#include<stdio.h>
void main()
{
    int n,rev_int=0,r,orig_int;
    printf("Enter the no.");
    scanf("%d",&n);

    orig_int=n;

    while(n!=0)
    {
        r = n % 10;
        rev_int = rev_int*10 + r;
        n = n/10;
    }
    printf("The reversed no. is %d\n",rev_int);
    if(orig_int==rev_int)
        printf("%d is a palindrome",orig_int);
    else
        printf("%d is not a palindrome",orig_int);
}

