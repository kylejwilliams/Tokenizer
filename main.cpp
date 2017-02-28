
#include <iostream>
#include <string>

#include "Tokenizer.h"
#include "FileHandler.h"
#include "BST.h"
#include "TreeBuilder.h"

using namespace std;

int main(int argc, char *argv[])
{
	bst btree;
	string filename = (argc != 2) ? "out" : argv[1];

	if (argc != 2) getKeyboardInput(filename);

	createTree(btree, filename);

	writeFile(filename + ".preorder", buildTree(traversePreorder(btree.root)));
	writeFile(filename + ".inorder", buildTree(traverseInorder(btree.root)));
	writeFile(filename + ".postorder", buildTree(traversePostorder(btree.root)));
}