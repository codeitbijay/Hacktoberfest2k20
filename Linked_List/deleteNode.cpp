


#include<bits/stdc++.h>
using namespace std;

class node {
    public:
    int data;
    node* next ;

    node(int val)
    {
        data = val;
        next =NULL;
    }
};

void insertAtTail(node* &head, int val)
{
    node* n = new node(val);
    if(head == NULL)
    {
        head = n ;
        return ;
    }
    else
    {
        node* temp = head;
        while(temp->next !=NULL)
        {
            temp = temp->next;
        }
        temp->next = n ;
    
    }
}

// Delete Node

void deleteNode(node* node) 
{
    int c = node->next->data;
    node->data = c;
    node->next = node->next->next;
} 

void display(node* &head)
{
    node* temp = head;
    while(temp!=NULL)
    {
        cout<<temp->data<<"->";
        temp =temp->next;
    }
    cout<<"NULL"<<"\n";
}

int main()
{
    node* head = NULL;
    
    insertAtTail(head,1);
    insertAtTail(head,2);
    insertAtTail(head,3);
    insertAtTail(head,4);
    insertAtTail(head,5);
    cout<<"Before Deletion : ";
    display(head);
    cout<<endl<<"After Deletion: ";
    deleteNode(head->next);
    display(head);

    return 0;
}



