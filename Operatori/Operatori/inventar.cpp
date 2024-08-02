#include "inventar.h"
using namespace std;

void Inventar::kopiraj(const Inventar& inv) {
	niz = new Zapis * [kap = inv.kap];
	duz = inv.duz;
	int i = 0;
	for (const Zapis* pz: inv )
	{
		niz[i++] = new Zapis(*pz);
	}


}

void Inventar::brisi() {
	if (!niz)
	{
		return;
	}
	for (Zapis* pz : *this) {
		delete pz;
	}
	delete[] niz;

}

Zapis* Inventar::operator[](string naziv) {
	for (Zapis* pz : *this) {
		if (pz->dohvNaz()==naziv)
		{
			return pz;
		}
	}
	return nullptr;

}

double Inventar::vrednost() const {
	double v = 0;
	for (const Zapis* pz : *this) {
		v += pz->vrednost();
	}

	return v;

}



ostream& operator<<(ostream& it,const Inventar& inv) {
	for (const Zapis* pz : inv) {
		it << *pz << endl;
	}
	return it << "============================\n" << "UKUPNO : " << inv.vrednost() << " din" << endl;

}
