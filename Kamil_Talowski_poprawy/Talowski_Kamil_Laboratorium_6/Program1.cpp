#include"Program1.h"


int *f_create_tab(int n)
{
    int *t = nullptr;
	try
	{
		t = new int[n];
    }
	catch (bad_alloc)
	{
		cout << "Wystapil blad podczas tworzenia tablicy";
		getchar();
		exit(0);
	}
	return t;
}

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

void f_write(int z,int *tab, ofstream &save_file)
{
    for (int i = 0; i < z; ++i )
    {
        save_file << tab[i]<<" ";
        if (save_file.fail())
            cout << "Save to file error!" << endl;
    }
    save_file << endl;
}

void Swap ( int* c, int* d )
{
    int t = *c;
    *c = *d;
    *d = t;
}

int Partition (int *tab, int iStart, int iEnd)
{
    int x = tab[iEnd];
    int i = (iStart - 1);

    for (int j = iStart; j <= iEnd- 1; j++)
    {
        if (tab[j] <= x)
        {
            i++;
            Swap (&tab[i], &tab[j]);
        }
    }
    Swap (&tab[i + 1], &tab[iEnd]);
    return (i + 1);
}

void quickSort (int *tab, int iStart, int iEnd)
{
    int *Stack=f_create_tab(iEnd - iStart + 1);
    int up = -1;

    up+=1;
    Stack[up] = iStart;
    up+=1;
    Stack[up] = iEnd;

    while ( up >= 0 )
    {
        // Wyrzuca iStart i iEnd
        iEnd = Stack[up-- ];
        iStart = Stack[up-- ];

        // Ustawia elementy na wlasciwych pozycjach w posortowanej tablicy
        int p = Partition( tab, iStart, iEnd );

        // Jesli sa elementy po lewej stronie osi to ustawia lewy indeks na stosie
        if ( p-1 > iStart )
        {
            up+=1;
            Stack[up] = iStart;
            up+=1;
            Stack[up] = p - 1;
        }

        // Jesli sa elementy po prawej stronie to ustawia prawy indeks na stosie
        if ( p+1 < iEnd )
        {
            up+=1;
            Stack[up] = p + 1;
            up+=1;
            Stack[up] = iEnd;
        }
    }
    delete[] Stack;
}
