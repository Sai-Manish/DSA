#include<stdio.h>
#include<stdlib.h>

// time complexity for building a segment tree is o(n)
// time complexity for query is o(log n)
// time complexity for update is o(log n)
// time complexity for update_range is o(r*log n)
// auxilary space is o(n)

int *build_tree(int *A,int n)
{
	int *st = (int*)malloc((2*n-1)*sizeof(int)); //memory allocation for segment tree
        //int ad = &st;
	int i,j;
	for(i=0;i<n;i++)                      
	{
		st[i+n-1] = i;    // storing the indices of array A in the st tree as they are leaf nodes
	}

	for(i=n-2;i> -1;i--)
	{
		j = 2*i;
		if((A[st[j+1]]) <= (A[st[j+2]])) // checkin for the inner nodes and assigning the index of minimum of their two children
		{
			st[i] = st[j+1];
		}

		else if(A[st[j+1]] > A[st[j+2]])
		{
			st[i] = st[j+2];
		}

	}

	return st;
}

void update(int st[],int A[],int i,int n,int x)
{
	A[i] = x;

	int j,k;

	j = n-1+i;

	int l;
        if(i < 0 || i > n-1)
	{
		return;
	}

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

// main function

void update_range(int st[],int A[],int ls,int es,int val,int n)
{        
	int i;
	if(ls>=0 && es<n)
	{
		for(i=ls;i<=es;i++)
		{
			A[i] = A[i] + val;
		}

		
	}

	else if(ls<0 || es > n)
	{
		return;
	}

	for(i=ls;i<=es;i++)
	{
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

}


int Range_min_query(int A[],int st[],int l,int r,int i, int j,int k)
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

		p1 = Range_min_query(A,st,l,mid,i,j,2*k+1);
		p2 = Range_min_query(A,st,mid+1,r,i,j,2*k+2);

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

// xor of numbers
int xor_main(int st[],int l,int r,int qs,int qe,int k)
{
	if(qs <= l && qe >= r)
	{
		return st[k];
	}

	if(r < qs || l > qe)
	{
		return 0;
	}

	int mid = (l + r)/2;

	return xor_main(st,l,mid,qs,qe,2*k+1) ^ xor_main(st,mid+1,r,qs,qe,2*k+2);
}


int xor_fun(int st[],int n,int qs,int qe,int k)
{
	if(qs < 0 || qe > n-1 || qs > qe)
	{
		printf("invalid input cannot compute xor");

		return -1;

	}

	return xor_main(st,0,n-1,qs,qe,0);
}

	

int main()
{
	int A[]= {1,4,3,6,8,7,9,0};

	int n = 8;

	int *st = build_tree(A,n);

	int min = Range_min_query(A,st,0,7,2,7,0);
        
	printf("min value is %d\n", A[min]);
        int xor1 = xor_fun(st,8,2,7,0);

	printf("xor of values of given range %d\n", xor1);

	update_range(st,A,4,7,6,8);
        
	int min2 = Range_min_query(A,st,0,7,2,7,0);

	printf("min2 value is %d\n", A[min2]);

	int xor2 = xor_fun(st,8,2,7,0);

	printf("xor of updated segement tree %d\n", xor2);

	return 0;
}


