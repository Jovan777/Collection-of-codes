#ifndef _figura1_h_
#define _figura1_h_
#include "tacka4.h"


class Figura : public Tacka {
	Tacka t;


public:
	Figura(const Tacka& tt=ORG) : t(tt) {};

	virtual ~Figura() = default;

	Figura& postavi(double x, double y) {
		t = Tacka(x, y);
		return *this;

	}


	Figura& pomeri(double dx, double dy) {
		t = Tacka(t.aps() + dx, t.ord() + dy);
		return *this;

	}

	virtual double O()const = 0;
	virtual double P()const = 0;

	virtual Figura* kopija() const = 0;

protected:
	virtual void citaj(istream& ut) {
		 ut >> t;
	}

	friend istream& operator>>(istream& ut, Figura& f) {
		f.citaj(ut);
		return ut;

	}

	virtual void pisi(ostream& it) const {
		it << "T = " << t;
	}
	friend ostream& operator<<(ostream& it, const Figura& f) {
		f.pisi(it);
		return it;

	}




};







#endif // !_figura1_h_



