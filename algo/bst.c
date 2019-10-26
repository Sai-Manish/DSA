#include<stdio.h>
#include<stdlib.h>

struct Node
{
	int data,h,l;
	struct Node* left;
	struct Node* right;
	struct Node* parent;
};

struct Node* createtree(int A[],int s, int e)
{

    
	if(s > e)
	{
		return NULL;
	}
//	printf("%d %d\n", s, e);

	struct Node* newnode = (struct Node*)malloc(sizeof(struct Node));

	newnode->parent = NULL;

      	int mid = (s+e)/2;
    		
	newnode->data = A[mid];
	newnode->left = createtree(A,s,mid - 1);
	newnode->right = createtree(A,mid + 1,e);

	if(newnode->left != NULL)
	{
		newnode->left->parent = newnode;
	}

	if(newnode->right != NULL)
	{
		newnode->right->parent = newnode;
	}
	

	return newnode;
}

void swap(int * a,int* b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}


int partation(int A[],int low, int r)
{
	int q = A[r];
	int i,j;
	i = low-1;
	for(j=low;j<r;j++)
	{
		if(A[j]<=q)
		{
			i = i+1;
			swap(&A[i],&A[j]);

		}
	}

	swap(&A[i+1],&A[r]);
	return i+1;
}

				
void quicksort(int A[],int low,int r)
{
	if(low<r)
	{
		int x = partation(A,low,r);
		quicksort(A,low,x-1);
		quicksort(A,x+1,r);
	}
}

void preorder(struct Node* root)
{
	if(root == NULL)
	{
		return;
	}
	else
	{

		printf("%d ", root->data);
		preorder(root->left);
		preorder(root->right);
	}
}

void inorder(struct Node* root)
{

	if(root == NULL)
	{
		return;
	}

	else
	{
		inorder(root->left);
		printf("%d ", root->data);
		inorder(root->right);
	}
}

void postorder(struct Node* root)
{
	if(root == NULL)
	{
		return;
	}

	else
	{
		postorder(root->left);
		postorder(root->right);
		printf("%d ",root->data);
	}
}

int maxheight(struct Node* root)
{
	if(root == NULL)
	{
		return 0;
	}

       	int lmaxheight = maxheight(root->left);
	int rmaxheight = maxheight(root->right);

//	root->left->h = lmaxheight;
//	root->right->h = rmaxheight;

	if(lmaxheight > rmaxheight)
	{
		return (lmaxheight + 1);
	}

	else
	{
		return (rmaxheight + 1);
	}
}

/*int level(struct Node* root,int l)
{
	if(root == NULL)
	{
		return -1;
	}

	if(root->right == NULL && root->left == NULL)
	{
	         return l;
	}

	int leftlevel = level(root->left, l+1);
	int rightlevel = level(root->right, l+1);

	if(leftlevel == -1)
	{
		return rightlevel;
	}

	else
	{
		return leftlevel;
	}
}*/
// C function to search a given key in a given BST 
struct node* search(struct node* root, int key) 
{ 
	// Base Cases: root is null or key is present at root 
	if (root == NULL || root->key == key) 
	return root; 
	
	// Key is greater than root's key 
	if (root->key < key) 
	return search(root->right, key); 

	// Key is smaller than root's key 
	return search(root->left, key); 
} 


int main()
{
	//int A[10]= {1,2,3,4,5,6,7,8,9,10},i;

	int A[10],i;
	for(i=0;i<10;i++)
	{
		A[i] = rand()%(1000-1+1);
	}

	quicksort(A,0,9);

	printf("sorted array : \n");
	for(i=0;i<10;i++)
	{
		printf("%d " , A[i]);
	}
	printf("\n");
	
	struct Node* root = createtree(A,0,9);
        
	printf("printing preorder : \n");

 	preorder(root);
        printf("\n");

	printf("printing inorder : \n");
	inorder(root);
	printf("\n");
        
	printf("printing postorder : \n");
	postorder(root);

	printf("\n");
        
	printf("height of binary tree : \n");
	root->h = maxheight(root);

	printf("%d \n", root->h);

	//int lev = level(root->left->left,0);
	//printf("level : ");
	//printf("%d \n", lev);

	return 0;
}



 







	



