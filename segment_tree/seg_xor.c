#include<stdio.h>
#include<stdlib.h>

int *buildtree(int *A,int n)
{
	int *st = (int*)malloc((2*n-1)*sizeof(int));

	int i,j;

	for(i=0;i<n;i++)
	{
		st[i+n-1] = i;
	}

	for(i=n-2;i>-1;i--)
	{
		j = 2*i;

		st[i] = (st[j+1])^(st[j+2]);

	}

	return st;
}

void update(int st[],int A[],int i,int n,int x)
{
        A[i] = x;

        int j,k;

        j = n-1+i;
        //st[j] = x;

        int l;
        
	if(i < 0 || i > n-1)
	{
		return;
	}

	else if(i>0 && i<n)
	{
		st[j] = x;

        	while(j>0)
		{	
			k = (j - 1)/2;

		       	st[k] = (st[2*k+1])^(st[2*k+2]);
                        
			j = (j-1)/2;
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

        int *st = buildtree(A,n);
        
	int xor1 = xor_fun(st,8,2,7,0);

        printf("xor of values of given range %d\n", xor1);

        update(st,A,4,6,8);
        
	int xor2 = xor_fun(st,8,2,7,0);

        printf("xor of updated segement tree %d\n", xor2);

        return 0;
}




