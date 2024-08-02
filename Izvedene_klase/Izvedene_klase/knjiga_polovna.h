#include "knjiga.h"

#ifndef _knjiga_polovna_h_
#define _knjiga_polovna_h_


class Knjiga_polovna : public Knjiga {

	double procenat;

public:
	
	Knjiga_polovna(string a, string n, double c, double p) : Knjiga(a, n, c), procenat(p) {};
	double vrednost() const override {
		return Knjiga::vrednost() * (1 - procenat/100);
	}

	void pisi(ostream& it) const override {
		Knjiga::pisi(it);
		it << " [polovna]";

	}




};
#endif // !_knjiga_tvrdo_kor_h_
