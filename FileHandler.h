#pragma once
#ifndef FILEHANDLER_H
#define FILEHANDLER_H

#include <iostream>
#include <string>
#include <fstream>
#include <vector>

using namespace std;

void getKeyboardInput(string);
void writeFile(string filename, string text);
string readFile(string filename);

#endif // !FILEHANDLER_H