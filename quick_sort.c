#include<stdio.h>
#include<stdlib.h>


void swap(int* a, int* b)
{
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
}


int  partition(int A[], int p, int r)
{
	int x = A[r];
	int i,j;
        i = p-1;
        
	for(j=p;j<r;j++)
	{
		if(A[j]<= x)
		{
			i = i +1;
			swap(&A[i],&A[j]);
		}
	}

	swap(&A[i+1],&A[r]);
	return i+1;

}

void quick_sort(int A[], int p, int r)
{
	if(p<r)
	{
		int q = partition(A,p,r);

		quick_sort(A,p,q-1);
		quick_sort(A,q+1,r);

	}
}

int  main()
{
	int A[7] = {4,2,3,6,1,5,9};

	quick_sort(A,0,7);

	for(int i=0; i<7;i++)
	{
		printf("%d", A[i]);

	}
	printf("\n");

	return 0;
}




