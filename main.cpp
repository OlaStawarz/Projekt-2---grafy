#include <iostream>
#include "generator.h"
#include "algorytm.h"
using namespace std;

int main()
{
	obslugapliku odczyt;
	/*double wypelnienie[] = { 1 };

		for (int i = 0; i < 1; i++)
		{
			generowanie(5, wypelnienie[i]);
		}*/
	int ** macierz = odczyt.wczytaj(6);
	dane* tab = Dijkstra(macierz, 6, 0);
	cout << "Wezel\tPoprz.\tDystans" << endl;
	for (int i = 0; i < 6; i++)
		wypiszdane(i, tab[i]);
	konwertuj(macierz, 6);

	//kolejka proba(5);
	//proba.dodaj_wartosc(1, 5);
	//proba.dodaj_wartosc(2, 1);
	//proba.dodaj_wartosc(3, 3);
	//proba.wyswietl();
	//cout << proba.zwroc_wartosc();
	//cout << proba.zwroc_wartosc();
	//cout << proba.zwroc_wartosc();
	//
	

	system("pause");
	return 0;
}