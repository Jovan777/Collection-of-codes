#include <iostream>


using namespace std;

#include "film.h"

int main() {

	try
	{
		List<int> l1;

		l1 += 1;
		l1 += 2;
		l1 += 3;


		cout << l1 << endl;

		cout << l1[2] << endl;

		l1[1] = 5;

		cout << l1[1] << endl;
		cout << l1 << endl;

		cout << endl << endl;
		
		Vreme v1(1, 15);
		Vreme v2(2, 46);

		cout << v1 << endl << v2 << endl << (v2 > v1) << endl;

		Vreme v3 = v1 + v2;

		cout << endl << v3;

		cout << endl << endl;


		/////radi
		
		Domaci f1("Balkanski spijun", Vreme(1, 30));

		cout << f1.getIme() << endl;
		cout << f1.getTrajanje() << endl;
		f1.oceni(10);
		f1.oceni(9);
		cout << endl;
		cout << f1.prosekOcena() << endl;
		
		cout << f1.brojOcena() << endl;
		
		cout << f1 << endl;


		
		Strani f2("Paklene ulica 3", Vreme(2, 0), "USA", Strani::TITLOVAN);

		f2.oceni(10);

		cout << f2 << endl;




	}
	catch (PremasenOpseg& p)
	{
		cout << p << endl;
	}
	

	return 0;
}