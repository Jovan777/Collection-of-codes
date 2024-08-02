#pragma once

#include "avion.h"

static int statId = 0;

class Let {


	int id = statId++;

	string imeP;
	string imeD;
	Avion* avion;

public:
	Let(string p, string d, Avion* a) : imeP(p), imeD(d), avion(a) {};
	Let() {};

	string getP() const {
		return imeP;
	}

	string getD() const {
		return imeD;
	}

	Avion* getA() {
		return avion;
	}

	int getId() const {
		return id;
	}

	friend ostream& operator<<(ostream& it, Let& l) {
		return it << "LET - " << l.imeP << " : " << l.imeD << " - " << *l.avion << endl;
	}

};