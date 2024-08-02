#ifndef ukras_h
#define ukras_h
#include "boja.h"

class Ukras {

	int masa;
	Boja boj;

public:
	Ukras(int mm, Boja bb) : masa(mm), boj(bb) {};

	virtual ~Ukras()
	{

	}

	Boja getBoj() const {
		return boj;
	}

	int getMasa() const {
		return masa;
	}

	virtual void pisi(ostream& it) const = 0;

	friend ostream& operator<<(ostream& it, const Ukras& u) {
		u.pisi(it);
		return it;
	}

};


class Kugla : public Ukras {


public:
	enum Velicina{MALA, SREDNJA, VELIKA};

	Kugla(int mas, Boja boj, Velicina v) : Ukras(mas, boj), vel(v) {};

	void pisi(ostream& it) const override {
		if (vel==SREDNJA)
		{
			it << "o";
		}
		if (vel==MALA)
		{
			it << ".";
		}
		if (vel==VELIKA)
		{
			it << "()";
		}

	}





private:

	Velicina vel;


};














#endif // !ukras_h
