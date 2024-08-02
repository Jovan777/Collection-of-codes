#ifndef  _tacka4_h_
#define _tacka4_h_
#include <iostream>

using namespace std;

class Tacka {

	double x, y;

public:
	Tacka(double xx=0, double yy=0) : x(xx), y(yy) {};

	double aps() const { return x; }
	double ord() const { return y; }

	friend istream& operator>>(istream& ut,  Tacka& t) {
		return ut >> t.x >> t.y;
	}

	friend ostream& operator<<(ostream& it, const Tacka& t) {
		return it << "( " << t.x << " , " << t.y << " )";
	}




};

const Tacka ORG;



#endif // ! _tacka4_h_
