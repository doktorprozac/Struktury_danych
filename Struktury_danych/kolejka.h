#include "Naglowki.h"

using namespace std;

int tablica[10];
int rozmiar_kol;
int glowa; // pierwszy element w kolejce [index]
int ogon; // pierwsze wolne miejsce w kolejce [index]


void wyswietl_kolejke()
{
	system("CLS");

	cout << endl;
	cout << "-------------------------------" << endl;
	cout << "ZAWARTOSC KOLEJKI: " << endl;
	cout << "-------------------------------" << endl;

	if (rozmiar_kol == 0)
	{
		cout << "kolejka jest pusta" << endl;
	}

	else
	{
		int indeks;

		for (int i=0; i<rozmiar_kol; i++)
		{
			indeks = glowa + i;

			if (glowa + i >= 10) // gdy wyszlo sie poza tablice
			{
				indeks = glowa + i - 10;
			}

			cout << tablica[indeks] << endl;
		}
	}

}

void push_kolejka()
{
	if (rozmiar_kol >= 10)
	{
		cout << "Kolejka jest pelna " << endl;
		Sleep(3000);
	}
	else if (rozmiar_kol == 0)
	{
		cout << "Jaka liczbe wstawic do kolejki: " << endl;
		cin >> tablica[ogon];

		ogon = ogon + 1;
		rozmiar_kol = rozmiar_kol + 1;
	}
	else
	{
		cout << "Jaka liczbe wstawic do kolejki: " << endl;
		cin >> tablica[ogon];
		ogon = (ogon+1)%10; // wyznaczenie indeksu ogona
		rozmiar_kol = rozmiar_kol + 1;
	}
}

void pop_kolejka()
{
	if (rozmiar_kol == 0)
	{
		cout << "Kolejka jest pusta " << endl;
		Sleep(3000);
	}
	else
	{
		cout << "Zostanie usuniety element z kolejki " << tablica[glowa];
		glowa = (glowa+1)%10; // wyznaczenie indeksu glowy
		rozmiar_kol = rozmiar_kol - 1;
		Sleep(3000);
	}
}

void size_kolejka()
{
	cout << "rozmiar kolejki wynosi: " << rozmiar_kol << endl;
}

void empty_kolejka()
{
	if (rozmiar_kol == 0)
	{
		cout << "Kolejka jest pusta" << endl;
	}
	else
	{
		cout << "Kolejka jest pelna" << endl;
	}
	Sleep(3000);
}



