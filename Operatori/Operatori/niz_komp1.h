#pragma once


#include "komp1.h"


class Niz_komp {

	int n;
	Kompl* niz;

	void kopiraj(const Niz_komp& nk) {
		niz = new Kompl[n = nk.n];
		for (int i = 0; i < n; i++)
		{
			niz[i] = nk.niz[i];
		}

	}

	void premesti(Niz_komp& nk) {
		niz = nk.niz;
		n = nk.n;
		nk.niz = nullptr;
	}

	void brisi() {
		delete[] niz;
	};


public:

	explicit Niz_komp(int n = 10) : n(n), niz(new Kompl[n]) {};

	Niz_komp(const Niz_komp& nk) {
		kopiraj(nk);
	}

	Niz_komp(Niz_komp&& nk) {
		premesti(nk);
	};

	~Niz_komp()
	{
		brisi();
	}


	Niz_komp& operator=(const Niz_komp& nk) {
		if (this!=&nk)
		{
			brisi();
			kopiraj(nk);
		}
		return *this;
	}


	Niz_komp& operator=( Niz_komp&& nk) {
		if (this!=&nk)
		{
			brisi();
			premesti(nk);
		}
		return *this;
	}


	int duz() const { return n; }


	Kompl& operator[](int i) {
		return niz[i];

	}


	const Kompl& operator[](int i) const {
		return niz[i];

	}

};