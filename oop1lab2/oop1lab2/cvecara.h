#ifndef cvecara_h
#define cvecara_h

#include <iostream>

#include"buket.h"

using namespace std;







class Cvecara
{
	struct Elem {
		Buket buket;
		Elem* sled;

		Elem(Buket b, Elem* s = nullptr) : buket(b), sled(s) {};

	};
	int zarada;
	Elem* prvi, * posl;

	void kopiraj(const Cvecara& c);
	void premesti(Cvecara& c) {
		prvi = c.prvi;
		posl = c.posl;
		zarada = c.zarada;
		c.prvi = nullptr;
		c.posl = nullptr;
		c.zarada = 0;

	}

	void brisi(){
		while (prvi)
		{
			Elem* temp = prvi;
			prvi = prvi->sled;
			delete temp;
		}
		posl = nullptr;

	}

public:
	Cvecara() : prvi(nullptr), posl(nullptr), zarada(1000) {};
	Cvecara(const Cvecara& c) {

	}
	Cvecara(Cvecara&& c) {
		premesti(c);
	}

	Cvecara& operator=(const Cvecara& c) {
		if (this != &c)
		{
			brisi();
			kopiraj(c);
		}
		return *this;

	}
	Cvecara& operator=(Cvecara& c) {
		if (this!=&c)
		{
			brisi();
			premesti(c);
		}
		return *this;

	}


	~Cvecara()
	{
		brisi();
	}

	void dodaj(Buket b);


	void prodaj(int i);



	friend ostream& operator<<(ostream& it, const Cvecara c) {
		
		it << "zarada=" << c.zarada << "RSD" << endl;
		Elem* temp = c.prvi;
		while (temp)
		{
			it << temp->buket << endl;
			temp = temp->sled;
		}

		return it;

	}


};

#endif // !cvecara_h
