#include<stdio.h>
#include<stdlib.h>

void swap(int* a, int* b)
{
	int t=*a;
	*a=*b;
	*b=t;
}

struct Heap
{
	int* H;		// array
	int size; 	// capacity
};

struct Heap* createHeap(int size)	// We didn't use this size anywhere
{
	struct Heap* heap=(struct Heap*)malloc(sizeof(struct Heap));
	heap->H=(int*)malloc(50*sizeof(int));          // Assuming the size of our heap won't increase 50
	heap->size=0;    // As we go on adding elements we'll increase the size of the heap
	return heap;
}

void BottomupHeapify(struct Heap* heap,int i)
{
	int p=(i-1)/2;		// p is the index of parent of index i
	while(p>=0)
	{
		if(heap->H[i] < heap->H[p])    // if the parent is more than child , which is not allowed
		{
			swap(&heap->H[i],&heap->H[p]); 
			i=p;
			p=(i-1)/2;
		}
		else 
			break;
	}
}

void Add(struct Heap* heap, int x)	// Adding x to the heap at last and then BottomupHeapify
{
	heap->H[heap->size]=x;
	BottomupHeapify(heap,heap->size);
	(heap->size)++;
}

void TopdownHeapify(struct Heap* heap,int i)   	// i is the position at which TopdownHeapify will start 
{
	int l;
	while((2*i+2) < heap->size)			// Goes into the loop if the node to be TopdownHeapified has Right Child also
	{
		if(heap->H[(2*i)+1] <= heap->H[(2*i)+2])	// if left child is smaller than right child
		{
			l=2*i+1;
		}
		else 
			l=2*i+2;
		if(heap->H[i] > heap->H[l])
		{
			swap(&heap->H[i], &heap->H[l]);
			i=l;
		}
		else 
			break;
	}
	// But if the parent has only left child
	if(2*i+1==heap->size-1 && heap->H[i] > heap->H[2*i+1])		// and if parent is more than child
	{
		swap(&heap->H[i],&heap->H[2*i+1]);
	}
}

int deleteMin(struct Heap* heap)
{
	int x=heap->H[0];
	swap(&heap->H[0],&heap->H[heap->size-1]);
	(heap->size)--;
	TopdownHeapify(heap,0);
	return x;
	
}

void buildHeap(struct Heap* heap)	// this function rearranges the given array (into min binary heap) in linear time
{
	for(int i=((heap->size)/2)+1;i>=0;i--)
		TopdownHeapify(heap,i);
	
}

void printHeap(struct Heap* heap)
{
	printf("The builded Heap is as follows\n");
        for(int i=0;i<heap->size;i++)
                printf("%d ",heap->H[i]);
        printf("\n");
	
}

void HeapSort(int H[],int size)
{
	struct Heap* new_heap=createHeap(50);
	for(int j=0;j<size;j++)
		new_heap->H[j]=H[j];
	new_heap->size=size;
	buildHeap(new_heap);
	for(int i=0;i<size;i++)
		H[i]=deleteMin(new_heap);
}


struct Heap* Union(struct Heap* heap1,struct Heap* heap2)
{
	struct Heap* new_heap=createHeap(heap1->size+heap2->size);
	new_heap->size=0;
	for(int i=0;i<heap1->size;i++)
	{
		new_heap->H[new_heap->size++]=heap1->H[i];
	}
	for(int j=heap1->size;j<heap1->size+heap2->size;j++)
	{
		new_heap->H[new_heap->size++]=heap2->H[j-heap1->size];
	}
	buildHeap(new_heap);
	return new_heap;
}


int main()
{
	struct Heap* heap1;
	heap1=createHeap(6);
	Add(heap1,15);
	Add(heap1,25);
	Add(heap1,35);
	Add(heap1,5);
	Add(heap1,50);
	Add(heap1,21);
	printHeap(heap1);
	int x=deleteMin(heap1);
	printf("%d \n",x);
	printHeap(heap1);
	struct Heap* heap2;
	heap2 = createHeap(8);
	for(int i=0;i<8;i++)
		heap2->H[i]=15-i;
	heap2->size=8;
	buildHeap(heap2);
	printHeap(heap2);
	HeapSort(heap2->H,heap2->size);
	printHeap(heap2);
	struct Heap* heap3=createHeap(50);
	heap3=Union(heap1,heap2);
	printHeap(heap3);
	printf("%d\n",deleteMin(heap3));
return 0;
}

