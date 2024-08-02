#ifndef buket_h
#define buket_h
#include "cvet.h"

#include <iostream>

using namespace std;






class Buket
{
	struct Elem {
		Cvet cvet;
		Elem* sled;

		Elem(Cvet c, Elem* s = nullptr) : cvet(c), sled(s) {};


	};
	Elem* prvi, * posl;
	void kopiraj(const Buket& b);
	void premesti(Buket& b);
	void brisi();


public:
	Buket() : prvi(nullptr), posl(nullptr) {};
	Buket(const Buket& b) {
		kopiraj(b);
	}
	Buket(Buket&& b) {
		premesti(b);
	}
	~Buket()
	{
		brisi();
	}

	Buket& operator=(const Buket& b) {
		if (this!=&b)
		{
			brisi();
			kopiraj(b);
		}
		return *this;
	}
	Buket& operator=(Buket&& b) {
		if (this != &b)
		{
			brisi();
			premesti(b);
		}
		return *this;
	}
	

	void dodaj(Cvet c) {
		posl = (prvi ? posl->sled : prvi) = new Elem(c);
	}

	int nabavna() const {
		Elem* temp = prvi;
		int cena = 0;
		while (temp)
		{
			cena += temp->cvet.dohvNab();
			temp = temp->sled;
		}
		return cena;
	}

	int prodajna() const {
		Elem* temp = prvi;
		int cena = 0;
		while (temp)
		{
			cena += temp->cvet.dohvProd();
			temp = temp->sled;
		}
		return cena;
	}

	int zarada() const {
		Elem* temp = prvi;
		int cena = 0;
		while (temp)
		{
			cena += temp->cvet.zarada();
			temp = temp->sled;
		}
		return cena;
	}

	friend bool operator>(const Buket& b1, const Buket& b2) {
		return b1.prodajna() > b2.prodajna();
	}

	friend ostream& operator<<(ostream& it, const Buket& b) {
		Elem* temp = b.prvi;
		it << "(";
		while (temp)
		{
			it << temp->cvet << (temp->sled ? ", " : ")");
			temp = temp->sled;
		}
		it <<b.prodajna()<<"RSD";
		return it;

	}



};

#endif // !buket_h
