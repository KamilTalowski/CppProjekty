#include <iostream>
#include <cstdlib>
#include <string>
#include <fstream>
#include <time.h>

using namespace std;
/**
*Funkcja tworzaca tablice dynamiczna
*@param n dlugosc tablicy
*@return t wskaznik
*/
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
*funcka zapisujaca zmienna w pliku
*@param z dlugosc tablicy, *tab wskaznik na tablice, save_file ofstream zapis
*@return none
*/
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
/**
*Funkcja zamieniajaca dwa elementy
*@param *c wskaznik na liczbe c, *d wskaznik na liczbe d
*@return *c wkaznik na d, *d wskaznik na c
*/
void Swap ( int* c, int* d )
{
    int t = *c;
    *c = *d;
    *d = t;
}
/**
*Funkcja partition pomocnicza opiera sie na niej quickSort dziel i zwyciezaj
*taka sama jak w rekurencji
*@param *tab wskaznik na tablice, iStart indeks poczatkowy, iEnd indeks koncowy
*@return i+1 zwraca indeks podtablicy
*/
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

/**
*Funkcja glowna quickSort iteracyjna korzystajaca z funkcji Partition
* *Stack tablica pomocnicza (stos) i inicjowanie góry stosu
*@param *tab wskaznik na tablice, iStart indeks poczatkowy, iEnd indeks koncowy
*@return *tab zwraca posortowana tablice
*/
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

//Glowny program testujacy algorytm teracyjny quickSort
int main()
{
    int z,n;
    int *tab;
    clock_t t_Start, t_End;
    string file_name;

    fstream ifFile;
    ofstream save_file;

    //wczytanie nazwy pliku z danymi i pliku zapisu
    cout<<"Dla pliku odczytu"<<endl;
    f_Add_File(file_name);
    ifFile.open(file_name.c_str(), ios::in);
    cout<<"Dla pliku zapisu"<<endl;
    f_Add_File(file_name);
    save_file.open(file_name.c_str(), ios::trunc);

    if (ifFile.good() == true && save_file.good() == true)
    {
        ifFile >> z;
        do{
            ifFile >> n;
            tab=f_create_tab(n);

            for(int i=0; i<n; i++)
                ifFile>>tab[i];

            t_Start = clock();
            quickSort( tab, 0, n - 1 );
            t_End = clock();
            long algorithm_time = static_cast<long>(t_End - t_Start);

            f_write(n, tab, save_file);
            cout <<"Czas wykonania quick sort dla "<<n<<" wyniosl: "<< algorithm_time <<" ms"<< endl;

            delete[] tab;
            z--;
        }while(z>0);
    }
    else
        cout<<"Blad otwarcia pliku wejsciowego."<<endl;

    if (ifFile.is_open()) ifFile.close();
    if (save_file.is_open()) save_file.close();

    cin.get();
    return 0;
}
