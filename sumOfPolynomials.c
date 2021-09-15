// You are using GCC
#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node* next;
}*poly1, *poly2;

void addPolynomialTerm(struct Node** head, int d)
{
    struct Node* newnode;
    newnode = (struct Node*)malloc(sizeof(struct Node));
    newnode->data = d;
    struct Node* last = *head;
    while(last->next != NULL)
    {
        last = last->next;
    }
    last->next = newnode;
    newnode->next = NULL;
}

void displayPolynomial(struct Node** head, int degree)
{
    int a = degree;
    struct Node* temp = *head;
    if(temp->data > 0){printf("+");}
    while(temp != NULL)
    {
        printf("%dX^%d", temp->data, a);
        a--;
        if(a >= 0){printf("+");}
        temp = temp->next;
    }
}

int main()
{
    int degree, e, count=2;
    scanf("%d", &degree);
    poly1 = (struct Node*)malloc(sizeof(struct Node));
    poly2 = (struct Node*)malloc(sizeof(struct Node));
    scanf("%d", &e);
    poly1->data = e;
    poly1->next = NULL;
    while(count <= degree+1)
    {
        scanf("%d", &e);
        addPolynomialTerm(&poly1, e);
        count++;
    }
    count = 2;
    scanf("%d", &e);
    poly2->data = e;
    poly2->next = NULL;
    while(count <= degree+1)
    {
        scanf("%d", &e);
        addPolynomialTerm(&poly2, e);
        count++;
    }
    struct Node* temp1 = poly1;
    struct Node* temp2 = poly2;
    while(temp1!=NULL || temp2!=NULL)
    {
        temp1->data = temp1->data + temp2->data;
        temp1 = temp1->next;
        temp2 = temp2->next;
    }
    displayPolynomial(&poly1, degree);
}
