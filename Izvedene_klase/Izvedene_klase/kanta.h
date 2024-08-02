#include "valjak.h"


class Kanta : public Valjak {

	double puno;


public:

	explicit Kanta(double rr = 1, double hh = 1, double p = 0) : Valjak(rr, hh), puno(p <= V() ? p : V()) {};

	Kanta(const Kanta&) = delete;
	double popunjeno() const { return puno; }
	double fali() const { return V() - puno; }

	bool puna() const { return puno == V(); }
	bool prazna()const { return puno == 0; }

	Kanta& operator+=(double dop) {
		puno += dop;
		if (puno>V())
		{
			puno = V();
		}
		return *this;
	}

	Kanta& operator-=(double odl) {
		puno -= odl;
		if (puno<0)
		{
			puno = 0;
		}
		return *this;
	}

	Kanta& operator=(Kanta& k) {
		
		if (this!=&k)
		{
			double prazno = fali();
			if (prazno>=k.puno)
			{
				puno += k.puno;
				k.puno = 0;
			}
			else
			{
				puno = V();
				k.puno -= prazno;
			}

		}


		return *this;
	}


	friend ostream& operator<<(ostream& it, const Kanta& k) {
		return it << "{ " << static_cast<const Valjak&>(k) << " , " << k.puno << " }";
	}

};