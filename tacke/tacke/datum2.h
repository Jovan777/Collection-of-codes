#pragma once
#include <iostream>

using namespace std;

static	const int dani[2][12] = {
		{31,28,31,30,31,30,31,31,30,31,30,31},
		{31,29,31,30,31,30,31,31,30,31,30,31}

};


class Datum {

	int d, m, g;
	

public:

	

	static bool moze(int d, int m, int g) {
		return g > 0 && d > 0 && m > 0 && m <= 12 && d <= dani[g % 4==0][m - 1];
	}

	explicit Datum(int d=1, int m=7, int g=2000) : d(d), m(m), g(g) {
		if (!moze(d, m, g))
		{
			exit(1);
		}
	};

	int dan() { return d; };
	int mes() { return m; }
	int god() { return g; }

	int uporedi(const Datum& dat) {
		if (g!=dat.g)
		{
			return abs(g - dat.g);
		}
		if (m!=dat.m)
		{
			return abs(m - dat.m);
		}
		return abs(d - dat.d);

	}




	bool citaj() { // Èitanje datuma.
		int d, m, g; cin >> d >> m >> g;
		if (!moze(d, m, g)) return false;
		*this = Datum(d, m, g); return true;
	}

	void pisi() const {
		cout << d << "." << m << '.' << g <<'.' << endl;
		
	}




};



