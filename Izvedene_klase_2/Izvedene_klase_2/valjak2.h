#ifndef _valjak2_h_
#define _valjak2_h_

#include "telo1.h"
using namespace std;


#include <utility>



class Valjak : public Telo {

	double r, h;

public:

	explicit Valjak(double rr = 1, double hh = 1) : r(rr), h(hh) {};

	char vrsta() const override {
		return 'V';
	}
	double V() const override {
		return r * r * h * 3.14159;
	}

	Valjak* kopija() const& override {
		return new Valjak(*this);
	}
	Valjak* kopija() && override {
		return new Valjak(move(*this));
	}

private:
	void pisi(ostream& it) const override {
		it << "V(" << r << ", " << h << ")";
	}

};





#endif // !_valjak2_h_
