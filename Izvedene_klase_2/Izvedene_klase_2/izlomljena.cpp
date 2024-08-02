#include "izlomljena.h"
#include "duz1.h"

void Linije::Izlomljena::kopiraj(const Tacka* niz, int k) {
	tem = new Tacka[n = k];
	for (int i = 0; i < n; i++)
	{
		tem[i] = niz[i];
	}


}


double Linije::Izlomljena::duzina() const {
	double d = 0;
	for (int i = 0; i < n-1; i++)
	{
		d += Duz(tem[i], tem[i + 1]).duzina();
	}
	return d;


}

