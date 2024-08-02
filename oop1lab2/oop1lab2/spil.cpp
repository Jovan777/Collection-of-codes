#include "spil.h"

Spil& Spil::operator+=(Slicica* c) {
	posl = (prvi ? posl->sled : prvi) = new Elem(c);

	return *this;
}

bool Spil::operator%(int k) {
	Elem* temp = prvi;
	while (temp)
	{
		if (temp->slicica->dohvBr()==k)
		{
			return true;
		}
		temp = temp->sled;
	}
	return false;

}

void Spil::naPocetak(int k) {
	Elem* temp = prvi;
	Elem* pret = nullptr;

	int i = 0;
	while (temp && i<k)
	{
		pret = temp;
		temp = temp->sled;
		i++;

	}

	if (temp)
	{
		(pret ? pret->sled : prvi) = temp->sled;

		temp->sled = prvi;
		prvi = temp;
	}

	return;


}

void Spil::naSledece(int k) {
	Elem* temp = prvi;
	Elem* pret=nullptr;


	int i = 0;
	while (temp && i < k)
	{
		pret = temp;
		temp = temp->sled;
		i++;

	}

	Elem* sl;
	if (temp)
	{
		sl = temp->sled;
		temp->sled = sl->sled;
		sl->sled = temp;
		pret->sled = sl;
	}

	return;


}

bool Spil::ima(int k) {
	Elem* temp = prvi;

	int i = 0;
	while (temp && i < k)
	{
		temp = temp->sled;
		i++;

	}

	if (temp)
	{
		return true;
	}

	return false;


}

Slicica* Spil::dohvTren(int k) {

	Elem* temp = prvi;

	int i = 0;
	while (temp && i < k)
	{
		temp = temp->sled;
		i++;

	}

	if (temp)
	{
		return temp->slicica;
	}


};
