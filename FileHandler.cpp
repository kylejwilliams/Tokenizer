
#include "FileHandler.h"

/* 
DESCRIPTION: 
	get input from the keyboard on the command line and write to a file
PARAMETERS:
	filename: desired filename to write the input to
RETURNS:
	NA
*/
void getKeyboardInput(string filename)
{
	ofstream file(filename);
	string buffer;
	
	if (!file.is_open())
	{
		cerr << "error while creating file " << filename << ". Exiting now..." << endl;
		exit(EXIT_FAILURE);
	}
	
	cout << "Begin entering text. Press CTRL+Z and return on a new line when finished:" << endl << "> ";
	while (getline(cin, buffer)) file << buffer << "\n";
	file.close();
}

/*
DESCRIPTION:
	Reads specified file
PARAMETERS:
	filename: file to be read
RETURNS:
	A string containing the contents of a file
*/
string readFile(string filename)
{
	ifstream file(filename);
	string buffer;
	string output;

	if (!file.is_open())
	{
		cerr << "error while opening file. " << filename << ". Exiting now..." << endl;
		exit(EXIT_FAILURE);
	}

	while (getline(file, buffer)) output += (buffer + "\n");
	file.close();

	return output;
}

/*
DESCRIPTION:
	Writes text to a file
PARAMETERS:
	filename: filename to be written to
	text: text that should be written
RETURNS:
	NA
*/
void writeFile(string filename, string text)
{
	ofstream file(filename);

	if (!file.is_open())
	{
		cerr << "error while opening file " << filename << ". Exiting now..." << endl;
		exit(EXIT_FAILURE);
	}

	file << text;
	file.close();
}