#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;

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
//tworzenie klasy data
class data
{
public:
	int number;
	data*next;
	data()
	{
		next = NULL;
	}
};
/**
*tworzenie klasy list, definiowanie pierwszego elementu
*/
class List
{
public:
	List()
	{
		head = NULL;
	}
	data*head;
	void Add(int a)
	{

		data*New = new data;
		New->number = a;
		if (head == NULL)
		{
			head = New;
		}
		else
		{
			data*temp = head;
			while (temp->next)
			{
				temp = temp->next;
			}
			temp->next = New;
			New->next = NULL;
		}
}
/**
*funkcja zapisujaca listy
*@param ofstream outFile write to file
*/
void fWrite(ofstream& outFile)
{
    data*temp = head;
    while (temp)
		{
			outFile << temp->number;
			outFile << " ";
			temp = temp->next;
		}
}
/**
*kod liczacy stopien pojedynczego wierzcholka
*@return int i as grade of tip
*/
int Count()
{
    int i = 0;
    data*temp = head;
		while (temp)
		{
			i++;
			temp = temp->next;
		}
		return i;
	}

};
/**
*funkcja szukajaca maksymalnego wierzcholka
*@param inFile ifstream read file
*@return int Max maximum tip
*/
int fFindMaxTip(ifstream &inFile)
{

	int max;
	inFile >> max;
	int temp;
	while (!inFile.eof())
	{
		inFile >> temp;
		if (temp > max)
			max = temp;

	}
	inFile.seekg(0, std::ios::beg);
	inFile.seekg(1, std::ios::cur);
	return max;

}
/**
*funkcja wypelniajaca liste
*@param List *tab table of lists
*@param ifstream &inFile
*@return List *tab fill with edges
*/
void fillList(List* tab, ifstream &inFile)
{
	int va, vb;
	while (!inFile.eof())
	{
		we >> va >> vb;
		tab[va - 1].Add(vb);
		tab[vb - 1].Add(va);

	}
}
// saving to file
void fWriteTab(List* tab, ofstream& outFile, int amoutOfEdges)
{
	for (int i = 0;i < amoutOfEdges-1;i++)
	{
		tab[i].fWrite(outFile);
		outFile << endl;
		outFile << endl;
	}
}
void checkGradeOfTips(List* tab, ofstream& outFile, int n)
{
	for (int j = 0;j < n;j++)
	{
		outFile<<tab[j].Count();
		outFile << endl;
	}
}

int main()
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

	int n = fFindMaxTip(inFile);

	lista *tab = new lista[n];
	fillList(tab, inFile);
	fWriteTab(tab, outFile, amoutOfEdges);
	checkGradeOfTips(tab, outFile, n);

	if (inFile.is_open()) inFile.close();
    if (outFile.is_open()) outFile.close();

    get.cin(0);
    return 0;
}

