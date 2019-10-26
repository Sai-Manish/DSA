#include<stdio.h>
#include<stdlib.h>

struct Interval
{
	int low;
	int high;
};

struct ITNode
{
	struct Interval* i;	// i is a pointer to the interval struct
	int max;		// max is the max high value in the subtree rooted at this node
	struct ITNode* left,right;	// two pointers for left and right
};

struct ITNode* createNode(struct Interval p)
{
	struct ITNode* node = (struct ITNode*)malloc(sizeof(struct ITNode));
	node->i=(struct Interval*)malloc(struct Interval);
	node->i->low=p.low;
	node->i->high=p.high;
	node->max=p.high;
	node->left=NULL;
	node->right=NULL;
	return node;
}

// Now as the BST will be implemented according to the low value of the intervals 
// 
