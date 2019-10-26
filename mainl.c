#include<stdio.h>
#include<stdlib.h>
#include"lqueue.h"

int main()
{
	struct Queue * q1 = createqueue();
	enqueue(q1, 10);
	enqueue(q1, 20);
	enqueue(q1, 30);
	printqueue(q1);

	dequeue(q1);
	dequeue(q1);

	printqueue(q1);

	return 0;
}

