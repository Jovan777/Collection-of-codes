#ifndef otpornik_h_
#define otpornik_h_

#include <iostream>
using namespace std;







class Otpornik
{

	double r, dr;



public:
	Otpornik(double rr = 1, double ddr = 1) : r(rr), dr(ddr) {};

	double getR() const {
		return r;
	}

	double getDr() const {
		return dr;
	}

	Otpornik& operator++() {
		r += dr;
		return *this;
	}

	Otpornik& operator--() {
		r = (r - dr) > 0 ? r - dr : 0;
		return *this;
	}

	friend istream& operator>>(istream& it, Otpornik& o) {
		it >> o.r >> o.dr;
		return it;

	}

	friend ostream& operator<<(ostream& it, Otpornik& o) {
		return it << "(" << o.r << ", " << o.dr << ")";
	}



};

#endif // !otpornik_h_
