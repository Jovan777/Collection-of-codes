#include "imenik.h"
#include <iostream>
using namespace std;





Imenik& Imenik::dodaj(const Osoba& oso) {


	Elem* tek = prvi, * pret = nullptr;

	while (tek && veci(oso.dohv_JMBG(), tek->oso.dohv_JMBG()))
	{
		pret = tek;
		tek = tek->sled;
	}

	(!pret ? prvi : pret->sled) = new Elem(oso, tek);
	return *this;


}

void Imenik::pisi() const {

	for (Elem* tek = prvi; tek ; tek=tek->sled)
	{
		tek->oso.pisi();
		cout << endl;
	}

}

Imenik::~Imenik() {

	while (prvi)
	{
		Elem* stari = prvi;
		prvi = prvi->sled;
		delete stari;

	}

}

Imenik::Imenik(const Imenik& im) {

	for (Elem* tek = im.prvi; tek ; tek=tek->sled)
	{
		posl = (!prvi ? prvi : posl->sled) = new Elem(tek->oso);
	}

}