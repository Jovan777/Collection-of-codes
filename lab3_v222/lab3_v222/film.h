#ifndef film_h
#define film_h


#include "vreme.h"
#include <iostream>
#include "lista.h"

using namespace std;


class Film
{
	string ime;
	Vreme trajanje;
	List<int> ocene;


public:
	Film(string i, Vreme t) : ime(i), trajanje(t), ocene() {}

	void oceni(int ocena) {
		ocene += ocena;
	}

	virtual ~Film()
	{

	}
	double prosekOcena()  {
		int suma = 0;
		int k = ocene.getBR();
		if (k==0)
		{
			return 0;
		}

		for (int i = 0; i < k; i++)
		{
			suma += ocene[i];
		}

		return (double)suma /ocene.getBR();
	}

	Vreme getTrajanje() const {
		return trajanje;
	}

	string getIme() const {
		return ime;
	}

	int brojOcena() const {
		return ocene.getBR();
	}


	virtual char oznaka() const = 0;

	virtual void pisi(ostream& it)  {
		it << oznaka() << " " << ime << " " << trajanje << " " << prosekOcena();


	};

	friend ostream& operator<<(ostream& it,  Film& f) {
		f.pisi(it);
		return it;
	}


};



class Domaci : public Film {

public:
	Domaci(string i, Vreme tr) : Film(i, tr) {};

	char oznaka() const override {
		return 'D';
	}


};

class Strani : public Film {

	string zemlja;
	

public:
	enum Titl { TITLOVAN, SINHRONIZOVAN };

	Strani(string ime, Vreme t, string z, Titl prev) : Film(ime, t), zemlja(z), prevod(prev) {};


	char oznaka() const override {
		return 'S';
	}





private:
	Titl prevod;

	void pisi(ostream& it) {
		Film::pisi(it);
		it << " " << zemlja << " ";
		if (prevod==TITLOVAN)
		{
			it << "titlovan";
		}
		else
		{
			it << "sinhronizovan";
		}

	}



};




#endif // !1
