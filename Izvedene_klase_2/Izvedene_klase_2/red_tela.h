#ifndef _red_tela_h_
#define _red_tela_h_


#include "telo1.h"
#include <iostream>
#include <cstdlib>
#include <utility>

using namespace std;


class Red_tela {

	Telo** tela;
	int kap, duz;
	int prvo, posl;
	void kopiraj(const Red_tela& r);
	void premesti(Red_tela& rt) {
		tela = rt.tela;
		kap = rt.kap;
		duz = rt.duz;
		prvo = rt.prvo;
		posl = rt.posl;
		rt.tela = nullptr;


	}

	void brisi();
public:

	explicit Red_tela(int kap = 5);
	Red_tela(const Red_tela& rt) {
		kopiraj(rt);
	}
	Red_tela(Red_tela&& rt) {
		premesti(rt);
	}
	~Red_tela()
	{
		brisi();
	}
	Red_tela& operator=(const Red_tela& rt) {
		if (this!=&rt)
		{
			brisi();
			kopiraj(rt);
		}
		return *this;
	}
	Red_tela& operator=( Red_tela&& rt) {
		if (this != &rt)
		{
			brisi();
			premesti(rt);
		}
		return *this;
	}

	bool pun() const {
		return duz == kap;
	}

	bool prazan() const {
		return duz == 0;
	}


	Red_tela& operator+=(const Telo& t) {  ////////
		if (duz==kap)
		{
			exit(1);
		}
		tela[posl++] = t.kopija();
		if (posl==kap)
		{
			posl = 0;
		}
		duz++;

		return *this;
	}

	Red_tela& operator+=(Telo&& t) {

		if (duz==kap)
		{
			exit(1);
		}
		tela[posl++] = move(t).kopija();
		if (posl==kap)
		{
			posl = 0;
		}
		duz++;
		return *this;

	}


	Telo* uzmi() {
		if (duz==0)
		{
			exit(2);
		}
		Telo* t = tela[prvo++];
		if (prvo==kap)
		{
			prvo = 0;
		}
		duz--;
		return t;


	}

	friend ostream& operator<<(ostream& it, const Red_tela& r);



};











#endif // !_red_tela_h_
