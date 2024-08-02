#include <iostream>
using namespace std;


class Karta {

	int red;
	int sed;
	float cena;


public:

	Karta(int r, int s, float c) : red(r), sed(s), cena(c) {};

	int dohvRed() const {
		return red;

	}

	int dohvSed() const {
		return sed;
	}
	float dohvCenu() const {
		return cena;
	}


	friend ostream& operator<<(ostream& it, Karta& k) {
		return it << "( " << k.red << " , " << k.sed << " , " << k.cena << " )";
	}

};