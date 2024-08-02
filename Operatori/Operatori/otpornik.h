#include <iostream>
using namespace std;


class Otpornik {

	double r, dr;

public:
	Otpornik(double rr = 1000, double drr = 1) : r(rr), dr(drr) {};

	double otp() const {
		return r;
	}

	Otpornik& operator++() {
		r += dr;
		return *this;
	}
	
	Otpornik& operator--() {
		r -= dr;
		if (r<0)
		{
			r = 0;
		}
		return *this;
	}

	friend ostream& operator<<(ostream& it, const Otpornik& r) {
		return it << "R ( " << r.r << " , " << r.dr << " ) ";
	}

	friend istream& operator>>(istream& ut, Otpornik& r) {
		return ut >> r.r >> r.dr;
	}

};