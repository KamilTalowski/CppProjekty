#include <iostream>
#include <cstdlib>
#include <string>
#include <fstream>
#include <random>

using namespace std;
// funkcja czytajaca z konsoli
int load(){
    int number;
    do
    cin>>number;
    while(number<0 || cin.fail());
    return number;
}
//funkcja sprawdzajaca czy plik sie dobrze otworzyl
//sprawdzanie czy plik znajduje sie w folderze zwraca true jesli tak
bool f_Open_File(string &file_name)
{
	ifstream iffile;
	iffile.open(file_name.c_str());
	if (iffile.is_open())
		return true;
    else
        return false;
}

//funkcja sprawdzajaca czy plik posiada rozszerzenie, wyszukiwanie rozszerzenia
//jezeli w podanej nazwie pliku nie znajduje sie fraza ".txt" to: cond przyjmuje false
//szukanie frazy .txt
//zwraca cond
bool f_Find_Extension(string & txt, string file_extension)
{
	bool cond;
	cond = true;
	size_t found_position = txt.find(file_extension);
	if (found_position == string::npos)
	{
		cond = false;
	}
	do
	{
		found_position = txt.find(file_extension, found_position + file_extension.size());
	} while (found_position != string::npos);
	return cond;
}
// funkcja pobierajaca i sprawdzajaca file_name
int f_Add_File(string &file_name)
{
    bool check, open;
	cout << "Podaj nazwe pliku: "<<endl;
	do
	{
		cin >> file_name;
		check = f_Find_Extension(file_name, ".txt");
		if (!check)
		{
			file_name = file_name + ".txt";
		}
		//sprawdzanie czy istnieje nowy plik z rozszerzeniem
		//jesli plik nie istnieje: informuje o bledzie
		open = f_Open_File(file_name);
		if (!open)
		{
			cout << "Niepoprawna nazwa pliku." << endl;
		}
	} while (!open);
}

