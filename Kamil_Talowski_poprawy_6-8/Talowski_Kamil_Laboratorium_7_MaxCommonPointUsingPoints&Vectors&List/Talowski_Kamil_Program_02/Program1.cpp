#include"Program1.h"


bool f_Open_File(string &file_name)
{
	ifstream iffile;
	iffile.open(file_name.c_str());
	if (iffile.is_open())
		return true;
    else
        return false;
}

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

