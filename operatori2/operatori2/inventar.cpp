#include "inventar.h"

void Inventar::kopiraj(const Inventar& inv) {
	niz = new Zapis * [kap = inv.kap];
	duz = inv.duz;
	int i = 0;
	for (const Zapis* pz : inv) {
		niz[i++] = new Zapis(*pz);
	}

	

}

void Inventar::brisi() {

	for (Zapis * pz  : (*this))
	{
		delete pz;
	}
	delete[] niz;

}

Zapis* Inventar::operator[](string naziv) {
	for (int i = 0; i < duz; i++)
	{
		if (niz[i]->getN()==naziv)
		{
			return niz[i];
		}

	}
	return nullptr;
}

double Inventar::vrednost() const {
	double s = 0;
	for (int i = 0; i < duz; i++)
	{
		s += niz[i]->vrednost();

	}

	return s;
}

ostream& operator<<(ostream& it, const Inventar& inv) { // Pisanje.
	for (const Zapis* pz : inv) it << *pz << endl;
	return it << "==============================\n"
		<< "UKUPNO:   " << inv.vrednost() << "din" << endl;
}