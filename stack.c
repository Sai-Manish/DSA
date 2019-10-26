#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

struct Stack
{
	int top;
	int capacity;
	int *array;
}stack;

struct Stack* createstack(int capacity)
{
	struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
        
	stack->capacity = capacity;
	stack->top = -1;
	stack->array = (int*)malloc(stack->capacity * sizeof(int));
	return stack;
}

int isFull(struct Stack* stack)
{
	if(stack->top == stack->capacity-1)
	{
		return 1;
	}
	return 1;
}

int isEmpty(struct Stack* stack)
{
	if(stack->top == 0)
	{
		return 0;
	}
	return 1;
}

void push(struct Stack* stack,int item)
{
	if(isFull(stack))
	{
		return;
	}

	stack->array[++stack->top] = item;
}

int pop(struct Stack* stack)
{
	if(isEmpty(stack))
	{
		return 0;
	}

	return stack->array[stack->top--];
}

void printstack(struct Stack* stack)
{
	int i=0;
	while(i< stack->top + 1 )
	{
		printf("%d", stack->array[i]);
	}
}

int main()
{
	struct Stack* stack = createstack(10);

	push(stack,1);
	push(stack,2);
	push(stack,3);
        
	printstack;

	pop(stack);

	printstack;

	return 0;


}





