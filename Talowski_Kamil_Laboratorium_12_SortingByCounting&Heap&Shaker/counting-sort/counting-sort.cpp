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
*Funkcja glówna algorytm Counting-Sort
*@param *tab wskaznik na poczatek tablicy do posortowania
*@return *tabOut wskaznik na poczatek tablicy posortowanej
*/
void countingSort(int *tab, int *tabOut, int n, int maxNum){
    int *temp;
        temp = f_create_tab(maxNum+1);
        int i;
        for (i = 0; i <= maxNum; i++) // zerowanie tablicy pomocniczej
        temp[i] = 0;
        for (i = 0; i < n; i++)
        temp[(tab[i])]++;
        // temp zawiera teraz liczbe wystapien liczby i w ciagu wejsciowym
        for (i = 1; i <= maxNum; i++)
        temp[i] += temp[i-1];
        //  temp zawiera teraz liczbe elementow mniejszych lub rownych i
        for (i = n-1; i >= 0; i--)
        {
        tabOut[(temp[(tab[i])])-1] = tab[i]; // wpisanie do tablicy wynikowej pod określony indeks tab[i]
        temp[(tab[i])]--; // zmniejszenie indeksu temp - odejmujemy wpisana przed chwila liczbe
        }
        delete[] temp;
}
//Glowny program testujacy algorytm Counting-Sort
int main()
{
    int z = 0,n, maxNum=0;
    int *tab, *tabOut;
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
            tabOut=f_create_tab(n);

            for(int i=0; i<n; i++){
                ifFile>>tab[i];
                if (maxNum < tab[i])
                maxNum = tab[i];
            };

            t_Start = clock();
            countingSort( tab, tabOut, n, maxNum );
            t_End = clock();
            long algorithm_time = static_cast<long>(t_End - t_Start);

            f_write(n, tabOut, save_file);
            cout <<"Czas wykonania counting sort dla "<<n<<" wyniosl: "<< algorithm_time <<" ms"<< endl;

            delete[] tab;
            delete[] tabOut;
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
