#include<stdio.h>
 
int main(){
	int num,i,s=0;
	printf("Enter a number: ");
	scanf("%d",&num);
	
	for(i=1;i<num;++i){
		if(num%i==0){
			s=s+i;
		}
	}
 
	if(s==num) {
		printf("\nPerfect Number");
	}	
	else {
		printf("\nNot perfect number");
	}
	
	return 0;
}
