#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node* next;
};

void add_beginning(int content, struct Node** head)
{
    struct Node* new = (struct Node*)malloc(sizeof(struct Node));
    new->data = content;
    new->next = *head;
    *head = new;
}

void add_end(int content, struct Node** head)
{
    struct Node* new = (struct Node*)malloc(sizeof(struct Node));
    struct Node* last = *head;
    new->next = NULL;
    new->data = content;
    if(*head == NULL){
        *head = new;
        return;
    }
    while(last->next != NULL){
        last = last->next;
    }
    last->next = new;
    return;
}

void add_after(int content, struct Node* before)
{
    if (before == NULL){
    printf("Error\n");    
    return;
    }
    struct Node* new = (struct Node*)malloc(sizeof(struct Node));
    new->data = content;
    new->next = before->next;
    before->next = new;
}

void delete(int key, struct Node** head)
{
    struct Node *temp = *head, *prev;
    if (temp != NULL && temp->data == key) {
        *head = temp->next; 
        free(temp); 
        return;
    }
    while (temp != NULL && temp->data != key) {
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL)
        return;
    prev->next = temp->next;
    free(temp);
}

void print(struct Node** head)
{
    struct Node* new = *head;
    printf("Your list: ");
    while(new != NULL)
    {
        printf("%d ", new->data);
        new = new->next;
    }
    printf("\n");
}
