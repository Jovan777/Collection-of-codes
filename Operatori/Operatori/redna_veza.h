#include "otpornik.h"
#include <iostream>
#include <cstdlib>
using namespace std;





class Redna_veza {

	Otpornik* niz;
	int duz, kap;
	void kopiraj(const Redna_veza& rv);
	void premesti(Redna_veza& rv) {
		niz = rv.niz;
		duz = rv.duz;
		kap = rv.kap;
		rv.niz = nullptr;
	}

	void brisi() {
		delete[] niz;
	}

public:
	explicit Redna_veza(int k = 2) : niz(new Otpornik[k]), kap(k), duz(0) {};
	Redna_veza(const Redna_veza& rv) {
		kopiraj(rv);
	}

	Redna_veza(Redna_veza&& rv) {
		premesti(rv);
	}

	~Redna_veza()
	{
		brisi();
	}
	Redna_veza& operator=(const Redna_veza& rv) {
		if (this!=&rv)
		{
			brisi();
			kopiraj(rv);
		}
	}
	Redna_veza& operator=(Redna_veza&& rv) {
		if (this!=&rv)
		{
			brisi();
			premesti(rv);
		}
		
	}

	int dohvKap() const {
		return kap;
	}

	int dohvDuz() const {
		return duz;
	}

	Redna_veza& operator+=(const Otpornik& ot) {
		if (duz==kap)
		{
			exit(1);
		}
		niz[duz++] = ot;
		return *this;
	}
	
	Otpornik& operator[](int i) {
		if (i<0 || i>=duz)
		{
			exit(2);
		}
		return niz[i];
	}

	const Otpornik& operator[](int i)const {
		if (i < 0 || i >= duz)
		{
			exit(2);
		}
		return niz[i];
	}


	Otpornik* begin() {
		return niz;
	}
	Otpornik* end() {
		return niz + duz;
	}

	const Otpornik*const begin()const {
		return niz;
	}
	const Otpornik*const end()const {
		return niz + duz;
	}

	double otp() const;
	Redna_veza& izbaci();
	friend ostream& operator<<(ostream& it, Redna_veza& rv);



};