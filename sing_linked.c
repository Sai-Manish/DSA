#include<stdio.h>
#include<stdlib.h>

struct Node
{
	int data;
	struct Node *Next;
};

//struct Node *createnode(int data)
//{
//	struct Node* newnode = (struct Node*)malloc(sizeof(struct Node));


void printlist(struct Node* node)
{
	while(node!=NULL)
	{
		printf("%d\n", node->data);
		node = node->Next;
	}
}

int main()
{
	struct Node* Head = (struct Node*)malloc(sizeof(struct Node));
        struct Node* First = (struct Node*)malloc(sizeof(struct Node));
	struct Node* Second = (struct Node*)malloc(sizeof(struct Node));
	struct Node* Third = (struct Node*)malloc(sizeof(struct Node));

	Head->Next = First;

	First->data = 10;
	First->Next = Second;

	Second->data = 20;
	Second->Next = Third;

	Third->data = 30;
	Third->Next = NULL;
        

	printlist(Head);

	return 0;
	
}


