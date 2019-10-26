#include<stdio.h>
#include<stdlib.h>
int Partition(int arr[],int start,int end);

void swap(int* a,int* b)
{
int t=*a;
*a=*b;
*b=t;
}
int RandomizedPartition(int arr[],int start, int end)
{
int pi=start+(rand()%(end-start+1));
swap(arr+pi,arr+end);
return Partition(arr,start,end);
}

// partition fn for quickSort
int Partition(int arr[],int start,int end)
{
int pivot=arr[end];
int pi=start;
for(int i=start;i<end;i++)
{
if(arr[i]<=pivot)
{
        swap(arr+i,arr+pi); // swap if element is lesser than pivot
        pi++;
}
}
swap(arr+pi,arr+end);
return pi;
}

void quickSort(int arr[],int start,int end)
{
        if(start<end)
        {
          int pi=Partition(arr,start,end);
          quickSort(arr,start,pi-1);
          quickSort(arr,pi+1,end);
        }
}

int R_Find_Rank(int arr[],int start,int end,int r) // r is the rank index
{
int K=RandomizedPartition(arr,start,end);

if(r==end-K+1)
	return arr[K];
else if(r<end-K+1)
	return R_Find_Rank(arr,K+1,end,r);
else 
	return R_Find_Rank(arr,start,K,r-end+K);
}


int main()
{
int arr[]={9,6,5,3,1};
printf("%d is the element of given rank\n",R_Find_Rank(arr,0,4,5));
return 0;
}

