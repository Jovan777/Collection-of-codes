#pragma once

#include "let.h"

class Arhiva {

	struct Elem {
		Let* let;
		Elem* sled;

		Elem(Let* l, Elem* s=nullptr) : let(l), sled(s) {};

	};
	Elem* prvi, * posl;

public:
	Arhiva(Elem* p = nullptr, Elem* s = nullptr) : prvi(p), posl(p) {};

	void dodaj(Let* l);
	Let* dohvP(string polaziste);
	Let* dohvD(string dolaziste);
	Let* dohvSve(string polaziste, string dolaziste);

	void pisi() const;




};