#include <iostream>
//#include "avion.h"
#include "flota.h"
#include "let.h"

using namespace std;



int main() {

	//avion radi
	/*
	Pilot p1("Tom", 123, false);
	cout << p1.getIme() << endl;
	cout << p1.getSati() << endl;
	cout << p1.getA() << endl;

	p1.povecaj(12);
	cout << "Novi sati : " << p1.getSati() << endl;


	//Pilot p1("Tom", 123);
	Pilot p2("Harry", 19);
	Avion a1("Jat", 200);

	cout << p1.getA() << endl;
	cout << p2.getA() << endl;

	cout << "Avio" << endl;

	cout << a1.getIme() << endl;
	cout << a1.getMax() << endl;



	a1.setKap(&p1);
	a1.setKop(&p2);
	Pilot* p3 = a1.getKap();
	cout << p3->getIme() << endl;
	cout << p3->getSati() << endl;
	p3 = a1.getKop();
	cout << p3->getIme() << endl;
	cout << p3->getSati() << endl;

	cout << p1.getA() << endl;
	cout << p2.getA() << endl;

	cout << a1 << endl;
	*/

	//flota radi
	
	Pilot p1("Tom", 123, false);
	Pilot p2("Harry", 19);
	Avion a1("Jat", 200);
	a1.setKap(&p1);
	a1.setKop(&p2);

	Pilot p3("James", 110, false);
	Pilot p4("Henry", 10, false);


	Avion a2("Air", 300);

	a2.setKap(&p3);
	a2.setKop(&p4);

	Pilot p5("Marc", 300, false);
	Pilot p6("Artur", 20, false);

	Avion a3("Tourist", 250);
	a3.setKap(&p5);
	a3.setKop(&p6);

	//cout << p1 << p2 << p3 << p4 << endl;
	//cout << a1 << a2 << endl;

	Flota f1("Flota1");

	f1.dodaj(&a1);
	f1.dodaj(&a2);
	f1.dodaj(&a3);

	int brojF = f1.brojA();
	cout << "Flota ima : " << brojF << " aviona " << endl;
	brojF = f1.maxP();
	cout << "Flota ima maksimalno : " << brojF << " putnika " << endl;

	Avion* ax = f1.maxA();

	cout << *ax << endl;

	f1.pisi();

	Avion* niz_a = f1.dohvA(220, 300);
	cout << endl<< niz_a[0];
	cout << niz_a[1] << endl;


	//let radi


	Let l1("Beograd", "Berlin", &a2);
	Let l2("Beograd", "Berlin", &a2);
	Let l3("Beograd", "Berlin", &a2);

	string p = l1.getP();
	string d = l1.getD();

	//cout << p << " " << d << " " << l3.getId() << endl;

	cout << l1 << endl;





	return 0;
}
