#ifndef biblioteka_h_
#define biblioteka_h_




#include "knjiga.h"



class Biblioteka
{


	string naziv;
	int kap, br;
	Knjiga** knjige;


public:

	Biblioteka(string n="", int k=1) : naziv(n), kap(k), br(0) {
		knjige = new Knjiga * [k];
	}

	
	Biblioteka& operator+=(Knjiga& k) {
		knjige[br++] = !k;
		return *this;
	}


	friend ostream& operator<<(ostream& it, const Biblioteka& b) {
		it << "BIBLIOTEKA " << b.naziv << " " << b.br << "/" << b.kap << endl;
		for (int i = 0; i < b.br; i++)
		{
			it << *b.knjige[i] << endl;
		}
		return it;

	}


	Knjiga* dohvati(int id) {
		for (int i = 0; i < br; i++)
		{
			if (knjige[i]->getID()==id && knjige[i])
			{
				return knjige[i];
			}
		}

	}


};

#endif // !biblioteka_h_
