#include <iostream>
using namespace std;


const double PI = 3.14159;

class Valjak {

	double r, h;

public:

	Valjak(double rr=1, double hh=1) : r(rr), h(hh) {};
	double getR() const { return r; }
	double getH() const { return h; }
	double V() const { return r * r * h * PI; }
	friend ostream& operator<<(ostream& it, const Valjak& v) {
		return it << "[ " << v.r << " , " << v.h << " ]";
	}



};