#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

void merge(int A[],int p,int q,int r)
{
        int n1 = q-p+1;
	int n2 = r-q;
	int L[n1];
	int R[n2];

	int i,j,k;

	for(i=0;i<n1;i++)
	{
		L[i] = A[p+i];
	}

	for(j=0;j<n2;j++)
	{
		R[j] = A[q+1+j];
	}

	i = 0 , j = 0 ,k = p;

	while(i<n1 && j<n2)
	{
		if(L[i]<=R[j])
		{	
			A[k]=L[i];
			i++;
		}		

		else 
		{	
			A[k]=R[j];
			j++;
		}
		k++;
	}

// only one will get executed

	while(i<n1)
	{
		A[k]=L[i];
		i++;
		k++;
	}
	while(j<n2)
	{
		A[k]=R[j];
		j++;
		k++;
	}

	
}



void merge_sort(int *A,int p, int r)
{
	if(p<r)
	{
	        int q = (p+r)/2;

		merge_sort(A, p, q);
		merge_sort(A, q+1, r);
		merge(A,p,q,r);
	}
}

int main()
{
	int A[7] = {9,0,3,4,6,1,5};
	merge_sort(A,0,6);
        
	for(int i=0;i<7;i++)
	{
        	printf("%d", A[i]);
	}
	printf("\n");

	return 0;
}


	
