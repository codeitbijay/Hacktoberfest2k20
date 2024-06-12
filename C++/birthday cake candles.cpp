#include <iostream>

using namespace std;

int main()
{
   int i,n,arr[100],tall,c=0;
   cin>>n;
   for (i=0 ; i<n ; i++)
   {
       cin>>arr[i];
   }
   tall=arr[0];
   for (i=0 ; i<n ; i++)
   {
       if (arr[i]>tall)
        tall=arr[i];
   }
   for (i=0 ; i<n ; i++)
   {
    if (tall==arr[i])
    c++;
   }
   cout<<c;
   return 0;
}
