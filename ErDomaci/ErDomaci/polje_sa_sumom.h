#ifndef polje_sa_sumom
#define polje_sa_sumom


#include "polje.h"
#include <iostream>


class Polje_sa_sumom : public Polje
{

	unsigned int gustina;
	void pisi(ostream& it) const override {
		it << oznaka()<<"_"<<neprohodnost << "(" << gustina << ")";

	}


public:
	Polje_sa_sumom(unsigned int g, int n = 100) :Polje(n), gustina(g) {};

	char oznaka() const override {
		return 'S';
	}







};

#endif // !polje_sa_sumom
