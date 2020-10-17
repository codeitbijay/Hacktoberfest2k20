#include <cstdio>
#include <cstdlib>
int main (void){
	int arr[10];
	for (int i=0; i<10;i++){
		scanf("%d", &arr[i]);
		}
		int min=arr[0], max=arr[0], sum=arr[0];
		for (int i=1; i<10;i++){
		if(arr[i]<min){
			min=arr[i];
		}
		if(arr[i]>max){
			max=arr[i];
		}
		sum = sum+arr[i];
	}
	printf("%d\n", min);
	printf("%d\n", max);
	printf("%lf\n", sum/10.0);
	
	
		
		
		return EXIT_SUCCESS;
		}
