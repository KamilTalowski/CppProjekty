#pragma once
#include <queue>
#include "myfunction.h"
#include "array.cpp"
#include "file.cpp"
#include "Program01.h"


struct Node
{
	double dValue;
	Node * leftChild;
	Node * rightChild;
	char Code;
};

struct compareNode
{
	bool operator ()(const Node * node1, const Node * node2)
	{
		//kolejnoœæ - rosn¹co
		if (node1->dValue > node2->dValue) return true;
		if (node1->dValue < node2->dValue) return false;
		return false;
	}

};
typedef priority_queue < Node *, vector < Node* >, compareNode > priorityQueue;

/**
* Create new node.
*
* @param	pQ	    Main priority Queue.
* @param    dValue  Frequency or Probability of occurence.
* @param    lChild  pointer to Left Child of node.
* @param    rChild  pointer to Reft Child of node.
* @param    Code    Symbol of current node.
*/
void insertNode(priorityQueue & pQ, double dValue, Node * lChild, Node * rChild, char Code = ' ');
/**
* Print unique code to file.
*
* @param    node1   Pointer to current Node.
* @param    sCode   Binary unique code to element.

*/
void PrintResults(Node * node1, string sCode);

/**
* Create unique code to all elements.
*
* @param    pQueue  Priority queue with elements.
*/
void Huffman(priorityQueue & pQueue);
void readDataFromFIle(ifstream & ifFileToRead, priorityQueue & pQ);
int readDataSetCount(ifstream & ifFileToRead);





