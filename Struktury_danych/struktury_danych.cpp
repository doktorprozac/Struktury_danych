#include "Naglowki.h"
#include "stos.h"

using namespace std;




int main ()
{
	int wybor, metody;
	rozmiar = 0;
	bool exit = false;

	int *tablica;
	tablica = new int [10];

	
	do
	{
	cout << "Metody: " << endl;
	cout << "------------------------------" << endl;
	cout << "1. STOS " << endl;
	cout << "2. KOLEJKA " << endl;

	cout << "wybierz: " << endl;
	cin >> metody;


	switch (metody)
	{
	case 1:
		////////////////////////////////
	do
	{
	wyswietl_stos(tablica);

	cout << "------------------------------" << endl;
	cout << "1. wprowadz na stos - PUSH " << endl;
	cout << "2. usun z stosu - POP " << endl;
	cout << "3. rozmiar stosu - SIZE " << endl;
	cout << "4. czy stos jest pusty - EMPTY " << endl;
	cout << "5. wyjscie " << endl;
	cout << "------------------------------" << endl;
	cout << "wybierz: " << endl;
	cin >> wybor;

	switch (wybor)
	{
	case 1:
		
		push(tablica);
		break;

	case 2:
	
		pop(tablica);
		break;

	case 3:
		
		size();
		break;

	case 4:
		
		empty();
		break;
		
	case 5:
		exit = true;
		//system("CLS");
		break;

	default:
		cout << "wybrano inna liczbe niz [1 2 3 4 5] " << endl;
		Sleep(5000);
		break;
	}

	}

	while (!exit);


		////////////////////////////////

		break;

	case 2:
		cout << "------------------------------" << endl;
		cout << " jeszcze nie oprogramowano :( " << endl;
		cout << "------------------------------" << endl;
		break;
	}
	}
	while (true);


	///////////////
	


	delete [] tablica;

	cin.get();
	return 0;
}
