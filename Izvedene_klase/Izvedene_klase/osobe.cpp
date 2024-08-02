#include "osobe.h"

void Osoba::citaj() {
	cout << "Ime i prezime?     "; getline(cin, ime);
	cout << "Datum rodjenja?    "; getline(cin, datum);
	cout << "Adresa stanovanja? "; getline(cin, adresa);
}

void Osoba::pisi() const {
	cout << "Ime i prezime : " << ime << endl;
	cout << "Datum rodj. : " << datum << endl;
	cout << "Adresa : " << adresa << endl;

}


void Djak::citaj() {
	Osoba::citaj();

	cout << "Skola : "; getline(cin, skola);
	cout << "Razred : "; getline(cin, razred);


}

void Djak::pisi() const {
	Osoba::pisi();
	cout << "Skola : " << skola << endl;
	cout << "Razred : " << razred << endl;

}

void Zaposleni::citaj() {
	Osoba::citaj();
	cout << "Firma : "; getline(cin, firma);
	cout << "Odeljenje : "; getline(cin, odeljenje);


}

void Zaposleni::pisi() const {
	Osoba::pisi();
	cout << "Firma : " << firma << endl;
	cout << "Odeljenje : " << odeljenje << endl;


}
