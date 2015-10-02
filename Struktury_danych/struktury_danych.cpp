
#include "Naglowki.h"
#include "Lista.h"
#include "Drzewo_bin.h"


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
	Lista lst;
	Drzewo_bin drzewo;

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
		///////////////////////////////////
		do
		{
			lst.wyswietl_lista();

			cout << "MENU LISTA " << endl;
			cout << "------------------------------" << endl;
			cout << "1.  push_front " << endl;
			cout << "2.  push_back " << endl;
			cout << "3.  pop_front " << endl;
			cout << "4.  pop_back " << endl;
			cout << "5.  size " << endl;
			cout << "6.  max_size " << endl;
			cout << "7.  empty " << endl;
			cout << "8.  remove " << endl;
			cout << "9.  sort " << endl;
			cout << "10. reverse " << endl;
			cout << "11. exit " << endl;
			cout << "------------------------------" << endl;
			cout << "wybierz: " << endl;
			cin >> wybor;

			

			switch (wybor)
			{
			case 1:
				lst.push_front();
				break;
			
			case 2:
				lst.push_back();
				break;

			case 3:	
				lst.pop_front();
				break;

			case 4:
				lst.pop_back();
				break;

			case 5:
				lst.size();
				break;

			case 6:
				lst.max_size();
				break;
	
			case 7:
				lst.empty();
				break;

			case 8:
				lst.remove();
				break;

			case 9:
				lst.sort();
				break;

			case 10:
				lst.reverse();
				break;

			case 11:
				exit = true;
				system("CLS");
				break;

			default:
				cout << "wybrano inna opcje niz powyzej " << endl;
				Sleep(3000);
				break;
			}
		}
		while (!exit);



		Sleep(3000);
		system("CLS");

		///////////////////////////////////

		break;

	case 4:
		for (int i = 1; i<=15; i++)
		{
			drzewo.pusty[i] = true;
		}

		do
		{
			drzewo.wyswietl();		
			cout << "MENU DRZEWO " << endl;
			cout << "------------------------------" << endl;
			cout << "1.  ADD - dodaj element do drzewa " << endl;
			cout << "2.  FIND - znajdz element w drzewie " << endl;
			cout << "3.  EXIT - wyjscie z programu " << endl;
			cout << "------------------------------" << endl;
			cout << "wybierz: " << endl;
			cin >> wybor;

			switch (wybor)
			{
			case 1:
				drzewo.add();
				Sleep(3000);
				break;

			case 2:
				drzewo.find();
				Sleep(3000);
				break;

			case 3:
				exit = true;
				system("CLS");
				break;

			default :
				cout << "Wybrano inna opcje niz [1 2 3] " << endl;
					break;
			}

		}
		while (!exit);

		break;
	}
	}
	while (true);


	///////////////
	


	delete [] tablica;

	cin.get();
	return 0;
	}