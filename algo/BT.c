#include<stdio.h>
#include<stdlib.h>

struct tNode
{
	int data;
	struct tNode* left;
	struct tNode* right;
};

struct tNode* createNode(int data)            // returns the pointer to the new node
{
	struct tNode* new_node=(struct tNode*)malloc(sizeof(struct tNode));
	new_node->data=data;
	new_node->left=NULL;
	new_node->right=NULL;
	return new_node;
}

int max(int a,int b)
{
	return a>=b?a:b;
}


int Height_of_BT(struct tNode* root)
{
if(root==NULL)
	return -1;
return max(Height_of_BT(root->left),Height_of_BT(root->right))+1;
}

int main()
{
	  /* Let us create following BT 
              50 
           /     \ 
          30      70 
         /  \    /  \ 
       20   40  60   80 
           /            
          40            */


	// first we create the root of the tree 
	struct tNode* root=createNode(50);
	root->left= createNode(30);
	root->right= createNode(70);
	root->left->left=createNode(20);
	root->left->right=createNode(40);
	root->left->right->left=createNode(40);
	root->right=createNode(70);
	root->right->left=createNode(60);
	root->right->right=createNode(80);
	
	printf("Height of BT is %d\n",Height_of_BT(root));

return 0;
}





