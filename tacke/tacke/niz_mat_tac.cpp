#include "niz_mat_tac.h"
#include <iostream>
using namespace std;



Niz_mat_tac::Niz_mat_tac(const Niz_mat_tac& nmt) {

	niz = new Mat_tacka[kap = nmt.kap];
	duz = nmt.duz;
	for (int i = 0; i < kap; i++)
	{
		niz[i] = nmt.niz[i];
	}

}


Niz_mat_tac& Niz_mat_tac::dodaj(const Mat_tacka& mt) {

	if (duz==kap)
	{
		Mat_tacka* pom = new Mat_tacka[kap += 5];
		for (int i = 0; i < kap; i++)
		{
			pom[i] = niz[i];

		}
		delete[] niz;
		niz = pom;

	}
	niz[duz++] = mt;
	return *this;



}


Mat_tacka Niz_mat_tac::maxF(const Mat_tacka& mt) const {
	double max = mt.F(niz[0]);
	int id = 0;
	for (int i = 0; i < duz; i++)
	{
		double F = mt.F(niz[i]);
		if (F>max)
		{
			max = F;
			id = i;
		}
	}

	return niz[id];

}

void Niz_mat_tac::pisi() const {
	for (int i = 0; i < duz; i++)
	{
		niz[i].pisi();
		cout << endl;
	}
}
