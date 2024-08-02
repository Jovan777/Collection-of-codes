#ifndef _brzina_h_
#define _brzina_h_



#include "vektor1.h"
using namespace std;


class Brzina : public Vektor {

private:
	void pisi(ostream& it) const override {
		it << "v";
		Vektor::pisi(it);
	}

public:
	Brzina() : Vektor() {};
	Brzina(double x, double y, double z) : Vektor(x, y, z) {};



};



#endif // !_brzina_h_
