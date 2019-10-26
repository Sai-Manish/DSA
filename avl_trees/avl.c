#include<stdio.h>
#include<stdlib.h>

struct node{

	int data;

	struct node *left;

	struct node *right;

	int height;

};

int height(struct node *node)
{
	if(node == NULL)
	{
		return -1;
	}

	return node->height;
}

int max(int a,int b)
{
	return(a > b) ? a : b;
}

struct node *rightrotate(struct node *y)
{
	struct node *x = y->left;
	struct node *t = x->right;

	x->right = y;
	y->left = t;

	y->height = max(height(y->left), height(y->right)) + 1;
	x->height = max(height(x->left), height(x->right)) + 1;

	return x;
}

struct node *leftrotate(struct node *a)
{
	struct node *b = a->right;
	struct node *l = b->left;

	// perform rotation
	b->left = a;
	a->right = l;

	a->height = max(height(a->left), height(a->right)) + 1;
	b->height = max(height(b->right), height(b->left)) + 1;

	return b;

}

int balance(struct node *n)
{
	if(n == NULL)
	{
		return 0;
	}

	return height(n->left) - height(n->right);

}

struct node *anode(int value)
{
	struct node *newnode = (struct node*)malloc(sizeof(struct node));
	newnode->left = NULL;
	newnode->right = NULL;
	newnode->data = value;
	newnode->height = 0;
        
	return newnode;
}

void inorder(struct node *root)
{
	if (root != NULL)
	{
		inorder(root->left);
		printf("%d \n", root->data);
		inorder(root->right);
	}
}

struct node* insert(struct node*node, int value)
{
	if(node == NULL)
	{
		return anode(value);
	}

	if (value < node->data)
	{
		node->left = insert(node->left,value);
	}
	else if(value > node->data)
	{
		node->right = insert(node->right,value);
	}

	node->height = 1 + max(height(node->left),height(node->right));

	int bal = balance(node);

	//cases if node becomes unbalanced
	
	// left left case or zig - zig
	
	if(bal > 1 && value < node->left->data)
	{
		return rightrotate(node);

	}

	// right right case or zig zig
	
	if(bal<-1 && value > node->right->data)
	{
		return leftrotate(node);
	}

	// left right case or zig-zag
	if(bal>1 && value > node->left->data)
	{
		node->left = leftrotate(node->left);

		return rightrotate(node);
	}

	// right left case
	if(bal < -1 && value  < node->right->data)
	{
		node->right = rightrotate(node->right);
		return leftrotate(node);
	}


	return node;
}

struct node * minValueNode(struct node* node)
{
    struct node* current = node;

    /* loop down to find the leftmost leaf */
    while (current->left != NULL)
        current = current->left;

    return current;
}

//delete function

struct node* deleteNode(struct node* root, int value) 
{ 
    // STEP 1: PERFORM STANDARD BST DELETE 
  
    if (root == NULL) 
        return root; 
  
    // If the key to be deleted is smaller than the 
    // root's key, then it lies in left subtree 
    if ( value < root->data ) 
        root->left = deleteNode(root->left, value); 
  
    // If the key to be deleted is greater than the 
    // root's key, then it lies in right subtree 
    else if( value > root->data ) 
        root->right = deleteNode(root->right, value); 
  
    // if key is same as root's key, then This is 
    // the node to be deleted 
    else
    { 
        // node with only one child or no child 
        if( (root->left == NULL) || (root->right == NULL) ) 
        { 
            struct node *temp = root->left ? root->left : 
                                             root->right; 
  
            // No child case 
            if (temp == NULL) 
            { 
                temp = root; 
                root = NULL; 
            } 
            else // One child case 
             *root = *temp; // Copy the contents of 
                            // the non-empty child 
            free(temp); 
        } 
        else
        { 
            // node with two children: Get the inorder 
            // successor (smallest in the right subtree) 
            struct node* temp = minValueNode(root->right); 
  
            // Copy the inorder successor's data to this node 
            root->data = temp->data; 
  
            // Delete the inorder successor 
            root->right = deleteNode(root->right, temp->data); 
        } 
    } 
  
    // If the tree had only one node then return 
    if (root == NULL) 
      return root; 
  
    // STEP 2: UPDATE HEIGHT OF THE CURRENT NODE 
    root->height = 1 + max(height(root->left), 
                           height(root->right)); 
  
    // STEP 3: GET THE BALANCE FACTOR OF THIS NODE (to 
    // check whether this node became unbalanced) 
    int bal = balance(root); 
  
    // If this node becomes unbalanced, then there are 4 cases 
  
    // Left Left Case 
    if (bal > 1 && balance(root->left) >= 0) 
        return rightrotate(root); 
  
    // Left Right Case 
    if (bal > 1 && balance(root->left) < 0) 
    { 
        root->left =  leftrotate(root->left); 
        return rightrotate(root); 
    } 
  
    // Right Right Case 
    if (bal < -1 && balance(root->right) <= 0) 
        return leftrotate(root); 
  
    // Right Left Case 
    if (bal < -1 && balance(root->right) > 0) 
    { 
        root->right = rightrotate(root->right); 
        return leftrotate(root); 
    } 
  
    return root; 
} 

void preorder(struct node *root)
{
	if(root!=NULL)
	{
		printf("%d ", root->data);
		preorder(root->left);
		preorder(root->right);
	}
}

int main()
{
	struct node *root = NULL;
	root = insert(root, 50);
	insert(root, 30);
	insert(root, 20);
	insert(root, 40);
	insert(root, 70);
	insert(root, 60);
        
	inorder(root);
	printf(" \n preorder \n ");
	preorder(root);

	return 0;
}


