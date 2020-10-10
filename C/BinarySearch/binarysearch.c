#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;
    printf("Enter the number of elements: ");
    scanf("%d",&n);
    int arr[n];
    printf("Enter the elements: ");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    int key;
    printf("Enter the element to be searched: ");
    scanf("%d",&key);
    int mid, high, low;
    low = 0;
    high = n-1;
    mid = (low + high)/2;
        while(key > arr[low] && arr[high] > key)
        {
            mid = (low + high)/2;
            if(arr[mid] == key)
            {
                printf("%d is found at position %d",key,mid);
                return 0;
            }
            if(arr[mid] > key)
            {
                high = mid - 1;
            }
            if(arr[mid] < key)
            {
                low = mid + 1;
            }
        }
        if(arr[low] == key)
        {
            printf("%d is found at position %d",key,low);
        }
        else if(arr[high] == key)
        {
            printf("%d is found at position %d",key,high);
        }
        else
        printf("Element Not Found!");
}
