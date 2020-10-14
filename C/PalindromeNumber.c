#include <stdio.h>
int main() {
    int num, rev=0, rem, num1;
    printf("Enter an integer: ");
    scanf("%d", &num);
    num1 = num;
    
    while (num != 0) {
        rem = num % 10;
        rev = rev * 10 + rem;
        num /= 10;
    }

    if (num1 == rev)
        printf("%d is a palindrome.", num1);
    else
        printf("%d is not a palindrome.", num1);

    return 0;
}
