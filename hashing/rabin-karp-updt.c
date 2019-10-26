#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

int p = 3;

int createhash(char arr[],int end)
{
	int i;
	int hash=0;
	for(i=0;i<end;i++)
	{
		hash = hash + (arr[i] * pow(p,i));
	
	}
        printf("a\n");
	return hash;
}

int recalculate(char arr[],int oldindex,int newindex,long oldhash,int patlen)
{
	long newhash = oldhash - arr[oldindex];
	newhash = newhash/p;
	newhash = newhash + (arr[newindex]* pow(p,patlen-1));
	printf("b");

	return newhash;
}

int checkstring(char arr1[],int start1,int end1,char arr2[],int start2,int end2)
{
	if(end1-start1 != end2-start2)
	{
		return 0;
	}

	while(start1<=end1 & start2<=end2)
	{
		if(arr1[start1] != arr2[start2])
		{
			return 0;
		}

		start1++;
		start2++;

	}
        printf("c");
	return 1;

}

int search(char txt[],char pat[])
{
	int n; //= strlen(txt);
        int m; //= strlen(pat);

	n = strlen(txt);
	m = strlen(pat);

	long txt_hash = createhash(txt,m);
	long pat_hash = createhash(pat,m);
        printf("h\n");

	int i = 0;
	while(i<n-m+1)

	{
	
		printf("m");
		if(txt_hash == pat_hash )
		{      
		       if(checkstring(txt,i,i+m-1,pat,0,m))
		     
		       {
			       return i;
			       printf("yes");
		       }

	        }

		else if(pat_hash!=txt_hash)
		{
			txt_hash = recalculate(txt,i,i+m-1,txt_hash,m);
			printf("%ld ", txt_hash);
			printf("no");
		}

		i++;

	}
	printf("d");

	return 0;
}

int main()
{
        char str[10] = "adcbsdfhkl";

        char pat[3] = "bsd";

        int k = search(str,pat);

	printf("%d ", k);

        return 0;
}

