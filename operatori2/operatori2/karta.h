#ifndef karta_h_
#define karta_h_


#include <iostream>

using namespace std;






class Karta
{
	int red;
	int sediste;
	double cena;


public:
	Karta(int r, int s, double c=0) : red(r), sediste(s), cena(c) {};

	int getRed() const {
		return red;
	}

	int getS() const {
		return sediste;
	}

	int getCena() const {
		return cena;
	}

	friend ostream& operator<<(ostream& it, const Karta& k) {
		return it << "(" << k.red << ", " << k.sediste << ", " << k.cena << ")";
	}


};

#endif // !karta_h_
