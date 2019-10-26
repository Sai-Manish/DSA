#ifndef QUEUE_H
#define QUEUE_H
typedef struct queue
{
	int front,rear;
	int capacity,size;
	int * data;
}queue;

struct queue* createqueue(int capacity);
int isFull(queue* queue);
int isEmpty(queue* queue);
void enqueue(queue* queue, int data);
int dequeue(queue* queue);
int front(queue* queue);
int rear(queue* queue);
void printqueue(queue* queue);

#endif

