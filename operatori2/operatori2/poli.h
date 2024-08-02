#ifndef poli_h_
#define poli_h_

#include <iostream>
using namespace std;




class Poli
{

	int n;
	double* a;

	void kopiraj(const double* a, int n);
	void premesti(Poli& p)                   // Premeštanje u polinom.
	{
		n = p.n; a = p.a; p.a = nullptr;
	}
	void brisi() { delete[] a; a = nullptr; n = -1; }

public:
	Poli() : n(-1), a(nullptr) {}                    // - prazan polinom,
	Poli(const double* a, int n) { kopiraj(a, n); } // - kopiranjem niza,
	Poli(const Poli& p) { kopiraj(p.a, p.n); }              // - kopiranjem polinoma,
	Poli(Poli&& p) { premesti(p); }                 // - premeštanjem polin.
	~Poli() { brisi(); }

	Poli& operator=(const Poli& p) {                        // - kopiranjem,
		if (this != &p) {  kopiraj(p.a, p.n); }
		return *this;
	}
	Poli& operator=(Poli&& p) {                      // - premeštanjem.
		if (this != &p) {  premesti(p); }
		return *this;
	}


	void niz(double* niz, int& nn) const {
		nn = n;
		for (int i = 0; i <=nn; i++)
		{
			niz[i] = a[i];
		}
	
	}

	double operator()(double x)const;

	double& operator[](int index) {
		
		if (index<0 || index> n)
		{
			cout << "Greska";
			exit(1);
		}
		return a[index];

	}

	friend Poli& operator+(const Poli& p1, const Poli& p2) {
		int n;
		if (p1.n == p2.n) for (n = p1.n; n >= 0 && p1.a[n] + p2.a[n] == 0; n--);
		else            n = (p1.n > p2.n) ? p1.n : p2.n;
		Poli p; p.n = n; p.a = new double[n + 1];
		for (int i = 0; i <= n; i++)
			p.a[i] = (i > p2.n) ? p1.a[i] :
			(i > p1.n) ? p2.a[i] :
			p1.a[i] + p2.a[i];
		return p;
	}


	double red() const {
		return n;
	}

	friend istream& operator>>(istream& it, Poli& p) {
		it >> p.n;
		p.a = new double[p.n + 1];
		for (int i = p.n; i >=0; i--)
		{
			it >> p.a[i];
		}

		return it;
	}

	friend ostream& operator<<(ostream& it, const Poli& p) {
		it << "p[ ";
		for (int i = p.n; i >=0; i--)
		{
			it << p.a[i] << (i ? ", " : "");
		}
		it << "]";
		return it;
	}



};

#endif // !poli_h_
