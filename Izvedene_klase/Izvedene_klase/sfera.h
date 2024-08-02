#ifndef  _sfera_h_
#define _sfera_h_

#include "predmet.h"



class Sfera : public Predmet{

	double r;


public:

	Sfera(double s=1, double rr=1) : Predmet(s), r(rr) {};

	double V() const override{
		return 4. / 3 * r * r * r * 3.14159;

	}


private:
	void citaj(istream& ut) override{
		Predmet::citaj(ut);
		ut >> r;

	}

	void pisi(ostream& it) const override {
		it << "Sfera : [ "; Predmet::pisi(it); it << " , " << r << " ] ";
		
	}


};




#endif // ! _sfera_h_
