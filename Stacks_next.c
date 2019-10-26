#include<stdio.h>
#include<stdlib.h>
int main()
{
	int n;
	scanf("%d",&n);
	int a[n];
	int i;
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	int b[n];
	int index[n];
	int top=0;
	b[0]=a[0];
	int p=0;
	/*for(i=1;i<n;i++)
	{
		if(a[i]>=b[top])
		{
			top++;
			b[top]=a[i];
		}
		else if(a[i]<b[top])
		{
			while(a[i]<b[top] && top>=0)
			{

				top--;
			}
			top++;
			b[top]=a[i];
		}
	}*/
	for(i=0;i<n;i++)
	{
		index[i]=-1;
	}
	int peak=0;
	for(i=1;i<n;i++)
	{
		peak=i;
		if(a[i]>=b[top])
		{
			top++;
			b[top]=a[i];
			index[peak]=i;
		}
		if(a[i]<b[top])
		{
			while(a[i]<b[top] && top>=0)
			{
				top--;
				peak--;
				index[peak]=i;
			}
			top++;
			b[top]=a[i];
		}
	}
	printf("The b array is \n");
	for(i=0;i<=top;i++)
	{
		printf("%d ",b[i]);
	}
	printf("\n");
	printf("The index array is \n");
	for(i=0;i<n;i++)
	{
		printf("%d ",index[i]);
	}
	printf("\n");
}
		



