#ifndef _vozilo1_h_
#define _vozilo1_h_


#include "osoba3.h"
using namespace std;
#include <iostream>

class Vozilo {

	const Osoba* vozac;
	float sop_tezina;

public:
	Vozilo(const Osoba* vozac, float sop_t) : vozac(vozac), sop_tezina(sop_t) {};
	Vozilo(const Vozilo&) = delete;
	Vozilo& operator=(const Vozilo&) = delete;
	virtual char vrsta() const=0;

	virtual float tezina() const {
		return sop_tezina + vozac->getTez();
	}

protected:
	virtual void pisi(ostream& it) const {
		it << vrsta() << "[" << *vozac << ", " << sop_tezina << "]";

	}

	friend ostream& operator<<(ostream& it, const Vozilo& v) {
		v.pisi(it);
		return it;
	}


};





#endif // !_vozilo1_h
