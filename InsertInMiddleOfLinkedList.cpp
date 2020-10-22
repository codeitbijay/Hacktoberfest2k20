#include<bits/stdc++.h>
using namespace std;

struct Node
{
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};

//function to display the linkedlist
void Display(Node *head)
{
  while(head != NULL) {
    cout<<head->data<<" ";
    head = head->next;
  }
  cout<<endl;
}

Node* insertInMiddle(Node* head, int x);

int main()
{
  int t,n,x;
  cin>>t;
  while(t--)
  {
    cin>>n>>x;
    struct Node *head = new Node(x);
    struct Node *tail = head;
    for (int i=0;i<n-1;i++)
    {
      cin>>x;
      tail->next = new Node(x);
      tail = tail->next;
    }
    cin>>x;
    head = insertInMiddle(head, x);
    Display(head);
  }
  return 0;
}

// function should insert node at the middle
// of the linked list
Node* insertInMiddle(Node* head, int x)
{
	// Cpde here
	Node *node = new Node(x);
	if (head == NULL)
  {
    head = node;
    return head;
  }
	int temp=0;
  Node *front = head;
	while (front !=  NULL)
	{
	    front = front->next;
	    temp++;
	}
	int mid = temp/2;
  //if number of nodes is even
  if (temp%2 != 0)
  {
    Node *prev;
	  Node *top = head;
	  int i;
	  for (i=0;i<=mid;i++)
	  {
	    prev = top;
	    top = top->next;
	  }
	  node->next = top;
	  prev->next = node;
	  return head;
  }
  //if number of nodes is odd
	Node *prev;
	Node *top = head;
	int i;
	for (i=0;i<mid;i++)
	{
	    prev = top;
	    top = top->next;
	}
	node->next = top;
	prev->next = node;
	return head;
}
