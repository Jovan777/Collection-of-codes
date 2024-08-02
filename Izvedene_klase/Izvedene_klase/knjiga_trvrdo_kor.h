#include "knjiga.h"

#ifndef _knjiga_tvrdo_kor_h_
#define _knjiga_tvrdo_kor_h_



class Knjiga_tvrdo_kor : public Knjiga {
	double cena_kor;

public:
	Knjiga_tvrdo_kor(string a, string n, double c, double kor) : Knjiga(a, n, c), cena_kor(kor) {};

	double vrednost() const override{
		double v = Knjiga::vrednost() ;
		v += cena_kor;
		return v;

	}

	void pisi(ostream& it) const override {
		Knjiga::pisi(it);
		it << " [tvrde korice] ";
		
	}


};
#endif