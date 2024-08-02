#include "datum1.h"
#include <iostream>

using namespace std;

/*
const short Datum::duz[][12] = {

	{31,28,31,30,31,30,31,31,30,31,30,31}, {31,29,31,30,31,30,31,31,30,31,30,31}

};

const short Datum::prot[][12] = {
	{0,31,59,90,120,151,181,212,243,273,304,334}, {0,59,60,91,121,152,182,213,244,274,305,335}

};

const string Datum::ime_d[] = { "ponedeljak", "utorak", "sreda", "cetvrtak", "petak", "subota", "nedelja" };
const string Datum::ime_m[] = { "januar", "februar", "mart", "april", "maj", "jun", "jul", "avgust", "septembar", "oktobar", "novembar", "decembar" };

Datum Datum::citaj() {
	short d, m, g;

	while (true)
	{
		cin >> d >> m >> g;
		if (moze(d, m, g))
		{
			break;
		}
		cout << "Los datum";

	}
	return Datum(d, m, g);
}

void Datum::pisi() const {
	cout << dan / 10 << dan % 10 << ". " << ime_m[mes - 1] << ". " << god << ".";

}

long Datum::ukDan() const{

	short g = god - 1;
	return g * 365L + g / 4 - g / 100 + g / 400 + danUgod();

}

void Datum::sutra()  {
	if (dan<duzMes())
	{
		dan++;
	}
	else
	{
		dan = 1;
		if (mes<12)
		{
			mes++;
		}
		else
		{
			mes = 1;
			god++;
		}

	}



}


void Datum::juce() {
	if (dan>1)
	{
		dan--;

	}
	else
	{
		if (mes>1)
		{
			mes--;
		}
		else
		{
			mes = 12; god--;
		}
		dan = duzMes();
	}

}

void Datum::dodaj(unsigned k) {
	for (unsigned i = 0; i < k; i++)
	{
		sutra();
	}
}

*/