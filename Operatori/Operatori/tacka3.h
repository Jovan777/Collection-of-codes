#include<iostream>
#include <cmath>
using namespace std;


class Tacka {

	double x, y;

public:
	Tacka(double x = 0, double y = 0) : x(x), y(y) {};
	double getX() const { return x; }
	double getY() const { return y; }

	bool operator==(const Tacka& t2) const{
		return x == t2.x && y == t2.y;
	}

	bool operator!=(const Tacka& t2) const {
		return x != t2.x || y != t2.y;
	}

	double operator-( const Tacka& t2) const{
		return sqrt(pow(x - t2.x, 2) + pow(y - t2.y, 2));

	}
	
	friend ostream& operator<<(ostream& it, const Tacka& t) {
		return it << "( " << t.x << " , " << t.y << " )";
	}








};