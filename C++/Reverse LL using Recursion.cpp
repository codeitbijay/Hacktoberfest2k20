//Reverse LL using Recursion
#include<bits/stdc++.h>
using namespace std ;
class Node
{
    public:
    int data ;
    Node* next ;
    Node(int data)
    {
        this->data = data ;
        this->next = NULL ;
    }
};
Node* rev(Node* head)
{
    if(head == NULL)
        return head ;
    Node *temp = rev(head->next) ;
    Node *ptr = temp ;
    head->next = NULL;
    if(temp == NULL)
        return head ;
    while(temp->next != NULL)
    {
        temp = temp->next ;
    }
    temp->next = head ;
    head = ptr ;
    return head ;
}
int main()
{
    Node *x = new Node(1);
    Node *y = new Node(2);
    Node *z = new Node(3);
    Node *a = new Node(4);
    Node *b = new Node(5);
    Node *c = new Node(6);
    x->next = y ;
    y->next = z ;
    z->next = a ;
    a->next = b ;
    b->next = c ;
    Node *head = rev(x) ;
    Node *temp = head ;
    while(temp != NULL)
    {
        cout<<temp->data<<" ";
        temp = temp->next ;
    }
    return 0;
}
