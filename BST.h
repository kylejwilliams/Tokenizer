
#ifndef NODE_H
#define NODE_H

#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct node_t
{
	char key;
	vector<string> values;
	node_t *left;
	node_t *right;
};

class bst
{
public:
	bst();
	void insert(string value);
	node_t *root;
private:
	void insert(char key, string value, node_t *leaf);
};

#endif // !NODE_H