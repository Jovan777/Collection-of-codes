#ifndef strofa_h
#define strofa_h


#include "stih.h"

#include <iostream>

using namespace std;



class Strofa
{
protected:
	int kap;
	Stih* stihovi;

	int slogovi;
	bool imaPrvi;
	int duz;

public:
	Strofa(int br) : kap(br), slogovi(0), imaPrvi(false), duz(0) {
		stihovi = new Stih[br];
	}
	

	int getBr() const {
		return kap;
	}

	int operator+() {
		return slogovi;
	}



	void operator+=(const Stih& s);

	void operator-();

	Stih operator[](int ind);

	void operator()(int i, int j);

	virtual bool operator*()=0;  

	virtual char oznaka() const = 0;

	void ispisi(ostream& it) const{
		for (int i = 0; i < duz; i++)
		{
			it << stihovi[i];
		}

	}
	
	friend ostream& operator<<(ostream& it, const Strofa& s) {
		s.ispisi(it);
		return it;
	}






};


class Katren : public Strofa {

public:
	Katren() : Strofa(4) {};

	char oznaka() const override {
		return 'K';
	}


	bool operator*() override {
		Stih s1 = stihovi[0];
		Stih s2 = stihovi[1];
		Stih s3 = stihovi[2];
		Stih s4 = stihovi[3];

		bool prvi_poslendji = s1 ^ s4;
		bool drugi_pret = s2 ^ s3;

		if (prvi_poslendji && drugi_pret)
		{
			return true;
		}



		return false;
	}



};















#endif // !strofa_h
