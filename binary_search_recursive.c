#include<stdio.h>

int binarysort(int arr[],int l, int r, int x)
{
	if(r>=l)
	{
		int mid = l+(r-l)/2;

		if(arr[mid]==x)
		{
			return mid;
		}


		if(arr[mid] > x)
		{
			return binarysort( arr,l,mid-1, x);
		}

		return binarysort(arr, mid + 1, r,x);
	}
 
	return -1;
	
}

int main()
{

	int arr[] = {1,2,3,4,10,40};
	int n = sizeof(arr)/ sizeof(arr[0]);
	int x = 10;
	int result = binarysort(arr,0,n-1,x);
	if(result == -1)
	{
		printf("element not found");
	}
	printf("element is present at index %d", result);

	return 0;
}




