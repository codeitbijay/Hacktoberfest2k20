#include <stdio.h> 
  
void printArray(int* arr) 
{  
  
    printf("Array: "); 
    for (int i = 0; i < sizeof(arr)-1; i++) { 
        printf("%d ", arr[i]); 
    } 
   
} 
  
int main() 
{ 
    int arr[] = {2,0,5,10,5,-3,16}; 
      
    printArray(arr); 
  
    return 0; 
}