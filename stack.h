struct stack{
	int * data;
	int capacity;
	int top;
}stack;

int isFull(struct stack* stack);
int isempty(struct stack* stack);
void push(struct stack* stack, int);
int pop(struct stack* stack);

