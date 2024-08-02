#pragma once
#include <iostream>
using namespace std;



class Poli {

	int n;
	double* a;
	using CP = const Poli;

	void kopiraj(const double* a, int n);
	void premesti(Poli& p) {
		n = p.n;
		a = p.a;
		p.a = nullptr;

	}

	void brisi() {
		delete[] a;
		a = nullptr;
		n = -1;
	}

public:
	Poli() : n(-1), a(nullptr) {};
	Poli(const double* a, int n) {
		kopiraj(a, n);
	}
	
	Poli(CP& p) {
		kopiraj(p.a, p.n);
	}
	
	Poli(Poli&& p) {
		premesti(p);
	}

	~Poli()
	{
		brisi();
	}

	Poli& operator=(CP& p) {
		brisi();
		kopiraj(p.a, p.n);
		return *this;
	}


	Poli& operator=(Poli&& p) {
		brisi();
		premesti(p);
		return *this;
	}

	void niz(double* a, int& n) const;
	int red() const { return n; }
	double operator() (double x) const;
	double& operator[](int ind);
	const double& operator[](int ind) const;

	friend Poli operator+(CP& p1, CP& p2);
	friend Poli operator-(CP& p1, CP& p2);
	friend Poli operator*(CP& p1, CP& p2);

	Poli& operator+=(CP& p2) {
		return *this = *this + p2;
	}
	Poli& operator-=(CP& p2) {
		return *this = *this - p2;
	}
	Poli& operator*=(CP& p2) {
		return *this = *this * p2;
	}

	friend istream& operator>>(istream& ut, Poli& p);
	friend ostream& operator<<(ostream& it, Poli& p);

private:
	enum class Greska{G_RED, G_IND};
	[[ noreturn ]] static void greska(Greska g); 






};