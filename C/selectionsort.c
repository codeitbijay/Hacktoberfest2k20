#include<stdio.h>

int main()
{
 int N,d,a;
 printf("Enter Size of Array: ");
 scanf("%d",&N);
 int arr[N];
 printf("Enter Elements in the Array:\n");
 for(int i=0;i<N;i++)
 {
  printf("Enter Element %d: ",(i+1));
  scanf("%d",&arr[i]);
 }
 printf("ARRAY: ");
 for(int i=0;i<N;i++)
  printf("| %d ",arr[i]);
 printf("|\n");
 
 //Selection Sort//
 for(int i=0;i<N;i++)
 {
  d=arr[i];
  a=i;
  for(int j=i+1;j<N;j++)
  {
   if(d>arr[j])
   {
    d=arr[j];
    a=j;
   }
  }
  arr[a]=arr[i];
  arr[i]=d;
 }
 printf("SORTED ARRAY: ");
 for(int i=0;i<N;i++)
  printf("| %d ",arr[i]);
 printf("|\n");
 
 return 0;
}
