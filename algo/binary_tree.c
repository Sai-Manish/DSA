#include<stdio.h>
#include<stdlib.h>
struct Node{
	int data;
	struct Node* left;
	struct Node* right;
	//struct Node* parent;

};

void inorder(struct Node* node)
{
	if(node == NULL)
	{
		return;
	}
	else
	{
		inorder(node->left);
        	printf("%d ", node->data);
		inorder(node->right);
	}
}


void preorder(struct Node*node)
{

	if(node == NULL)
	{
		return;
	}
	else
	{

		printf("%d ", node->data);
		preorder(node->left);
		preorder(node->right);
	}
    
}

void postorder(struct Node* node)
{
	if(node == NULL)
	{
		return;
	}
        else
	{
		postorder(node->left);
		postorder(node->right);
		printf("%d ", node->data);
	}

}

struct Node* createnode(int data)
{
	struct Node* node = (struct Node*)malloc(sizeof(struct Node));

	node->data = data;
	node->left = NULL;
	node->right = NULL;
	//node->parents = NULL;
	return node;
}

/* A utility function to insert a new node with given key in BST */
struct node* insert(struct node* node, int key) 
{ 
    /* If the tree is empty, return a new node */
    if (node == NULL) return newNode(key); 
  
    /* Otherwise, recur down the tree */
    if (key < node->key) 
        node->left  = insert(node->left, key); 
    else if (key > node->key) 
        node->right = insert(node->right, key);    
  
    /* return the (unchanged) node pointer */
    return node; 
} 

/* Given a binary search tree and a key, this function deletes the key 
   and returns the new root */
struct node* deleteNode(struct node* root, int key) 
{ 
    // base case 
    if (root == NULL) return root; 
  
    // If the key to be deleted is smaller than the root's key, 
    // then it lies in left subtree 
    if (key < root->key) 
        root->left = deleteNode(root->left, key); 
  
    // If the key to be deleted is greater than the root's key, 
    // then it lies in right subtree 
    else if (key > root->key) 
        root->right = deleteNode(root->right, key); 
  
    // if key is same as root's key, then This is the node 
    // to be deleted 
    else
    { 
        // node with only one child or no child 
        if (root->left == NULL) 
        { 
            struct node *temp = root->right; 
            free(root); 
            return temp; 
        } 
        else if (root->right == NULL) 
        { 
            struct node *temp = root->left; 
            free(root); 
            return temp; 
        } 
  
        // node with two children: Get the inorder successor (smallest 
        // in the right subtree) 
        struct node* temp = minValueNode(root->right); 
  
        // Copy the inorder successor's content to this node 
        root->key = temp->key; 
  
        // Delete the inorder successor 
        root->right = deleteNode(root->right, temp->key); 
    } 
    return root; 
} 

int main()
{
	struct Node* root = createnode(5);

	root-> left = createnode(3);
	root->right = createnode(4);

	root->left->left = createnode(1);
	root->left->right = createnode(2);
        
	printf("binary tree order in inorder\n");
	inorder(root);
	printf("\n");

	printf("binary tree order in preorder\n");
	preorder(root);
	printf("\n");

	printf("binary tree order in postorder\n");
	postorder(root);
	printf("\n");

	return 0;

}

