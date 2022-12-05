#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <Program1.h>

using namespace std;

//tworzenie klasy data
class data
{
public:
	int number;
	data*next;
	data()
	{
		next = NULL;
	}
};
/**
*tworzenie klasy list, definiowanie pierwszego elementu
*/
class List
{
public:
	List()
	{
		head = NULL;
	}
	data*head;
	void Add(int a)
	{

		data*New = new data;
		New->number = a;
		if (head == NULL)
		{
			head = New;
		}
		else
		{
			data*temp = head;
			while (temp->next)
			{
				temp = temp->next;
			}
			temp->next = New;
			New->next = NULL;
		}
}

int main()
{
	string file_name;
	fstream inFile;
    ofstream outFile;

    cout<<"Dla pliku odczytu"<<endl;
    f_Add_File(file_name);
    inFile.open(file_name.c_str(), ios::in);
    cout<<"Dla pliku zapisu"<<endl;
    f_Add_File(file_name);
    outFile.open(file_name.c_str(), ios::trunc);

	int amoutOfEdges;
	inFile >> amoutOfEdges;

	int n = fFindMaxTip(inFile);

	lista *tab = new lista[n];
	fillList(tab, inFile);
	fWriteTab(tab, outFile, amoutOfEdges);
	checkGradeOfTips(tab, outFile, n);

	if (inFile.is_open()) inFile.close();
    if (outFile.is_open()) outFile.close();

    get.cin(0);
    return 0;
}

