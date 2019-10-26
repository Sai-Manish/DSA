#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define char_to_int(c) ((int)c - (int)'a')

struct trienode
{
	struct trienode * data[26];

	int isend;
};

struct trienode *create_newnode(void)
{
	struct trienode *newnode = NULL;

	newnode = (struct trienode *)malloc(sizeof(struct trienode));
        
	if (newnode)
	{
		int i;

		newnode->isend = 0;

		for (i=0;i<26;i++)
		{
			newnode -> data[i] = NULL;
		}

	}

	return newnode;
}

void insert(struct trienode *root,const char *key)
{
	int l;//level
	int len = strlen(key);
	int i;
        
	struct trienode *node = root;
	for(l=0;l<len;l++)
	{
		i = char_to_int(key[l]);
		if(node->data[i] == NULL)
		{
			node->data[i] = create_newnode();
		}

		node = node->data[i];
	}

	node->isend = 1;
}


int search(struct trienode *root, const char key[])
{
	int l;//level
        int len = strlen(key);
        int i;
        
	struct trienode *node = root;
	for(l=0;l<len;l++)
	{
		i = char_to_int(key[l]);

		if(node->data[i] == NULL)
		{
			return 0;
		}

		node = node->data[i];

	}

	if(node != NULL && node->isend == 0)
	{
		return 1;
	}
       
        //return 0;

}

int have_children(struct trienode *node)
{
	for(int i = 0; i < 26;i++)
	{
		if(node->data[i])
		{
			return 1;
		}

	}

	return 0;

}

int delete(struct trienode** node, const char *keys)
{
	//if trie is empty
	if(*node == NULL)
	{
		return 0;
	}

	//not reached the end of the string
	//recursive for node coressponding to next char
	if(*keys)
	{
		if(*node != NULL && (*node)->data[*keys - 'a'] != NULL && delete(&((*node)->data[*keys - 'a']), keys + 1) && (*node)->isend == 0)
				
		{
			if(!have_children(*node))
				
			{
				free(*node);
				(*node) = NULL;
				return 1;
					
			}

			else
			{
				return 0;
				
			}
		}
	}
	// when reached end of the string

	if(*keys == '\0'&& (*node)->isend == 1)
	{
		//if current node is leaf node and dont have any children
		if(!have_children(*node))
		{
			free(*node);// delete current node
			(*node) = NULL;
			return 1; //delete non leaf parent node
		}

		//if current node is leaf node and  have childeren
                
		else
		{
			//mark current node as non-leaf node and dont delete it
                        
			(*node) -> isend = 0;
			return 0;
		}
	}
}

int main()
{
	char keys[][8] = {"the","these","is","thope","anvith","sai","teddy","and"};
	char output[][32] = {"not present in trie","present in trie"};

	struct trienode *root = create_newnode();
	int i;

	for(i=0;i<8;i++)
	{
		insert(root,keys[i]);
	}

	printf("%s : app \n",output[search(root,"app")]);
	printf("%s : and \n",output[search(root,"and")]);

	delete(&root,"sai");


	printf("%s : sai \n",output[search(root,"sai")]);

	return 0;
}






