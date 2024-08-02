#include "karta1.h"
#include <string>
#include <iostream>
using namespace std;


class Predstava {

	string naslov;
	long datum;
	Karta*** karte;
	int br_red, duz_red;
	void kopiraj(const Predstava& p);
	void premesti(Predstava& p) {
		naslov = p.naslov;
		datum = p.datum;
		karte = p.karte;
		br_red = p.br_red;
		duz_red = p.duz_red;
		p.karte = nullptr;
	}
	void brisi();


public:
	Predstava(string nas, long dat, int br_r, int duz_r) : naslov(nas), datum(dat), duz_red(duz_r), br_red(br_r) {
		karte = new Karta * *[br_red];
		for (int i = 0; i < br_red; i++)
		{
			karte[i] = new Karta * [duz_red];
			for (int j = 0; j < duz_red; j++)
			{
				karte[i][j] = nullptr;
			}

		}
	};
	Predstava(const Predstava& p) {
		kopiraj(p);
	}
	Predstava(Predstava&& p) {
		premesti(p);
	}
	~Predstava()
	{
		brisi();
	}
	Predstava& operator=(const Predstava& p) {
		if (this!=&p)
		{
			brisi();
			kopiraj(p);
		}
		return *this;
	}
	Predstava& operator=( Predstava&& p) {
		if (this != &p)
		{
			brisi();
			kopiraj(p);
		}
		return *this;
	}

	
	string dohvNasl() const {
		return naslov;
	}
	long dohvDat() const {
		return datum;

	}

	int dohv_br_red() const {
		return br_red;
	}
	int dohv_duz_red() const {
		return duz_red;
	}

	bool operator+=(const Karta& k);
	float vrednost() const;
	friend ostream& operator<<(ostream& it, Predstava& p);




};