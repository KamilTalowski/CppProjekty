// Quick Sort Iterative Kamil Talowski
#include <iostream>
#include <cstdlib>
#include <string>
#include <fstream>
#include <time.h>
#include <Program1.h>

using namespace std;

//Glowny program testujacy algorytm teracyjny quickSort
int main()
{
    int z,n;
    int *tab;
    clock_t t_Start, t_End;
    string file_name;

    fstream ifFile;
    ofstream save_file;

    //wczytanie nazwy pliku z danymi i pliku zapisu
    cout<<"Dla pliku odczytu"<<endl;
    f_Add_File(file_name);
    ifFile.open(file_name.c_str(), ios::in);
    cout<<"Dla pliku zapisu"<<endl;
    f_Add_File(file_name);
    save_file.open(file_name.c_str(), ios::trunc);

    if (ifFile.good() == true && save_file.good() == true)
    {
        ifFile >> z;
        do{
            ifFile >> n;
            tab=f_create_tab(n);

            for(int i=0; i<n; i++)
                ifFile>>tab[i];

            t_Start = clock();
            quickSort( tab, 0, n - 1 );
            t_End = clock();
            long algorithm_time = static_cast<long>(t_End - t_Start);

            f_write(n, tab, save_file);
            cout <<"Czas wykonania quick sort dla "<<n<<" wyniosl: "<< algorithm_time <<" ms"<< endl;

            delete[] tab;
            z--;
        }while(z>0);
    }
    else
        cout<<"Blad otwarcia pliku wejsciowego."<<endl;

    if (ifFile.is_open()) ifFile.close();
    if (save_file.is_open()) save_file.close();

    cin.get();
    return 0;
}
