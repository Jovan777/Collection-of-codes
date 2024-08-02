#include "flota.h"


Flota::Elem* Flota::dohvMax(int min, int max) {
	int tek;
	int maxP = -1;

	Elem* temp = prvi;
	while (temp)
	{
		tek = temp->avion->getMax();
		if (tek>maxP && tek>min &&  tek<max)
		{
			maxP = tek;
		}
		temp = temp->sled;


	}

	Elem* head=nullptr, *last=nullptr;

	temp = prvi;
	while (temp)
	{
		if (temp->avion->getMax() == maxP)
		{
			//Elem* novi = new Elem(temp->avion);
			last = (head ? last->sled : head) = new Elem(temp->avion);

		}
		temp = temp->sled;

	}


	return head;

}