#ifndef predstava_h_
#define predstava_h_

#include "karta.h"
#include <iostream>
using namespace std;









class Predstava
{

	string naslov;
	long datum;
	int brRed;
	int brSed;
	Karta*** karte;

	void kopiraj(const Predstava& p);
	void premesti(Predstava& p) {
		naslov = p.naslov;
		datum = p.datum;
		brRed = p.brRed;
		brSed = p.brSed;
		karte = p.karte;
		p.karte = nullptr;


	}

	void brisi() {

		for (int i = 0; i < brRed; i++)
		{
			for (int j = 0; j < brSed; j++)
			{
				delete karte[i][j];
			}
			delete[] karte[i];
		}
		delete[] karte;

	}



public:
	Predstava(string n, long d, int red, int sed) : naslov(n), datum(d), brRed(red), brSed(sed) {
		karte = new Karta * *[brRed];
		for (int i = 0; i < brSed; i++) {
			karte[i] = new Karta * [brSed];
			for (int j = 0; j < brSed; karte[i][j++] = nullptr);
		}

	
	};
	Predstava(const Predstava& p) {
		kopiraj(p);
	}

	Predstava(Predstava&& p) {
		premesti(p);
	}

	Predstava& operator=(const Predstava& p) {
		if (this!=&p)
		{
			brisi();
			kopiraj(p);
		}
		return *this;
	}


	Predstava& operator=(Predstava&& p) {
		if (this!=&p)
		{
			brisi();
			premesti(p);
		}
		return *this;
	}

	~Predstava()
	{
		brisi();
	}

	string getN() const {
		return naslov;
	}

	long getDate() const {
		return datum;
	}

	int getBrRed() const {
		return brRed;
	}
	int getBrSed() const {
		return brSed;
	}



	bool operator+=(const Karta& k) {
		int red = k.getRed(), sed = k.getS();
		if (red < 0 || red >= brRed || sed < 0 || sed >= brSed || karte[red][sed])
			return false;
		karte[red][sed] = new Karta(k);
		return true;

	
	};

	double vrednost()const {
		double s=0;
		for (int i = 0; i < brRed; i++)
		{
			for (int j = 0; j < brRed; j++)
			{
				s += (karte[i][j] ? karte[i][j]->getCena() : 0);
			}
			
		}
		return s;

	}


	friend ostream& operator<<(ostream& it, const Predstava& p) {
		for (int i = 0; i < p.brRed; i++)
		{
			for (int j = 0; j < p.brSed; j++)
			{
				it << (p.karte[i][j] ? "#" : "_")<<" ";
			}
			it << endl;
		}
		return it;
	}








};

#endif // !predstava_h_
