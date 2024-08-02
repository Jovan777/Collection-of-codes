#include "redna_veza.h"

double Redna_veza::otp() const {
	double R = 0;
	for(Otpornik r  : *this)
	{
		R += r.otp();
	}
	return R;
}

void Redna_veza::kopiraj(const Redna_veza& rv) {
	niz = new Otpornik[kap = rv.kap];
	duz = rv.duz;
	int i = 0;
	for (Otpornik r : rv) {
		niz[i++] = r;
	}


}


Redna_veza& Redna_veza::izbaci() {
	int j = 0;
	for (Otpornik r : *this) {
		if (r.otp())
		{
			niz[j++] = r;
		}
	}
	duz = j;
	return *this;
}

ostream& operator<<(ostream& it, Redna_veza& rv) {
	int i = 0;
	for (Otpornik r : rv) {
		if (i++)
		{
			it << "+";
		}
		it << r;
	}
	return it;
}