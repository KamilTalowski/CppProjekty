// Kamil Talowski wyszukiwanie binarne
#include <iostream>
#include <fstream>
#include <string>
#include <math.h>

using namespace std;
//funkcja sprawdzajaca czy plik sie dobrze otworzyl
//sprawdzanie czy plik znajduje sie w folderze zwraca true jesli tak
bool f_Open_File(string &file_name)
{
	ifstream iffile;
	iffile.open(file_name.c_str());
	if (iffile.is_open())
		return true;
    else
        return false;
}

//funkcja sprawdzajaca czy plik posiada rozszerzenie, wyszukiwanie rozszerzenia
//jezeli w podanej nazwie pliku nie znajduje sie fraza ".txt" to: cond przyjmuje false
//szukanie frazy .txt
//zwraca cond
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
// funkcja pobierajaca i sprawdzajaca file_name
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

// Wejście: int iStart = 0, Mid = 0; indeks poczatkowy i srodkowy podtablicy
// int iEnd = N -1; indeks koñcowy podtablicy mniejszy o jeden
//jestli indeks staryowy jest wiekszy od end: to przerwij pętle
//wyznaczenie srodka podtablicy
//jesli nasza szukana Numer jest rowna wartosci srodka tablicy to sumuje ilosc jej wystapien
//jesli wartosc srodka jest mniejsza to przesuwa indeks poczatkowy tablicy jesœli mniejsza to indeks koncowy
//wykonuje do liczby krokow potrzebnej dla wyszukiwania binarnego
//Zwraca: ilosc wystąpień
int f_AmountOfNumberIteration(long int *tab, int N, long int Number, int Steps, int &AmountOfNumber){
    int iStart = 0, Mid = 0;
    int iEnd = N -1;
#pragma region Main Loop
    do {
        if(iStart > iEnd)
            break;

        Mid = (iStart + iEnd) /2;
        if(tab[Mid] == Number)
        {
            AmountOfNumber++;
            for(int i = Mid +1; (i <= iEnd)&(tab[i] == Number); i++)
                AmountOfNumber++;
            for(int i = Mid-1; (i >= iStart)&(tab[i] == Number); i--)
                AmountOfNumber++;
            break;
    }
        if (tab[Mid] < Number)
            iStart = Mid +1;
        else
            iEnd = Mid -1;

        Steps--;

    }while(Steps > 0);
#pragma endregion

    return AmountOfNumber;
}
//funkcja zapisujaca wyniki do file_name, dopisanie i zamkniecie pliku
    int f_Write_To_File(long int &Number, int &AmountOfNumber, string &file_name)
{
        ofstream ofFile;
        ofFile.open(file_name.c_str(), ios::app);
        if (ofFile.good() == true)
        {
            ofFile << endl;
            ofFile << Number << " " << AmountOfNumber;
            ofFile.close();
        }
        else
		return 0;
}
int main()
{   //Definiowanie potrzebnych zmiennych
    int z = 0, Steps = 0, N = 1000000, N2 = 10000;
    long int Number = 0;
    long int * tab = new long int[N];
    long int * numberstab = new long int[N2];
    double RunTime;
    string file_name;
    f_Add_File(file_name);
// wczytanie danych: z- ilosc zestawow; N- wielkosc tablicy w pliku; tab-wypelnienie posortowanej tablicy z pliku;
//N2 - ilosc sprawdzanych liczb. Steps - licczba krokow dla wyszukiwani binarnego
#pragma region Main Code

    fstream ifFile;
    ifFile.open(file_name.c_str(), ios::in);
    if (ifFile.good() == true)
    {
        ifFile >> z;

    while(z > 0){

        ifFile >> N;
        for(int i = 0; i < N; i++){
            ifFile >> tab[i];
        }
        ifFile >> N2;
        for(int i = 0; i < N2; i++){
            ifFile >> numberstab[i];
        }

        Steps = ceil(log2(N));
        for(int i = 0; i < N2; i++){
            int AmountOfNumber = 0;
            Number = numberstab[i];
            f_AmountOfNumberIteration(tab, N, Number, Steps, AmountOfNumber);
            f_Write_To_File(Number, AmountOfNumber, file_name);
        }

    z--;
    }
    delete [] tab, numberstab;
    }
    else
        cout<<"Blad otwarcia pliku wejsciowego."<<endl;
#pragma endregion
    cin.get();
    return 0;
}
