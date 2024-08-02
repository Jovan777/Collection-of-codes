#include "lista6.h"


U_Lista& U_Lista::operator+=(int b){


	Elem* temp = prvi;
	Elem* pret = nullptr;


	while (temp && temp->br<b)
	{
		pret = temp;
		temp = temp->sled;
	}
	Elem* novi = new Elem(b, temp);
	(pret ? pret->sled : prvi) = novi;
	if (!temp)
	{
		posl = novi;
	}
	duz++;

	return *this;

}