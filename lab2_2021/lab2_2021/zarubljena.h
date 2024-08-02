#ifndef _zarubljena_h_
#define _zarubljena_h_


#include "Kupa.h"
#include <iostream>
using namespace std;





class Zarubljena : public Kupa
{

	double d;
	void pisi(ostream& it)  override {
		Kupa::pisi(it);
		it << "," << d;
	}
	

public:
	Zarubljena(double r, double h, double dd) : Kupa(r, h), d(dd) {};

	double V() const override {
		return r * r * 3.14159 * (h * h * h - d * d * d) / 3 * h * h;
	}

	double getD() const {
		return d;
	}

	






};

#endif // !_zarubljena_h_
