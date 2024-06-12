#include<stdio.h>
#include<math.h>
int main()
{
    float a,b,c,x,y,disc,p,q,r;
    printf("\n *** C PROGRAMS BLOG ***");
    printf("\n >>>> C PROGRAM TO FIND ROOTS OF QUADRATIC EQUATION <<<<");
    printf("\n Enter the values of a,b,c : ");
    scanf("%f %f %f",&a,&b,&c);
    disc=(b*b)-(4*a*c);
    if(disc == 0)
    {
        x=(-b)/(2*a);
        y=x;
        printf("\n Roots are Equal..");
        printf("\n x= %f , y= %f",x,y);
    }
     else if(disc < 0)
    {
        p=(-b)/(2*a);
        q=sqrt(-disc)/(2*a);
        printf("\n Roots are Complex and Imaginary..");
        printf("\n x= %f+%fi , y= %f-%fi",p,q,p,q);
    } 
     else if(disc > 0)
    {
        r=sqrt(disc);
        x=((-b)+r)/(2*a);
        y=((-b)-r)/(2*a);
        printf("\n Roots are Real Numbers..");
        printf("\n x= %f , y= %f",x,y);
    }
    else if(a==0)
    {
      x=(-c)/b;
      printf("\n Root is x = %f ",x);
    }
    getch();
    return 0;
}
