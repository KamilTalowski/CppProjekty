#ifndef PROGRAM1.H
#define PROGRAM1.H

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <iomanip>
#include <ctime>

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
*funkcja szukajaca maksymalnego wierzcholka
*@param inFile ifstream read file
*@return int Max maximum tip
*/
int findMaxTip(ifstream &inFile);

/**
*funkcja tworzaca tablice dynamiczna
*@param int w lines
*@param int k columns
*@return **t pointer to table
*/
int **f_create_tab(int w, int k);

/**
*funkcja usuwajaca tablice dwuwymiarowa
*/
void f_DeleteTab(int w, int **tab);

/**
*funkcja wypelniajaca tablice dynamiczna incydencjami krawedzi
*@param int **tab
*@return **tab fill with coincidences
*/
void fillArrayPointer(int **tab, ifstream& inFile, int amoutOfEdges, int amountOFTips);

//function saving array in file
void fWriteArrayPointer(int **tab, ofstream outFile, int amoutOfEdges , int amountOFTips);

//function saving vector in file
void fWriteArrayVector(vector<vector<int>> tab, ofstream outFile, int amoutOfEdges, int amountOFTips);

/**
*tworzenie vektora dwuwymiarowego
*@param int amoutOfEdges
*@param int amountOFTips
*@return tab as vector
*/
vector<vector<int>> setVector( ifstream &inFile, int amoutOfEdges, int amountOFTips);

/**
*funkcja wypelniajaca tablice vektorów incydencjami krawedzi
*@param int &tab
*@return tab fill with coincidences
*/
void fillArrayVector(vector<vector<int>> &tab, ifstream& inFile, int amoutOfEdges, int amountOFTips);

/**
*funkcja sprawdzajaca sasiadow dla tablicy dwuwymiarowej
*@param int **tab
*@return **tab fill with neighbors
*/
void checkNeighborPointer(int **tab, ofstream outFile, int amoutOfEdges, int amountOFTips);

void IncydenceArrayPointer();
/**
*funkcja sprawdzajaca sasiadow dla vektora
*@param int *&ab
*@return tab fill with neighbors
*/
void checkNeighborVector(vector<vector<int>> &tab, ofstream outFile, int amoutOfEdges, int amountOFTips);

void IncydenceArrayVector();

#endif /* PROGRAM1.H */
