#ifndef _trougao4_h_
#define _trougao4_h_

#include "figura1.h"


class Trougao : public Figura {
	double a, b, c;

public:

	Trougao(double aa, double bb, double cc, const Tacka& t = ORG) : a(aa), b(bb), c(cc), Figura(t) {};

	Trougao(double aa=1, const Tacka& t = ORG) : a(aa), b(aa), c(aa), Figura(t) {};

	double O() const override {
		return a + b + c;
	}
	double P() const override {
		double s = (a + b + c) / 2;
		return sqrt(s * (s - a) * (s - b) * (s - c));

	}

	Trougao* kopija() const override {
		return new Trougao(*this);
	}

private:
	void citaj(istream& ut) override {
		Figura::citaj(ut);
		ut >> a >> b >> c;
	}

	void pisi(ostream& it) const override {
		it << "trougao : [ "; Figura::pisi(it);
		it << ", a = " << a << " , b = " << b << " , c = " << c << " , " << O() << " , P = " << P() << " ] ";

	}



};



#endif // !_trougao4_h
