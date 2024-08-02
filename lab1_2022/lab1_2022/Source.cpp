#include <iostream>
#include "flota.h"
#include "arhiva.h"

using namespace std;


int main() {


	
	Pilot p("P", 150, true);
	Pilot p2("P2", 10);

	Pilot p11("P11", 100);
	Pilot p12("P12", 50);

	Pilot p31("P31", 200);
	Pilot p32("P32", 10);

	p.pisi();
	cout << endl;
	p2.pisi();

	Avion a1("JAT", 100);
	Avion a2("AIR", 200);
	Avion a3("Airplane7", 300);
	Avion a4("Airplane8", 300);
	Avion a5("Airplane9", 300);

	a1.setKap(&p);
	a1.setKop(&p2);

	a2.setKap(&p11);
	a2.setKop(&p12);

	a3.setKap(&p31);
	a3.setKop(&p32);

	Pilot* p3 = a1.getKap();
	Pilot* p4 = a1.getKop();

	cout << endl;
	p3->pisi();
	cout << endl;

	p4->pisi();
	cout << endl;
	p2.pisi();

	cout << endl;

	a1.pisi();
	cout << endl;
	cout << endl;
	cout << endl;
	
	Flota f1("Flota1");

	f1.dodaj(&a1);
	f1.dodaj(&a2);
	f1.dodaj(&a3);
	f1.dodaj(&a4);
	f1.dodaj(&a5);

	f1.pisi();
	cout << endl;

	cout << "Usao" << endl;
	Avion* pa = f1.getMaxA();
	pa->pisi();
	cout << endl;
	cout << "broj aviona : " << f1.numberOfPlanes() << endl;
	cout << "broj putnika : " << f1.brojP() << endl;
	
	cout <<"Brisanje"<< endl;

	f1.brisiAvion("AIR"); //radi brisanje
	f1.pisi();
	cout << "Usao2" << endl;
	cout << endl;
	Flota::Elem* head = f1.dohvMax(100, 500);
	cout << endl;

	Flota::Elem* temp = head;
	while (temp)
	{
		//cout << "Usao3" << endl;

		temp->avion->pisi(); cout << endl;
		temp = temp->sled;
	}

	cout << endl;
	f1.pisi();

	cout << endl << endl ;

	Let l1("Beograd", "Atina", &a1);
	Let l2("Beograd", "Brisel", &a3);
	Let l3("Amsterdam", "Atina", &a2);
	Let l4("Beograd", "Atina", &a3);


	//l1.pisi();

	cout << endl << endl;

	Arhiva a;
	a.dodaj(l1);
	a.dodaj(l2);
	a.dodaj(l3);
	a.dodaj(l4);

	a.pisi();

	Arhiva ar2 = a.istoP("Beograd");
	Arhiva ar3 = a.istoD("Atina");

	cout << endl;
	ar2.pisi();
	cout << endl;
	ar3.pisi();

	Arhiva ar4 = a.istoPD("Beograd", "Atina");

	cout << endl;
	ar4.pisi();


	return 0;
}