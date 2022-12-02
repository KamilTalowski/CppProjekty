#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <iomanip>
#include <ctime>
#include <Program1.h>
using namespace std;


int main()
{
	ifstream inFile("graf.txt");
	cout << "A/B?";
	int option;
	cin >> option;

	if(option == 1)
	IncydenceArrayPointer();
	else if (option == 2)
	IncydenceArrayVector();

	if (inFile.is_open()) inFile.close();
    if (outFile.is_open()) outFile.close();

    get.cin(0);
	return 0;
}
