#include <iostream>
using namespace std;
#define loop(i,c,n) for(int i=c;i<n;i++)


void mergeSort(int arr[],int n){
	if(n<2) {
		return;
	} else{
		int m=n/2;
		int la[m],ra[n-m];
		loop(i,0,m){
			la[i]=arr[i];
			ra[i]=arr[m+i];
		}
		ra[n-m-1]=arr[n-1];
		
		//recursive call
		//array braked into two parts
		mergeSort(la,m);
		mergeSort(ra,n-m);
		
		//merging the sorted array
		
		int nl=m,nr=n-m;
		int i=0,j=0,k=0;
	   while(i<nl && j<nr)
	   {
		   if(la[i]<=ra[j])
		   {
			  arr[k]=la[i];
			  k++;i++;
	   	} else
	   	{
			  arr[k]=ra[j];
		  	k++;j++;
		   }
  	}
	  while(i<nl){
			arr[k]=la[i];
			k++;i++;		
  	}
	  while(j<nr){
			arr[k]=ra[j];
			k++;j++;		
	  }	
	}
}


int main()
{
	int tmp,t;
	cin>>t;
	int arr[t];;
	for(int i=0;i<t;i++){
		cin>>arr[i];
	}
	mergeSort(arr,t);
	
	for(int i=0;i<t;i++){
		cout<<arr[i]<<endl;
	}

	return 0;
}
