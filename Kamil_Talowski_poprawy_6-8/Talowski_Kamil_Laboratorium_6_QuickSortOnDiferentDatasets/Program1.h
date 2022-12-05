#ifndef PROGRAM1.H
#define PROGRAM1.H

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
int *f_create_tab(int n);

/**
*funkcja sprawdzajaca czy plik sie dobrze otworzyl
*sprawdzanie czy plik znajduje sie w folderze zwraca true jesli tak
*@param file name string nazwa pliku
*@return true or false
*/
bool f_Open_File(string &file_name);
/**
*funkcja sprawdzajaca czy plik posiada rozszerzenie, wyszukiwanie rozszerzenia
*jezeli w podanej nazwie pliku nie znajduje sie fraza ".txt" to: cond przyjmuje false
*szukanie frazy .txt
*@param txt string nazwa pliku string file_extension rozszerzenie ".txt"
*@return cond rowny true or false
*/
bool f_Find_Extension(string & txt, string file_extension);

/**
*funkcja pobierajaca i sprawdzajaca file_name
*@param file_name string
*@return file_name string nazwa pliku
*/
int f_Add_File(string &file_name);

/**
*funcka zapisujaca zmienna w pliku
*@param z dlugosc tablicy, *tab wskaznik na tablice, save_file ofstream zapis
*@return none
*/
void f_write(int z,int *tab, ofstream &save_file);

/**
*Funkcja zamieniajaca dwa elementy
*@param *c wskaznik na liczbe c, *d wskaznik na liczbe d
*@return *c wkaznik na d, *d wskaznik na c
*/
void Swap ( int* c, int* d );

/**
*Funkcja partition pomocnicza opiera sie na niej quickSort dziel i zwyciezaj
*taka sama jak w rekurencji
*@param *tab wskaznik na tablice, iStart indeks poczatkowy, iEnd indeks koncowy
*@return i+1 zwraca indeks podtablicy
*/
int Partition (int *tab, int iStart, int iEnd);


#endif /* PROGRAM1.H */
