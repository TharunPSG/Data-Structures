// You are using GCC
// Finding if a given linked list is circular or not
#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node* next;
}*head, *tail;
struct Node* getTail(struct Node** head, int size)
{
    struct Node* tail = *head;
    int count = 1;
    while(count < size)
    {
        tail = tail->next;
        count++;
    }
    if(tail->next == *head)
    {
        printf("Yes\n");
    }
    else
    {
        printf("No\n");
        tail->next = *head;
    }
    return tail;
}
void push(struct Node** head, int d)
{
    struct Node* newnode;
    newnode = (struct Node*)malloc(sizeof(struct Node));
    newnode->data = d;
    newnode->next = *head;
    *head = newnode;
}
int main()
{
    head = (struct Node*)malloc(sizeof(struct Node));
    head->data = 2;
    head->next = NULL;
    push(&head, 3);
    push(&head, 4);
    push(&head, 5);
    getTail(&head, 4);
    getTail(&head, 4);
}
