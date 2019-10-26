#include<stdio.h>

void swap(int *a,int *b)
{
	int temp = *a;
        *a = *b;
	*b = temp;
}

void selectionsort(int A[],int n)
{
	int i,j,min;
        for(i=0;i<n-1;i++)
	{
		min = i;
		for(j=i+1;j<n;j++)
		{
			if(A[j]<A[min])
			{
				min=j;
			}
		}
	        swap(&A[i],&A[min]);
	}
}

int main()
{
	int A[] = {4,1,3,5,6,7,9,0};
        int n = sizeof(A)/sizeof(A[0]);
	selectionsort(A,n);
	for(int i=0;i<n;i++)
	{
		printf("%d ", A[i]);
	}
        printf("\n");
	return 0;
}


		



