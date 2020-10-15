#include<stdio.h>
#include<stdlib.h>
struct node{
int x;
struct node *next;
};
struct node *start;
void add_node();
void display_node();
void findLowest();
void move_Last();
void modify();
void main(){
int op;
do{
printf("\n----------------------MENU-------------------------------");
printf("\n1)Add node\n2)Display node\n3)Find lowest\n4)Move last node to first\n5)Modify_List\n6)Exit");
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
    findLowest();
    break;
case 4 :
    move_Last();
    break;
case 5:
    modify();
    break;
case 6:
    printf("\nGood Bye!");
    exit(1);
default:
    printf("\nInvalid Option");
    }
   }while(1);
}
void add_node(){
struct node *ptr;
ptr = (struct node *)malloc(sizeof(struct node));
if(ptr == NULL){
    printf("Memory is Full");
    return ;
   }
   printf("\nEnter element in node::");
   scanf("%d", &ptr->x);
   ptr->next = start;
   start = ptr;
}
void display_node(){
    struct node *ptr;
    ptr= start;
    while(ptr!=NULL){
        printf("\nElement is : %d" , ptr->x);
        ptr=ptr->next;
    }
}
void findLowest(){
struct node *ptr;
int min;
int idx = 0 , count = 0;
ptr = start;
min= ptr->x;
while(ptr!=NULL){
        count++;
    if((ptr->x) < min){
        min = ptr->x;
        idx = count;
    }
ptr=ptr->next;
}
printf("Minimum Element in LinkedList = %d at node number %d" , min , idx);
}
void move_Last(){
struct node *ptr , *last ;
last = ptr = start;
while(last->next!= NULL){
    last=last->next;
}
while(ptr->next != last){
    ptr = ptr->next;
}
last->next = start;
start = ptr->next;
ptr->next = NULL;
}
void modify(){
    struct node *ptr;
    int num , new , flag=0;
    printf("\nEnter the element you want to modify::");
    scanf("%d" , &num);
    ptr = start;
    while(ptr != NULL){
        if(ptr->x == num){
            printf("\nEnter the new element::");
            scanf("%d" , &new);
            flag =1 ;
            ptr->x = new;
            break;
        }
        ptr=ptr->next;
    }
    if(flag == 0){
        printf("No such node is FOUND");
    }

}
