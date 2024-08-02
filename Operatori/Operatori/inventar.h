#include "zapis.h"
#include <iostream>
#include <string>
using namespace std;


class Inventar {

	Zapis** niz;
	int kap, duz;
	void kopiraj(const Inventar& inv);
	void premesti(Inventar& inv) {
		niz = inv.niz;
		kap = inv.kap;
		duz = inv.duz;
		inv.niz = nullptr;
	}

	void brisi();
public:

	explicit Inventar(int k = 10) : niz(new Zapis* [k]), kap(k), duz(0) {};
	Inventar(const Inventar& inv) {
		kopiraj(inv);
	}
	Inventar(Inventar&& inv) {
		premesti(inv);
	}

	~Inventar()
	{
		brisi();
	}

	Inventar& operator=(const Inventar& inv) {
		if (this!=&inv)
		{
			brisi();
			kopiraj(inv);
		}
		return *this;

	}

	Inventar& operator=( Inventar&& inv) {
		if (this != &inv)
		{
			brisi();
			premesti(inv);
		}
		return *this;

	}


	int duzina() const {
		return duz;
	}
	int kapacitet() const {
		return kap;
	}

	Zapis* operator[](string naziv);
	const Zapis* operator[](string naziv) const;
	bool operator+=(Zapis* z) {
		if (duz==kap || (*this)[z->dohvNaz()])
		{
			return false;
		}
		niz[duz++] = z;
		return true;
	}


	Zapis** begin() {
		return niz;
	}
	Zapis** end() {
		return niz + duz;
	}

	const Zapis*const*const begin() const{
		return niz;
	}
	const Zapis*const*const end() const{
		return niz + duz;
	}

	double vrednost() const;
	friend ostream& operator<<(ostream& it, const Inventar& i);




};