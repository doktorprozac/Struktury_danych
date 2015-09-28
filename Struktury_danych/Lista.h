#include "Naglowki.h"
#include <list>

using namespace std;

list <int> lista;

class Lista
{
public:
	int liczba;

void wyswietl_lista()
{
	system ("CLS");
	cout << " ZAWARTOSC LISTY: " << endl;
	cout << "------------------------------" << endl;

	for (list<int>::iterator i=lista.begin() ; i!=lista.end(); i++)
	{
		cout << *i << " " ;
	}

	cout << endl;
	cout << "------------------------------" << endl;

}
/////////////////////////////////////

void push_front()
{
	int liczba;
	cout << "Podaj liczbe jaka chcesz wstawic na poczatek listy" << endl;
	cin >> liczba;
	lista.push_front(liczba);
}


/////////////////////////////////////
void push_back()
{
	int liczba;
	cout << "Podaj liczbe jaka chcesz wstawic na koniec listy" << endl;
	cin >> liczba;
	lista.push_back(liczba);
}

/////////////////////////////////////
void pop_front()
{
	if (lista.empty() == 1)
	{
		cout << "nie mozna usunac zadnego elementu :) " << endl;
		Sleep(3000);
	}
	else
	{
	cout << "Zostanie usuniety element z poczatku listy" << endl;
	Sleep(2000);
	lista.pop_front();
	}
}


/////////////////////////////////////
void pop_back()
{
	if (lista.empty() == 1)
	{
		cout << "nie mozna usunac zadnego elementu :) " << endl;
		Sleep(3000);
	}
	else
	{
	cout << "Zostanie usuniety element z konca listy" << endl;
	Sleep(2000);
	lista.pop_back();
	}
}

/////////////////////////////////////
void size ()
{
	cout << "Na liscie znajduje sie : " << lista.size() << " elementow " << endl;
	Sleep(2000);
}

/////////////////////////////////////
void max_size()
{
	cout << "Maksymalny rozmiar listy to: " << lista.max_size() << endl;
	Sleep(2000);
}

/////////////////////////////////////
void empty()
{
	cout << "Czy lista jest pusta: " << endl;
	if (lista.empty() == 1)
	{
		cout << "TRUE" << endl;
	}
	else
	{
		cout << "FALSE" << endl;
	}
	Sleep(2000);
}

/////////////////////////////////////
void remove()
{
	if (lista.empty() == 1)
	{
		cout << "nie mozna usunac zadnego elementu :) " << endl;
		Sleep(3000);
	}
	else
	{
	int liczba;
	cout << "Jaka liczbe chcesz usunac z listy " << endl;
	cin >> liczba;
	lista.remove(liczba);
	}
}

/////////////////////////////////////
void sort()
{
	if (lista.empty() == 1)
	{
		cout << "nie ma co posortowac :) " << endl;
		Sleep(3000);
	}
	else
	{
	cout << "Nastapi posortowanie liczb w liscie " << endl;
	lista.sort();
	}
}

/////////////////////////////////////
void reverse ()
{
	if (lista.empty() == 1)
	{
		cout << "nie ma co odwracac :) " << endl;
		Sleep(3000);
	}
	else
	{
	cout << "Nastapi odwrocenie liczb w liscie " << endl;
	lista.reverse();
	}
}

/////////////////////////////////////


};



























