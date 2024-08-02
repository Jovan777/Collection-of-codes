#include <iostream>
#include "lista.h"
#include "slika.h"
#include "Nota.h"
#include "Takt.h"

using namespace std;

struct Node {

	int n;
	Node* sled;

	Node(int nn, Node* s = nullptr) : n(nn), sled(s) {};

	

};



int main() {

	/*
	Razlomak r1(1, 2);
	Razlomak r2(1, 3);

	Nota n1(1, Nota::MI, r1);
	
	cout << n1 << endl;

	Pauza p(r2);

	Node c1(1);
	Node c2(2, &c1);

	cout << c1.n << c2.sled->n << endl;
	*/

	Sekvenca<int> s1;

	int n1 = 1;
	int n2 = 2;
	int n3 = 3;
	s1.dodaj(n1);
	s1.dodaj(n2);
	s1.dodaj(n3);

	Razlomak osm(1, 8), cet(1, 4), pol(1, 2);
	Nota mi_2(2, Nota::MI, pol),
		re_4(2, Nota::RE, cet),
		do_8(2, Nota::DO, osm),
		la_8(2, Nota::LA, osm),
		sol_4(2, Nota::SOL, cet),
		si_2(2, Nota::SI, pol);
	Pauza p_2(pol), p_4(cet), p_8(osm);


	Takt t1(pol), t2(pol), t3(pol);
	
	t1.dodaj(re_4);
	t2.dodaj(mi_2);
	t3.dodaj(la_8);

	cout << t2 << endl;

	

	return 0;
}