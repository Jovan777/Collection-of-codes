#include <iostream>
#include <string>

using namespace std;


class Osoba {
	string ime, datum, adresa;
public:
	Osoba() {}
	virtual void citaj();
	virtual void pisi() const;
};

class Djak : public Osoba {
	string skola, razred;

public:
	Djak() : Osoba() {};
	void citaj();
	void pisi() const;


};

class Zaposleni : public Osoba {
	string firma, odeljenje;

public:
	Zaposleni() : Osoba() {};
	void citaj();
	void pisi() const;


};