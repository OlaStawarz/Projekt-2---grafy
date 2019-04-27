#ifndef LISTA_H
#define LISTA_H
#include <iostream>

using namespace std;

struct element
{
	int wierzcholek;
	int priorytet;
	element* nastepny;
	element(int wierzcholek, int priorytet)
	{
		this->wierzcholek = wierzcholek;
		this->priorytet = priorytet;
		nastepny = NULL;
	}
};

class lista
{
	element* head;
public:
	lista()
	{
		head = NULL;
	}
	void dodaj_element(int wierzcholek, int priorytet)
	{
		element* pom = new element(wierzcholek, priorytet);
		
		if (head == NULL)
		{
			head = pom;
		}
		else
		{
			element* iterator = head;
			while (iterator->nastepny)
			{
				iterator = iterator->nastepny;
			}
			iterator->nastepny = pom;

		}
	}
	void wyswietl()
	{
		element* iterator = head;
		do
		{
			cout << iterator->wierzcholek << ", " << iterator->priorytet << endl;
			iterator = iterator->nastepny;
		} while (iterator);
	}
	int sprawdz(int wierzcholek)
	{
		if (head != NULL)
		{
			element* iterator = head;
			do
			{
				if (wierzcholek == iterator->wierzcholek)
				{
					return iterator->priorytet;
				}
				iterator = iterator->nastepny;
			} while (iterator);
		}
	return -1;		
	}
	void wyswietl_wierzcholki()
	{
		element* iterator = head;
			do
			{
				cout << iterator->wierzcholek << " ";
				iterator = iterator->nastepny;
			} while (iterator);
			cout << endl;
	}

	int liczba_sasiadow()
	{
		int liczba = 0;
		element* iterator = head;
		while (iterator)
		{
			liczba++;
			iterator = iterator->nastepny;
		} 
		return liczba;
	}
	
};
#endif