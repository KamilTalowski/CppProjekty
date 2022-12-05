#ifndef PROGRAM1.H
#define PROGRAM1.H

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
*funkcja zapisujaca listy
*@param ofstream outFile write to file
*/
void fWrite(ofstream& outFile);

/**
*kod liczacy stopien pojedynczego wierzcholka
*@return int i as grade of tip
*/
int Count();

/**
*funkcja szukajaca maksymalnego wierzcholka
*@param inFile ifstream read file
*@return int Max maximum tip
*/
int fFindMaxTip(ifstream &inFile);

/**
*funkcja wypelniajaca liste
*@param List *tab table of lists
*@param ifstream &inFile
*@return List *tab fill with edges
*/
void fillList(List* tab, ifstream &inFile);

// saving to file
void fWriteTab(List* tab, ofstream& outFile, int amoutOfEdges);

void checkGradeOfTips(List* tab, ofstream& outFile, int n);

#endif /* PROGRAM1.H */