// funcka zapisujaca zmienna w pliku
void f_write(int z, ofstream &save_file)
{
    save_file << z <<endl;
	if (save_file.fail())
		cout << "Save to file error!" << endl;

}
// zczytanie daych wejsciowych z konsoli dla LCG i spradzenie warunkow
// wejscie nadanie wartosci seed, dlugosc tablicy, dlugosc lanncucha i dzielnik
void check_and_load(int &x0, int &n, int &xmax, int &m){
    do{
        cout<<"podaj seed x0"<<endl;
        x0=load();
        cout<<"podaj ilosc losowanych liczb n"<<endl;
        n=load();
        cout<<"podaj przedzial losowania xmax"<<endl;
        xmax=load();
        m=xmax+1;
    }while(x0<0 || x0>m || n < 0 || m <= 0);
}
//funkcja tworzaca tablice
//wejscie dlugosc tablicy
//wyjscie wskaznik tablicy
int *f_create_tab(int n)
{
    int *t = nullptr;
	try
	{
		t = new int[n];
    }
	catch (bad_alloc)
	{
		cout << "Wystapil blad podczas tworzenia tablicy";
		getchar();
		exit(0);
	}
	return t;
}
// losowanie liczb do metody addytywnej
int random_add(int r)
{
	random_device rd;
	mt19937 mt(rd());
	uniform_int_distribution<int>dist(0, r);
	r = dist(rd);
	return r;
}
// funkcja szukajaca NWD
//wejscie dwie liczby
//zwraca ich NWD
int NWD(int a, int b)
{
	while (a != b)
		if (a>b)
			a = a - b;
		else
			b = b - a;
	return a;
}
//funkcja pdnoszaca do potegi
int potega(long int podstawa, int wykladnik)
{
    int wynik = 1;

    for (int i = 0; i<wykladnik; i++)
        wynik*=podstawa;

    return wynik;
}
//sprawdzanie czy jest to liczba pierwsza
bool f_is_first(int b)
{
  if(b<2)
    return false;

  for(int i=2;i*i<=b;i++)
    if(b%i==0)
      return false;
  return true;
}
// szukanie odpowiedniego a dla LCG metoda wzoru z zajec
//sprawdza warunki czy a jet wielokrotnoscia liczby pierwszej ktora jest dzielnikiem m oraz czy m/4 to (a-1)/4
//zwraca max a lub BestMaxa oraz max lambda dla najlepszego a^lambda mod m=1
void check_a(int &a, int &lambda, int &m)
{
	int h,lambdamax=0,amax=0,BestAmax=0;
	long long pow=0;

	for (a=2; a < m; a++)
	{
	    h=0;
		for (lambda = 1; lambda < 2*m; lambda++)
		{
			pow=potega(a, lambda);
			h = pow%m;
			if (h == 1)
			{
				if (lambda >= lambdamax)
				{
				lambdamax = lambda;
                    if((f_is_first(a)==true && (a-1)%m==0) || (m%4 == 0 && (a-1)%4 == 0))
                            BestAmax=a;
                    else amax=a;
                }else;
                    lambda=2*m+1;
                break;
			}
		}
	}
	lambda = lambdamax;
	if(BestAmax!=0)
	a=BestAmax;
	else a=amax;
}
//wykonanie glownego algorytmu dla LCG
void generate_LCG(int &x0, int &n, int &c, int &a, int &m, ofstream &save_file)
{
	int *tab=f_create_tab(n+1);
	tab[0]=x0;
	for(int i = 1; i < n+1; i++)
	{
		tab[i]=(a*tab[i-1] +c) % m;
		cout<<tab[i]<<endl;
		f_write(tab[i], save_file);
	}
    delete[] tab;
}
// Generowanie liczb dla metody adt para liczb 2 i 5
int generate_adt(int n, int m, ofstream &save_file){
    int *tab=f_create_tab(n);
    for(int i=0; i<5; i++)
    tab[i]=random_add(10000);

    for(int i=6; i<=n; i++){
    tab[i]=(tab[i-2]+tab[i-5]);
    tab[i]=tab[i]%m;
    cout<<tab[i]<<endl;
    f_write(tab[i], save_file);
    }
    delete[] tab;
}
// Generowanie liczb dla metody adt_para liczb 3 i 7
int generate_adt_tas(int n, int m, ofstream &save_file){
    int *tab2=f_create_tab(n+1);
    for(int i=0; i<7; i++)
    tab2[i]=random_add(10000);

    for(int i=8; i<=n; i++){
    tab2[i]=(tab2[i-3]+tab2[i-7]);
    tab2[i]=tab2[i]%m;
    cout<<tab2[i]<<endl;
    f_write(tab2[i], save_file);
    }
    delete[] tab2;
}

main()
{
    int menu;
    int a=1,m=0,c=1,n=0,xmax=0,x0=0,check=0, lambda=1;
    string file_name;
    f_Add_File(file_name);
    //otwieranie pliku zapisu
    ofstream save_file;
        save_file.open(file_name.c_str(), ios::trunc);
        if (save_file.good() == true);
        else cout << "Error creating output file" << endl;

    cout<< "wybierz metode 1/2/3" <<endl;
    do{
    cin>>menu;
    }while(menu>3 || menu<0);
    //menu wybierajace metode
    switch(menu){
        //LCG
    case 1:
        check_and_load(x0,n,xmax,m);
        do
        {
            check=NWD(m, c);
            if (check == 1)
                ;
            else
            check=0;
            c = c+1;
        }
        while(check==0);

        check_a(a, lambda, m);
        generate_LCG(x0, n, c, a, m, save_file);

        break;
        //Metoda addytywna
    case 2:
        cout<<"podaj ilosc losowanych liczb"<<endl;
        n=5+load();
        cout<<"podaj zakres losowanych liczb"<<endl;
        m=load();

        generate_adt(n,m, save_file);

        break;
    //Metoda addytywna dla innego zestawu liczb
    case 3:
        cout<<"podaj ilosc losowanych liczb"<<endl;
        n=7+load();
        cout<<"podaj zakres losowanych liczb"<<endl;
        m=load();

        generate_adt_tas(n,m, save_file);

        break;
    }

    if (save_file.is_open())
    save_file.close();

    cin.get();
	return 0;
}
