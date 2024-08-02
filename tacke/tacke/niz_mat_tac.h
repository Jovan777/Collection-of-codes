#include "mat_tacka.h"

class Niz_mat_tac {

	Mat_tacka* niz;
	int kap, duz;


public:
	explicit Niz_mat_tac(int kap = 5) : niz(new Mat_tacka[5]), kap(kap), duz(0) {};

	
	Niz_mat_tac(const Niz_mat_tac& nmt);
	
	
	Niz_mat_tac(Niz_mat_tac&& nmt) {
		niz = nmt.niz;
		nmt.niz = nullptr;
		kap = nmt.kap;
		duz = nmt.duz;
	}

	~Niz_mat_tac()
	{
		delete[] niz;
	}

	int vel() const {
		return duz;

	}

	Niz_mat_tac& dodaj(const Mat_tacka& mt);
	Mat_tacka maxF(const Mat_tacka& mt) const;
	void pisi() const;


};

