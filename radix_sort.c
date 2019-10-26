#include<stdio.h>

int getmax(int arr[],int n)
{
	int max;
	int i;
        
	max = arr[0];
	for(i=1;i<n;i++)
	{
		if(arr[i]>max)
		{
			max = arr[i];
		}
	}

	return max;
}


void countsort(int arr[],int n, int exp)
{
	int i,output[n];
	int count[10]={0};

	for(i=0;i<n;i++)
	{
		count[(arr[i]/exp)%10]++ ;

	}

	for(i=1;i<10;i++)
	{
		count[i] += count[i-1];
	}

	for(i=n-1;i>=0;i--)
	{
		output[count[(arr[i] / exp)%10]-1] = arr[i];
		count[(arr[i]/exp)%10]-- ;
	}

	for(i=0;i<n;i++)
	{
		arr[i] = output[i];
	}
	
}


void radixsort(int arr[],int n)
{
	int m = getmax(arr,n);
	int exp;

	for(exp=1;m/exp>0;exp*=10)
	{
		countsort(arr,n,exp);
	}
}

void print(int arr[], int n)
{
	int i;
	for(i=0;i<n;i++)
	{
		printf("%d " ,arr[i]);
	}
}

int main()
{
	int arr[] = {170,45,75,90,802,24,2,66};
	int n = sizeof(arr)/sizeof(arr[0]);

	radixsort(arr,n);
	print(arr, n);

	return 0;
}



        
  	

