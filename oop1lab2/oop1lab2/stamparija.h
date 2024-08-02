#ifndef stamparija_h
#define stamparija_h


#include "slicica.h"

#include<iostream>

using namespace std;





class Stamparija
{
	string* nizNaziva;
	int n;



public:
	Stamparija(string* niz, int nn) : n(nn) {
		nizNaziva = new string[n];
		for (int i = 0; i < n; i++)
		{
			nizNaziva[i] = niz[i];
		}

	}

	Stamparija(const Stamparija& s) = delete;
	Stamparija& operator=(const Stamparija&) = delete;

	Slicica* odstampaj(int k){
		if (k>n)
		{
			return nullptr;
		}
		return new Slicica(k, nizNaziva[k]);
	
	}

	int dohvN() const {
		return n;
	}


};

#endif // !stamparija_h
