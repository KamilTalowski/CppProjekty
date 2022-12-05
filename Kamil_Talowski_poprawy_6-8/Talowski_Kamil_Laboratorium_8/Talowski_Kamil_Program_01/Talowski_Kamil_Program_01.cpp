#include "array.cpp"
#include "file.cpp"


int readDataSet(ifstream & ifFile);

string findbp(long*, int, int, int = 0,	int = 0, int = 0, string = "");

void setTabWithData(ifstream & ifFileToRead, long *pTab, int iTabSize);

void printResults(int iBackpackSize, string sBp);

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
