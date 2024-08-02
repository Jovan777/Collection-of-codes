#include "odred.h"
#include <iostream>

using namespace std;


class Recnik {

	struct Elem {
		Odred odr;
		Elem* sled;

		Elem(Odred o, Elem* s = nullptr) : odr(o), sled(s) {};
	};
	Elem* prvi;
	void kopiraj(const Recnik& r);
	void premesti(Recnik& r) {
		prvi = r.prvi;
		r.prvi = nullptr;
	}
	void brisi();



public:

	Recnik() { prvi = nullptr; }
	Recnik(const Recnik& rec) {
		kopiraj(rec);
	}
	Recnik(Recnik&& rec) {
		premesti(rec);
	}
	~Recnik()
	{
		brisi();
	}

	Recnik& operator=(const Recnik& rec) {
		if (this!=&rec)
		{
			brisi();
			kopiraj(rec);
		}
		return *this;
	}

	Recnik& operator=(Recnik&& rec) {
		if (this != &rec)
		{
			brisi();
			premesti(rec);
		}
		return *this;
	}

	Recnik& operator+=(const Odred& odr);
	Recnik operator<<(string poj);
	friend ostream& operator<<(ostream& it, const Recnik& rec);



};
