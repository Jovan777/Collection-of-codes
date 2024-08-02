#ifndef _kvadrat_h_
#define _kvadrat_h_
#include "figura1.h"

class Kvadrat : public Figura {

	double a;

public:

	Kvadrat(double aa=1, const Tacka& t = ORG) : a(aa), Figura(t) {};

	double O() const override {
		return 4 * a;
	}

	double P() const override {
		return a * a;
	}

	Kvadrat* kopija() const override {
		return new Kvadrat(*this);
	}

private:
	void citaj(istream& ut) override{
		Figura::citaj(ut);
		ut >> a;
	}
	void pisi(ostream& it) const override {
		it << "kvadrat : [ ";
		Figura::pisi(it);
		it << ", a = " << a << ", O = " << O() << ", P = " << P() << " ] ";

	}



};






#endif // !_kvadrat_h_
