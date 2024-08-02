#ifndef boja_h
#define boja_h
#include <iostream>

using namespace std;

class LosaBoja {
public:
	friend ostream& operator<<(ostream& it, const LosaBoja& b) {
		return it << "Boja nije crna ili bela" << endl;
	}

};

class Boja {

	int crv, plv, zel;


public:
	Boja(int c = 255, int z = 255, int p = 255)
	{
		if ((c < 0 || c>255) || (z < 0 || z>255) || (p < 0 || p>255)) {
			throw LosaBoja();
		}
		else {
			plv = p;
			crv = c; 
			zel = z;
		}
	}
	int getCrv() const { return crv; }
	int getPlv() const { return plv; }

	int getZel() const { return zel; }




	friend Boja operator+(const Boja& b1, const Boja& b2) {
		int a1 = b1.crv + b2.crv;
		int a2 = b1.zel + b2.zel;
		int a3 = b1.plv + b2.plv;

		a1 /= 2;
		a2 /= 2;
		a3 /= 2;

		return Boja(a1, a2, a3);

	}

	friend bool operator==(const Boja& b1, const Boja& b2) {
		return ((b1.crv == b2.crv) && (b1.zel == b2.zel) && (b1.plv == b2.plv));
	}


	friend ostream& operator<<(ostream& it, const Boja& b) {
		return it << "( C = " << b.crv << ", P = " << b.plv << ", Z = " << b.zel << " )"<<endl;
	}


};







#endif // !boja_h
