#ifndef razlomak_h_
#define razlomak_h_

using namespace std;

#include <iostream>
#include <string>











class Razlomak
{
	int br, im;


	
public:
	Razlomak(int b, int i = 1) : br(b), im(i) {};

	friend Razlomak operator+(const Razlomak& r1, const Razlomak& r2) {

		int b = r1.br * r2.im + r2.br * r1.im;
		int i = r1.im * r2.im;
		return Razlomak(b, i);

	}

	friend bool operator>(const Razlomak& r1, const Razlomak& r2) {
		double d1 = r1.br / r1.im;
		double d2 = r2.br / r2.im;

		return d1 > d2;

	}

	friend ostream& operator<<(ostream& it, const Razlomak& r) {
		return it << r.br<<"/" << r.im;
	}






};

#endif // !razlomak_h_
