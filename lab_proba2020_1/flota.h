#include <iostream>
#include "avion.h"
using namespace std;




class Flota {

	string imeFLote;
	
	struct Elem {
		Avion* avion;
		Elem* sled;

		Elem(Avion* a, Elem* s = nullptr) : avion(a), sled(s) {};
	};
	Elem* prvi;
	Elem* posl;

public:
	Flota(string i,Elem* pr=nullptr,Elem* po=nullptr) : imeFLote(i), prvi(pr), posl(po) {};

	int brojA() const;
	void dodaj(Avion* a);
	int maxP() const;

	Avion* maxA();

	void pisi() const;

	void izbaci(string ime);

	Avion* dohvA(int min, int max);





};

