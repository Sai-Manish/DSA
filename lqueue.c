#include<stdio.h>
#include<stdlib.h>
#include"lqueue.h"

struct QNode * newnode(int k)
{
	struct QNode * temp = (struct QNode*)malloc(sizeof(struct QNode));
	temp->key = k;
	temp->next = NULL;
	return temp;
}

struct Queue * createqueue()
{
	struct Queue * q = (struct Queue*)malloc(sizeof(struct Queue));
        
	q->front = q->rear = NULL;
	return q;
}

void enqueue(struct Queue * q, int k)
{
	struct QNode *temp = newnode(k);

	if(q->rear == NULL)
	{
		q->front = q->rear = temp;
		return;
	}

	q->rear->next = temp;
	q->rear = temp;
}

struct QNode * dequeue(struct Queue* q)
{
	if (q->front == NULL)
	{
		return NULL;
	}
	struct QNode *tem = q->front;
	q->front = q->front->next;

	if(q->front == NULL)
	{
		q->rear = NULL;
	}
	return tem;
}

void printqueue(struct Queue * q)
{
	while(q->front!=NULL)
	{
		printf("%d", q->front->key);
		q->front = q->front->next;

	}
}



