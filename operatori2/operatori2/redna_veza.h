#ifndef redna_veza_h
#define redna_veza_h

#include "otpornik.h"
#include <iostream>

using namespace std;





class Redna_veza
{
	Otpornik* niz;
	int kap, duz;
	void kopiraj(const Redna_veza& rv) {
		kap = rv.kap;
		duz = rv.duz;
		niz = new Otpornik[kap];
		for (int i = 0; i < duz; i++)
		{
			niz[i] = rv.niz[i];
		}

	}
	void premesti(Redna_veza& rv) {
		niz = rv.niz;
		kap = rv.kap;
		duz = rv.duz;
		rv.niz = nullptr;

	}
	void brisi() {
		delete[] niz;
	}
public:

	Redna_veza(int k = 2) : kap(k), duz(0) {
		niz = new Otpornik[kap];
	}
	Redna_veza(const Redna_veza& rv) {
		kopiraj(rv);
	}
	Redna_veza(Redna_veza&& rv) {
		premesti(rv);
	}
	~Redna_veza()
	{
		brisi();
	}

	Redna_veza& operator=(const Redna_veza& rv) {
		if (this!=&rv)
		{
			brisi();
			kopiraj(rv);
		}
		return *this;

	}

	Redna_veza& operator=(Redna_veza&& rv) {
		if (this!=&rv)
		{
			brisi();
			premesti(rv);
		}
		return *this;
	}

	int getKap() const {
		return kap;
	}
	int getDuz() const {
		return duz;
	}

	Otpornik operator[](int i) {
		if (i<0 || i>=duz)
		{
			exit(1);
		}
		return niz[i];
	}

	Redna_veza& operator+=(Otpornik r) {
		if (duz==kap)
		{
			return *this;
		}
		niz[duz++] = r;
		return *this;

	}

	Otpornik* begin() {
		return niz;
	}

	Otpornik* end() {
		return niz + duz;
	}

	double vrednost() const {
		double suma = 0;
		for (int i = 0; i < duz; i++)
		{
			suma += niz[i].getR();
		}

		return suma;
	}

	friend ostream& operator<<(ostream& it, Redna_veza& rv) {
		for (int i = 0; i < rv.duz-1; i++)
		{
			it << rv.niz[i].getR() << "+";
		}
		it << rv.niz[rv.duz - 1].getR();
		return it;
	}

	Redna_veza& izbaci() {
		int j = 0;
		for (int i = 0; i < duz; i++)
		{
			if (niz[i].getR()!=0)
			{
				niz[j++] = niz[i];
			}

		}
		duz = j;
		return *this;
	}



};

#endif // !redna_veza_h
