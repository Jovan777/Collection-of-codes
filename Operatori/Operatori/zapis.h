#include <string>
#include <iostream>
using namespace std;



class Zapis {

	string naz, jed;
	double kol, cen;

public:

	Zapis(string n, string j, double c) : naz(n), jed(j), kol(0), cen(c) {};

	string dohvNaz() const {
		return naz;
	}
	string dohvJed() const {
		return jed;
	}

	double dohvKol() const {
		return kol;
	}
	double dohvCen() const {
		return cen;
	}

	double vrednost() const {
		return cen * kol;
	}

	bool operator+=(double dk) {
		if ((kol+dk)<0)
		{
			return false;
		}
		kol += dk;
		return true;
	}

	friend ostream& operator<<(ostream& it, const Zapis& z) {
		return it << z.naz << " : " << z.kol << z.jed << "x" << z.cen << " din = " << z.vrednost() << " din ";
	}


};