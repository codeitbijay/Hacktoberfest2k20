#include <stdio.h>
#include <math.h>

int main() {
   int num, num1, rem, n = 0;
   float result = 0.0;

   printf("Enter an integer: ");
   scanf("%d", &num);

   num1 = num;
   
   for (num1 = num; num1 != 0; ++n) {
       num1 /= 10;
   }

   for (num1 = num; num1 != 0; num1 /= 10) {
       rem = num1 % 10;
      result += pow(rem, n);
   }
   
   if ((int)result == num)
    printf("%d is an Armstrong number.", num);
   else
    printf("%d is not an Armstrong number.", num);
   return 0;
}
