#pragma once

#include "zapis.h"
#include <iostream>
#include <string>

using namespace std;


class Inventar
{
	Zapis** niz;
	int kap, duz;
	void kopiraj(const Inventar& inv);            // Kopiranje u objekat.
	void premesti(Inventar& inv) {                // Premeštanje u objekat.
		niz = inv.niz; kap = inv.kap; duz = inv.duz;
		inv.niz = nullptr;
	}
	void brisi();


public:
	Inventar(int k = 10) : kap(k), duz(0) {
		niz = new Zapis * [kap];
	}
	Inventar(const Inventar& inv)                 // Kopirajuæi konstruktor.
	{
		kopiraj(inv);
	}
	Inventar(Inventar&& inv)                      // Premeštajuæi konstruktor.
	{
		premesti(inv);
	}
	~Inventar() { brisi(); }                         // Destruktor.
	Inventar& operator=(const Inventar& inv) {       // Kopirajuæa dodela
		if (this != &inv) { brisi(); kopiraj(inv); }   //   vrednosti.
		return *this;
	}
	Inventar& operator=(Inventar&& inv) {            // Premeštajuæa dodela
		if (this != &inv) { brisi(); premesti(inv); }  //   vrednosti.
		return *this;
	}
	int duzina() const { return duz; }

	Zapis* operator[](string naziv);                 // - iz promenljivog,
	const Zapis* operator[](string naziv) const      // - iz nepromenljivog
	{
		return const_cast<Inventar&>(*this)[naziv];
	} // objekta.
	bool operator+=(Zapis* z) {                      // Dodavanje zapisa.
		if (duz == kap || (*this)[z->getN()]) return false;
		niz[duz++] = z; return true;
	}
	// Iteratori:
	Zapis** begin() { return niz; }                     // - za promenljive
	Zapis** end() { return niz + duz; }                 //   inventare,
	const Zapis* const* const begin() const { return niz; } // - za nepromenljive
	const Zapis* const* const end() const { return niz + duz; }  //   inventare.
	double vrednost() const;                       // Vrednost svih artikala.
	friend ostream& operator<<(ostream& it, const Inventar& inv); // Pisanje.



};

