#include "Naglowki.h"


using namespace std;

int rozmiar_kol = 0;
int rozmiar = 0;
int glowa; // pierwszy element w kolejce [index]
int ogon; // pierwsze wolne miejsce w kolejce [index]



//////////////////////////////
 


class Struktury
{
public:
	virtual void push (int *tablica) = 0;
	virtual void pop (int *tablica) = 0;
	virtual void size () = 0;
	virtual void empty () = 0;
	virtual void wyswietl (int *tablica) = 0;
};

class Stos :  public Struktury
{
	
public:
virtual void push(int *tablica)
{
	if (rozmiar >= 10)
	{
		std::cout << " stos jest pelny" << endl;
		Sleep(5000);
	}
	else
	{
		std::cout << "Jaka liczbe wprowadzic na stos: " << endl;
		rozmiar = rozmiar + 1;
		std::cin >> tablica[rozmiar];
	}
}

virtual void pop(int *tablica)
{
	if (rozmiar >= 1)
	{
		std::cout << "usuniety zostanie element z stosu " << tablica[rozmiar]  << endl;
		rozmiar = rozmiar - 1;
	}
	else
	{
		
		std::cout << "Stos jest pusty" << endl;
		Sleep(5000);
	}
}

virtual void size()
{
	std::cout << " rozmiar naszego stosu wynosi: " << rozmiar << endl;
	Sleep(5000);
}

virtual void empty()
{
	if (rozmiar >=1 )
	{
		std::cout << "stos nie jest pusty" << endl;
		Sleep(5000);
	}
	else
	{
		std::cout << "stos jest pusty " << endl;
		Sleep(5000);
	}
}

virtual void wyswietl (int *tablica)
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



};


class Kolejka: public Struktury
{
public:
	
virtual void push(int *tablica)
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

virtual void pop(int *tablica)
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

virtual void size()
{
	cout << "rozmiar kolejki wynosi: " << rozmiar_kol << endl;
}

virtual void empty()
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

void wyswietl (int *tablica)
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


};


int main ()
{
	using namespace std;

	int wybor, metody;
	glowa = 0;
	ogon = 0;
	bool exit = false;

	int *tablica;
	tablica = new int [10];


	Struktury *wsk;
	Stos st;
	Kolejka kol;

	do
	{
	cout << "Metody: " << endl;
	cout << "------------------------------" << endl;
	cout << "1. STOS " << endl;
	cout << "2. KOLEJKA " << endl;
	cout << "3. LISTA " << endl;
	cout << "4. DRZEWO BINARNE " << endl;
	cout << "------------------------------" << endl;
	cout << "wybierz: " << endl;
	cin >> metody;


	switch (metody)
	{
	case 1:
		////////////////////////////////
		wsk = &st;
	do
	{
	wsk->wyswietl(tablica);

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
		wsk->push(tablica);
		break;

	case 2:
		wsk->pop(tablica);
		break;

	case 3:
		wsk->size();
		break;

	case 4:
		wsk->empty();
		break;
		
	case 5:
		exit = true;
		system("CLS");
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
		
		wsk = &kol;
	do
	{
		wsk->wyswietl(tablica);

	cout << "------------------------------" << endl;
	cout << "1. wprowadz do kolejki - PUSH " << endl;
	cout << "2. usun z kolejki - POP " << endl;
	cout << "3. rozmiar kolejki - SIZE " << endl;
	cout << "4. czy kolejka jest pusta - EMPTY " << endl;
	cout << "5. wyjscie " << endl;
	cout << "------------------------------" << endl;
	cout << "wybierz: " << endl;
	cin >> wybor;

	switch (wybor)
	{
	case 1:
		wsk->push(tablica);
		break;

	case 2:
		wsk->pop(tablica);
		break;

	case 3:
		wsk->size();
		break;

	case 4:
		wsk->empty();
		break;
		
	case 5:
		exit = true;
		system("CLS");
		break;

	default:
		cout << "wybrano inna liczbe niz [1 2 3 4 5] " << endl;
		Sleep(5000);
		break;
	}

	}

	while (!exit);
		break;

	case 3:
		cout << "------------------------------" << endl;
		cout << " jeszcze nie oprogramowano :( " << endl;
		cout << "------------------------------" << endl;
		break;

	case 4:
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
