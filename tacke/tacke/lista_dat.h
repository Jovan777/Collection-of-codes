#pragma once

#include "datum2.h"


class Lista {

	struct Elem {
		Datum dat;
		Elem* sled;
		Elem(const Datum& d) : dat(d), sled(nullptr) {};



	};

	Elem* prvi, * posl;
	int duz;


public:

	Lista() : prvi(nullptr), posl(nullptr) {};
	Lista(const Lista& lst);
	Lista(Lista&& lst) {
		prvi = lst.prvi;
		posl = lst.posl;
		duz = lst.duz;
		lst.prvi = lst.posl = nullptr;

	}
	~Lista();


	Lista& dodaj(const Datum& dat) {
		posl = (!prvi ? prvi : posl->sled) = new Elem(dat);
		duz++;
		return *this;

	}

	int duzina() const { return duz; }

	const Datum* max() const;

	void pisi() const;





};

