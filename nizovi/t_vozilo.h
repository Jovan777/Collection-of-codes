#ifndef _t_vozilo_h_
#define _t_vozilo_h_

#include "vozilo1.h"

using namespace std;


class T_vozilo : public Vozilo {

	float nosivost, tovar;

public:
	T_vozilo(const Osoba* vozac, float sop_t, float nos, float t=0) : Vozilo(vozac, sop_t), nosivost(nos), tovar(t) {};

	char vrsta() const override {
		return 'T';
	}

	bool operator+=(float tez) {
		if ((tovar+tez)>nosivost)
		{
			return false;
		}
		else
		{
			tovar += tez;
			return true;
		}
	}

	bool operator-=(float tez) {
		if (tovar-tez<0)
		{
			return false;
		}
		else {
			tovar -= tez;
			return true;
		}
	}

	float tezina() const override {
		return Vozilo::tezina() + tovar;
	}

private:
	void pisi(ostream& it) const override {
		Vozilo::pisi(it);
		it << "(" << tovar << "/" << nosivost << ")";
	}



};





#endif // !_t_vozilo_h_



