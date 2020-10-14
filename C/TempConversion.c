#include <stdio.h>
int main()
{
  
    float f,c;
    int choice;
 
    printf("\n1: Convert from Fahrenheit to Celsius."); 
    printf("\n2: Convert from Celsius to Fahrenheit.");
    printf("\nEnter your choice - 1,2 : ");
    scanf("%d",&choice);
 
    if(choice ==1){
        printf("\nEnter Temperature in Fahrenheit: ");
        scanf("%f",&f);
        c= (f - 32) / 1.8;
        printf("Temperature in Celsius: %.2f",c);
    }
    else if(choice==2){
        printf("\nEnter Temperature in Celsius: ");
        scanf("%f",&c);
        f= (c*1.8)+32;
        printf("Temperature in Fahrenheit: %.2f",f);
    }
    else{
        printf("\nWrong Choice !!!");
    }
    return 0;
}
