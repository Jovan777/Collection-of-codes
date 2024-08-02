#include "lista2.h"
#include <iostream>

using namespace std;


/*

int Lista::duz() const {
	int n = 0;
	for (Elem* tek = prvi; tek ; tek=tek->sled)
	{
		n++;
	}

	return n;
}

void Lista::pisi() const {

	for (Elem* tek = prvi; tek ; tek=tek->sled)
	{
		cout << tek->broj << " ";
	}
	cout << endl;

}



void Lista::na_kraj(int b) {

	Elem* novi = new Elem(b);
	if (!prvi)
	{
		prvi = novi;
	}
	else
	{
		Elem* tek = prvi;
		while (tek->sled)
		{
			tek = tek->sled;
		}
		tek->sled = novi;

	}


}


void Lista::citaj1(int n) {
	prazni();
	for (int i = 0; i < n; i++)
	{
		int b; cin >> b;
		prvi = new Elem(b, prvi);

	}



}


void Lista::citaj2(int n) {
	prazni();
	Elem* posl = nullptr;
	for (int i = 0; i < n; i++)
	{
		int b; cin >> b;
		Elem* tek = new Elem(b, nullptr);
		if (prvi==nullptr)
		{
			prvi = tek;
		}
		else
		{
			posl->sled = tek;
		}
		posl = tek;



	}


}

Lista::Lista(const Lista& lst) {
	prvi = nullptr;
	for (Elem* tek = lst.prvi, *posl=nullptr; tek ; tek=tek->sled)
	{
		Elem* novi = new Elem(tek->broj, nullptr);
		if (!prvi)
		{
			prvi = novi;
		}
		else
		{
			posl->sled = novi;
		}
		posl = novi;


	}

}

void Lista::umetni(int b) {

	Elem* tek = prvi, * pret = nullptr;

	while (tek && tek->broj<b)
	{
		pret = tek;
		tek = tek->sled;

	}
	Elem* novi = new Elem(b, tek);
	if (!pret)
	{
		prvi = novi;
	}
	else
	{
		pret->sled = novi;

	}


}

void Lista::prazni() {

	while (prvi)
	{
		Elem* stari = prvi;
		prvi = prvi->sled;
		delete stari;



	}



}


void Lista::izostavi(int b) {

	Elem* tek = prvi, * pret = nullptr;

	while (tek)
	{
		if (tek->broj!=b)
		{
			pret = tek;
			tek = tek->sled;
		}
		else
		{
			Elem* stari = tek;
			tek = tek->sled;
			if (!prvi)
			{
				prvi = tek;
			}
			else
			{
				pret->sled = tek;

			}
			delete stari;


		}


	}




}
*/