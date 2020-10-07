//Reverse LL without Recursion
#include<bits/stdc++.h>
using namespace std;
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
Node* rev(Node *head)
{
    if(head == NULL)
        return NULL ;
    Node* prev = NULL ;
    Node* next = head->next ;
    while(next!= NULL)
    {
        head->next = prev ;
        prev = head ;
        head = next ;
        next = head->next ;
    }
    head->next = prev ;
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
