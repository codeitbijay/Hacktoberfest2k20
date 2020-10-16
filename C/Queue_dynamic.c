#include<stdio.h>
#include<stdlib.h>
typedef struct node{
int x;
 struct node *next;
};
struct node *rear , *front;
void insert();
void delete1();
void display();
void main(){
int op;
do{
        printf("\n------MENU------");
        printf("\n 1)Insert \n 2) Delete \n 3) Display\n 0)Exit");
        printf("\n Enter your option::");
        scanf("%d" , &op);
        switch (op){
    case 1:
        insert();
        break;
    case 2:
        delete1();
        break;
    case 3:
        display();
        break;
    case 0:
        printf("\n Good Bye!");
        return 1;
    default:
        printf("\n Invalid Option");
        }
    }while(1);
}
void insert(){
struct node *ptr;
ptr = (struct node *)malloc(sizeof (struct node));
if(ptr == NULL){
  printf("\n Memory is Full!");
  return;
}
printf("\n Enter element in node::");
scanf("%d" , &ptr->x);
if(rear == NULL){
    rear = front = ptr;
    ptr->next = NULL;
}
else{
    rear->next = ptr;
    rear = ptr;
    ptr->next = NULL;
}
}
void delete1(){
struct node *ptr;
ptr = front;
if(front == NULL){
  printf("\n Queue is Empty!");
  return;
}
printf("\n %d is deleted" , ptr->x);
front = front->next;
free(ptr);
}

void display(){
struct node *ptr;
ptr = front;
printf("\n");
while(ptr != NULL){
 printf("%d " , ptr->x);
 ptr=ptr->next;
}
}