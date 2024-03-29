
// C program to show segment tree operations like construction, query 
// and update 
#include <stdio.h> 
#include <math.h>
#include<stdlib.h>
int *build_tree(int *A,int n)
{
        int *st = (int*)malloc((2*n-1)*sizeof(int)); //memory allocation for segment tree
        //int ad = &st;
        int i,j;
        for(i=0;i<n;i++)
        {
                st[i+n-1] = i;    // storing the indices of array A in the st tree as they are leaf nodes
        }

        for(i=n-2;i> -1;i--)
        {
                j = 2*i;
                if((A[st[j+1]]) <= (A[st[j+2]])) // checkin for the inner nodes and assigning the index of minimum of their two children
                {
                        st[i] = st[j+1];
                }

                else if(A[st[j+1]] > A[st[j+2]])
                {
                        st[i] = st[j+2];
                }

        }

        return st;
}
  
// A utility function to get the middle index from corner indexes. 
int getMid(int s, int e) {  return s + (e -s)/2;  } 
  
/*  A recursive function to get the sum of values in given range 
    of the array. The following are parameters for this function. 
  
    st    --> Pointer to segment tree 
    si    --> Index of current node in the segment tree. Initially 
              0 is passed as root is always at index 0 
    ss & se  --> Starting and ending indexes of the segment represented 
                 by current node, i.e., st[si] 
    qs & qe  --> Starting and ending indexes of query range */
int getSumUtil(int *st, int ss, int se, int qs, int qe, int si) 
{ 
    // If segment of this node is a part of given range, then return 
    // the sum of the segment 
    if (qs <= ss && qe >= se) 
        return st[si]; 
  
    // If segment of this node is outside the given range 
    if (se < qs || ss > qe) 
        return 0; 
  
    // If a part of this segment overlaps with the given range 
    int mid = getMid(ss, se); 
    return getSumUtil(st, ss, mid, qs, qe, 2*si+1) + 
           getSumUtil(st, mid+1, se, qs, qe, 2*si+2); 
} 
  
/* A recursive function to update the nodes which have the given  
   index in their range. The following are parameters 
    st, si, ss and se are same as getSumUtil() 
    i    --> index of the element to be updated. This index is  
             in the input array. 
   diff --> Value to be added to all nodes which have i in range */
void updateValueUtil(int *st, int ss, int se, int i, int diff, int si) 
{ 
    // Base Case: If the input index lies outside the range of  
    // this segment 
    if (i < ss || i > se) 
        return; 
  
    // If the input index is in range of this node, then update  
    // the value of the node and its children 
    st[si] = st[si] + diff; 
    if (se != ss) 
    { 
        int mid = getMid(ss, se); 
        updateValueUtil(st, ss, mid, i, diff, 2*si + 1); 
        updateValueUtil(st, mid+1, se, i, diff, 2*si + 2); 
    } 
} 
  
// The function to update a value in input array and segment tree. 
// It uses updateValueUtil() to update the value in segment tree 
void updateValue(int arr[], int *st, int n, int i, int new_val) 
{ 
    // Check for erroneous input index 
    if (i < 0 || i > n-1) 
    { 
        printf("Invalid Input"); 
        return; 
    } 
  
    // Get the difference between new value and old value 
    int diff = new_val - arr[i]; 
  
    // Update the value in array 
    arr[i] = new_val; 
  
    // Update the values of nodes in segment tree 
    updateValueUtil(st, 0, n-1, i, diff, 0); 
} 
  
// Return sum of elements in range from index qs (quey start) 
// to qe (query end).  It mainly uses getSumUtil() 
int getSum(int *st, int n, int qs, int qe) 
{ 
    // Check for erroneous input values 
    if (qs < 0 || qe > n-1 || qs > qe) 
    { 
        printf("Invalid Input"); 
        return -1; 
    } 
  
    return getSumUtil(st, 0, n-1, qs, qe, 0); 
} 
   
// Driver program to test above functions 
int main() 
{ 
    int arr[] = {1, 3, 5, 7, 9, 11}; 
    int n = sizeof(arr)/sizeof(arr[0]); 
  
    // Build segment tree from given array 
    int *st = build_tree(arr, n); 
  
    // Print sum of values in array from index 1 to 3 
    printf("Sum of values in given range = %d\n",  
            getSum(st, n, 1, 3)); 
  
    // Update: set arr[1] = 10 and update corresponding  
    // segment tree nodes 
    updateValue(arr, st, n, 1, 10); 
  
    // Find sum after the value is updated 
    printf("Updated sum of values in given range = %d\n", 
             getSum(st, n, 1, 3)); 
    return 0; 
} 

