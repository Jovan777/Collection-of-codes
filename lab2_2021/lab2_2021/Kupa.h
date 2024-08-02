#ifndef kupa_h_
#define kupa_h_
#include <iostream>


using namespace std;



class Kupa
{
	


public:
	Kupa(double rr = 1, double hh = 2) : r(rr), h(hh) {};
	 
	virtual double V() const {
		return r * r * 3.14159 * (h / 3);
	}

	friend bool operator<(const Kupa& k1, const Kupa& k2) {
		return k1.V() < k2.V();
	}

	friend ostream& operator<<(ostream& it,  Kupa& k) {
		k.pisi(it);
		return it;
	}


protected:

	double r, h;


	virtual void pisi(ostream& os) {
		os << r << ", " << h;
	}







};

#endif // !kupa_h_
