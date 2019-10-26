#include <stdio.h>
#include <stdlib.h>
#define SIZE 40

struct Queue
{
    int array[SIZE];
    int front;
    int rear;
};

struct Queue* createQueue();
void enQueue(struct Queue* q, int);
int deQueue(struct Queue* q);
void display(struct Queue* q);
int isEmpty(struct Queue* q);
void printQueue(struct Queue* q);

struct node
{
    int vertex;
    struct node* next;
};

struct node* createNode(int);

struct Graph
{
    int numVertices;
    struct node** adjLists;
    int* visited;
};

struct Graph* createGraph(int vertices);
void addEdge(struct Graph* graph, int src, int dest);
void printGraph(struct Graph* graph);
void bfs(struct Graph* graph, int startVertex,int* parent);


void bfs(struct Graph* graph, int startVertex,int parent[])
{

    struct Queue* q = createQueue();

    graph->visited[startVertex] = 1;
    enQueue(q, startVertex);
    parent[startVertex]=-1;

    while(!isEmpty(q))
    {
        printQueue(q);
        int currentVertex = deQueue(q);
        printf("Visited %d\n", currentVertex);

       struct node* temp = graph->adjLists[currentVertex];
       // temp is an iterator over the adjacency list of that deQueued element

       while(temp)
       {
            int adjVertex = temp->vertex;

            if(graph->visited[adjVertex] == 0)
	          {
                graph->visited[adjVertex] = 1;
                enQueue(q, adjVertex);
                parent[adjVertex]=currentVertex;
            }
            temp = temp->next;
       }
    }
}


struct node* createNode(int v)
{
    struct node* newNode = malloc(sizeof(struct node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}


struct Graph* createGraph(int vertices)
{
    struct Graph* graph = malloc(sizeof(struct Graph));
    graph->numVertices = vertices;

    graph->adjLists = malloc(vertices * sizeof(struct node*));
    graph->visited = malloc(vertices * sizeof(int));


    int i;
    for (i = 0; i < vertices; i++)
    {
        graph->adjLists[i] = NULL;
        graph->visited[i] = 0;
    }

    return graph;
}

void addEdge(struct Graph* graph, int src, int dest)
{
    // Add edge from src to dest
    struct node* newNode = createNode(dest);
    newNode->next = graph->adjLists[src];
    graph->adjLists[src] = newNode;

    // Add edge from dest to src
    newNode = createNode(src);
    newNode->next = graph->adjLists[dest];
    graph->adjLists[dest] = newNode;
}

struct Queue* createQueue() {
    struct Queue* q = malloc(sizeof(struct Queue));
    q->front = -1;
    q->rear = -1;
    return q;
}


int isEmpty(struct Queue* q) {
    if(q->rear == -1)
        return 1;
    else
        return 0;
}

void enQueue(struct Queue* q, int value){
    if(q->rear == SIZE-1)
        printf("\nQueue is Full!!");
    else {
        if(q->front == -1)
            q->front = 0;
        q->rear++;
        q->array[q->rear] = value;
    }
}

int deQueue(struct Queue* q){
    int item;
    if(isEmpty(q)){
        printf("Queue is empty\n");
        item = -1;
    }
    else{
        item = q->array[q->front];
        q->front++;
        if(q->front > q->rear){
            printf("Resetting Queue\n");
            q->front = q->rear = -1;
        }
    }
    return item;
}

void printQueue(struct Queue *q) {
    int i = q->front;

    if(isEmpty(q)) {
        printf("Queue is empty");
    } else {
        printf("\nQueue contains\n");
        for(i = q->front; i < q->rear + 1; i++) {
                printf("%d   ", q->array[i]);
        }
    }
}
int main()
{
    struct Graph* graph = createGraph(6);
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 2);
    addEdge(graph, 1, 2);
    addEdge(graph, 1, 4);
    addEdge(graph, 1, 3);
    addEdge(graph, 2, 4);
    addEdge(graph, 3, 4);
    addEdge(graph, 4, 5);

    int parent[6];
    bfs(graph, 0,parent);

    printf("Parent()  i \n");
    for(int i=0;i<6;i++)
      printf("%d \t  %d \n",parent[i],i);
    return 0;
}
