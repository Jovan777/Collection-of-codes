#include "flota.h"


int Flota::brojA() const {

	int b = 0;
	for (Elem* temp = prvi; temp ; temp=temp->sled)
	{
		b++;
	}
		
	return b;
}

void Flota::dodaj(Avion* a) {

	posl = (prvi ? posl->sled : prvi) = new Elem(a);

}

int Flota::maxP() const{
	int b = 0;

	for (Elem* temp = prvi; temp; temp=temp->sled)
	{
		int k = temp->avion->getMax();
		b += k;

	}
	return b;

}

Avion* Flota::maxA() {

	Avion* a = prvi->avion;
	for (Elem* temp = prvi->sled; temp ; temp=temp->sled)
	{
		if (temp->avion->getMax()>a->getMax())
		{
			a = temp->avion;
		}

	}

	return a;

}

void Flota::pisi() const {

	cout << imeFLote << endl;
	for (Elem* temp = prvi;  temp ;  temp=temp->sled)
	{
		cout << *temp->avion ;
	}


}


void Flota::izbaci(string ime) {

	
	for (Elem* temp = prvi, *pret=nullptr; temp ; temp=temp->sled)
	{
		if (temp->avion->getIme()!=ime)
		{
			pret = temp;
			temp = temp->sled;
		}
		else
		{
			Elem* stari = temp;
			temp = temp->sled;
			if (!pret)
			{
				prvi = temp;
			}
			else
			{
				pret->sled = temp;
			}

		}


	}



}


Avion* Flota::dohvA(int min, int max) {
	int n = 0;
	for (Elem* temp = prvi; temp; temp = temp->sled)
	{
		if (temp->avion->getMax() >= min && temp->avion->getMax() <= max)
		{
			n++;
		}
	}

	Avion* a = new Avion[n];
	int index = 0;
	for (Elem* temp = prvi; temp; temp = temp->sled)
	{
		if (temp->avion->getMax() >= min && temp->avion->getMax() <= max)
		{
			a[index++] = *temp->avion;
		}
	}

	return a;
}