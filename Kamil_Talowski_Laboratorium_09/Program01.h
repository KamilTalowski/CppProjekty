#pragma once
 
struct Node
{
	int iProfit,
		iMaxWeight,
		iParentNode;
	Node();
};
long readDataFromFIle(ifstream & ifFileToRead);

void reverseBubbleSort(long ** pTabWithWages, double * pTabWithScales, int iRows);

void setArrayWithData(ifstream & ifIn, long ** TabWithWeight, double * TabWithScales, int iRows);

void knapSack(vector <int> vTabWithResults, Node mainNode);

int findNodeOverflow(vector<int> vTabWithResults, Node mainNode);

int findTotal(vector<int> vTabWithResults, int iI, int iK, bool bP = false);

bool checkPromising(vector<int> vTabWithResults, Node mainNode, string & sSave);

void keepBestPacking(vector<int> vTabWithResults, Node mainNode);







