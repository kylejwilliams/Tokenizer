#ifndef TREEBUILDER_H
#define TREEBUILDER_H

#include <vector>
#include <string>

#include "BST.h"
#include "Tokenizer.h"
#include "FileHandler.h"

using namespace std;

vector<string> traversePreorder(node_t *root);
vector<string> traverseInorder(node_t *root);
vector<string> traversePostorder(node_t *root);
string buildTree(vector<string> branches);
void createTree(bst &tree, string filename);

static vector<string> traversePreorder(vector<string> &values, node_t *leaf, int depth);
static vector<string> traverseInorder(vector<string> &values, node_t *leaf, int depth);
static vector<string> traversePostorder(vector<string> &values, node_t *leaf, int depth);
static string buildBranch(node_t *leaf, int depth);

#endif // !TREEBUILDER_H