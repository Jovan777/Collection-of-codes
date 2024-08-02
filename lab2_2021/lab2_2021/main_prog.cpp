#include <iostream>
#include "skladiste.h"
#include "Cvecara.h"
#include "biblioteka.h"

using namespace std;

double PTrougla(double a, double b, double c) {
	double s = (a + b + c) / 2;
	return sqrt(s * (s - a) * (s - b) * (s - c));


}

double PTrougla(double a, double b) {
	return PTrougla(a, b, b);
}

double PTrougla(double a) {
	return PTrougla(a, a, a);
}



int main() {


	//Kupe i skladiste
	/*
	Kupa k1;

	Kupa k2(5, 5);

	Kupa k3(3, 4);

	
	Zarubljena z1(1,5,3);

	Zarubljena z2(5, 5, 3);

	
	Skladiste s1;

	s1 += &k1;
	s1 += &k2;
	s1 += &k3;
	s1 += &z1;
	s1 += &z2;

	cout << s1 << endl;
	

	//Cvecara

	
	Buket b;
	Cvet c1("Ruza", 100, 150);
	Cvet c2("Lala", 110, 130);
	Cvet c3("Karanfil", 200, 300);

	b.dodaj(&c1);
	b.dodaj(&c2);
	b.dodaj(&c3);

	cout << b.zar() << endl;
	

	Buket b2;
	Cvet c4("Maslacak", 50, 100);
	Cvet c5("Jorgovan", 500, 750);

	b2.dodaj(&c4);
	b2.dodaj(&c5);


	Cvecara c;
	c.dodaj(&b);
	c.dodaj(&b2);
	
	cout << c << endl;
	
	Knjiga k("Knjiga", "ALL");

	Knjiga k2("Knjiga2", "nop");

	Knjiga k3("Knjiga3", "noasp");

	Biblioteka b("lib", 5);	
	
	cout << k << endl << k2 << endl << k3;

	b += k;
	b += k2;
	b += k3;


	cout << b << endl;

	Knjiga* z = b.dohvati(3);
	cout << *z << endl;
	*/


	double a = 5, double b = 4, double c = 3;

	cout << "Opsti trougao P : " << PTrougla(a, b, c) << endl;
	




	return 0;
}