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

/**
 * @brief	Reads data set.
 *
 * @param [in,out]	ifFile	if file.
 *
 * @return	The data set.
 */
int readDataSet(ifstream & ifFile)
{
	int iVal;
	do
	{
		ifFile >> iVal;

	} while ((iVal < 1 || iVal > 1000000) && ifFile.good());

	return iVal;
}

/**
 * @brief	Find first correct packing of the backpack.
 *
 * @param [in,out]	pTab	 	  If non-null, the tab with elements.
 * @param 		  	iBpSize  	  Size of the bp.
 * @param 		  	iIndexMax	  Index of the index maximum.
 * @param 		  	iStartSum	  Index of beginning of the sum.
 * @param 		  	iActualEl     Temporary index of actual element.
 * @param 		  	sum	 		  The sum.
 * @param 		  	Sbackpack	  The sbackpack.
 *
 * @return	A string.
 */
string findbp(long *pTab, int iBpSize, int iIndexMax, int iStartSum,
	int iActualEl, int iSum, string Sbackpack)
{
	// Jesli znaleziono okreslona sume lub zadne liczby nie
	// spelniaja zadanego kryterium to zwroc stosowna informacje.
	if (iSum == iBpSize || iIndexMax == iStartSum)
	{
		return Sbackpack;
	}
	else
	{
		if (iIndexMax == iActualEl)
		{
			return findbp(pTab, iBpSize, iIndexMax,	iStartSum + 1, iStartSum + 1);
		}
		int iThisElement = *(pTab + iActualEl);
		if (iSum + iThisElement <= iBpSize)
		{
			iSum += iThisElement;
			Sbackpack += to_string(iThisElement) + " ";
		}
		return findbp(pTab, iBpSize, iIndexMax, iStartSum,
						iActualEl + 1, iSum, Sbackpack);
	}

}

void setTabWithData(ifstream &ifFileToRead, long *pTab, int iTabSize)
{
	int iTempValue;
	for (int j = 0; j < iTabSize; j++)
	{
		ifFileToRead >> iTempValue;
		*(pTab + j) = iTempValue;
	}

}

void printResults(int iBackpackSize, string sBp)
{
	if (sBp != "")
	{
		cout << iBackpackSize << " = " << sBp << endl;
	}
	else
	{
		cout << "BRAK" << endl;
	}
}

int main()
{

	ifstream ifFileToRead = readFile("data.txt");
	int iDataSetSize = readDataSet(ifFileToRead),
		iBackpackSize, iElementsSize;

	for ( int i = 0; i < iDataSetSize; i++)
	{
		iBackpackSize = readDataSet(ifFileToRead);
		iElementsSize = readDataSet(ifFileToRead);

		long *pElementsWeight = createNewTab(iElementsSize);

		// Wczytujemy dane z pliku do tablicy typu long.
		setTabWithData(ifFileToRead, pElementsWeight, iElementsSize);

		// Glowna funkcja, znajduje pierwsze poprawne rozwiazanie.
		string sBp = findbp(pElementsWeight, iBackpackSize, iElementsSize);

		// Jesli funkcja findbp zwroci niepusty ciag, to znaczy,
		// ze istnieje upakowanie, dla pustego ciagu nie istnieje.
		printResults(iBackpackSize, sBp);

		delete[] pElementsWeight;

	}
	closeFile(ifFileToRead);

	return 0;
}
