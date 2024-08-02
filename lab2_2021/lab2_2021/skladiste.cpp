#include "skladiste.h"


void Skladiste::kopiraj(const Skladiste& s) {
	prvi = nullptr; posl = nullptr;
	for (Elem* temp = s.prvi; temp ; temp=temp->sled)
	{
		posl = (prvi ? posl->sled : prvi) = new Elem(temp->k);
	}

	

}

int Skladiste::operator()(double v1, double v2) {
	int n=0;

	for (Elem* temp = prvi; temp ; temp=temp->sled)
	{
		if (temp->k->V() <v1 && temp->k->V()<v2)
		{
			n++;
		}
	}
	return n;

}