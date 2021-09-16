#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node* next;
}*head_result, *L1, *L2;

void append(struct Node* head, int d)
{
    struct Node* newnode = (struct Node*)malloc(sizeof(struct Node));
    newnode->data = d;
    if(head == NULL){
        head = newnode;
        newnode->next = NULL;
        return;
    }
    struct Node* last = head;
    while(last->next != NULL){
        last = last->next;
    }
    last->next = newnode;
    newnode->next = NULL;
}

struct Node* intersection(struct Node* L1, struct Node* L2, struct Node* head_result)
{
    struct Node* temp1 = (L1)->next;
    struct Node* temp2 = (L2)->next;
    while(temp1!=NULL && temp2!=NULL)
    {
        if(temp1->data == temp2->data){
            append(head_result, temp1->data);
            temp1 = temp1->next;
            temp2 = temp2->next;
        }
        else if(temp1->data < temp2->data){
            temp1 = temp1->next;
        }
        else if(temp2->data < temp1->data){
            temp2 = temp2->next;
        }
    }
    return head_result;
}
int main()
{
    L1 = (struct Node*)malloc(sizeof(struct Node));
    L2 = (struct Node*)malloc(sizeof(struct Node));
    head_result = (struct Node*)malloc(sizeof(struct Node));
    append(L1, 2);
    append(L1, 3);
    append(L1, 4);
    append(L2, 3);
    append(L2, 5);
    head_result = intersection(L1, L2, head_result);
    struct Node* temp = head_result;
    printf("Intersection: ");
    if(head_result != NULL){
        while(temp != NULL){
            printf("%d ", temp->data);
            temp = temp->next;
        }
    }
    return 0;
}
