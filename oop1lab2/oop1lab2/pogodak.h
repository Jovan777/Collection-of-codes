#ifndef pogodak_h
#define pogodak_h

#include "fudbaler.h"
#include <iostream>

using namespace std;






class Pogodak
{
	Fudbaler* strelac;
	int min;


public:
	Pogodak(Fudbaler* f, int m) : strelac(f), min(m) {};

	


	Fudbaler* dohvStrelca() const {
		return strelac;
	}



	friend ostream& operator<<(ostream& it, const Pogodak& p) {
		return it << "[" << p.min << "' ]-" << *p.strelac;
	}


};

#endif // !pogodak_h
