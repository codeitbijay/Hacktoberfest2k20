/********************************************************************************/
/*                       MATRIX MULTIPLICATION                                  */   
/********************************************************************************/

/**
 * Authot:  SYEED MOHD AMEEN 
 * Email:   ameensyeed2@gmail.com
 */


/*----------------------------------------------------------------*/
/* if       matrix multiplication is not possible return FALSE    */
/* else     perform multiplcation on matrix and return TRUE       */
/*----------------------------------------------------------------*/

#include<stdio.h>
#include<conio.h>
#define MAX 100             /* Change According to requirment */ 


/* Prototype functions Declaration */
bool mul(int *,int *,int *,int ,int ,int );
void display(int *,int ,int );


void main(void){
    int a[MAX],b[MAX],c[MAX];
    int r1,c1,r2,c2;
    int *p,*q,*ds;

    /* pointer assingment */
    p = a;              /* first matrix*/
    q = b;              /* second Matrix */
    ds = c;             /* Destination or resultant matrix */


    printf("\n Enter the Order of First Matrix:  ");
    scanf("%d%d",&r1,&c1);

    printf("\n Enter the Order of Second Matrix:   ");
    scanf("%d%d",&r2,&c2);

    if (c1 == r2){
        printf("Give element of First Matrix \n ");
        for (int i=0; i<r1; i++)
            for (int j=0; j<c1; j++)
                scanf("%d",(p+(i*c1)+j));
        
        printf("Give element of Second Matrix \n ");
        for (int i=0; i<r2; i++)
            for (int j=0; j<c2; j++)
                scanf("%d",(q+(i*c2)+j));
        
        printf("First Matrix:\n ");
        display(a,r1,c1);
        printf("Second Matrix:\n ");
        display(b,r2,c2);

        printf("Multiplication Matrix \n");
        mul(p,q,ds,r1,c1,c2);
        display(c,r1,c2);
    }
    else
        printf("Matrix Multiplication is Not possible \n");
}


/* Matrix Multiplication Function Using pointer */
bool mul(int *p,int *q,int *ds,int r1,int c,int c2){
    int temp = 0;
    register int i,j,k;

    for (i=0; i<r1; i++){
        for (j=0; j<c; j++){
            for (k=0; k<c2; k++){
                temp += *(p+(i*c)+k) * *(p+(k*c2)+j);          /* c[i][j] = a[i][k]*b[k][j] */
            }
            *(ds+(i*c2)+j) = temp;
            temp = 0;
        }
    }
}

/* Display Function */
void display(int *p,int r,int c){
    int temp = 0;

    for (int i=0; i<r; i++){
        for (int j=0; j<c; j++){
            printf("%d ",*(p+(i*c)+j));
        }
        printf("\n");
    }
    printf("\n ");
}
