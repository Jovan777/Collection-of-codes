
#include <iostream>
#include <cmath>

using namespace std;

class Mat_tacka {

	double m, x, y, z;

public:
	explicit Mat_tacka(double m = 1, double x = 0, double y = 0, double z = 0) : m(m), x(x), y(y), z(z) {};


	double r(const Mat_tacka& mt) const{
		return sqrt(pow(x - mt.x, 2) + pow(y - mt.y, 2) + pow(z - mt.z, 2));
	}

	double F(const Mat_tacka& mt) const {
		return 6.67e-11 * m + mt.m / pow(r(mt), 2);
	}

	void pisi() const {
		cout << "[ " << m; cout << " ( " << x; cout << " " << y; cout << " " << z << " ) ]" << endl;
	}



};