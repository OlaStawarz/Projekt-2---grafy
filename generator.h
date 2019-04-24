#ifndef GENERATOR_H
#define GENERATOR_H
#include <iostream>
#include <fstream>
#include "algorytm.h"
#include "lista.h"

using namespace std;

class obslugapliku
{
	fstream plik;
	string sciezka = "graf.txt";
public:
	void zapis(int** tablica, int rozmiar) // zapisywanie tablicy do pliku
	{
		//fstream plik;
		//string sciezka = "graf.txt"; // towrzenie pliku .txt o nazwie rownej rozmiarowi
		plik.open(sciezka, fstream::out | fstream::app);

		for (int i = 0; i < rozmiar; i++)
		{
			for (int j = 0; j < rozmiar; j++) {
				plik << tablica[i][j] << " ";
			}
			plik << endl;
		}
		plik << endl;
		plik.close();
	}

	int** wczytaj(int rozmiar)
	{
		/*fstream plik;
		string sciezka = "graf.txt";*/
		plik.open(sciezka, fstream::in);
		int **tablica = new int *[rozmiar]; //alokacja pamieci
		for (int i = 0; i < rozmiar; ++i)
		{
			tablica[i] = new int[rozmiar]; //alokacja pamieci
			for (int j = 0; j < rozmiar; ++j)
				plik >> tablica[i][j];
		}
		//w celu sprawdzenia czy dobrze wczytuje z pliku odkomentowac ta funckje
		/*cout << "TABLICA WCZYTANA Z PLIKU" << endl;
		for (int i = 0; i < rozmiar; ++i, cout << endl)
			for (int j = 0; j < rozmiar; ++j)
				cout << tablica[i][j] << '\t';*/
		cout << endl;
		plik.close();
		return tablica;
	}

	
};

void generowanie(int rozmiar, double wypelnienie)
{
	int  procent = (1 - wypelnienie)*(rozmiar*(rozmiar - 1));
	int l_zer = 0;
	int **tab2 = new int *[rozmiar]; //alokacja pamieci
	for (int i = 0; i < rozmiar; ++i)
	{
		tab2[i] = new int[rozmiar]; //alokacja pamieci
		for (int j = 0; j < rozmiar; ++j)
			//wpisanie randomowych wartosci do tablicy
		{
			//if (i > j)
			//{
				tab2[i][j] = (rand() % 10 + 1);
			//}
		}
	}

	//for (int k = 0; k < rozmiar; k++) // odbicie lustrzane
	//{
	//	for (int w = 0; w < rozmiar; w++)
	//	{
	//		tab2[k][w] = tab2[w][k];
	//	}
	//}

	for (int p = 0; p < rozmiar; p++)
	{
		tab2[p][p] = 0;
	}

	while (l_zer != procent)
	{
		int kolumna = rand() % rozmiar;
		int wiersz = rand() % rozmiar;
		if (tab2[wiersz][kolumna] != 0)
		{
			tab2[wiersz][kolumna] = 0;
			l_zer++;
		}

	}

	//wypisz tab2[w][k]
	obslugapliku plik;
	cout << "TABLICA" << endl;
	for (int i = 0; i < rozmiar; ++i, cout << endl)
		for (int j = 0; j < rozmiar; ++j)
			cout << tab2[i][j] << '\t';
	cout << endl;
	plik.zapis(tab2, rozmiar);

	//funkcja algorytmu dijkstry 
	dane* tab = Dijkstra(tab2, rozmiar, 0);
	cout << "Wezel\tPoprz.\tDystans" << endl;
	for (int i = 0; i < rozmiar; i++)
		wypiszdane(i, tab[i]);

	//zniszcz tab2
	for (int i = 0; i < rozmiar; ++i)
		delete[] tab2[i]; //uwolnienie pamieci
	delete[] tab2;
}

lista* konwertuj(int** macierz, int liczba_elementow)
{
	lista* graf = new lista[liczba_elementow];
	for (int i = 0; i < liczba_elementow; i++)
	{
		for (int j = 0; j < liczba_elementow; j++)
		{
			if (macierz[i][j] > 0)
				graf[i].dodaj_element(j, macierz[i][j]);

		}
	}
	for (int i = 0; i < liczba_elementow; i++) {
		cout << i << ": " << endl;
		graf[i].wyswietl();

	}
	return graf;
}

#endif GENERATOR_H