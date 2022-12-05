#include "array.cpp"
#include "file.cpp"
#include <iomanip>
#define vector2D vector<vector<long>>
#define vector1D vector<string>

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

void fillTabData(vector2D & vTabWithVal, vector1D & vTabWithNames, ifstream & ifFileToRead)
{
	int iVal1, iVal2;
	string sName;
	ifFileToRead >> sName;
	ifFileToRead >> iVal1;
	ifFileToRead >> iVal2;

	do
	{
		// Tworzy nowy wiersz i kolumny w obiekcie typu vector
		// oraz wypelnia ja danymi z pliku.
		vector <long> vnewColumn;
		vnewColumn.push_back(iVal1);
		vnewColumn.push_back(iVal2);
		vTabWithVal.push_back(vnewColumn);
		vTabWithNames.push_back(sName);

		// Wczytuje kolejna linijke z pliku,
		// jesli sie nie powiedzie, petla sie przerywa.
		ifFileToRead >> sName;
		ifFileToRead >> iVal1;
		ifFileToRead >> iVal2;

	} while (ifFileToRead.good());

}

long max(long a, long b) { return (a > b) ? a : b; }

/**
* @brief	Set array elemenets with 0 and create Columns.
*
* @param [in,out]	pTab         Array to process.
* @param			iRows        Array rows.
* @param			iColumns     Array columns.
*/
void setTab(long ** pTab, int iRows, int iColumns)
{
	for (int i = 0; i < iRows + 1; i++)
	{
		*(pTab + i) = createNewTab(iColumns + 1);
		fill(*(pTab + i), *(pTab + i) + iColumns + 1, 0);
	}
}
/**
* @brief	Print Tab 2D.
*
* @param [in,out]	pTabP       Array with best prize.
* @param [in,out]	pTabQ       Array with best weight.
* @param			iTabSize    Array rows.
* @param			iBpSize     Array columns.
* @param			vTabWithel  Object with data.
*/
void fillTabPandQ(long ** pTabP, long ** pTabQ, int iTabSize,
				  int iBackpackSize, vector2D vTabWithEl)
{

	int ipPrize, ipWeight, iMax1;
	for (int i = 1; i <= iTabSize; i++)
	{
		for (int w = 1; w <= iBackpackSize; w++)
		{
			ipPrize = vTabWithEl[i - 1][1];
			ipWeight = vTabWithEl[i - 1][0];

			// Pakowanie do wiersza tylko jednego elementu,
			// ktory moze wystepowac wiele razy.
			pTabP[i][w] = (w / ipWeight)*ipPrize;

			if (ipWeight <= w)
			{
				// Sprawdzenie, czy nowe upakowanie jest drozsze od
				// upakowania w poprzednim wierszu (tej samej kolumnie).
				iMax1 = max(ipPrize + pTabP[i - 1][w - ipWeight], pTabP[i - 1][w]);

				// Komorka tablicy bedzie zawierala albo poprzednie wyliczenie
				// iMax1 albo wielokrotne upakowanie tego samego elementu.
				pTabP[i][w] = max(iMax1, pTabP[i][w]);


			}
			else
			{
				// Jesli nowy przedmiot nie miesci sie w plecaku, to
				// od razu bierzemy wartosc z poprzedniego wiersza.
				pTabP[i][w] = pTabP[i - 1][w];

			}
			// Jesli stworzono nowe upakowanie, to aktualizujemy ostatni
			// przedmiot zapakowany do plecaka, w przeciwnym wypadku bierzemy
			// wartosc z porzedniego wiersza.
			pTabQ[i][w] = (pTabP[i][w] == pTabP[i - 1][w]) ? pTabQ[i - 1][w] : i;
		}
	}
}
/**
* @brief	Print Tab 2D.
*
* @param [in,out]	pTab      Array with data.
* @param			iRows     Array rows.
* @param			iColumns  Array columns.
*/
void printTab(long ** pTab, int iRows, int iColumns)
{
	// Liczy ilosc cyfr w najwiekszej wartosci, by
	// wyswietlic w czytelny sposob.
	int iSizeMax = checkWidth(pTab[iRows][iColumns]);

	for (int i = 0; i <= iRows; i++)
	{
		for (int j = 0; j <= iColumns; j++)
		{
			cout << setw(iSizeMax) <<  pTab[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;

}

/**
* @brief Free up memory allocated for Array.
*
* @param [in,out]	pTab	  2D Array.
* @param            iTabSize  Rows Count.
*/
void removeArray2D(long **pTab, int iTabSize)
{
	for (int i = 0; i < iTabSize; ++i)
		delete[] pTab[i];

	delete[] pTab;
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

void printResults(long ** pTabP, long ** pTabQ, vector2D vTabWithEl,
					vector1D vTabWithNames, int iBackpackSize, int iTabSize)
{
	// Najdrozsze upakowanie to ostatni element tablicy.
	cout << "Najdrozsze upakowanie plecaka [zl]:" << pTabP[iTabSize][iBackpackSize];
	cout << "\n Upakowane elementy:|";

	int iLeft = iTabSize, iRight = iBackpackSize, iQValueWeight;
	// Upakowanie elementy czytamy od ostatnie komorki tablicy,
	// odejmujac od aktualnej kolumny jednostki miarowe upakowanego
	// elementu, konczymy, gdy wartosc tablicy wyniesie 0
	// bedzie to oznaczalo koniec upakowania.
	if (pTabQ[iLeft][iRight] != 0)
	{
		do
		{
			iQValueWeight = pTabQ[iLeft][iRight];
			cout << vTabWithNames[iQValueWeight - 1] << "|";
			iRight -= vTabWithEl[iQValueWeight - 1][0];


		} while (pTabQ[iLeft][iRight]);
	}
	else
	{
		cout << "BRAK";
	}
}

/**
* @brief	count the digit size.
*
* @param iValue  An long to process.
*
* @return	The width of digit.
*/
int checkWidth(long iValue)
{

	return (int)log10(iValue) + 1;


}

int main()
{

	ifstream ifFileToRead = readFile("data2.txt");
	int iBackpackSize = readDataSet(ifFileToRead), iTabSize;
	vector2D vTabWithEl= createNewVector2D(0, 0);
	vector1D vTabWithNames = createNewVectorTab();

	// Wypelnienie tablicy danymi z pliku tekstowego.
	fillTabData(vTabWithEl, vTabWithNames, ifFileToRead);

	 iTabSize = vTabWithEl.size();

	 long ** pTabP = createNewTab2D(iTabSize + 1),
		  ** pTabQ = createNewTab2D(iTabSize + 1);

	 // Wypelnienie tablicy p i Q wedlug algorytmu.
	 setTab(pTabP, iTabSize, iBackpackSize);
	 setTab(pTabQ, iTabSize, iBackpackSize);
	 fillTabPandQ(pTabP, pTabQ, iTabSize, iBackpackSize, vTabWithEl);

	 // Wyswietlenie tablicy P i Q.
	 printTab(pTabP, iTabSize, iBackpackSize);
	 printTab(pTabQ, iTabSize, iBackpackSize);

	 // Wyswietlenie upakowanych rzeczy i ceny.
	 printResults(pTabP, pTabQ, vTabWithEl, vTabWithNames, iBackpackSize, iTabSize);


	 // Zwolnienie pamieci i zamkniecie pliku do odczytu.
	 removeArray2D(pTabP, iTabSize);
	 removeArray2D(pTabQ, iTabSize);
	 closeFile(ifFileToRead);

	return 0;
}
