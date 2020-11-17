#include <stdio.h>
#include <stdlib.h>

int main()
{   int x,y,L;
    printf("Enter two numbers\n");
    scanf("%d %d",&x,&y);
    for(L=1;L<=x*y;L++)

    if(L%x==0&&L%y==0)
        break;  // agar break ahi laga rahe to  do baar print ho rha hai

    printf("Lcm of number is %d",L);

    return 0;
}
