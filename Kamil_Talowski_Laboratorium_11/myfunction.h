#ifndef  myfunction
#define myfunction

#include <vector>
#include <ctime>
#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include <sstream>
#include <algorithm>
using namespace std;

// TABS
long *createNewTab(int size);
double *createNewTabDouble(int iSize);
long **createNewTab2D(int size);
vector <vector<long>> createNewVector2D(int iSize, int iSize2);
vector <int> createNewVectorTab(int iValue);
void printTab(long *lTab, int iSize, const char cSep[]);
string tabToString(long *lTab, int iSize, const char cSep[]);
long * fillTab(long *pTab, int iTabSize);
void delete2DArray(long ** pTab, int iRows);

// FILES
ofstream createFile(string sName);
ifstream readFile(string sName);
void saveFile(ofstream &file, string cont);
template <class T>
void closeFile(T &file);
long *FileToTab(ifstream &file, int &iTabSize);


#endif // ! myfunction