#ifndef kvadar_h_
#define kvadar_h_

#include <iostream>


using namespace std;



class Kvadar
{
	static int pos_id;
	int id = ++pos_id;

	double a, b, c;

	void kopiraj(const Kvadar& k) {
		a = k.a, b = k.b, c = k.c;
	}

public:
	explicit Kvadar(double a = 1, double b = 1, double c = 1) : a(a), b(b), c(c) {};

	Kvadar(const Kvadar& k) { kopiraj(k); }
	Kvadar& operator=(const Kvadar& k) {
		kopiraj(k); 
		return *this;
	}

	double V() const {
		return a * b * c;
	}

	friend ostream& operator<<(ostream& it, const Kvadar& k) {
		return it<<"K : "<<k.id<<" " << "(" << k.a << ", " << k.b << ", " << k.c << ")";
	}

	friend istream& operator>>(istream& it,  Kvadar& k) {
		return it >> k.a >> k.b >> k.c;
	}



};

#endif // !kvadar_h_
