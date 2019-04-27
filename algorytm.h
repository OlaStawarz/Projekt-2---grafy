#ifndef DIJKSTRA_H
#define DIJKSTRA_H
#include <iostream>
#include "lista.h"

using namespace std;

class dane 
{
public:
	int dystans;
	int poprzednik;
	bool odwiedzony;
};

class kolejka
{
	int** tablica;
	int liczba_elementow;
public:
	kolejka(int max_wielkosc)
	{
		tablica = new int* [max_wielkosc];
		for (int i = 0; i < max_wielkosc; i++)
			tablica[i] = new int[2];
		liczba_elementow = 0;
	}
	int zwroc_wartosc()
	{
		int tmp;
		tmp = tablica[0][0];
		if (liczba_elementow > 0)
		{
			for (int i = 0; i < liczba_elementow; i++)
			{
				tablica[i][1] = tablica[i + 1][1];
				tablica[i][0] = tablica[i + 1][0];
			}
			liczba_elementow--;
		}
		return tmp;
	}
	void dodaj_wartosc(int wierzcholek, int priorytet)
	{
		if (liczba_elementow == 0)
		{
			tablica[0][0] = wierzcholek;
			tablica[0][1] = priorytet;
			liczba_elementow++;
		}
		else
		{
			int i;
			for (i = 0; i < liczba_elementow; i++)
			{
				if (tablica[i][0] == wierzcholek)
				{
					if (tablica[i][1] > priorytet)
						tablica[i][1] = priorytet;
					return;
				}
			}
			
			
			for (i = liczba_elementow-1; i >= 0; i--)
			{
				if (priorytet < tablica[i][1])
				{
					tablica[i + 1][1] = tablica[i][1];
					tablica[i + 1][0] = tablica[i][0];
				}
				else
				{
					break;
				}
			}
			tablica[i + 1][0] = wierzcholek;
			tablica[i + 1][1] = priorytet;
			liczba_elementow++;
		}
	}
	bool czy_pusta()
	{
		if (liczba_elementow > 0)
			return false;
		else
			return true;
	}
	void wyswietl()
	{
		for (int i = 0; i < liczba_elementow; i++)
		{
			cout << tablica[i][0] << ", " << tablica[i][1] << endl;
		}
		cout << endl;
	}
};

int szukajMinimum(int n, dane* tab) 
{
	int min = -1;
	int min_dystans = INT_MAX;
	for (int i = 0; i < n; i++)
	{
		if (!tab[i].odwiedzony && tab[i].dystans < min_dystans)
		{
			min = i;
			min_dystans = tab[i].dystans;
		}
	}
	return min;
}

dane* Dijkstra(int** macierz, int n, int start) 
{
	dane* tab = new dane[n];
	for (int i = 0; i < n; i++) 
	{
		tab[i].dystans = INT_MAX; // ustawiamy na maksymalny dystans
		tab[i].odwiedzony = false; // ustawiamy, ze nie byl odwiedzony
		tab[i].poprzednik = -1; // przyjmujemy -1
	}
	kolejka kolejka(n);
	kolejka.dodaj_wartosc(start, 0);
	tab[start].dystans = 0;
	int u;
	while (!kolejka.czy_pusta())
	{
		//kolejka.wyswietl();
		u = kolejka.zwroc_wartosc();
		tab[u].odwiedzony = true;
		for (int i = 0; i < n; i++)
		{
			if (macierz[u][i] > 0 && macierz[u][i]+tab[u].dystans<tab[i].dystans)
			{
				tab[i].dystans = macierz[u][i] + tab[u].dystans;
				tab[i].poprzednik = u;
			}
			if (macierz[u][i] > 0 && !tab[i].odwiedzony)
			{
				kolejka.dodaj_wartosc(i, tab[i].dystans);
			}
			
		}

	}
	return tab;
}

dane* Dijkstra_lista(lista* graf, int n, int start)
{
	dane* tab = new dane[n];
	for (int i = 0; i < n; i++)
	{
		tab[i].dystans = INT_MAX; // ustawiamy na maksymalny dystans
		tab[i].odwiedzony = false; // ustawiamy, ze nie byl odwiedzony
		tab[i].poprzednik = -1; // przyjmujemy -1
	}
	kolejka kolejka(n);
	kolejka.dodaj_wartosc(start, 0);
	tab[start].dystans = 0;
	int u;
	while (!kolejka.czy_pusta())
	{
		//kolejka.wyswietl();
		u = kolejka.zwroc_wartosc();
		tab[u].odwiedzony = true;

		for (int i = 0; i < n; i++)
		{
			if (graf[u].sprawdz(i) >0 && graf[u].sprawdz(i) + tab[u].dystans < tab[i].dystans)
			{
				tab[i].dystans = graf[u].sprawdz(i) + tab[u].dystans;
				tab[i].poprzednik = u;
			}
			if (graf[u].sprawdz(i) > 0 && !tab[i].odwiedzony)
			{
				kolejka.dodaj_wartosc(i, tab[i].dystans);
			}

		}

	}
	return tab;
}

//void wypiszsciezke(dane d, int j) //wypisywanie calej sciezki
//{
//	if (d.poprzednik == -1)
//		return;
//	wypiszsciezke(d.poprzednik, j);
//	cout << j;
//}

void wypiszdane(int i, dane d) 
{
	cout << i << "\t";
	if (!d.odwiedzony) 
	{
		cout << "nieodwiedzony";
	}
	else 
	{
		if (d.poprzednik == -1)
			cout << "brak";
		else
		{
			cout << d.poprzednik;
		}
		cout << "\t" << d.dystans;
	}
	cout << endl;
}


void wypiszdane2(dane* d, int rozmiar)
{
	int pom;
	for (int i = 0; i < rozmiar; i++)
	{
		cout << i << "\t";
		if (!d[i].odwiedzony)
		{
			cout << "nieodwiedzony";
		}
		else
		{
			if (d[i].poprzednik == -1)
				cout << "brak";
			else
			{
				pom = d[i].poprzednik;
				while (pom != -1)
				{
					cout << pom << " ";
					pom = d[pom].poprzednik;
				}
			
			}
			cout << "\t" << d[i].dystans;
		}
		cout << endl;
	}
	
}

#endif DIJKSTRA_H