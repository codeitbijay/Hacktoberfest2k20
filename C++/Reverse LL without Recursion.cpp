#include<bits/stdc++.h>
using namespace std;

struct node {
    int data;
    struct node *next;
};

void push(struct node **head, int data) {
    struct node *node;
    node = (struct node*)malloc(sizeof(struct node));
    node->data = data;
    node->next = (*head);
    (*head) = node;
}
 
void reverse(struct node **head) {
    struct node *temp = NULL;
    struct node *prev = NULL;
    struct node *current = (*head);
    while(current != NULL) {
        temp = current->next;
        current->next = prev;
        prev = current;
        current = temp;
    }
    (*head) = prev;
}

void print(struct node *head) {
    while(head != NULL) {
        cout<<head->data<<" ";
        head = head->next;
    }
}

int main() {
    struct node *head = NULL;
    push(&head, 100);
    push(&head, 1);
    push(&head, 3);
    push(&head, 11);
    push(&head, 9);
    push(&head, 27);
    
    print(head);
    cout<<endl;
    reverse(&head); 
    print(head);
    return 0;
}
