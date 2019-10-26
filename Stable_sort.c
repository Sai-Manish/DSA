#include<stdio.h>
#include<stdlib.h>
int main()
{
	int n;
	scanf("%d",&n);
	int i,j;
	int a[n];
	int b[10];
	for(i=0;i<10;i++)
	{
		b[i]=0;
	}
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
		b[a[i]]++;
	}
	int c[10];
	c[0]=b[0];
	for(i=1;i<10;i++)
	{
		c[i]=b[i]+c[i-1];
	}
	printf("The counting array is\n");
	for(i=0;i<10;i++)
	{
		printf("%d ",b[i]);
	}
	printf("\n");
	printf("The summation array is \n");
	for(i=0;i<10;i++)
	{
		printf("%d ",c[i]);
	}
	printf("\n");
	int d[10];
	for(i=0;i<10;i++)
	{
		d[i]=0;
	}
	for(i=9;i>0;i--)
	{
		while(c[i]-c[i-1]>0 && i>0)
		{
			c[i]--;
			d[c[i]]=i;
		}
		if(i==0)
		{
			while(c[0]>0)
			{
				c[0]--;
				d[c[0]]=i;
			}
		}
	}
	for(i=0;i<9;i++)
	{
		printf("%d ",d[i]);
	}
	printf("\n");
}







