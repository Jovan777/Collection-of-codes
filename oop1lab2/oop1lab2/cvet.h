#ifndef cvet_h
#define cvet_h



#include <iostream>
using namespace std;



class Cvet
{
	string naziv;
	int nabavna;
	int prodajna;

public:
	Cvet(string n, int nab, int pro) : naziv(n), nabavna(nab), prodajna(pro) {};

	string dohvNaziv() const {
		return naziv;
	}
	
	int dohvNab() const {
		return nabavna;
	}

	int dohvProd() const {
		return prodajna;
	}
	
	int zarada() const {
		return prodajna - nabavna;
	}

	friend bool operator==(const Cvet& c1, const Cvet& c2) {
		return c1.naziv == c2.naziv;
	}

	friend ostream& operator<<(ostream& it, const Cvet& c) {
		return it << c.naziv;
	}




};

#endif // !cvet_h
