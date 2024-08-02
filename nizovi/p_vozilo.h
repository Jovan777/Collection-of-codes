#ifndef _p_vozilo_h_
#define _p_vozilo_h_

#include "vozilo1.h"



class P_vozilo : public Vozilo {
	const Osoba** osobe;
	int kap;

public:
	P_vozilo(const Osoba* vozac, float sop_t, int k);
	~P_vozilo()
	{
		delete[] osobe;
	}


	char vrsta() const override {
		return 'P';
	}

	float tezina() const override;
	bool operator+=(const Osoba* o);
	bool operator-=(const Osoba* o);

private:
	void pisi(ostream& it) const override;

};




#endif // !_p_vozilo_h_
