#include<stdio.h>
#include<stdlib.h>

struct Node
{
	int data;
	struct Node* Next;
	struct Node* Previous;

};

void push(struct Node** href, int data)
{
	struct Node* newnode = (struct Node*)malloc(sizeof(struct Node));

	newnode->data = data;
	newnode->Next = *href;
	newnode->Previous = NULL;
        

	if(*href != NULL)
	{
		(*href->Previous = newnode);
	}

	(*href) = newnode;
}

int pop(struct Node** href)
{
	
		

        
	

