#ifndef flota_h_
#define flota_h_

#include <string>
#include <iostream>
#include <cstdlib>
#include "avion.h"






class Flota
{
	
	//friend int main(int);

public:
	struct Elem {
		Avion* avion;
		Elem* sled;
		Elem(Avion* a, Elem* s = nullptr) : avion(a), sled(s) {};

	};
	Flota(string n) : name(n), prvi(nullptr), posl(nullptr) {};

	void dodaj(Avion* a) {
		posl = (prvi ? posl->sled : prvi) = new Elem(a);
	}

	int numberOfPlanes() const {
		int br = 0;
		Elem* temp = prvi;
		while (temp)
		{
			br++;
			temp = temp->sled;

		}
		return br;
	}

	int brojP() const {
		int br = 0;
		Elem* temp = prvi;
		while (temp)
		{
			br += temp->avion->getMax();
			temp = temp->sled;

		}
		return br;


	}

	Avion* getMaxA() {
		int max = -1;
		Elem* temp = prvi;
		Avion* maxA=nullptr;
		while (temp)
		{
			if (temp->avion->getMax()>max)
			{
				maxA = temp->avion;
				max = temp->avion->getMax();
			}
			temp = temp->sled;

		}

		return maxA;
	}

	void pisi() const {

		cout << name << endl;
		Elem* temp = prvi;
		while (temp)
		{
			temp->avion->pisi(); cout << endl;
			temp = temp->sled;
		}


	}


	void brisiAvion(string imeA) {
		for (Elem* temp = prvi, *pret=nullptr; temp ; )
		{
			if (temp->avion->getName()!=imeA)
			{
				pret = temp;
				temp = temp->sled;

			}
			Elem* stari = temp;
			temp = temp->sled;
			(prvi ? pret->sled : prvi) = temp;
			return;

		}


	}

	Elem* dohvMax(int min, int max);

private:
	string name;

	Elem* prvi, * posl;



};

#endif // !flota_h_
