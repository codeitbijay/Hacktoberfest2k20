#include <iostream>
using namespace std;

int binarysearch(int arr[], int l,int r, int x){
	if(r>=l){
		int mid = l + (r-1)/2;
		
		if(arr[mid]==x)
			return mid;
		
		if(arr[mid]>x)
			return binarysearch(arr,l,mid-1,x);
		
		return binarysearch(arr,l,mid+1,x);
	}
	return -1;
}

int main()
{
	int count, num, i, arr[30];
	cout<<"how many elements would you like to enter?:"; 
        cin>>count;

	for (i=0; i<count; i++)
	{
		cout<<"Enter number "<<(i+1)<<": "; 
                cin>>arr[i];
	}
	cout<<"Enter the number that you want to search:"; 
        cin>>num;
	
	int res = binarysearch(arr,0,count-1,num);
	if(result==-1)
		cout<<"\nElement is not present in the array";
	else
		cout<<"\nElement is found at index "<<result;
	  
	return 0;
}
