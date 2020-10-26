#include<stdio.h>
#include<conio.h>
#include<alloc.h>
#include<stdlib.h>
struct node
{
int data;
struct node *next;
}
*start=NULL;
void create()
{
char ch;
do
{
struct node *newnode,*current;
newnode=(struct node*)malloc(sizeof(newnode));
printf("\nEnter the data:");
scanf("%d",&newnode->data);
newnode->next=NULL;
if(start==NULL)
{	
start=newnode;
current=newnode;
}
else
{
current->next=newnode;
current=newnode;
}
printf("\nDo you want to add more nodes?:");
ch=getche();
}
while(ch!='n');
}
void del_beg()
{
	struct node *temp;
	if (start=NULL)
	{
		printf(“\nList is empty.”);
	}
else
	{
temp=start;
	start=start->next;
	printf(“\nData deleted:%d”,temp->data);
	free(temp);
	}
}
void del_end()
{
	struct node *ptr,*ptr1;
	if(start==NULL)
	{
		printf("\nList is empty.");
	}
	else
	{
		ptr=start;
		while(ptr->next!=NULL)
		{
			ptr1=ptr;
			ptr=ptr->next;
		}
		ptr1->next=ptr->next;
		free(ptr);
	}
}
void del_pos()
{
	int k;
	struct node *ptr, *ptr1;
	if (start==NULL)
	{
		printf("\nList is empty.");
	}
	else
	{
		printf("\nEnter the data to be deleted:");
		scanf("%d",&k);
		ptr=start;
		while((ptr->next!=NULL)&&(ptr->data!=k))
		{
			ptr1=ptr;
			ptr=ptr->next;
		}
		if (ptr->data==k)
		{
			ptr1->next=ptr->next;
			free(ptr);
		}
		else
		{
			printf("value not found");
		}
	}
}
void display()
{
struct node *newnode;
printf("\nLinked list:");
newnode=start;
while(newnode!=NULL)
{
printf("%d",newnode->data);
newnode=newnode->next;
}
printf("NULL");
}

void main()
{       
	int i;
	char c;
clrscr();
	do
	{       
printf("TYPE 1: To create list\t\t
TYPE 2: To delete data at beginning\n
TYPE 3: To delete data at the end\t
TYPE 4: To delete data at given position\n
TYPE 5: To display the linked list\n
Enter the choice:\n "); 
scanf("%d",&i);
		switch(i)
		{
			case 1:
			{
				create();
				break;
			}
			case 2:
			{
				del_beg();
				break;
			}
			case 3:
			{
				del_end();
				break;
			}
			case 4:
			{	display();
				del_pos();
				break;
			}
			case 5:
			{
				display();
				break;
			}
			default:
			{}
}
		printf("\nDo you want to continue?:");
		c=getche();
	}
	while (c!='n');
getch();
}

