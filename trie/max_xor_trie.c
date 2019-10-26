// C program to find minimum XOR value in an array. 

#include <stdio.h>
#include<stdlib.h>
#include<math.h>
#include<limits.h>

#define INT_SIZE 32 

int max(int x, int y)
{
	return x>y ? x:y;
}


// A Trie Node 
struct TrieNode { 
	struct TrieNode* left;		// left is for 0 and right is for 1
	struct TrieNode* right;
}; 

// Utility function to create a new Trie node 
struct TrieNode* createNode() 
{ 
	struct TrieNode* newNode;
	newNode = (struct TrieNode*)malloc(sizeof(struct TrieNode)); 
	newNode->left=NULL;
	newNode->right=NULL;
	return newNode; 
} 

// utility function insert new key in trie  i.e to insert the binary rep. of key
void insert(struct TrieNode* root, int key) 
{ 
	struct TrieNode* curr = root; 

	// start from the most significant bit, insert all 
	// bit of key one-by-one into trie 
	for (int i = INT_SIZE - 1; i >= 0; i--) 
	{ 
		// Find current bit  
		int b = (key>>i) & 1; 

		// Add a new Node into trie 
		if(b==0)
		{
			if(!curr->left)
			{
				curr->left= createNode();
			}
			curr=curr->left;
		}
		else
		{
			if(!curr->right)
			{
				curr->right= createNode();
			}
			curr=curr->right;
		}
	}
}

// Returns minimum XOR value of an integer inserted 
// in Trie and given key. 
int max_XOR_for_key(struct TrieNode* root, int key) 
{ 
	struct TrieNode* curr = root; 
	int xor_val=0;
	for (int i = INT_SIZE - 1; i >= 0; i--) 
	{ 
		// Find current bit 
		int b= (key>>i)&1;
		// Traversal Trie, look for node that has 
		// same bit 
		if(b==0)		// try to go to right
		{
			if(curr->right)
			{
				curr=curr->right;
				xor_val+=pow(2,i);
			}
			else 
				curr=curr->left;
		}
		else  			// if(b==1)
		{
			if(curr->left)
			{
				curr=curr->left;
				xor_val+=pow(2,i);
			}
			else 
				curr=curr->right;
		}

	}
	return xor_val;
} 

int max_Xor_for_array(int arr[],int n)		// Returns the max XOR value tof the pair in arr[]
{
	int max_xor=INT_MIN;
	// create a True and insert first element in it
 	struct TrieNode* root = createNode();

    	// Traverse all array element and find maximum xor
    	// for every element
        // insert current array value into Trie
        for(int i=0;i<n;i++)
		insert(root, arr[i]);
    	for (int i = 1; i < n; i++) 
	{
        // Find maximum XOR value of current element with
        // previous elements inserted in Trie
        max_xor = max(max_xor, max_XOR_for_key(root, arr[i]));
	}
   return max_xor;
}

// Driver
int main() 
{ 
	int arr[] = {8,1,2,12,10,5,3}; 
	int n = sizeof(arr) / sizeof(arr[0]); 
	printf("%d is the max xor possible\n",max_Xor_for_array(arr,7));
	return 0; 
} 

