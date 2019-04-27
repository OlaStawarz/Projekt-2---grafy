#include <iostream>
#include "generator.h"
#include "algorytm.h"
#include <string>

using namespace std;
using tp = chrono::time_point<std::chrono::system_clock>;
using duration = chrono::duration<float>;

int main()
{
	tp start;
	duration d;

	obslugapliku odczyt;
	int rozmiar;
	string sciezka;
	double wypelnienie[] = { 1 }; // { 1, 0.75, 0.5, 0.25 };
	int rozmiary[] = { 10, 50 }; // , 100, 500, 1000};
	int numer = 0;
	//
	//for (int i = 0; i < 2; i++)
	//{
	//	for (int j = 0; j < 1; j++)
	//	{
	//		for (int k = 0; k < 1; k++)
	//		{
	//			generowanie(rozmiary[i], wypelnienie[j], numer);
	//			numer++;
	//		}
	//	}
	//}
	
	for (int i = 0; i < 5; i++)
	{
		sciezka.clear();
		sciezka += to_string(i) + ".txt";
		int ** macierz = odczyt.wczytaj(rozmiar, sciezka);
		start = chrono::system_clock::now();
		dane* tab = Dijkstra(macierz, rozmiar, 0);
		d = chrono::system_clock::now() - start;
		odczyt.zapiszczas_macierz(d);
		cout << "Wezel\tPoprz.\tDystans" << endl;
		wypiszdane2(tab, rozmiar);
		lista* graf = konwertuj(macierz, rozmiar);
		start = chrono::system_clock::now();
		tab = Dijkstra_lista(graf, rozmiar, 0);
		d = chrono::system_clock::now() - start;
		odczyt.zapiszczas_lista(d);
		cout << "Wezel\tPoprz.\tDystans" << endl;
		wypiszdane2(tab, rozmiar);		
	}

	//sciezka = "graf.txt";
	
	

	system("pause");
	return 0;
}