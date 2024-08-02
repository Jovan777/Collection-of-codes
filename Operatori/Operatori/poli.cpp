#include "Poli.h"
#include <cstdlib>
#include <string>

using namespace std;


[[ noreturn ]] void Poli::greska(Greska g) {
	string poruke[] = {
		"Nedozvoljen red polinoma", "Nedozvoljen indeks"
	};
	cerr << "***" << poruke[(int)g] << endl;
	exit((int)g + 1);
}

void Poli::kopiraj(const double* aa, int nn) {
	if ((n=nn)<-1)
	{
		return greska(Greska::G_RED);
	}
	a = new double[nn + 1];
	for (int i = 0; i < nn; i++)
	{
		a[i] = aa[i];
	}

}

void Poli::niz(double* aa, int& nn) const{
	for (int i = 0; i < n; i++)
	{
		aa[i] = a[i];

	}
	nn = n;

}

double Poli::operator()(double x) const{
	double s = 0;
	for (int i = n; i >=0 ; i--)
	{
		(s *= x) += a[i];
	}
	return s;
}

double& Poli::operator[](int ind) {
	if (ind<0 || ind>n)
	{
		greska(Greska::G_IND);
	}
	return a[ind];
}


const double& Poli::operator[](int ind) const{
	if (ind<0 || ind>n)
	{
		greska(Greska::G_IND);
	}
	return a[ind];
}


Poli operator+(const Poli&p1, const Poli&p2) {
	int n;

	if (p1.n==p2.n)
	{
		for (n = p1.n; n >= 0 && p1.a[n] + p2.a[n] == 0; n--);
	}
	else
	{
		n = (p1.n > p2.n) ? p1.n : p2.n;
	}
	Poli p;
	p.n = n;
	p.a = new double[n+1];
	for (int i = 0; i <=n ; i++)
	{
		p.a[i] = (i > p2.n) ? p1.a[i] : (i > p1.n) ? p2.a[i] : p1.a[i] + p2.a[i];
	}


	return p;
}

Poli operator-(const Poli& p1, const Poli& p2) {
	int n;

	if (p1.n == p2.n)
	{
		for (n = p1.n; n >= 0 && p1.a[n] - p2.a[n] == 0; n--);
	}
	else
	{
		n = (p1.n > p2.n) ? p1.n : p2.n;
	}
	Poli p;
	p.n = n;
	p.a = new double[n + 1];
	for (int i = 0; i <= n; i++)
	{
		p.a[i] = (i > p2.n) ? p1.a[i] : (i > p1.n) ? -p2.a[i] : p1.a[i] - p2.a[i];
	}


	return p;
}

Poli operator*(const Poli& p1, const Poli& p2) {
	int n = (p1.n >= 0 && p2.n >= 0) ? p1.n + p2.n : -1;

	Poli p;
	p.n = n;
	p.a = new double[n + 1];

	for (int i = 0; i <=n; i++)
	{
		p.a[i] = 0;
	}

	for (int i = 0; i < p1.n; i++)
	{
		for (int j = 0; j < p2.n; j++)
		{
			p.a[i + j] += p1.a[i] * p2.a[j];
		}

	}

	return p;
}

istream& operator>>(istream& ut, Poli& p) {
	p.brisi();

	ut >> p.n;
	if (p.n<-1)
	{
		Poli::greska(Poli::Greska::G_RED);
	}
	p.a = new double[p.n+ 1];
	for (int i = p.n; i >=0 ; i--)
	{
		ut >> p.a[i];
	}

	return ut;
}

ostream& operator<<(ostream& it, Poli& p) {
	it << "p [ ";
	for (int i = p.n; i >=0 ; i--)
	{
		it << p.a[i] << (i ? " , " : "");
	}
	it << " ]";

	return it;
}