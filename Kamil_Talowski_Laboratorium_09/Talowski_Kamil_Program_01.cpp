#include "Program01.h"
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
 * create new array double.
 *
 * @param	iSize	int size of array.
 *
 * @return	pointer to created array.
 */
double *createNewTabDouble(int iSize)
{
	try // probujemy stworzyc nowa tablice
	{ // za pomoca operatora new
		double *T = new double[iSize];
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

vector<int> createNewVectorTab(int size)
{
	try // probujemy stworzyc nowa tablice
	{ // za pomoca operatora new
		vector <int>T(size, 1);
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


void delete2DArray(long ** pTab, int iRows)
	{
		for (int i = 0; i < iRows; i++)
		{
			delete[] pTab[i];
		}
		delete[] pTab;

	}

// Tablica z wagami i cenami.
long ** pTabWithWeight = nullptr;
// Tablica ze stosunkiem ceny do wagi.
double * pTabWithScales = nullptr;

int g_iBestValue,
	g_iElCount,
	g_iBpSize;

string g_sBestPacking;

ofstream ofFileToSave;

int main()
{
	ifstream ifFileToRead = readFile("data.txt");
	ofFileToSave = createFile("OU.txt");
	g_iElCount = readDataFromFIle(ifFileToRead);
	g_iBpSize = readDataFromFIle(ifFileToRead);
	g_iBestValue = 0;

	 pTabWithWeight = createNewTab2D(g_iElCount + 1);
	 pTabWithScales = createNewTabDouble(g_iElCount + 1);

	// Wczytanie z pliku do tablicy, nastepnie ich
	// posortowanie od najwiekszej do najmniejszej
	// wedlug ich wspolczynnika ceny do wagi.
	setArrayWithData(ifFileToRead, pTabWithWeight, pTabWithScales, g_iElCount);
	closeFile(ifFileToRead);
	reverseBubbleSort(pTabWithWeight, pTabWithScales, g_iElCount);

	vector<int> vTabWithResult = createNewVectorTab(g_iElCount + 1);
	Node mainNode;

	// Wywoluje glowna funkcje rekurencyjna.
	knapSack(vTabWithResult, mainNode);

	// Zapisuje nalepsza znaleziona wartosc.
	saveFile(ofFileToSave, "Najlepsza wartosc = " + to_string(g_iBestValue));
	saveFile(ofFileToSave, "\nNajlepsze upakowanie = " + g_sBestPacking);
	// Zamkniecie plikow i czyszczenie pamieci.
	closeFile(ofFileToSave);
	delete2DArray(pTabWithWeight, g_iElCount + 1);
	delete[] pTabWithScales;

	return 0;
}

/**
* @brief	Reads data value.
*
* @param [in,out]	ifFileToRead file to read.
*
* @return	The value, if returned -1 there is no value.
*/
long readDataFromFIle(ifstream & ifFileToRead)
{
	long iValue;
	ifFileToRead >> iValue;
	if (ifFileToRead.good())
	{
		return iValue;
	}
	return -1;
}

/**
* @brief	Sort array with weight and Prize
*           from highest to lowest using scales.
*
* @param [in,out]	ifFileToRead file to read.
*
* @return	The value, if returned -1 there is no value.
*/
void reverseBubbleSort(long ** pTabWithWages, double * pTabWithScale, int iRows)
{
	for (int i = 0; i < iRows; i++)
	{
		for (int j = 1; j < iRows - i; j++)
		{
			if (pTabWithScale[j - 1] < pTabWithScale[j])
			{
				//zamiana miejscami
				swap(pTabWithScale[j - 1], pTabWithScale[j]);
				swap(pTabWithWages[j - 1][0], pTabWithWages[j][0]);
				swap(pTabWithWages[j - 1][1], pTabWithWages[j][1]);
			}
		}
	}
}

/**
* @brief	Set Array With data from file.
*
* @param [in,out]	ifIn            file to read.
* @param [in,out]	pTabWithWeight   An empty array to keep weight and prizes.
* @param [in,out]	pTabWithScales   An empty array to keep scales.
* @param            iRows           Rows quantity.
*/
void setArrayWithData(ifstream & ifIn, long ** pTabWithWeight, double * pTabWithScales, int iRows)
{
	long iWeight, iPrizes;
	double dScale;
	for (int i = 0; i <= iRows; i++)
	{
		*(pTabWithWeight + i) = createNewTab(2);
		iWeight = 0, iPrizes = 0, dScale = 0;

		// Ostanie komorki tablicy przechowuja wartosc 0.
		if (i != iRows)
		{
			iWeight = readDataFromFIle(ifIn);
			iPrizes = readDataFromFIle(ifIn);
			dScale = iPrizes / iWeight;
		}

		// [i][0] Przechowuje wagi, [i][1] zawiera cene.
		pTabWithWeight[i][0] = iWeight;
		pTabWithWeight[i][1] = iPrizes;
		pTabWithScales[i] = dScale;

	}
}

/**
* @brief	Find the best backpack packing.
*
* @param [in,out]	pTab            An Array with weight and prizes.
* @param [in,out]	g_iBestValue      An variable to keep best prize.
* @param [in,out]	pTabWithScales   An array with scales (prize / weight).
* @param            vTabWithResults Tabs with items in actual backpack.
* @param            mainNode        Struct to keep Parent weight, prizes, etc.
* @param            ofFileToSave    File to save data from algoritm.
*/
void knapSack(vector <int> vTabWithResults, Node mainNode)
{

	string sToSave = "";
	bool bPromising;
	// Mamy nowa najlepsza wartosc.
	if (g_iBestValue < mainNode.iProfit && mainNode.iMaxWeight <= g_iBpSize)
	{
		g_iBestValue = mainNode.iProfit;
		keepBestPacking(vTabWithResults, mainNode);

	}

	bPromising = checkPromising(vTabWithResults, mainNode, sToSave);

	// Informacja o wyliczonych wartosciach.
	saveFile(ofFileToSave, sToSave + "\n");

   // Gdy wezel jest obiecujacym i nie jest lisciem
	if (bPromising)
	{
		int iCurrNode = mainNode.iParentNode++;
		Node tempNode = mainNode;


		// Idziemy w lewo (dodajemy element),
		// czyli dodajemy do sumy jego wage
		// oraz profit (zysk).
		mainNode.iMaxWeight += pTabWithWeight[iCurrNode][0];
		mainNode.iProfit += pTabWithWeight[iCurrNode][1];
		knapSack(vTabWithResults, mainNode);

		// Idziemy w prawo (odrzucamy element).
		vTabWithResults[iCurrNode + 1] = 0;
		knapSack(vTabWithResults, tempNode);
	}

}
/**
* @brief	Find the node where max weight will be exceeded.
*
* @param 	        vTabWithResult  Object with element to in backpack.
* @param [in,out]	pTab            An array with weight and prizes.
* @param          mainNode        Struct with element in backpack.
*
* @return The index of element causing overflow/
*/
int findNodeOverflow(vector <int> vTabWithResults, Node mainNode)
{
	int a = 0;

	for (int i = 1; i <= g_iElCount; i++)
	{
		a += vTabWithResults[i] * (pTabWithWeight[i - 1][0]);
		if (a >= g_iBpSize) return i;
	}

	return g_iElCount + 1;

}

/**
* @brief	Sum the weight or prize elements from I +  1 to K - 1.
*
* @param 	        vTabWithResult  Object with element  in backpack.
* @param [in,out]	pTab            An array with weight and prizes.
* @param            iI			    Starting index of sum.
* @param            iK			    Ending   index of sum.
*
* @return The total sum of that element.
*/
int findTotal(vector <int> vTabWithResults, int iI, int iK, bool bPrize)
{
	int iSum = 0;
	for (int j = iI; j < iK - 1; j++)
	{
		iSum += vTabWithResults[j + 1] * (pTabWithWeight[j][bPrize]);
	}
	return iSum;

}

/**
* @brief	Find the bound of the packing
*
* @param 	vTabWithResult  Object with element  in backpack.
* @param    mainNode		Node with weight and profit.
*
* @return The bound of this settings.
*/
double findBound(vector <int> vTabWithResults, Node mainNode)
{
	int iCurrNode = mainNode.iParentNode,
		iWeight = mainNode.iMaxWeight,
		iProfit = mainNode.iProfit,
		iK = findNodeOverflow(vTabWithResults, mainNode),
		iTotalWeight = iWeight + findTotal(vTabWithResults, iCurrNode, iK);
	double iScale = pTabWithScales[iK - 1],
		   dBound = iProfit + findTotal(vTabWithResults, iCurrNode, iK, true);
		   dBound = dBound + (g_iBpSize - iTotalWeight)*iScale;

	return dBound;

}


Node::Node()
{
	iParentNode = 0;
	iProfit = 0;
	iMaxWeight = 0;
}


/**
* @brief	Find the bound of the packing
*
* @param 	vTabWithResult  Object with element  in backpack.
* @param    mainNode		Node with weight and profit.
* @param    sToSave         String with output to file.
*
* @return The node promising.
*/
bool checkPromising(vector <int> vTabWithResults, Node mainNode, string & sToSave)
{
	int &iCurrNode = mainNode.iParentNode,
		&iWeight = mainNode.iMaxWeight,
		&iProfit = mainNode.iProfit;


	// Komunikaty bledow.
	sToSave = " Jestem w wezle na poziomie " +
		to_string(iCurrNode) + ", ";
	string sError = " Wezel Nieobiecujacy: ",
		   sError1 = "waga przedmiotow > plecaka \n",
		   sError2 = "granica < max profit\n";


	// Pierwszy warunek, nie mozemy dodac juz przedmiotow
	if (iWeight >= g_iBpSize)
	{
		sToSave = sToSave + sError + sError1;
		return false;
	}

	double dBound = findBound(vTabWithResults, mainNode);

	// Komunikat do pliku, zeby pokazac dzialanie krok po kroku.
	sToSave = sToSave + " weight = " + to_string(iWeight) + ", profit = " +
		to_string(iProfit) + ", bound = " + to_string(dBound) +
		". bestProfit = " + to_string(g_iBestValue) + "\n";

  // Bound <= MaxProfit
	if (dBound <= g_iBestValue)
	{
		sToSave = sToSave + sError + sError2;
		return false;
	}
	return true;
}

/**
* @brief	Keep the best packing.
*
* @param 	vTabWithResult  Object with element  in backpack.
* @param  mainNode		    Node with weight and profit.
*/
void keepBestPacking(vector <int> vTabWithResults, Node mainNode)
{
	int iSize = static_cast<int>(vTabWithResults.size());
	g_sBestPacking = "";
	for (int i = 1; i <= mainNode.iParentNode ; i++)
	{
		if (vTabWithResults[i])
		{
			g_sBestPacking += to_string(pTabWithWeight[i - 1][1]) + " ";
		}

	}
}
