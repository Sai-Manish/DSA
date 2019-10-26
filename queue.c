#include<stdio.h>
#include<stdlib.h>
#include"queue.h"

struct queue* createqueue(int capacity)
{
	struct queue* queue = (struct queue*)malloc(sizeof(struct queue));
	queue->capacity = capacity;
	queue->size = 0;
	queue->front = 0;
	queue->rear = -1;
	queue->data = (int*)malloc(queue->capacity *sizeof(int));
	return queue;
}

int isFull(queue* queue)
{
	if(queue->size==queue->capacity)
	{
		return 1;
	}

	return 0;

}

int isEmpty(queue* queue)
{
	if(queue->size==0)
	{
		return 1;
	}

	return 0;
}

void enqueue(queue* queue,int d)
{
	if(isFull(queue))
	{
		printqueue(queue);
	}
	else
	{
		
         	queue->rear= queue->rear+1 % queue->capacity;
        	queue->data[queue->rear] = d;
        	queue->size=queue->size+1;
	}
}

int dequeue(queue* queue)
{
       if(isEmpty(queue))
       {
               return 0;
       }
       
       int d = queue->data[queue->front];
       queue->front=queue->front + 1%queue->capacity;
       queue->size = queue->size-1;
       
       return d;
}

int front(queue* queue)
{
	if(isEmpty(queue))
	{
		return 0;
	}

	return queue->data[queue->front];
}

int rear(queue* queue)
{
	if(isEmpty(queue))
	{
		return 0;
	}

	return queue->data[queue->rear];
}

void printqueue(queue*queue)
{
	int i=0;
	while(i<queue->size)
	{
		printf("%d", queue->data[(queue->front + i)%queue->capacity] );
		i++;
	}
	printf("\n");
}


              

