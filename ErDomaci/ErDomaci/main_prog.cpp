#include <iostream>
#include "mapa.h"


using namespace std;



int main() {

	Polje_sa_sumom ps(150, 200);

	cout << ps << endl << endl;


	Mapa m(3, 3);
	cout << m << endl;

	m += 50;
	cout << m << endl;
	m -= 70;

	cout << m << endl;

	m.zamena(1, 1, 50);
	m.zamena(2, 2, VrstaPuta::KAMENI);
	cout << m << endl;

	Mapa m2 = m;


	cout << m2 << endl;


	return 0;
}