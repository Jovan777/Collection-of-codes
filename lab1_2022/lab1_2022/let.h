#ifndef let_h_
#define let_h_
#include "avion.h"



using namespace std;


static int id=0;


class Let
{
	string imeP;
	string imeD;
	int idL = id++;
	Avion* avion;

public:
	Let(string p, string d, Avion* a) : imeP(p), imeD(d), avion(a) {};

	string getP() const {
		return imeP;
	}

	string getD() const {
		return imeD;
	}

	Avion* getA() const {
		return avion;
	}

	void pisi() const {
		cout << "LET-" << imeP << ":" << imeD<<"-";
		avion->pisi();
	}



};

#endif // !let_h_
