#ifndef znak_h_
#define znak_h_

#include <iostream>
#include <string>

using namespace std;

#include "razlomak.h"







class Znak
{
	Razlomak t;

public:
	Znak(Razlomak r) : t(r) {};

	Razlomak getT() const {
		return t;
	}


	friend Razlomak operator+(const Znak& r1, const Znak& r2) {
		return r1.t + r2.t;
	}


	operator Razlomak() const {
		return t;
	}

	virtual string opis() const = 0;

	friend ostream& operator<<(ostream& it, const Znak& z) {
		return it << z.opis() << "(" << z.t << ")";
	}




};

#endif // !znak_h_
