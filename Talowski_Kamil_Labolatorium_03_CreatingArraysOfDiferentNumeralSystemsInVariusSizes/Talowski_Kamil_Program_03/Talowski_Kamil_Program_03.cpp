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
//funkcja wczytujaca z konsoli liczbe
int load(){
    int number;
    do
	{
		cin>>number;
	} while (number <= 0);
    return number;
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

//funkcja zapisujaca petla wyniki w pliku
void f_write(int length_of_variation, ofstream &save_file, int *t)
{
	for (int i = 0; i<length_of_variation; i++)
	{
		save_file << t[i];
	}
	save_file << endl;
	if (save_file.fail()){
		cout << "Nie udalo sie zapisac!" << endl;
	}
}
//funkcja tworzaca tablice o rozmiarze size i wypelniajaca ja podana waroscia
int *createTable(int Size, int number)
{
	int *t = new int[Size];
	for (int i = 0; i < Size; i++)
	{
		t[i] = number;
	}
	return t;
}
//funkcja zwraca numer indeksu tablicy
int index(int m, int values)
{
	int i = 0;
	while (m % values == 0) {
		i = i + 1;
		m = m / values;
	}
	return i;
}
// Glowny Problem(Algorytm)
//tworzenie tablicy t2 wypelnionej "1"; zapis do pliku
void main_problem(int length_of_variation, int values, int *t, ofstream &save_file) //g³ówny algorytm
{
	int *t2 = createTable(length_of_variation, 1);
	int m = 0;
	int c;
	do {
		f_write(length_of_variation, save_file, t);
		m = m + 1;
		c = index(m, values);
		if (c <= length_of_variation) {
			t[c] = t[c] + t2[c];
			if (t[c] == 0)
				t2[c] = 1;
			if (t[c] == values - 1)
				t2[c] = -1;
		}
	} while (c < length_of_variation);
	delete[] t2;
}
//tworzenie tablicy t wypelnionej "0"
//main_problem- wykonanie glownego algorytmu
int main()
{
    string file_name;
	f_Add_File(file_name);
	ofstream save_file;
	save_file = f_open_save_file(file_name);

	int length_of_variation = load();
	int values = load();
	int *t = createTable(length_of_variation, 0);

	main_problem(length_of_variation, values, t, save_file);

    if (save_file.is_open())
        save_file.close();

    delete[] t;
    cin.get();

	return 0;
}
