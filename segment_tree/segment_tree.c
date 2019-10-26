#include<stdio.h>
#include<stdlib.h>

int *build_tree(int *A,int n)
{
	int *st = (int*)malloc((2*n-1)*sizeof(int)); //memory allocation for segment tree

	int i,j;
	for(i=0;i<n;i++)                      
	{
		st[i+n-1] = i;    // storing the indices of array A in the st tree as they are leaf nodes
	}

	for(i=n-2;i> -1;i--)
	{
		j = 2*i;
		if(A[st[j+1]] <= A[st[j+2]]) // checkin for the inner nodes and assigning the index of minimum of their two children
		{
			st[i] = st[j+1];
		}

		else if(A[st[j+1]] > A[st[j+2]])
		{
			st[i] = st[j+2];
		}

	}

	return st
}

void update(int st[],int A[],int n,int i, int x)
{
	A[i] = x;

	int j,k;

	j = n-1+i;

	int l;

	while(j>0)
	{
		k=(j-1)/2;

		if(A[st[2*k+1]] < A[st[2*k+2]])
		{
			l = 2*k+1;
		}

		else
		{
			l = 2*k+2;
		}

		st[k] = l;

		j = (j-1)/2;
	}
}

int Range_min_query(int st[],int A[],int l,int r,int i, int j,int k)
{
	int p1,p2;

	if(i<=l && r<=j)
	{
		return st[k];
	}

	else if(r<=i || j<l)
	{
		return -1;
		
	}

	else
	{
    		int mid = (l+r)/2;

		p1 = Range_min_query(st,A,l,mid,i,j,2*k+1);
		p2 = Range_min_query(st,A,mid+1,r,i,j,2*k+2);

		if(p1== -1)
		{
			return p2;
		}

		else if(p2 == -1)
		{
			return p1;
		}
                
		else if(A[p1] < A[p2])
		{
			return p1;
		}

		else
		{
			return p2;
		}

	}
}

int main 





