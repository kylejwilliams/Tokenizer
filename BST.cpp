
#include "BST.h"

/*
	DESCRIPTION:
		Default contructor for a binary search tree. 
	PARAMETERS:
		NA
	RETURNS:
		NA
*/
bst::bst() 
{
	root = NULL; 
}

/*
	DESCRIPTION:
		Inserts the given value as a node in the tree
	PARAMETERS:
		string to be inserted
	RETURNS:
		NA
*/
void bst::insert(string value)
{
	char key = value.at(0);

	if (root != NULL)
		insert(key, value, root);
	else
	{
		root = new node_t;
		root->key = key;
		root->values.push_back(value);
		root->left = NULL;
		root->right = NULL;
	}
}

/*
	DESCRIPTION:
		Recursively add data into the node. Internal view
	PARAMETERS:
		key: first letter of the string to be inserted
		value: full string to be inserted
		leaf: current node being evaluated for insertion
	RETURNS:
		NA
*/
void bst::insert(char key, string value, node_t *leaf)
{
	if (key == leaf->key)
		leaf->values.push_back(value);
	else if (key < leaf->key)
	{
		if (leaf->left != NULL) 
			bst::insert(key, value, leaf->left);
		else
		{
			leaf->left = new node_t;
			leaf->left->key = key;
			leaf->left->values.push_back(value);
			leaf->left->left = NULL;
			leaf->left->right = NULL;
		}
	}
	else if (key > leaf->key)
	{
		if (leaf->right != NULL)
			bst::insert(key, value, leaf->right);
		else
		{
			leaf->right = new node_t;
			leaf->right->key = key;
			leaf->right->values.push_back(value);
			leaf->right->left = NULL;
			leaf->right->right = NULL;
		}
	}
}

