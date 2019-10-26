#ifndef LQUEUE_H
#define LQUEUE_H
typedef struct QNode
{
	int key;
	struct QNode * next;
};

struct Queue
{
	struct QNode *front, *rear;
};

struct Queue * newnode(int k );

struct Queue * createqueue();

void enqueue(struct Queue * q, int k);

struct QNode * dequeue(struct Queue *q);

void printqueue( struct Queue * q);

#endif
