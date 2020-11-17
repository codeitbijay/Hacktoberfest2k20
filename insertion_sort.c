#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(){
    int c, x;
    scanf("%d", &x);
    for(c=0;c<x;c++){
    int i, j, aux, v[1001], cont = 0, quant, v2[1001];
    scanf("%d", &quant);
    for(i=0;i<quant;i++){
        scanf("%d", &v[i]);
    }
    for(i=0;i<quant;i++){
        v2[i] = v[i];
    }
    for(i=1;i<quant;i++){

        aux = v[i];
        j = i - 1;

        while((j >= 0)&&(aux > v[j])){
            v[j+1] = v[j];
            j--;
        }
        v[j+1] = aux;
    }

    for(i=0;i<quant;i++){
        if(v2[i] == v[i]){
            cont++;
        }
    }
    printf("%d\n", cont);
}
    return 0;
}
