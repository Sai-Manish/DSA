#include<stdio.h>
#include<math.h>

void insertion(int A[], int n)
{
	int i, key, j;
        
	for(i=1; i<n; i++)
	{
		key = A[i];
		j = i - 1;
		while(j>=0 && A[j] > key)
		{
			A[j+1] = A[j];
			j = j-1;

		}
		
		A[j+1] = key;
	}
}

int main()
{
	int i,j;
	int Arr[6];
	Arr[6] ={9,3,5,4,1,2};
        int n = sizeof(Arr)/sizeof(Arr[0]);

	insertion(Arr,n);
	for(i=0;i<n;i++)
	{
		printf("%d ", Arr[i]);
	}

	printf("\n");

	return 0;
}
