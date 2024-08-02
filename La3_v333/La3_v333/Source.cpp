#include <iostream>

using namespace std;

#include "lista.h"
#include "boja.h"
#include "ukras.h"

int main() {

	try {
		Lst<int> lista;


		lista <<= 1;
		lista <<= 2;
		lista <<= 3;
		lista >>= 5;

		cout << lista << endl;

		cout << endl << endl;

		Boja b1(10, 10, 10);
		Boja b2(20, 20, 20);

		cout << b1;
		cout << b2;

		Boja b3 = b1 + b2;

		cout << b3;
		cout << endl << endl;

		Kugla k1(100, b1, Kugla::MALA);

		cout << k1 << endl;
	}
	catch (TempNull& t) {
		cout << t;
	}


	return 0;
}