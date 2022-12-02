#include "myfunction.h"

/**
 * Creates a file.
 *
 * @param	sName	The name.
 *
 * @return	The new file.
 */
ofstream createFile(string sName)
{
	remove(sName.c_str());
	
		ofstream out(sName.c_str(), ios::app);
		if (!out)
		{
			cout<< "Cannot create/open file " << sName << " to save!\n";
			system("Pause");
			exit(1);
		}
		return out;

}

/**
 * read file.
 *
 * @param	sName	string file name.
 *
 * @return	pointer to opened file.
 */
ifstream readFile(string sName)
{
	ifstream in;
	in.open(sName.c_str());
	if (!in)
	{
		cout << "Cannot open file " << sName << " to read!\n";
		system("Pause");
		exit(1);
	}
	return in;

}

/**
 * Saves a file.
 *
 * @param [in,out]	file 	The file.
 * @param 		  	sCont	The container.
 */
void saveFile(ofstream &file, string sCont)
{
	file << sCont;

}

/**
 * Closes a file.
 *
 * @tparam	T	Generic type parameter.
 * @param [in,out]	file	The file.
 */
template <class T>
void closeFile(T &file)
{
	if( file )	file.close();
	
}

/**
 *
 * @ File to tab.
 *
 * @param [in,out]	file		The file.
 * @param [in,out]	iTabSize	Size of the tab.
 *
 * @return	Null if it fails, else a pointer to a long tabs.
 */
long *FileToTab(ifstream &file, int &iTabSize)
{
	file >> iTabSize;
	long *lTab = createNewTab(iTabSize);

	for (int j = 0; j < iTabSize; j++)
	{
		file >> *(lTab + j);
	}
	return lTab;

}

