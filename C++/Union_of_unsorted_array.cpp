/*  Find Union two unsorted array
    Here I have used set to make the array in a sorted order
    since set uses Binary search ,therefore its time complexity is O(logn).
    @author : Rishikesh raj
*/

# include<iostream>
#include<set>
#include<iterator>
using namespace std;

void sort(int arr1[],int arr2[],int n1,int n2)
{
        set<int>s;
        for(int i=0;i<n1;i++)
        {
            s.insert(arr1[i]);   
        }

        for(int i=0;i<n2;i++)
        {
            s.insert(arr2[i]);
        }

        set<int>::iterator itr;
    cout<< "Union of the array : ";
        for(itr=s.begin();itr!=s.end();itr++)
        {
            cout<<*itr<<" ";
        }
}


int main()
{
    cout<<"Enter the size of array 1 : ";
    int n1;
    cin>>n1;

    int arr1[n1];
    cout<<"Enter the element of 1st array"<<endl;
    for(int i=0;i<n1;i++)
        cin>>arr1[i];


    cout<<"Enter the size of array 2: ";
    int n2;
    cin>>n2;

    int arr2[n2];
    cout<<"Enter the element of 2nd array"<<endl;
    for(int i=0;i<n2;i++)
        cin>>arr2[i];    
    
    sort(arr1,arr2,n1,n2);
    return 0;
}
