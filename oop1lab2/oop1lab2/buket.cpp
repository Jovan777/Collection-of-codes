#include "buket.h"


void Buket::kopiraj(const Buket& b) {
	Elem* temp = b.prvi;
	prvi = posl = nullptr;
	while (temp)
	{	
		posl = (prvi ? posl->sled : prvi) = new Elem(temp->cvet);
		temp = temp->sled;
	}



}

void Buket::premesti(Buket& b) {

	prvi = b.prvi;
	posl = b.posl;
	b.prvi = nullptr;
	b.posl = nullptr;


}

void Buket::brisi() {
	while (prvi)
	{
		Elem* temp = prvi;
		prvi = prvi->sled;
		delete temp;

	}
	posl = nullptr;


}