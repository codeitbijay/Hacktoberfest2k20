//Circular Linked list inserting and displaying node through method #1
#include<stdio.h>
#include<stdlib.h>
struct node
{
 int x;
 struct node *next;
 };
 struct node *start;
 void add_node();
 void display_node();
 void searching();
 void main()
 {
     int op;
     do
      {
          printf("\n --------MENU--------");
          printf("\n 1) Add node \n 2) Display Node \n 3)Search Node \n 4) Exit ");
          printf("\n Enter your option ::");
          scanf("%d",&op);
          switch(op)
            {
                case 1:
                  add_node();
                  break;
                case 2:
                  display_node();
                  break;
                case 3:
                    searching();
                    break;
                case 4:
                  printf("\n Good Bye !");
                  exit(1);
                default:
                 printf("\n Invalid Option ");
            }
      }while(2);
 }// end of main()
void add_node(){
struct node *ptr ,  *last;
ptr = (struct node *)malloc(sizeof(struct  node));
printf("\nEnter the Element in new node::");
scanf("%d" , &ptr->x);
if(start == NULL){
    start = ptr;
    ptr->next = start;
}
else{
        last = start;
    while(last->next!=start)
     last =  last->next;
  last->next = ptr;
  ptr->next = start;
  start = ptr;
  }
}
void display_node(){
struct node *ptr;
ptr = start;
do{
printf("\nElement = %d" , ptr->x);
ptr = ptr->next;
  }while(ptr!= start);
}
void searching(){
struct node *ptr;
int num;
printf("\nEnter the element to search::");
scanf("%d" , &num);
ptr = start;
do{
        if(ptr->x == num){
            printf("Found");
            return;
        }
    ptr = ptr->next;
}while(ptr != start);
printf("Not Found!");
}








