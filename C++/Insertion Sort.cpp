#include<iostream>
using namespace std;
void insert(int arr[], int i)
{
        int key, j;
        key = arr[i];  
        j = i - 1;
        while (j >= 0 && arr[j] > key) 
        {  
            arr[j + 1] = arr[j];  
            j = j - 1;  
        }  
        arr[j + 1] = key;  
}

void insertionSort(int arr[], int n)
{
   int i;
   for (i = 1; i <n; i++)
      insert(arr, i);
}


void printArray(int arr[], int size)
{
    int i;
    for (i=0; i < size; i++)
        cout<<arr[i];
   cout<<endl;
}

int main()
{
    int arr[1000],n,T,i;

    cin>>T;

    while(T--){

    cin>>n;

    for(i=0;i<n;i++)
      cin>>arr[i];

    insertionSort(arr, n);
    printArray(arr, n);
    }
    return 0;
}

