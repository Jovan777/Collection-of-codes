#ifndef zapis_h_
#define zapis_h_

#include<iostream>
using namespace std;


class Zapis
{
	string naziv, jed;
	double kol, cena;


public:
	Zapis(string n, string j, double c, double k=0) : naziv(n), jed(j), kol(k), cena(c) {};

	string getN() const {
		return naziv;
	}

	string getJ() const {
		return jed;
	}

	double getK() const {
		return kol;
	}
	double getC() const {
		return cena;
	}
	double vrednost() const {
		return kol * cena;
	}

	bool operator+=(double dk) {
		kol += dk;
		return true;
	}

	friend ostream& operator<<(ostream& it, const Zapis& z) {
		return it << z.naziv << ": " << z.kol << z.jed << " x "
			<< z.cena << "din = " << z.vrednost() << "din";
	}


};

#endif // !zapis_h_
