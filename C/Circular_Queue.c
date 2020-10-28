#include<stdio.h>
#include<stdlib.h>
int arr[100];
int n=0;
int front = -1,rear = -1;
void insert()
{
	int d;
	printf("Enter the Value : ");
	scanf("%d",&d);
	if((rear+1)%n == front)
	{
		printf("Queue is Full cannot insert\n");
		return;	
	}
	else if(front==-1)
	{
		front=0;
		rear=0;
		arr[rear]=d;
		//rear=(rear+1)%n;
	}
	else
	{
		rear=(rear+1)%n;
		arr[rear]=d;			
	}	
}
void delete()
{
	if(front==-1)
	{
		printf("Queue is Empty cannot Delete\n");
		return;		
	}
	else if(front == rear)
	{
		front =-1;
		rear=-1;
	}
	else
	{
		front=(front+1)%n;
	}	
}
void display()
{
	if(front==-1)
	{
		printf("Queue is Empty\n");
		return;
	}
	printf("Elemts in queue : ");	
	int i=front;
	while(i!=rear)
	{
		printf("%d ",arr[i]);
		i=(i+1)%n;	
	}
	printf("%d\n ",arr[i]);
}
void main()
{
	int choice;
	printf("Enter the size of Queue : ");
	scanf("%d",&n);
	up:
	printf("\t\t Circular Queue\n");
	printf("1) insert\n");
	printf("2) Delete\n");
	printf("3) Display\n");
	printf("4) Exit\n");
	printf("Enter choice: ");
	scanf("%d",&choice);
	switch(choice)
	{
		case 1:
			insert();
			break;
		case 2:
			delete();
			break;
		case 3:
			display();
			break;
		case 4:
			exit(0);
			break;
		default:
			printf("\nWrong choice \n\n");
	}
	goto up;
}
