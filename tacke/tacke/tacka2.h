

class Tacka {

private : double x, y;

public:
	void postavi(double a, double b) {
		x = a;
		y = b;

	}

	double aps() const { return x; };
	double ord() const { return y; };


	double rastojanje(Tacka t) const;
	void citaj();
	void pisi() const;





};


#include <iostream>
#include <cmath>

using std::cin; using std::cout; using std::sqrt; using std::pow; using std::endl;

inline void Tacka::citaj() {
	cin >> x >> y;
}
inline void Tacka::pisi() const {
	cout << "( " << x << " , " << y << " )" << endl;
}

inline double Tacka::rastojanje(Tacka t) const{

	return sqrt(pow(x - t.x, 2) + pow(y - t.y, 2));

}