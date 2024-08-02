#include "red1.h"



void Red::kopiraj(const Red& r) {

	prvi = posl = nullptr;
	duz = r.duz;
	for (Elem* tek = r.prvi; tek ; tek=tek->sled)
	{
		posl = (prvi ? posl->sled : prvi) = new Elem(tek->pod);
	}

}

void Red::brisi() {

	while (prvi)
	{
		Elem* stari = prvi;
		prvi = prvi->sled;
		delete stari;
	}
	posl = nullptr;
	duz = 0;
}


Red& Red::operator+=(const Red& r) {

	if (r.prvi)
	{
		Red s(r);
		(posl ? posl->sled : prvi) = s.prvi;
		posl = s.posl;
		duz += s.duz;
		s.prvi = s.posl = nullptr;
		s.duz = 0;



	}
	return *this;
}

int Red::uzmi() {
	if (!prvi)
	{
		exit(1);
	}
	int pod = prvi->pod;
	Elem* stari = prvi;
	prvi = prvi->sled;
	delete stari;
	if (!prvi)
	{
		posl = nullptr;
	}
	duz--;
	return pod;


}

Red Red::operator-(int k) const {
	Red r;
	for (Elem* tek = prvi; tek ; tek=tek->sled)
	{
		if (tek->pod!=k)
		{
			r += tek->pod;
		}
	}

	return r;
}


