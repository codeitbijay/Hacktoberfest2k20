#include <stdio.h>
int main() 
{
    int n,a,b,i;
    printf("Enter a Two Numbers: ");
    scanf("%d%d",&a,&b);

    for(n=a+1; n<b; n++)
    {
        for (i=2; i<n; i++)
        {
            if (n%i==0)
                break;
        }
        if(i==n)
            printf("%d ",n);
    }

    return 0;
}