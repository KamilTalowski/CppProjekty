#include <iostream>
#include <fstream>
#include <string>


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
// funkcja ustalajaca ilosc permutacji, liczy silnie z n!
int number_of_permutations(int length_of_permutations)
{
	int number_of_permutations = 1;
	for (int i = 1; i <= length_of_permutations; i++)
	{
		number_of_permutations = number_of_permutations*i;
	}
	return number_of_permutations;
}
//funkcja zapisujaca wyniki w pliku
//petla zapisujaca kolejne elementy tablicy w pliku
//sprawdzanie czy element zostal zapisany
void f_write(int length_of_permutations, ofstream &save_file, int *permutation)
{
	for (int x = 0; x<length_of_permutations; x++)
	{
		save_file << permutation[x];
	}
	save_file << endl;
	if (save_file.fail())
		cout << "Save file error!" << endl;
}
//m- zmienna pomocnicza; permutation[k] = k; - ciag wyjsciowy w nat. kolejnosci
int main()
{
	string file_name;
	f_Add_File(file_name);
    ofstream save_file;
	int size_of_permutation = length_of_permutations();
	int number_of_permutation = number_of_permutations(size_of_permutation);
	int *combination = new int[size_of_permutation - 1];
	int *permutation = new int[size_of_permutation];

	save_file = f_open_save_file(file_name);

	for (int l = 0; l < number_of_permutation; l++)
	{
		int m = l;
		for (int k = 2; k <= size_of_permutation; k++)
		{
			combination[k - 2] = m%k;
			m = m / k;
		}
		for (int k = 0; k < size_of_permutation; k++)
			{
			permutation[k] = k;
			}
		for (int k = size_of_permutation; k >= 2; k--)
		{
			int j = combination[k - 2];
			swap(permutation[j], permutation[k - 1]); //zamiana elementow tablicy
		}
		f_write(size_of_permutation, save_file, permutation);
	}

	delete[] combination, permutation;

    // zamykanie pliku jeœli jest otwarty
	if (save_file.is_open())
		save_file.close();

    cin.get();
	return 0;
}
