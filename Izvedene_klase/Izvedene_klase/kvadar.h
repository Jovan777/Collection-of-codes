#ifndef  _kvadar_h_
#define _define_h_
#include "predmet.h"


class Kvadar : public Predmet {

	double a, b, c;

public:

	Kvadar(double s=1, double aa=1, double bb=1, double cc=1) : Predmet(s), a(aa), b(bb), c(cc) {};

	double V() const override {
		return a * b * c;
	}

private:
	void citaj(istream& it) override {
		it >> a >> b >> c;
	}

	void pisi(ostream& it) const override {
		it << "Kvadar : [ "; Predmet::pisi(it); it << a << " , " << b << " , " << c << " ]";

	}


};



#endif // ! _kvadar_h_
