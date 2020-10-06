#include <stdio.h>
#include <stdlib.h>

int binaryrec(int arr[] , int first , int last ,int key )
{
    int mid ;
    mid = (first + last) /2 ;
    if (arr[mid] == key )
    {
        return mid + 1;
    }
    else if(arr[mid] > key)
    {
        binaryrec(arr , first ,mid - 1 , key );
    }
    else if(arr[mid] < key)
    {
        binaryrec(arr , mid + 1 , last , key );
    }

}


int main()
{
    int arr[10] = {1,2,3,4,5,6,7,8};
    int key = 10;
    printf("position is %d ",binaryrec(arr,0,9,key));
    return 0;
}