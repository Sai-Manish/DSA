#include<stdio.h>
#include<string.h>
#include<math.h>

void search(char str[], char pat[], int m )
{
	int n = strlen(str);
	int p = strlen(pat);

	int hash_p=0;

	int hash_s = 0;

	int j=0;

	for(int i=0;i<p;i++)
	{

		hash_p = pat[i] * pow(m,i);
	}
        
        printf(" %d\n", hash_p);
	for(j = 0;j<p;j++)
	{
		hash_s = str[j] * pow(m,j);
	}

	printf(" %d\n", hash_s);

	for(j=p; j < n ; j++)
	{
		hash_s = ((hash_s - (str[j - p]))/3) + ((str[j]) * pow(m,p-1));
		printf(" %d\n",hash_s);


		int k;

		if(hash_p == hash_s)
		{
			for(k = j;k < j+p;k++)
			{
				if(pat[k-j] == str[k])
				{
					printf(" pattern is same for index %d\n ", k);
				}

				else
				{
					break;
				}
			}
		}
	}
}

int main()
{
	char str[10] = "adcbsdfhkl";

	char pat[3] = "bsd";

	int m = 3;

	search(str,pat,3);

	return 0;
}












        	
