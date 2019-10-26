#include<stdio.h>

void countsort(int A[],int k, int n)
{
	int i,j;

	int S[n],c[k+1];

	for(i = 0;i<k+1;i++)
	{
		c[i] = 0;
	}

	for(j=0;j<n;j++)
	{
		c[A[j]]=c[A[j]] + 1;
	}

	for(i=0;i<k+1;i++)
	{
		c[i] = c[i] + c[i-1];
	}

	for(j=n-1;j>=0;j--)
	{
		S[c[A[j]]] = A[j];
		c[A[j]] =c[A[j]] - 1;
	}

	printf("sorted array is : ");
	for(i=0;i<k+1;i++)
	{
		printf("%d ", S[i]);
	}

}



int main()
{
	int n,k=0,i;
	int A[15] = {2,4,5,2,6,7,6,8,9,1,11,13,11,15,10};
	n = sizeof(A)/sizeof(A[0]);
	for(i=0;i<n;i++)
	{
		if(A[i] > k)
		{
			k = A[i];
		}
	}

	countsort(A,k,n);

	return 0;
}


