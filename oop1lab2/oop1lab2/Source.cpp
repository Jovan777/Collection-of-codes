#include <iostream>
#include "cvecara.h"
#include "spil.h"
#include "pogodak.h"


using namespace std;


int main() {

	Fudbaler f1("Messi", "Argentina", Fudbaler::FWD);

	cout << f1 << endl;

	Fudbaler f2("Isagi", "Japan", Fudbaler::MID);

	cout << f2 << endl;

	cout << f2.dohvIme() << endl;
	cout << f2.dohvRepr() << endl;
	cout << f2.dohvPoz() << endl;

	f2.promeniPoz(Fudbaler::FWD);

	cout << f2 << endl;

	Pogodak p1(&f1, 55);

	cout << p1 << endl;

	Fudbaler* ff = p1.dohvStrelca();

	cout << *ff << endl;

	return 0;
}