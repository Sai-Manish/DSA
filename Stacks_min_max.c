#include<stdio.h>
int top1=-1;
int top2=-1;
int b[1000];
int pass=0;
void push(int *a,int x)
{
	top1++;
	a[top1]=x;
	if(pass==0)
	{
		top2++;
		b[top2]=x;
		pass=1;
	}
	else if(a[top1]<b[top2])
	{
		top2++;
		b[top2]=b[top2-1];
	}
	else 
	{
		top2++;
		b[top2]=a[top1];
	}
}
void pop()
{
	top1--;
	top2--;
}
void Maximum()
{
	printf("%d is the maximum\n",b[top2]);
}
int main()
{
	int a[10000];
	push(a,10);
	//push(a,60);
	push(a,40);
	pop();
	Maximum();
	push(a,40);
	push(a,9);
	Maximum();
	push(a,100);
	//pop();
	Maximum();
}
