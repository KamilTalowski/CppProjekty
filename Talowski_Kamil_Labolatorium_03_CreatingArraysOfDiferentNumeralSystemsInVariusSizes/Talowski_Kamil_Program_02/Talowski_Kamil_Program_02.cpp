#include <iostream>
#include <fstream>
#include<string>

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
// funkcja otwierajaca plik przed zapisywaniem w nim
ofstream f_open_save_file(string file_name)
{
    ofstream ofFile;

        ofFile.open(file_name.c_str(), ios::trunc);
        if (ofFile.good() == true);
        else cout << "Error creating output file" << endl;

	return ofFile;
}
// funkcja pobierajaca dlugosc permutacji z konsoli
int length_of_permutations()
{
	int length_of_permutations;
	do
	{
		cin >> length_of_permutations;
	} while (length_of_permutations <= 0 || cin.fail());
	return length_of_permutations;

}
// funkcja odwracajaca tablice
void invert_m(int length_of_permutations, int *t)
{
	int i = 0, j = length_of_permutations;
	while (i<j)
	{
		swap(t[i], t[j]); //zamiana wartosci tabicy
		i = i + 1;
		j = j - 1;
	}
}
//funkcja zapisujaca wyniki w pliku
void f_write(int z, ofstream &save_file, int *t)
{
	for (int i = 0; i<z; i++)
	{
		save_file << t[i];

	}
	save_file << endl;
	if (save_file.fail()) // sprawdzanie czy element zostal zapisany
		cout << "Save to file error!" << endl;

}
// Główna funkcja
//(length_of_permutations == 0) a nie jeden jak w zadaniu bo tablica jest uzupelniana od 0
void main_function(int length_of_permutations, int *t, int z, ofstream &save_file)
{
	if (length_of_permutations == 0)
	{
		f_write(z, save_file, t);
	}
	else {
		for (int i = 0; i <= length_of_permutations; i++)
		{
		    // wykorzystanie rekurencji
			main_function(length_of_permutations - 1, t, z, save_file);
			if (i < length_of_permutations)
			{
				swap(t[i], t[length_of_permutations]);
				invert_m(length_of_permutations - 1, t);
			}
		}

	}
}

int main()
{
	string file_name;
	f_Add_File(file_name);
	ofstream save_file;
	save_file = f_open_save_file(file_name);

	int N = length_of_permutations();
	int z = N;

	int *t = new int[N];
	for (int i = 0; i < N; i++)
	{
		t[i] = i + 1;
	}
	main_function(N-1, t, z, save_file);

    // zamykanie pliku zapisu
    if (save_file.is_open())
    save_file.close();

    delete[] t;

    cin.get();
	return 0;
}
