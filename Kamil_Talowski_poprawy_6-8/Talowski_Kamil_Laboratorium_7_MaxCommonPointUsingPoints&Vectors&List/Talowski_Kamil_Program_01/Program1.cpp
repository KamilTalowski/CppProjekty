#include"Program1.h"

/**
*funkcja sprawdzajaca czy plik sie dobrze otworzyl
*sprawdzanie czy plik znajduje sie w folderze zwraca true jesli tak
*@param file name string nazwa pliku
*@return true or false
*/
bool f_Open_File(string &file_name)
{
	ifstream iffile;
	iffile.open(file_name.c_str());
	if (iffile.is_open())
		return true;
    else
        return false;
}
/**
*funkcja sprawdzajaca czy plik posiada rozszerzenie, wyszukiwanie rozszerzenia
*jezeli w podanej nazwie pliku nie znajduje sie fraza ".txt" to: cond przyjmuje false
*szukanie frazy .txt
*@param txt string nazwa pliku string file_extension rozszerzenie ".txt"
*@return cond rowny true or false
*/
bool f_Find_Extension(string & txt, string file_extension)
{
	bool cond;
	cond = true;
	size_t found_position = txt.find(file_extension);
	if (found_position == string::npos)
	{
		cond = false;
	}
	do
	{
		found_position = txt.find(file_extension, found_position + file_extension.size());
	} while (found_position != string::npos);
	return cond;
}
/**
*funkcja pobierajaca i sprawdzajaca file_name
*@param file_name string
*@return file_name string nazwa pliku
*/
int f_Add_File(string &file_name)
{
    bool check, open;
	cout << "Podaj nazwe pliku: "<<endl;
	do
	{
		cin >> file_name;
		check = f_Find_Extension(file_name, ".txt");
		if (!check)
		{
			file_name = file_name + ".txt";
		}
		//sprawdzanie czy istnieje nowy plik z rozszerzeniem
		//jesli plik nie istnieje: informuje o bledzie
		open = f_Open_File(file_name);
		if (!open)
		{
			cout << "Niepoprawna nazwa pliku." << endl;
		}
	} while (!open);
}
/**
*funkcja szukajaca maksymalnego wierzcholka
*@param inFile ifstream read file
*@return int Max maximum tip
*/
int findMaxTip(ifstream &inFile)
{

	int Max;
	inFile >> Max;
	int temp;
	while (!inFile.eof())
	{
		inFile >> temp;
		if (temp > Max)
			Max = temp;
	}
	inFile.seekg(0, std::ios::beg);
	inFile.seekg(1, std::ios::cur);
	return Max;

}
/**
*funkcja tworzaca tablice dynamiczna
*@param int w lines
*@param int k columns
*@return **t pointer to table
*/
int **f_create_tab(int w, int k)
{
	int i;
	int **t = NULL;
	try
	{
		t = new int*[w];
	}
	catch (bad_alloc)
	{
		cout << "Not enought space to create table.";
		getchar();
		cin.ignore();
		exit(0);
	}

	for (i = 0; i<w; i++)
		try
	{
		t[i] = new int[k]();
	}
	catch (bad_alloc)
	{
		cout << "Not enought space to create table.";
		getchar();
		cin.ignore();
		exit(0);
	}
	return t;
}
/**
*funkcja usuwajaca tablice dwuwymiarowa
*/
void f_DeleteTab(int w, int **tab)
{
	for (int i = 0; i<w; i++)
		delete[] tab[i];

	delete[] tab;
}
/**
*funkcja wypelniajaca tablice dynamiczna incydencjami krawedzi
*@param int **tab
*@return **tab fill with coincidences
*/
void fillArrayPointer(int **tab, ifstream& inFile, int amoutOfEdges, int amountOFTips)
{
	inFile.seekg(0, std::ios::beg);
	inFile.seekg(1, std::ios::cur);
	// na wszelki wypadek
	int numberOfEdge = 0;
	int tipIn;
	int tipOut;
	while (!inFile.eof())
	{

		inFile >> tipIn >> tipOut;
		cout << tipIn << " " << tipOut;
		tab[tipIn-1][numberOfEdge] = 1;
		tab[tipOut-1][numberOfEdge] = -1;
		numberOfEdge++;
	}

}
//function saving array in file
void fWriteArrayPointer(int **tab, ofstream outFile, int amoutOfEdges , int amountOFTips)
{
	for (int i = 0; i < amountOFTips; i++)
	{
		for (int j = 0;j < amoutOfEdges;j++)
			outFile<<setw(5)<< tab[i][j] << " ";
		outFile << endl;
		outFile << endl;
	}
}
//function saving vector in file
void fWriteArrayVector(vector<vector<int>> tab, ofstream outFile, int amoutOfEdges, int amountOFTips)
{
	for (int i = 0; i < amountOFTips; i++)
	{
		for (int j = 0;j < amoutOfEdges;j++)
			outFile << tab[i][j] << " ";
		outFile << endl;
		outFile << endl;
	}
}
/**
*tworzenie vektora dwuwymiarowego
*@param int amoutOfEdges
*@param int amountOFTips
*@return tab as vector
*/
vector<vector<int>> setVector( ifstream &inFile, int amoutOfEdges, int amountOFTips)
{
	vector<vector<int>>tab(amountOFTips);
	for (int i = 0; i < amountOFTips; i++)
	{
		tab[i] = vector<int>(amoutOfEdges);
	}
	for (int i = 0; i < amountOFTips; i++)
	{
		for (int j = 0;j < amoutOfEdges;j++)
			tab[i][j] = 0;
	}

	return  tab;
}
/**
*funkcja wypelniajaca tablice vektorów incydencjami krawedzi
*@param int &tab
*@return tab fill with coincidences
*/
void fillArrayVector(vector<vector<int>> &tab, ifstream& inFile, int amoutOfEdges, int amountOFTips)
{
	inFile.seekg(0, std::ios::beg);
	inFile.seekg(1, std::ios::cur);
	// na wszelki wypadek
	int numberOfEdge = 0;
	int tipIn;
	int tipOut;
	while (!inFile.eof())
	{

		inFile >> tipIn >> tipOut;

		tab[tipIn - 1][numberOfEdge] = 1;
		tab[tipOut - 1][numberOfEdge] = -1;
		numberOfEdge++;
	}

}
/**
*funkcja sprawdzajaca sasiadow dla tablicy dwuwymiarowej
*@param int **tab
*@return **tab fill with neighbors
*/
void checkNeighborPointer(int **tab, ofstream outFile, int amoutOfEdges, int amountOFTips)
{
	for (int i = 0;i < amountOFTips;i++)
	{
		outFile << "Neighbors " << i+1 << " : ";

		for (int j = 0;j < amoutOfEdges;j++)
		{
			if (tab[i][j] ==1)
				for (int k = 0;k < amoutOfEdges;k++)
				{
					if (tab[k][j] == -1)
					{
						outFile << k+1<< " ";

						break;
					}
				}

		}
		outFile << endl;
		outFile << endl;
	}
}
void IncydenceArrayPointer()
{
	string file_name;
	fstream inFile;
    ofstream outFile;

    cout<<"Dla pliku odczytu"<<endl;
    f_Add_File(file_name);
    inFile.open(file_name.c_str(), ios::in);
    cout<<"Dla pliku zapisu"<<endl;
    f_Add_File(file_name);
    outFile.open(file_name.c_str(), ios::trunc);

	int amoutOfEdges;
	inFile >> amoutOfEdges;
	int amountOFTips = findMaxTip(inFile);
	int **tab = f_create_tab(amountOFTips, amoutOfEdges);
	fillArrayPointer(tab, inFile, amoutOfEdges, amountOFTips);
	fWriteArrayPointer(tab, outFile, amoutOfEdges, amountOFTips);
	checkNeighborPointer(tab, outFile, amoutOfEdges, amountOFTips);
	f_DeleteTab();

}
/**
*funkcja sprawdzajaca sasiadow dla vektora
*@param int *&ab
*@return tab fill with neighbors
*/
void checkNeighborVector(vector<vector<int>> &tab, ofstream outFile, int amoutOfEdges, int amountOFTips)
{
	for (int i = 0;i < amountOFTips;i++)
	{
		outFile << "Neighbors " << i + 1 << " : ";

		for (int j = 0;j < amoutOfEdges;j++)
		{
			if (tab[i][j] == 1)
				for (int k = 0;k < amoutOfEdges;k++)
				{
					if (tab[k][j] == -1)
					{
						outFile <<setw(5)<< k + 1 << " ";

						break;
					}
				}

		}
		outFile << endl;
		outFile << endl;
	}
}
void IncydenceArrayVector()
{
	string file_name;
	fstream inFile;
    ofstream outFile;

    cout<<"Dla pliku odczytu"<<endl;
    f_Add_File(file_name);
    inFile.open(file_name.c_str(), ios::in);
    cout<<"Dla pliku zapisu"<<endl;
    f_Add_File(file_name);
    outFile.open(file_name.c_str(), ios::trunc);

	int amoutOfEdges;
	inFile >> amoutOfEdges;
	int amountOFTips = findMaxTip(inFile);
	vector<vector<int>> tab = setVector(inFile, amoutOfEdges, amountOFTips);
	fillArrayVector(tab, inFile, amoutOfEdges, amountOFTips);
	fWriteArrayVector(tab, outFile, amoutOfEdges, amountOFTips);

}
