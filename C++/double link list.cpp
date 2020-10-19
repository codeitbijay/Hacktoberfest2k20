#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
struct node
{
	int info;
	struct node *next;
	struct node *previous;
};
struct node *START=NULL;
struct node* createnode()
{
	struct node *t;
	t=(struct node*)malloc(sizeof(struct node));
	return(t);
}
void insertbeg()
{
	struct node *temp;
	temp=createnode();
		printf("Enter the value \n");
	scanf("%d",&temp->info);
	temp->next=NULL;
	temp->previous=NULL;
	if(START==NULL)
	{
		START=temp;
	}
	else
	{
	START->previous=temp;
	temp->next=START;
	START=temp;

	
		
		
		
	}
}
void insertend()
{
	struct node *t,*s;
	s=createnode();
	printf("Enter the value \n");
	scanf("%d",&s->info);
	s->previous=NULL;
	s->next=NULL;
	if(START==NULL)
	START=s;
	else
	{
		t=START;
		while(t->next!=NULL)
		{
		t=t->next;	
		}
		t->next=s;
		s->previous=t;
		
	}
}
int sizecount()
{
	struct node *t;
	int count=0;
	if(START==NULL)
	{
		return(0);
	}
	else
	{
		t=START;
		while(t!=NULL)
		{
			count++;
			t=t->next;
		}
		return(count);
	}
	
}
void insertpos(int pos)
{
	if(START==NULL)
	{
		printf("List is Empty \n");
	}
	else
	{
		int size=sizecount();
		if(pos<0 || pos>size)
		{
			printf("Invalid position \n");
		}
		else
		{
			int i;
			struct node *poi,*temp;
			temp=createnode();
			printf("Enter the value to insert \n ");
			scanf("%d",&temp->info);
			temp->next=NULL;
			temp->previous=NULL;
			poi=START;
			if(pos==0)
			{
				START->previous=temp;
	              temp->next=START;
               	START=temp;
			}
			else
			{
				for(i=0;i<pos-1;i++)
				{
					poi=poi->next;
				}
				temp->previous=poi->next->previous;
				temp->next=poi->next;
				poi->next=temp;
			}
		}
	}
}
//Delete at beggining
void deletebeg()
{
	if(START==NULL)
	{
		printf("List is empty");
	}
	else
	{
		if(START->next==NULL)
		{
			struct node *temp;
			temp=START;
			START=NULL;
			temp->next=NULL;
			free(temp);
		}
		else
		{
		
		struct node *t;
		t=START;
		START=START->next;
		START->previous=NULL;
		t->next=NULL;
		free(t);}
	}
}

//DELETE AT LAST
void deletelast()
{
	if(START==NULL)
	{
		printf("List is empty");
	}
	else
	{
		if(START->next==NULL)
		{
			struct node *a;
			a=START;
			START=NULL;
			free(a);
		}
		else
		{
	
	struct node *secondlast,*last;
	secondlast=START;
	last=START;
	while(last->next!=NULL)
	{
		secondlast=last;
		last=last->next;
		}
		secondlast->next=NULL;
		free(last);}
			
	}
}
//DELETE BY VALUE
void deleteval(int v)
{
if(START==NULL)
printf("List is empty");
else{
struct node *last,*secondlast;
if(START->next==NULL)
{
	if(START->info==v)
	{
		struct node *t;
		t=START;
		START=NULL;
		free(t);
	}
	else
	{
		printf("%d is not available in list",v);
	}
}
else
{
	struct node *last,*seclast,*t;
	if(START->info==v)
	deletebeg();
	else
	{
		last=seclast=START;
		while(last!=NULL)
		{
		seclast=last;
		if(last->info==v)
		{
		t=last;
		seclast->next=t->next;
		seclast->next->previous=seclast;
		free(t);
		break;
		}
		last=last->next;	
		}
		if(last==NULL)
		printf("%d is not in list \n",v);
	}
}	
}
		
}
void traversebeg()
{
	if(START==NULL)
	{
		printf("List is empty \n");
	}
	else
	{
		struct node *t;
		t=START;
		while(t!=NULL)
		{
			printf("%d->",t->info);
			t=t->next;
		}
	}
 getch();
}
void traverseend()
{
	struct node *last,*secondlast;
	if(START==NULL)
	{
		printf("List is empty \n");
	}
		else
		{
			last=START;
			while(last!=NULL)
			{
			secondlast=last;
			last=last->next;
			}
			while(secondlast!=NULL){
				printf("%d->",secondlast->info);
				secondlast=secondlast->previous;
			}
				
			
		}
			getch();	
}


int menu()
{
	printf("\n1. Insert at beggining");
	printf("\n2. Insert at end");
	printf("\n3. Insert at position");
	printf("\n4. Traverse from Starting");
	printf("\n5. Traverse from end");
	printf("\n6. Delete at beggining");
	printf("\n7. Delete Last element");
	printf("\n8. Delete by value");
	printf("\n9. Size of list");
	printf("\n10. Exit");
	printf("\n Enter choice \n");
	int choice;
	scanf("%d",&choice);
	return(choice);
}
main()
{
	int a;
	while(1)
	{
		system("cls");
		switch(menu())
		{
			case 1:  insertbeg();
			traversebeg();
			break;
			case 2: insertend();
			traversebeg();
			break;
			case 3:int ch;
			printf("\n Enter the position \n");
			scanf("%d",&ch);
			 insertpos(ch);
			
			
			case 4:traversebeg();
			break;
			
			case 5: traverseend();
			break;
		
			case 6: deletebeg();
			        traversebeg();
			        break;
			case 7: deletelast();
			         traversebeg();
					 break; 
			case 8: printf("\n Enter the value to delete   : ");
			        scanf("%d",&a);
			        deleteval(a);
			        traversebeg();
					break;       
			case 9: 	printf(" \n Size of Linked List is : %d ",sizecount()) ;
			getch();
			break;
			
			
			case 10: exit(1);
		}
	}
}
