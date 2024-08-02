#ifndef _osoba3_h_
#define _osoba3_h_

#include <iostream>
#include <string>

using namespace std;



class Osoba {

	string ime;
	float tezina;

public:
	Osoba(string i, float t) : ime(i), tezina(t) {};
	Osoba(const Osoba&) = delete;
	Osoba& operator=(const Osoba&) = delete;
	string getIme() const {
		return ime;
	}
	float getTez() const { return tezina; }

	friend ostream& operator<<(ostream& it, const Osoba& o) {
		return it << o.ime << "(" << o.tezina << ")";
	}


};




#endif // !
