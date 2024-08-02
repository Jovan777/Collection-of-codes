#include "cvecara.h"

void Cvecara::dodaj(Buket b) {

	if ((b.prodajna() - b.nabavna()) < (b.nabavna() * 0.2))
	{
		return;
	}


	Elem* temp = prvi, * pret = nullptr;

	if (!prvi )
	{
		posl = prvi = new Elem(b);
		return;
	}

	while (temp && temp->buket.prodajna() < b.prodajna())
	{
		pret = temp;
		temp = temp->sled;

	}
	Elem* novi = new Elem(b);
	(pret ? pret->sled : prvi) = novi;
	novi->sled = temp;

	zarada -= novi->buket.nabavna();
}

void Cvecara::kopiraj(const Cvecara& c) {
	Elem* temp = c.prvi;
	prvi = posl = nullptr;
	while (temp)
	{
		posl = (prvi ? posl->sled : prvi) = new Elem(temp->buket);
	}

}

void Cvecara::prodaj(int n) {
	Elem* temp = prvi;
	Elem* pret = nullptr;

	int i = 0;
	while (temp && i<n)
	{
		pret = temp;
		temp = temp->sled;
		i++;

	}

	if (!temp)
	{
		cout << "Nema buketa na zadatoj poziciji"<<endl;
		exit(1);
	}

	Elem* stari = temp;
	zarada += temp->buket.prodajna();
	(pret ? pret->sled : prvi) = temp->sled;

	delete temp;


}