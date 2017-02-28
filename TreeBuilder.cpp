
#include "TreeBuilder.h"

/*
	DESCRIPTION:
		Traverse through the tree in a preorder and store all of the nodes' data
	PARAMETERS:
		root: The root node of the tree to traverse
	RETURNS:
		A vector containing all of the data within the tree
*/
vector<string> traversePreorder(node_t *root)
{
	vector<string> results;
	traversePreorder(results, root, 0);
	return results;
}

/*
	DESCRIPTION:
		Used internally to recursively traverse the tree
	PARAMETERS:
		values: a memory address of a vector to store all of the tree data to
		leaf: current node being traversed
		depth: depth of the current node within the tree with respect to the root
*/
vector<string> traversePreorder(vector<string> &values, node_t *leaf, int depth)
{
	values.push_back(buildBranch(leaf, depth));
	if (leaf->left != NULL)
		traversePreorder(values, leaf->left, depth + 1);
	if (leaf->right != NULL)
		traversePreorder(values, leaf->right, depth + 1);
	return values;
}

/*
DESCRIPTION:
Traverse through the tree in an inorder and store all of the nodes' data
PARAMETERS:
root: The root node of the tree to traverse
RETURNS:
A vector containing all of the data within the tree
*/
vector<string> traverseInorder(node_t *root)
{
	vector<string> results;
	traverseInorder(results, root, 0);
	return results;
}

/*
DESCRIPTION:
Used internally to recursively traverse the tree
PARAMETERS:
values: a memory address of a vector to store all of the tree data to
leaf: current node being traversed
depth: depth of the current node within the tree with respect to the root
*/
vector<string> traverseInorder(vector<string> &values, node_t *leaf, int depth)
{
	if (leaf->left != NULL)
		traverseInorder(values, leaf->left, depth + 1);
	values.push_back(buildBranch(leaf, depth));
	if (leaf->right != NULL)
		traverseInorder(values, leaf->right, depth + 1);
	return values;
}

/*
DESCRIPTION:
Traverse through the tree in a postorder and store all of the nodes' data
PARAMETERS:
root: The root node of the tree to traverse
RETURNS:
A vector containing all of the data within the tree
*/
vector<string> traversePostorder(node_t *root)
{
	vector<string> results;
	traversePostorder(results, root, 0);
	return results;
}

/*
DESCRIPTION:
Used internally to recursively traverse the tree
PARAMETERS:
values: a memory address of a vector to store all of the tree data to
leaf: current node being traversed
depth: depth of the current node within the tree with respect to the root
*/
vector<string> traversePostorder(vector<string> &values, node_t *leaf, int depth)
{
	if (leaf->left != NULL)
		traversePostorder(values, leaf->left, depth + 1);
	if (leaf->right != NULL)
		traversePostorder(values, leaf->right, depth + 1);
	values.push_back(buildBranch(leaf, depth));
	return values;
}

/*
	DESCRIPTION: 
		Formats the data on the current leaf based on its depth within the tree. 
		Each branch begins with an indentation of two spaces times the depth of 
		the data, followed by the key of the node and then the list of values contained
		in that node.
	PARAMETERS:
		leaf: current node in the tree
		depth: depth within the tree
	RETURNS:
		string containing the formatted branch
*/
string buildBranch(node_t *leaf, int depth)
{
	string output = "";
	for (int i = 0; i < depth; i++) output += "  ";
	output += leaf->key;
	for (string value : leaf->values) output += " " + value;
	return output;
}

/*
	DESCRIPTION:
		Takes all of the branches and combines them into a single string representing the entire tree
	PARAMETERS:
		branches: a vector containing the different formatted branches
	RETURNS:
		A string representing the full tree
*/
string buildTree(vector<string> branches)
{
	string output = "";
	for (string branch : branches)
		output += branch + "\n";
	return output;
}

/*
	DESCRIPTION:
		creates a binary tree based on the data stored in a given file.
	PARAMETERS:
		tree: A memory address to a tree that needs to be created
		filename: A file containing the data that should be stored in the tree
	RETURNS:
		NA
*/
void createTree(bst &tree, string filename)
{
	vector<string> tokens = tokenize(readFile(filename));
	for (string token : tokens)
		tree.insert(token);
}