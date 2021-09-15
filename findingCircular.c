// You are using GCC
#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node* next;
}*head, *tail;
struct Node* getTail(struct Node** head)
{
    struct Node* tail = *head;
    int count = 1;
    while(count < 4)
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
    getTail(&head);
    getTail(&head);
}
