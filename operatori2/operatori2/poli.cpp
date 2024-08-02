#include "poli.h"


void Poli::kopiraj(const double* aa, int nn) { // Kopiranje u tekuæi objekat
	n = nn;
	a = new double[nn+1];
	for (int i = 0; i <=n ; i++)
	{
		a[i] = aa[i];
	}

}

double Poli::operator()(double x)const {
	double s = 0;
	for (int i = n; i >=0 ; i--)
	{
		(s *= x) += a[i];
	}

	return s;
}