#include "Buket.h"


void Buket::kopiraj(const Buket& b) {
	prvi = nullptr;posl = nullptr;

	for (Elem* temp = b.prvi; temp ; temp=temp->sled)
	{
		posl = (prvi ? posl->sled : prvi) = new Elem(temp->cvet);

	}


}