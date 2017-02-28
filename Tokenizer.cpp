
#include "Tokenizer.h"

/*
DESCRIPTION:
	Converts a given string into it's tokenized form, stripped of all white space and separated by word
PARAMETERS:
	text: the string to be tokenized
RETURNS:
	A vector containing all of the tokens
*/
vector<string> tokenize(string text)
{
	stringstream ss(text);
	vector<string> v;
	string buf;

	while (ss >> buf) v.push_back(buf);
	
	return v;
}