#include<stdio.h>
#include<stdlib.h>
 
#define MAX 100  
 
#define initial 0
#define waiting 1
#define visited 2
 
int n; // no:of vertices    
int adj[MAX][MAX]; // adjacency matrix
int state[MAX];  // finding that it visited or not
void create_graph(); //greating a graph
void BF_Traversal(); 
void BFS(int v);
 
int queue[MAX], front = -1,rear = -1; // queue intializing front and rear to -1
void insert_queue(int vertex); //function to insert vertex to queue
int delete_queue(); // for deletion of vertex from queue
int isEmpty_queue(); // to check if queue is empty
 
int main()
{
	create_graph();
	BF_Traversal();
	return 0;
}
 
void BF_Traversal()
{
	int v;
	
	for(v=0; v<n; v++) 
		state[v] = initial;
	
	int s; // start vertex
	printf("Enter Start Vertex for BFS: \n");
	scanf("%d", &s);
	BFS(s);
}
 
void BFS(int v)
{
	int i;
	
	insert_queue(v);
	state[v] = waiting;
	
	while(!isEmpty_queue())
	{
		v = delete_queue();
		printf("%d ",v);
		state[v] = visited;
		
		for(i=0; i<n; i++)
		{
			if(adj[v][i] == 1 && state[i] == initial) 
			{
				insert_queue(i);
				state[i] = waiting;
			}
		}
	}

	printf("\n");

	for(i=0;i<n;i++)  // if there is a disconnected graph
	{
		if(state[i] == initial)
		{
			BFS(i);
		}
	}

	printf("\n");
}
 
void insert_queue(int vertex)
{
	if(rear == MAX-1)
		printf("Queue Overflow\n");
	else
	{
		if(front == -1) 
			front = 0;
		rear = rear+1;
		queue[rear] = vertex ;
	}
}
 
int isEmpty_queue()
{
	if(front == -1 || front > rear)
		return 1;
	else
		return 0;
}
 
int delete_queue()
{
	int delete_item;
	if(front == -1 || front > rear)
	{
		printf("Queue Underflow\n");
		exit(1);
	}
	
	delete_item = queue[front];
	front = front+1;
	return delete_item;
}
 
void create_graph()
{
	int count,max_edge,origin,destin;
 
	printf("Enter number of vertices : ");
	scanf("%d",&n);
	max_edge = n*(n-1);
 
	for(count=1; count<=max_edge; count++)
	{
		printf("Enter edge %d( -1 -1 to quit ) : ",count);
		scanf("%d %d",&origin,&destin);
 
		if((origin == -1) && (destin == -1))
			break;
 
		if(origin>=n || destin>=n || origin<0 || destin<0)
		{
			printf("Invalid edge!\n");
			count--;
		}
		else
		{
			adj[origin][destin] = 1;
		}
	}
}
