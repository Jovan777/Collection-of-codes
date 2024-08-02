#ifndef recnik_h
#define recnik_h

#include "odrednica.h"
#include <iostream>
#include <string>

using namespace std;






class Recnik
{
	struct Elem {

		Odrednica odr;
		Elem* sled;
		Elem(Odrednica o, Elem* s = nullptr) : odr(o), sled(s) {};


	};
	Elem* prvi, * posl;
	void kopiraj(const Recnik& r) {
		Elem* temp = r.prvi;
		while (temp)
		{
			posl = (prvi ? posl->sled : prvi) = new Elem(temp->odr);

		}


	};
	void premesti(Recnik& r) {
		prvi = r.prvi;
		posl = r.posl;
		r.prvi = nullptr;
		r.posl = nullptr;
	}
	void brisi() {
		while (prvi)
		{
			Elem* old = prvi;
			prvi = prvi->sled;
			delete old;

		}
		prvi = nullptr;
		posl = nullptr;


	}


public:
	Recnik() : prvi(nullptr), posl(nullptr) {};
	Recnik(const Recnik& r) {
		kopiraj(r);
	}
	Recnik(Recnik&& r) {
		premesti(r);
	}
	~Recnik()
	{
		brisi();
	}

	Recnik& operator=(const Recnik& r) {
		if (this!=&r)
		{
			brisi();
			kopiraj(r);
		}
		return *this;
	}
	Recnik& operator=( Recnik&& r) {
		if (this != &r)
		{
			brisi();
			premesti(r);
		}
		return *this;
	}

	Recnik& operator+=(const Odrednica& odr) {
		Elem* temp = prvi;
		Elem* pret = nullptr;
		while (temp && temp->odr<odr)
		{
			pret = temp;
			temp = temp->sled;
		}
		Elem* novi = new Elem(odr);
		(pret ? pret->sled : prvi) = novi;
		novi->sled = temp;

		return *this;
	}

	Recnik operator<<(string pojam) {
		Recnik rec;
		for (Elem* temp = prvi; temp ; temp=temp->sled)
		{
			if (temp->odr==pojam)
			{
				rec += temp->odr;
			}
			
		}
		return rec;

	}

	friend ostream& operator<<(ostream& it, const Recnik& rec) {
		for (Elem* temp = rec.prvi; temp ; temp=temp->sled)
		{
			it << temp->odr << endl;

		}
		return it;
	}

};

#endif // !recnik_h
