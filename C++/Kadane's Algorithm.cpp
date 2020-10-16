#include <iostream>
using namespace std;
int main() {
	int t;
	cin>>t;
	while(t--)
	{
	    int n,i,j,k,sum=0;
	    cin>>n;
	    int a[n];
	    for(i=0;i<n;i++)
	        cin>>a[i];
	   int sum_temp=0; //stores the sum including current element
	   sum=a[0]; //Stores the maximum sum upto the current element
	   for(i=0;i<n;i++)
	   {
	        sum_temp+=a[i];
	        if(sum_temp>sum)
	        {
	            sum=sum_temp;
	        }
	        if(sum_temp<0)
	        {
	            sum_temp=0;
	        }
	    }
	    cout<<sum<<"\n";
	}
	return 0;
}
