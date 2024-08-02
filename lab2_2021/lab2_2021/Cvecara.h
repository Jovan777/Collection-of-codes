#ifndef cvecara_h_
#define cvecara_h_
#include "Buket.h"

using namespace std;

class Cvecara
{

	struct Elem {
		Buket* buket;
		Elem* sled;

		Elem(Buket* b, Elem* s = nullptr) : buket(b), sled(s) {};


	};

	Elem* prvi, * posl;
	int zarada;
	void kopiraj(const Cvecara& c);
	void premesti(Cvecara& c) {
		zarada = c.zarada;
		prvi = c.prvi;
		posl = c.posl;
		delete c.prvi;
		delete c.posl;

	}

	void brisi() {
		zarada = 0;
		while (prvi)
		{
			Elem* old = prvi;
			prvi = prvi->sled;
			delete old;
		}
		posl = nullptr;
	}


public:
	Cvecara() : zarada(1000), prvi(nullptr), posl(nullptr) {};
	Cvecara(const Cvecara& c) {
		kopiraj(c);
	}
	Cvecara(Cvecara&& c) {
		premesti(c);
	}
	~Cvecara()
	{
		brisi();
	}
	Cvecara& operator=(const Cvecara& c) {
		if (this!=&c)
		{
			brisi();
			kopiraj(c);
		}
		return *this;
	}
	Cvecara& operator=(Cvecara&& c) {
		if (this!=&c)
		{
			brisi();
			premesti(c);
		}
		return *this;
	}


	Cvecara& dodaj( Buket* b) {

		/*
		int n = b->zar();
		if (n<b->nabavna()*0.2)
		{
			return *this;
		}

		for (Elem* temp = prvi, *pret=nullptr; temp ; temp=temp->sled)
		{
			if (temp->buket->prodajna()<b->prodajna())
			{
				pret = temp;
			}
			else
			{
				Elem* novi = new Elem(b);
				(prvi ? pret->sled : prvi) = novi;
				novi->sled = temp;
				zarada -= novi->buket->nabavna();
				return *this;
			}



		}
		*/
		posl = (prvi ? posl->sled : prvi) = new Elem(b);
		zarada -= b->nabavna();

		return *this;



	}


	Buket* prodaj(int i);


	friend ostream& operator<<(ostream& it, const Cvecara& c) {

		it << "zarada=" << c.zarada << "RSD" << endl;
		for (Cvecara::Elem* temp = c.prvi; temp; temp=temp->sled)
		{
			it << *temp->buket << endl;
		}
		return it;

	}



};

#endif // !cvecara_h_
