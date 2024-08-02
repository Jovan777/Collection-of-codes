#ifndef cvet_h_
#define cvet_h_


#include <string>
#include <iostream>

using namespace std;





class Cvet
{
	string naziv;
	int nabavna;
	int prodajna;


public:
	Cvet(string n, int nab, int pro) : naziv(n), nabavna(nab), prodajna(pro) {};

	string getNaziv() const { return naziv; }
	int getNabavna() const { return nabavna; }
	int getProdajna() const { return prodajna; }

	int zarada() const { return prodajna - nabavna; }

	friend bool operator==(const Cvet& c1, const Cvet& c2) {
		return c1.getNaziv() == c2.getNaziv();
	}

	friend ostream& operator<<(ostream& it, const Cvet& c) {
		return it << c.naziv;
	}





};

#endif // !cvet_h_
