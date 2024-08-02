#ifndef _vektor1_h_
#define _vektor1_h_



#include <iostream>

using namespace std;

class Vektor {

	double x, y, z;

public:
	Vektor(double xx = 0, double yy = 0, double zz = 0) : x(xx), y(yy), z(zz) {};
	double intenz() const {
		return sqrt(x * x + y * y + z * z);
	}

	virtual ~Vektor() = default;

	friend Vektor operator+(const Vektor& v1, const Vektor& v2) {
		return Vektor(v1.x + v2.x, v1.y + v2.y, v1.z + v2.z);
	}

	friend Vektor operator*(const Vektor& v1, int s) {
		return Vektor(v1.x * s, v1.y * s, v1.z * s);
	}

protected:
	virtual void pisi(ostream& it)const {
		it << "(" << x << ", " << y << ", " << z << ")";
	}
	friend ostream& operator<<(ostream& it, const Vektor& v1) {
		v1.pisi(it);
		return it;
	}

};





#endif // !_vektor1_h_
