#include<stdio.h>
#include<stdlib.h>
//int sum;
int *getsum(int bit[], int index)
{
	//int sum = (int*)malloc(sizeof(int));
        
	int *s;
	s = (int*)malloc(sizeof(int));
        int sum = 0;

	s = &sum;

	int j = index + 1;

	while(j>0)
	{
		sum = sum + bit[j];
               //printf("%d \n",sum);
		j = j - (j & (-j));

	}

	return s;

}

void update(int bit[], int val, int i,int n)
{

	int j = i + 1;

	while(j <= n)
	{
		bit[j] = bit[j] + val;

                //printf("%d\n",bit[j]);
	
		j = j + (j & (-j));

		//printf("j = %d \n",j);

	}

}

/*int *constructbitree(int arr[], int n)
{
	int *bit = (int*)malloc((n+1)*sizeof(int));
        //int bit[n+1];
	int i;
	for(i=0;i<=n;i++)
	{
		bit[i] = 0;
	}

	for(i=i;i<n;i++)
	{
		update(bit,arr[i-1],i-1,n);

	}

	return bit;
}*/

int main()
{
	int freq[] = {2,1,4,2,5,6,7,8,9,5,3};
	int n = sizeof(freq)/sizeof(freq[0]);
	int bit[n+1];
        int i;
        for(i=0;i<=n;i++)
        {
                bit[i] = 0;
        }

        for(i=1;i<n;i++)
        {
                update(bit,freq[i-1],i-1,n);

        }

        //int *bit = constructbitree(freq,n);

	int *sum1; 
	sum1 = getsum(bit,6);

	printf("sum from (0,5) is %d\n",*sum1);
}



	





