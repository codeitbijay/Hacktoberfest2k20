#include<stdio.h>
#include<stdlib.h>
struct node{
int x;
struct node *next;
};
struct node *start;
void add_node();
void display_node();
void print_nth();
void exchange();
void insert();
void delete();
void main(){
int op;
do{
printf("\n----------------------MENU-------------------------------");
printf("\n1)Add node\n2)Display node\n3)Print nth and n-1th element\n4)Exchange First with Last\n5)Insert node\n6)Delete node\n7)Exit");
printf("\nEnter your option::");
scanf("%d" , &op);
switch(op){
case 1:
    add_node();
    break;
case 2:
    display_node();
    break;
case 3:
    print_nth();
    break;
case 4:
    exchange();
    break;
case 5:
    insert();
    break;
case 6:
    delete();
    break;
case 7:
    printf("\nGood Bye!");
    exit(1);
default:
    printf("\nInvalid Option");
    }
   }while(1);
}
void add_node(){
struct node *ptr , *last;
ptr = (struct node *)malloc(sizeof(struct node));
printf("Enter element in node::");
scanf("%d",&ptr->x);
if(start == NULL){
    ptr->next = NULL;
    start = ptr;
}
else{
    last = start;
    while(last->next != NULL){
        last = last->next;
    }
    last->next = ptr;
    ptr->next = NULL;
}
}
void display_node(){
    struct node *ptr;
   ptr= start;
    while(ptr!=NULL){
        printf("\nElement is : %d" , ptr->x);
        ptr=ptr->next;
    }
}
void print_nth(){
int n , count=0 ,flag=0;
struct node *ptr , *prev;
printf("Enter the value of n:");
scanf("%d" ,&n);
ptr = start;
while(ptr!=NULL){
    count++;
    if(count==n && n==1){
        printf("1st element is ::%d and 0th element Not Found" , ptr->x);
        flag=1;
        break;
    }
    if(count == n && n!=1){
            flag=1;
        printf("%dth and %dth element is :: %d and %d", n , n-1,ptr->x , prev->x);
        break;
    }
    prev = ptr;
    ptr = ptr->next;
}
if(flag==0)
    printf("Element Not Found");
}
void exchange(){
struct node *first , *last ,*prev;
first = last = prev = start;
while(last->next!=NULL){
        prev = last;
    last=last->next;
}
start = last;
last->next = first->next;
prev->next=first;
first->next = NULL;
}
void insert(){
struct node *ptr , *fpt;
int node_no , c=0;
printf("Enter node number after which you want to insert ::");
scanf("%d" , &node_no);
fpt = start;
while(fpt!=NULL){
    c++;
    if(c==node_no){
            ptr=(struct node*)malloc(sizeof(struct node));
            printf("Enter element in new node ::");
            scanf("%d" , &ptr->x);
            ptr->next = fpt->next;
            fpt->next = ptr;
            return;
     }
     else
     fpt=fpt->next;
}
printf("Node number %d not Found" , node_no);
}
void delete(){
struct node *ptr , *prev;
int num;
printf("Enter the elememt to delete::");
scanf("%d" , &num);
ptr = start;
while(ptr != NULL){
    if(ptr->x == num){
        if(ptr == start){
            start = start->next;
            printf("\n%d is deleted" ,num);
            free(ptr);
            return;
        }
         else if(ptr->next == NULL){
           prev->next =NULL;
           printf("\n%d is deleted" , num);
           free(ptr);
           return;
        }
        else{
            prev->next = ptr->next;
            printf("%d is deleted", ptr->x);
            free(ptr);
            return;
        }
    }
    prev= ptr;
    ptr= ptr->next;
 }
 printf("%d is NOT Found IN Linked List", num);
}