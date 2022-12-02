#include "myfunction.h"

/**
 * create new array.
 * 
 * @param	iSize	int size of array.
 *
 * @return	pointer to created array.
 */
long *createNewTab(int iSize)
{
	try // probujemy stworzyc nowa tablice
	{ // za pomoca operatora new
		long *T = new long[iSize];
		return T;
	}
	catch (bad_alloc) // jesli nie udalo sie stworzyc
	{ // tablicy z powodu braku wolnej pamieci
		cout << "Brak miejsca na utworzenie tablicy";
		cin.ignore();
		getchar();
		exit(0);
	}
}

/**
 * create new array.
 * 
 * @param	iSize	int size of array.
 *
 * @return	pointer to created array.
 */
long **createNewTab2D(int iSize)
{
	try // probujemy stworzyc nowa tablice
	{ // za pomoca operatora new
		long **T = new long *[iSize];
		return T;
	}
	catch (bad_alloc) // jesli nie udalo sie stworzyc
	{ // tablicy z powodu braku wolnej pamieci
		cout << "Brak miejsca na utworzenie tablicy";
		cin.ignore();
		getchar();
		exit(0);
	}
}

vector <vector<long>> createNewVector2D(int iSize, int iSize2)
{
	try // probujemy stworzyc nowa tablice
	{ // za pomoca operatora new
		vector <vector<long>>T(iSize, vector<long>(iSize2,0));
		return T;
	}
	catch (bad_alloc) // jesli nie udalo sie stworzyc
	{ // tablicy z powodu braku wolnej pamieci
		cout << "Brak miejsca na utworzenie tablicy";
		cin.ignore();
		getchar();
		exit(0);
	}
}

vector<string> createNewVectorTab()
{
	try // probujemy stworzyc nowa tablice
	{ // za pomoca operatora new
		vector <string>T;
		return T;
	}
	catch (bad_alloc) // jesli nie udalo sie stworzyc
	{ // tablicy z powodu braku wolnej pamieci
		cout << "Brak miejsca na utworzenie tablicy";
		cin.ignore();
		getchar();
		exit(0);
	}
}
/**
 * Reverse tab.
 *
 * @param [in,out]	tabWithEl	If non-null, the tab with el.
 * @param 		  	tabSize  	Size of the tab.
 */
void reverseTab(long *tabWithEl, int tabSize)
{
	int i = 0, j = tabSize - 1;

	while (i < j)
	{
		swap(*(tabWithEl + i), *(tabWithEl+ j));
		i++;
		j--;
	}
}

/**
 * 	Print tab.
 *
 * @param [in,out]	iTab		If non-null, zero-based index of the tab.
 * @param 		  	iTabSize	size of the Tab.
 * @param 		  	cSep		The separator.
 */
void printTab(long *pTab, int iTabSize, const char cSep[])
{
	for (int i = 0; i < iTabSize; i++)
	{
		if (i == iTabSize - 1) cSep = "";
		cout << *(pTab + i) << cSep;
	}
	cout << endl;

}

/**
 * convert tab values to one string.
 *
 * @param [in,out]	pTab		If non-null, the tab.
 * @param 		  	iTabSize	Tab size.
 * @param 		  	cSep		delimiter.
 *
 * @return	out merged string containing all digit.
 */
string tabToString(long *pTab, int iTabSize, const char cSep[])
{
	string out ="" ;
	for (int i = 0; i < iTabSize; i++)
	{
		if (i == iTabSize - 1) cSep = "\n";
		out += to_string(*(pTab + i));
		out += cSep;
	}
	return out;

}
/**
 * Fill tab.
 *
 * @param [in,out]	pTab		If non-null, the tab.
 * @param 		  	iTabSize	Size of the tab.
 *
 * @return	Null if it fails, else a pointer to a long.
 */
long *fillTab(long *pTab, int iTabSize)
{
	for (int k = 0; k < iTabSize; k++)
	{
		*(pTab + k) = k + 1;
	}
	return pTab;
}


