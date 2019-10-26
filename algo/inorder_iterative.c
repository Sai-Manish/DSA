#include<stdio.h>
#include<stdlib.h>
#define bool int

struct tNode
{
	int data;
	struct tNode* left;
	struct tNode* right;

};

struct sNode
{
	struct tNode *t;
	struct sNode *next;
};

void push(struct **top,struct tNode *t);
struct tNode *pop(struct sNode** top);
bool isEmpty(struct sNode *top);

void inorder(struct tNode *root)
{
	struct tNode *current  = root;
	struct sNode *s = NULL;
	bool flag = 0;

	while(!flag)
	{
		if(current != NULL)
		{
			push(&s, current);
			current = current->left;
		}

		else 
		{
			if(!isEmpty(s))
			{
				current = pop(&s);
				printf("%d ", current->data);

				current  = current->right;
			}
			 else
			 {
				 flag = 1;
			 }
		}
	}




