#include<stdio.h>

void swap(int *a, int *b)
{
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
}

void bubblesort(int A[],int n)
{
	int i,j;

	for(i=0;i<n-1;i++)
	{
		for(j=0;j<n-i-1;j++)
		{
			if(A[j]>A[j+1])
			{
				swap(&A[j],&A[j+1]);
			}
		}
	}
	return ;
}

int main()
{
	int A[] = {4,2,1,6,3,9,7};
	int n = sizeof(A)/sizeof(A[0]);
	int i,j;
	bubblesort(A,n);

	for(i=0;i<n;i++)
	{
		printf("%d", A[i]);
	}
	printf("\n");
        
	return 0;
}



        
