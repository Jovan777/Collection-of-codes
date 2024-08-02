
#include "jmbg.h"
#include <string>
#include <iostream>
using namespace std;

class Osoba {

	string ime;
	JMBG jmbg;

public:

	Osoba(string i, JMBG j) : jmbg(j) , ime(i) {}

	string dohvIme() const { return ime; }
	JMBG dohv_JMBG() const { return jmbg; }

	void pisi() const {
		cout << ime << " ( ";
		jmbg.pisi();
		cout << " )";

	}




};