#include "Naglowki.h"

class Drzewo_bin
{
protected:
	/* zmienne  */
	
	int *korzen;
	int dane [16]; // tablica z danymi
	

public:
	friend class Struktury;
	bool pusty [16]; // tablica przechowujaca puste miejsca do wypelnienia 
	/* void ustawiajacay kursor w miejscu X,Y na ekranie */

	void gotoxy (int x, int y)
	{
		COORD c;
		c.X = x - 1;
		c.Y = y - 1;
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
	}

	/* wyswietlenie drzewa */

	void wyswietl()
	{
		system("CLS");
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);

	gotoxy(40,1); if (pusty[1] == true) cout << "_"; else cout << dane[1];
	gotoxy(20,4); if (pusty[2] == true) cout << "_"; else cout << dane[2];
	gotoxy(60,4); if (pusty[3] == true) cout << "_"; else cout << dane[3];
	gotoxy(10,6); if (pusty[4] == true) cout << "_"; else cout << dane[4];
	gotoxy(30,6); if (pusty[5] == true) cout << "_"; else cout << dane[5];
	gotoxy(50,6); if (pusty[6] == true) cout << "_"; else cout << dane[6];
	gotoxy(70,6); if (pusty[7] == true) cout << "_"; else cout << dane[7];
	gotoxy(5,10); if (pusty[8] == true) cout << "_"; else cout << dane[8];
	gotoxy(15,10); if (pusty[9] == true) cout << "_"; else cout << dane[9];
	gotoxy(25,10); if (pusty[10] == true) cout << "_"; else cout << dane[10];
	gotoxy(35,10); if (pusty[11] == true) cout << "_"; else cout << dane[11];
	gotoxy(45,10); if (pusty[12] == true) cout << "_"; else cout << dane[12];
	gotoxy(55,10); if (pusty[13] == true) cout << "_"; else cout << dane[13];
	gotoxy(65,10); if (pusty[14] == true) cout << "_"; else cout << dane[14];
	gotoxy(75,10); if (pusty[15] == true) cout << "_"; else cout << dane[15];

		cout << endl << endl << endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
	}

	void add()
	{
		int liczba;
		cout << "Podaj liczbe jaka chcesz wprowadzic do drzewa " << endl;
		cin >> liczba;

		if (pusty[1] == true)
		{
			korzen = &dane[1];
			*korzen = liczba;
			pusty[1] = false;
		}

		else
		{
			bool znalazlem_miejsce = false;
			int wezel = 1;

			while (znalazlem_miejsce == false)
			{
				if (pusty[wezel] == true)
				{
					znalazlem_miejsce = true;
					dane[wezel] = liczba;
					pusty[wezel] = false;
				}
				else if (liczba < dane[wezel])
				{
					// liczba idze w lewo
					wezel = 2 * wezel;
				}
				else 
				{
					// liczba idzie w prawo
					wezel = 2 * wezel + 1;
				}
				if (wezel > 15)
				{
					cout << "drzewo jest przepelnione, nie mozna wstawic elementu " << endl;
				}

			}
		}

	}

	void find()
	{
		int liczba;
		cout << "Podaj liczbe ktora chcesz znalezc w drzewie: " << endl;
		cin >> liczba;

		bool znalazlem_liczbe = false;
		int wezel = 1;

		while (znalazlem_liczbe == false)
		{
			if (liczba == dane[wezel])
			{
				cout << "Znaleziono liczne w wezle nr " << wezel << endl;
				Sleep(3000);

				znalazlem_liczbe = true;
			}
			else if (znalazlem_liczbe < dane[wezel])
			{
				wezel = 2 * wezel;
			}
			else
			{
				wezel = 2 * wezel + 1;
			}

			if (wezel > 15)
			{
				cout << "Nie znaleziono liczby :( " << endl;
				Sleep(3000);
				znalazlem_liczbe = true;
			}
		}
	}


};