#include<stdio.h>
#include<stdlib.h>
#include"inversion_pairs.h"
int inversion_pairs(int* ar,int start,int end)
{
	if(start < end)
	{
		int middle = (start+end)/2;
		return inversion_pairs(ar,start,middle)+inversion_pairs(ar,middle+1,end) + merge(ar,start,middle,end);
	}
	return 0;
}
int merge(int* ar,int start,int middle,int end)
{
        int *left = (int*)malloc((middle-start+1)*sizeof(int));
        int *right = (int*)malloc((end-middle)*sizeof(int));
        for(int i = start,j = 0;i <= middle;i++,j++)
                *(left+j) = *(ar+i);
        for(int i = middle+1,j = 0;i <= end;i++,j++)
                *(right+j) = *(ar+i);
        int ptr1 = 0,ptr2 = 0,pairs = 0;
	for(int i = 0, j = 0;i < middle-start+1 && j < end-middle;)
	{
		if(left[i] > right[j])
		{
			pairs += (middle - start) - i + 1;
			j++;
		}
		else
			i++;
	}
        while(ptr1 <= (middle - start) && ptr2 <= (end - middle - 1))
        {
                if(*(left+ptr1) < *(right+ptr2))
                {
                        *(ar + start + ptr1 + ptr2) = *(left+ptr1);
                        ptr1++;
                }
                else
                {
                        *(ar + start + ptr1 + ptr2) = *(right+ptr2);
                        ptr2++;
                }
        }
        while(ptr1 <= (middle - start))
        {
                *(ar + start + ptr1 + ptr2) = *(left + ptr1);
                ptr1++;
        }
        while(ptr2 <= (end - middle - 1))
        {
                *(ar + start + ptr1 + ptr2) = *(right + ptr2);
                ptr2++;
        }
        free(left);
        free(right);
	return pairs;
}

