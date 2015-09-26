#include "Naglowki.h"

/* stos */
using namespace std;

int rozmiar;

void wyswietl_stos(int *tablica)
{
	system("CLS");
	cout << endl;
	cout << "----------------------------" << endl;
	cout << "ZAWARTOSC STOSU: " << endl;
	cout << "----------------------------" << endl;
	for (int i = rozmiar; i>=1; i--)
	{
		cout << tablica[i] << endl;
	}

	if (rozmiar == 0)
	{
		cout << "Stos jest pusty :( " << endl;
		cout << "----------------------------" << endl;
	}
}

void push(int *tablica)
{
	if (rozmiar >= 10)
	{
		cout << " stos jest pelny" << endl;
		Sleep(5000);
	}
	else
	{
		cout << "Jaka liczbe wprowadzic na stos: " << endl;
		rozmiar = rozmiar + 1;
		cin >> tablica[rozmiar];
	}
}

void pop(int *tablica)
{
	if (rozmiar >= 1)
	{
		cout << "usuniety zostanie element z stosu " << tablica[rozmiar]  << endl;
		rozmiar = rozmiar - 1;
	}
	else
	{
		
		cout << "Stos jest pusty" << endl;
		Sleep(5000);
	}
}

void size()
{
	cout << " rozmiar naszego stosu wynosi: " << rozmiar << endl;
	Sleep(5000);
}

void empty()
{
	if (rozmiar >=1 )
	{
		cout << "stos nie jest pusty" << endl;
		Sleep(5000);
	}
	else
	{
		cout << "stos jest pusty " << endl;
		Sleep(5000);
	}
}