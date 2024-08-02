#ifndef spil_h
#define spil_h

#include "stamparija.h"
#include <iostream>

using namespace std;







class Spil
{

	struct Elem {
		Slicica* slicica;
		Elem* sled;
		Elem(Slicica* sli, Elem* s = nullptr) : slicica(sli), sled(s) {};



	};
	Elem* prvi, * posl;


public:
	Elem* tekPoz;

	Spil() : prvi(nullptr), posl(nullptr) {};
	Spil(const Spil& s) = delete;
	Spil& operator=(const Spil&) = delete;

	bool operator%(int k);
	Spil& operator+=(Slicica* s);
	
	void naPocetak(int k);

	void naSledece(int k);

	bool ima(int k);

	Slicica* dohvTren(int k);

	void izvadi(int k) {
		Elem* temp = prvi;
		Elem* pret = nullptr;
		while (temp && temp->slicica->dohvBr()!=k)
		{
			pret = temp;
			temp = temp->sled;
		}
		if (temp && temp->slicica->dohvBr()==k)
		{
			Elem* stari = temp;
			(pret ? pret->sled : prvi) = temp->sled;
			delete temp;

		}


	}
	
	friend ostream& operator<<(ostream& it, const Spil& s) {
		Elem* temp = s.prvi;
		while (temp)
		{
			it << *temp->slicica<<endl;
			temp = temp->sled;
		}

		return it;
	}



};

#endif // !spil_h
