#include<stdio.h>
#include<math.h>
int main(){
    int i,x,y,a,z;
    for(i=1;i<500;i++){
        x=i%10;
        a=i/10;
        y=a%10;
        z=a/10;
        if(pow(x,3)+pow(y,3)+pow(z,3)==i){
            printf("%d is an Armstrong number \n",i);
        }
    }
    return 0;
}
