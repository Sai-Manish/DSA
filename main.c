#include<stdio.h>
#include<stdlib.h>
#include"queue.h"

int main()
{
	int n = 5;
	struct queue* q =createqueue(n);
        enqueue(q, 1);
	enqueue(q, 2);
	enqueue(q, 3);
	enqueue(q, 4);
	enqueue(q, 5);
	printqueue(q);
	dequeue(q);
	printqueue(q);
	enqueue(q, 5);
	printqueue(q);

	return 0;
}

