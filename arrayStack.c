// You are using GCC
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
struct Stack
{
    int capacity;
    int topIndex;
    int* array;
}*stack;
struct Stack* createStack(int size)
{
    struct Stack* myStack = (struct Stack*)malloc(sizeof(struct Stack));
    myStack->capacity = size;
    myStack->topIndex = -1;
    myStack->array = (int*)malloc(size*(sizeof(int)));
    return myStack;
}
bool isEmpty(struct Stack* stack)
{
    return (stack->topIndex == -1);
}
bool isFull(struct Stack* stack)
{
    return (stack->topIndex == (stack->capacity)-1);
}
void push(struct Stack* stack, int content)
{
    if(isFull(stack)) {return;}
    (stack->array)[++(stack->topIndex)] = content;
    return;
}
int pop(struct Stack* stack)
{
    if(isEmpty(stack)) {return INT_MIN;}
    return (stack->array)[(stack->topIndex)--];
}
void displayStack(struct Stack* stack)
{
    for(int i=(stack->topIndex); i>=0; i--) {printf("%d ", (stack->array)[i]);}
    printf("\n");
}
int main()
{
    int capacity, element, top;
    scanf("%d", &capacity);
    stack = createStack(capacity);
    for(int i=0; i<capacity; i++) {
        scanf("%d", &element);
        push(stack, element);
    }
    displayStack(stack);
    top = pop(stack);
    printf("Top element is %d\n", top);
    displayStack(stack);
    top = pop(stack);
    printf("Top element is %d\n", top);
}
