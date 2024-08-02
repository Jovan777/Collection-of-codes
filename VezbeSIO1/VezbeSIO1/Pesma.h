#ifndef pesma_h_
#define pesma_h_


#include "Izvodjac.h"

#include <iostream>
#include <string>



class Pesma
{
	string naziv;
	int minuti;
	int sekunde;
	Izvodjac** izvodjaci;
	int maxI;
	int brI;

	void pisi(ostream& it) const{
		it << "P(" << naziv << "-" << minuti << ":" << sekunde << ")" << endl;
		for (int i = 0; i < brI; i++)
		{
			it << *izvodjaci[i] << endl;
		}
	}


public:
	Pesma(string n, int min, int sek, int max) : naziv(n), minuti(min), sekunde(sek), maxI(max) {
		izvodjaci = new Izvodjac*[maxI];
		brI = 0;
	}

	Pesma(const Pesma& p) = delete;
	Pesma(Pesma&& p) = delete;
	~Pesma()
	{
		delete[] izvodjaci;
	}


	int getMin() const { return minuti; }
	int getSek() const { return sekunde; }

	friend bool duze(const Pesma& p1, const Pesma& p2) {
		if (p1.minuti >p2.minuti || p1.minuti==p2.minuti && p1.sekunde>p2.sekunde)
		{
			return true;
		}
		return false;

	}

	void dodaj(Izvodjac* izv) {
		if (brI<maxI)
		{
			izvodjaci[brI++] = izv;
		}
		return;

	}

	int trajanje() const {
		return 60 * minuti + sekunde;

	}

	
	friend ostream& operator<<(ostream& it, const Pesma& p) {
		p.pisi(it);
		return it;
	}




};

#endif // !pesma_h_
