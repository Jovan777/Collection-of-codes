#ifndef buket_h_
#define buket_h_
#include <iostream>

#include "Cvet.h"
using namespace std;



class Buket
{

	struct Elem {
		Cvet* cvet;
		Elem* sled;

		Elem(Cvet* c, Elem* s = nullptr) : cvet(c), sled(s) {};


	};

	Elem* prvi, * posl;
	void kopiraj(const Buket& b);
	void premesti(Buket& b) {
		prvi = b.prvi;
		posl = b.posl;
		delete b.prvi;
		delete b.posl;

	};
	void brisi() {
		while (prvi)
		{
			Elem* old = prvi;
			prvi = prvi->sled;
			delete old;
		}
		posl = nullptr;
	}


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
		if (this!=&b)
		{
			brisi();
			premesti(b);
		}
		return *this;
	}


	int nabavna() const {
		int n = 0;
		for (Elem* temp = prvi; temp ; temp=temp->sled)
		{
			n += temp->cvet->getNabavna();
		}
		return n;

	}
	int prodajna() const {
		int n = 0;
		for (Elem* temp = prvi; temp; temp = temp->sled)
		{
			n += temp->cvet->getProdajna();
		}
		return n;

	}

	int zar() const {
		return prodajna() - nabavna();

	}

	Buket& dodaj(Cvet* c) {
		posl = (prvi ? posl->sled : prvi) = new Elem(c);
		return *this;
	}


	friend bool operator>(const Buket& b1, const Buket& b2) {
		return b1.prodajna() > b2.prodajna();
	}

	friend ostream& operator<<(ostream& it, const Buket& b) {
		it << "(";
		for (Buket::Elem* temp = b.prvi; temp ; temp=temp->sled)
		{
			it << *temp->cvet << ",";
		}
		it << ")";
		it << b.prodajna() << "RSD";

		return it;
	}




};

#endif // !buket_h_
