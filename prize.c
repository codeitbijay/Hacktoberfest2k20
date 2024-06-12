#include<stdio.h>
int main(int argc, char const *argv[])
{
int a ,b ;
printf ("enter yours marks in maths \n ");
scanf ("%d", &a);
printf (" enter marks in science \n");
scanf("%d" ,&b);
if ( a > 33 & b >33) {
 printf("you won 78 rupees");
}
else if ( a <33 & b > 33) {
        
        printf("you won 25 rupess");
}
else if (a >33 & b < 33){
        printf ( "you won 20 rupees");
}
else {
        printf ( "work hard");
}
        return 0;
}
