typedef struct Node node;
struct Node* reverseList(struct Node *head)
{
   if(head==NULL|| head->next==NULL)
   return head;
   node *rev = reverseList(head->next);
   node*p = head;
   while(p->next!=NULL)
   p=p->next;
   p->next=head;
   head->next=NULL;
   return rev;
}
