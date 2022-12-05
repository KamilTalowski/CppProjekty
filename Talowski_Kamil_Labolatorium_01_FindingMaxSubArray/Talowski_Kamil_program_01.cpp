#include <iostream>
#include <fstream>

using namespace std;
//Filling Array with integer numbers
int FillArray(int *tab, unsigned int N, int &ModulusValue)
{
    for(int i = 0; i < N; i++)
    {
        cin>>tab[i];
        if(tab[i]<=0) ModulusValue += -tab[i];
        else ModulusValue += tab[i];
    }
    return ModulusValue;
}
//Main method to find max SubArray
int MaxArray(int *tab, unsigned int N, int &BestValue, int &BestPositionStart, int &BestPositionEnd)
{
    int CurrentValue=0;
    int NewValue=0;

    int PositionEnd=0;
    int PositionStart=0;

    int NewPositionEnd=0; int NewPositionStart=0;
        //main loop
        #pragma region Main Loop O(n)
	    for(int i = 0; i < N; i++) {
    	if(tab[i] > 0) {
        //checking value next element of array
		NewValue = CurrentValue + (3 * tab[i]);
        NewPositionEnd=i;
		}
    	if(tab[i] == 0) {
		NewValue = CurrentValue;
        NewPositionEnd=i;
		}

    	if(tab[i] < 0) {
    	NewValue = CurrentValue + (2 * tab[i]);

    	}

//checking lots of conditions to find best value and best start and end value
#pragma Conditions
    if(NewValue < 0) {
    	CurrentValue = 0;
    	NewPositionStart = i+1;
    	NewValue= 0;
	}
	else {
		if(CurrentValue > NewValue) {
            CurrentValue = NewValue;
            BestPositionEnd=PositionEnd;
		}
		else {
			PositionEnd = NewPositionEnd;
			CurrentValue = NewValue;
            PositionStart = NewPositionStart;
			if(BestValue <= CurrentValue) {
                BestValue = CurrentValue;
                BestPositionEnd=PositionEnd;
                BestPositionStart=PositionStart;
			}
		}
	}
#pragma endregion
}
#pragma endregion
}
//Save results to file Results.txt
int write(int &BestValue, int &BestPositionStart, int &BestPositionEnd)
{
        cout <<  BestPositionStart << " " << BestPositionEnd << " " << BestValue << endl;

        ofstream File;
        File.open("Results.txt", ios::app);
        if (File.good() == true)
        {

        File << " "<< BestPositionStart << " " << BestPositionEnd << " " << BestValue << endl;
        File.close();
        }
        else
		cout << "Creating output file error" << endl;

       	return 0;
}
//z- number of sets; tab- array(table)
//if Modulus is over 2000 adding new set
int main()
{
    int BestValue=0;
    int BestPositionStart=0;
    int BestPositionEnd=0;

    int ModulusValue=0;
    int z=0;
    int N = 1000000;

    do
    {
    cin>>z;
    }while(z<1);

    while(z>0)
    {
        do
        {
        cin>>N;
        }while((N<=0)|(N>1000000));

        int * tab = new int[N];

        FillArray(tab, N, ModulusValue);
        if(ModulusValue<=2000)
        {
        MaxArray(tab, N, BestValue, BestPositionStart, BestPositionEnd);
        write(BestValue, BestPositionStart, BestPositionEnd);
        }
        else z += 1;

        delete [] tab;
        z--;

    };
    cin.get();
    return 0;
}
