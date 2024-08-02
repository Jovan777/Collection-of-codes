#include "lista_dat.h"


#include <iostream>
using namespace std;

Lista::Lista(const Lista& lst) {
	prvi = posl = nullptr;
	duz = 0;

	for (Elem* tek = lst.prvi; tek ; tek=tek->sled)
	{
		dodaj(tek->dat);
	}


}


Lista::~Lista() {
	while (prvi)
	{
		Elem* stari = prvi;
		prvi = prvi->sled;
		delete stari;
	}
}


const Datum* Lista::max() const {

	if (!prvi)
	{
		return nullptr;
	}
	Datum* m = &prvi->dat;
	for (Elem* tek = prvi->sled; tek ; tek->sled)
	{
		if (m->uporedi(tek->dat)<0)
		{
			m = &tek->dat;
		}


	}

	return m;



}

void Lista::pisi() const {
	for (Elem* tek = prvi; tek ; tek=tek->sled)
	{
		tek->dat.pisi(); cout << " ";
	}

}