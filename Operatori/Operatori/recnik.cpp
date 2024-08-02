#include "recnik.h"


void Recnik::kopiraj(const Recnik& rec) {
	prvi = nullptr;
	for (Elem* tek = rec.prvi, *posl=nullptr; tek ; tek=tek->sled)
	{
		posl = (prvi ? posl->sled : prvi) = new Elem(tek->odr);

	}

}


void Recnik::brisi() {
	while (prvi)
	{
		Elem* stari = prvi;
		prvi = prvi->sled;
		delete stari;
	}

}

Recnik& Recnik::operator+=(const Odred& odr) {
	Elem* tek = prvi, * pret = nullptr;
	while (tek && tek->odr<odr)
	{
		pret = tek;
		tek = tek->sled;
	}
	(!pret ? prvi : pret->sled) = new Elem(odr, tek);

	return *this;
}


Recnik Recnik::operator<<(string poj) {
	Recnik rec;
	for (Elem* tek = prvi; tek ; tek=tek->sled)
	{
		if (tek->odr==poj)
		{
			rec += tek->odr;
		}
	}
	return rec;
}

ostream& operator<<(ostream& it, const Recnik& rec) {
	for (Recnik::Elem* tek= rec.prvi; tek; tek=tek->sled)
	{
		it << tek->odr << endl;
	}
	return it;
}


