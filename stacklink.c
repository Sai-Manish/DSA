#include<stdio.h>
#include<stdlib.h>

struct StackNode
{
	int data;
	struct StackNode* Next;
};

struct StackNode* newNode(int data)
{
	struct StackNode* stackNode = (struct StackNode*)malloc(sizeof(struct StackNode));
	stackNode->data = data;
	stackNode->Next = NULL;
	return stackNode;
}


int isEmpty(struct StackNode* root)
{
	return !root;
}


void push(struct StackNode** root, int data)
{

	struct StackNode* stackNode = newNode(data);
	stackNode->Next = *root;
	*root = stackNode;
}

int pop(struct StackNode** root)
{
	if (isEmpty(*root))
	{
		return 0;
	}
	struct StackNode* temp = *root;

	*root =  (*root)->Next;
	int popped = temp->data;
	free(temp);

	return popped;
}


int peek(struct StackNode* root)
{
	if(isEmpty(root))
	{
		return 0;
	}

	return root->data;
}

int main()
{
	struct StackNode* root = NULL;

	push(&root, 10);
	push(&root, 20);
	push(&root, 30);

	printf("%d popped from stack\n", pop(&root));
	printf("top element is %d\n", peek(root));

	return 0;
}


