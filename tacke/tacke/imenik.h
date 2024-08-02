#include "osoba.h"



class Imenik {

	struct Elem {
		Osoba oso;
		Elem* sled;
		Elem(const Osoba& o, Elem* s = nullptr) : oso(o), sled(s) {};



	};

	Elem* prvi, * posl;

public:
	Imenik() : prvi(nullptr) {};
	Imenik(const Imenik& im);
	Imenik(Imenik&& im) {
		prvi = im.prvi;
		im.prvi = nullptr;
	}
	~Imenik();
	Imenik& dodaj(const Osoba& oso);
	void pisi() const;




};