#ifndef DIJKSTRA_H
#define DIJKSTRA_H
#include <iostream>

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
			for (i = liczba_elementow - 1; i >= 0; i--)
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
			cout << d.poprzednik;
		cout << "\t" << d.dystans;
	}
	cout << endl;
}

#endif DIJKSTRA_H