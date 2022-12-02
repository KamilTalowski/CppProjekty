#include "Program01.h"

ofstream ofFileToSave;
int main()
{
	ifstream ifFileToRead = readFile("data.txt");
	ofFileToSave = createFile("OU.txt");

	int iDataSet = readDataSetCount(ifFileToRead);

	// Petla dla testow.
	while (iDataSet--)
	{
		// Glowny algorytm.
		priorityQueue pQueue;
		int iCountSet = readDataSetCount(ifFileToRead);

		// Petla dla ilosci danych.
		while (iCountSet--)
		{
			readDataFromFIle(ifFileToRead, pQueue);
		}
		Huffman(pQueue);

		// Wyswietlanie wynikow.
		Node * nTop = pQueue.top();
		PrintResults(nTop->leftChild, "0");
		PrintResults(nTop->rightChild, "1");
	}

	// Zamkniecie plikow i czyszczenie pamieci.
	closeFile(ifFileToRead);
	closeFile(ofFileToSave);


	return 0;
}




void insertNode(priorityQueue & pQ, double iValue, Node * lChild, Node * rChild, char Code)
{
	Node  * Node1 = new Node;
	Node1->dValue = iValue;
	Node1->leftChild = lChild;
	Node1->rightChild = rChild;
	Node1->Code = Code;
	pQ.push(Node1);
}

void PrintResults(Node * node1, string before)
{

	// Jesli dany wierzcholek nie jest lisciem, to szukamy dalej w lewo.
	if (node1->leftChild != nullptr)
	{
		PrintResults(node1->leftChild, before + to_string(0));
	}

	// Jesli dany wierzcholek nie jest lisciem, to szukamy dalej w prawo.
	if (node1->rightChild != nullptr)
	{
		PrintResults(node1->rightChild, before + to_string(1));
	}

	// Jesli wierzcholek jest lisciem, to wypisujemy jego kod.
	if (node1->leftChild == nullptr)
	{
		string sToSave = "";
		sToSave = sToSave + (node1->Code) + "; ";
		sToSave += before + " " + to_string(node1->dValue) + "\n";
		saveFile(ofFileToSave, sToSave);
	}


}

void Huffman(priorityQueue & pQueue)
{
	// Dopoki pozostalo wiecej niz jedno drzewo.
	while (pQueue.size() > 1)
	{
		// WeŸ dwa drzewa t1 t2 o najmniejszych prawdopodobienstwach
		Node * t1 = pQueue.top();
		pQueue.pop();
		Node * t2 = pQueue.top();
		pQueue.pop();

		double dSum = t1->dValue + t2->dValue;
		// I polacz je.
		insertNode(pQueue, dSum, t1, t2);
	}
}

void readDataFromFIle(ifstream & ifFileToRead, priorityQueue & pQ)
{
	double dValue;
	char Code;

	ifFileToRead >> dValue;
	ifFileToRead >> Code;
	if (ifFileToRead.good())
	{
		insertNode(pQ, dValue, nullptr, nullptr, Code);
	}
}



int readDataSetCount(ifstream & ifFileToRead)
{
	int iCount;
	do
	{
		ifFileToRead >> iCount;
	} while (!ifFileToRead.good() && iCount < 0);
	return iCount;
}
