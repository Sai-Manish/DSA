// Trie implemntation of alphabets
// Here consider only small alphabets 
// Hence the size of children array is 26

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>

#define ARRAY_SIZE(a) sizeof(a)/sizeof(a[0])

#define ALPHABET_SIZE (26)

#define CHAR_TO_INDEX(c) ((int)c-(int)'a') 	// Just subtracting the ASCII value of 'a' so that it becomes in sync with index

// Now let us make a Trie Node

struct TrieNode
{
	struct TrieNode* children[ALPHABET_SIZE];	// each node will contain an array of pointers (which will be the link to their children) 
							// (child is the next letter in word)
	// isEndofWord is true if that node represents the end of the word
	bool isEndofWord;
};

struct TrieNode* createNode()		// Function which creates a TrieNode with all values initialised to NULL
{
	struct TrieNode* TNode=NULL;
	TNode=(struct TrieNode*)malloc(sizeof(struct TrieNode));

	if(TNode)		// if the memory is allocated then the TNode won't be NULL
	{
		TNode->isEndofWord=false;
		for(int i=0;i<26;i++)
		{
			TNode->children[i]=NULL; 		// Initialising all the children pointer of the new node as NULL
		}
	}
	return TNode;
}

void Insert(struct TrieNode* root,const char* key)	// If the word is not there, insert it
							// if it is there, just mark the leaf node
{
	int level;
	int length=strlen(key);
	int index;

	struct TrieNode* node=root;
	
	for(int level=0;level<length;level++)
	{
		index=CHAR_TO_INDEX(key[level]);
		if(!node->children[index])
			node->children[index]=createNode();
		node=node->children[index];
	}
	
	// Now mark the last node as leaf
	node->isEndofWord=true;
}
// Searching a string
bool Search(struct TrieNode* root,const char* key)
{
	int level;
        int length=strlen(key);
        int index;

	struct TrieNode* node=root;

	for(int level=0;level<length;level++)
	{
		index=CHAR_TO_INDEX(key[level]);
		if(!node->children[index])
			return false;
		node=node->children[index];
	}
	
	return (node!=NULL && node->isEndofWord);
}

// Returns true if root has no children, else false
bool isEmpty(struct TrieNode* root)
{
    for (int i = 0; i < ALPHABET_SIZE; i++)
        if (root->children[i])
            return false;
    return true;
}

// Recursive function to delete a string from given Trie & while calling this fn start with depth =0
struct TrieNode* Delete(struct TrieNode* root, const char* key, int depth)
{
    // If tree is empty
    if (!root)
        return NULL;

    // If last character of key is being processed
    if (depth == strlen(key)) 
    {

        // This node is no more end of word after
        // removal of given key
        if (root->isEndofWord)
            root->isEndofWord = false;

        // If given is not prefix of any other word
        if (isEmpty(root)) 
	{
            free(root);
            root = NULL;
        }

        return root;
    }

    // If not last character, recur for the child
    // obtained using ASCII value
    int index = key[depth] - 'a';
    root->children[index] =
          Delete(root->children[index], key, depth + 1);

    // If root does not have any child (its only child got
    // deleted), and it is not end of another word.
    if (isEmpty(root) && root->isEndofWord == false) 
    {
        free(root);
        root = NULL;
    }

    return root;
}

// Driver 
int main() 
{ 
    // Input keys (use only 'a' through 'z' and lower case) 
    char keys[][8] = {"the", "a", "there", "answer", "any", 
                     "by", "bye", "their"}; 
  
    char output[][32] = {"Not present in trie", "Present in trie"}; 
  
  
    struct TrieNode *root = createNode(); 
  
    // Construct trie 
    int i; 
    for (i = 0; i < ARRAY_SIZE(keys); i++) 
        Insert(root, keys[i]); 
  
    // Search for different keys 
    printf("%s --- %s\n", "the", output[Search(root, "the")] ); 
    printf("%s --- %s\n", "their", output[Search(root, "their")] ); 
    printf("%s --- %s\n", "thaw", output[Search(root, "thaw")] ); 
    Delete(root,"these",0);
    printf("%s --- %s\n", "these", output[Search(root, "these")] ); 

    return 0; 
} 
