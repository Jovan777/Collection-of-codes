#include <iostream>
#include "kanta.h"
#include "osobe.h"
#include "knjiga.h"
#include "knjiga_polovna.h"
#include "polica.h"
#include "knjiga_trvrdo_kor.h"
#include "lista.h"
#include "lista6.h"
#include "predmet.h"
#include "sfera.h"
#include "kvadar.h"
#include "figura1.h"
#include"trougao4.h"
#include "kvadrat.h"
#include "krug2.h"


using namespace std;





int main() {


	//valjak i kanta
	
	/*
	Valjak v1(2, 3); cout << "v1 : " << v1 << " " << v1.V() << endl;
	Kanta k1(1, 3, 10); cout << "k1 : " << k1 << " " << k1.V() << endl;
	cout << "k1-=5 : " << (k1 -= 5) << endl;
	cout << "k1==4 : " << (k1 += 4) << endl;

	Kanta k2( 0.6, 5); cout << "k2 : " << k2 << " " << k2.V() << endl;

	cout << "k2=k1 : " << (k2 = k1) << endl;
	cout << "k1 : " << k1 << endl;

	Valjak& uv = k1; cout << "uv : " << uv << " , " << uv.V() << endl;
	Valjak* pv = &k1; cout << "*pv : " << *pv << " , " << pv->V() << endl;
	Kanta& uk = k1; cout << " uk : " << uk << " , " << uk.V() << endl;
	*/

	//osobe

	/*
	Osoba* ljudi[20];
	int n = 0;

	cout << "Citanje podataka : " << endl;
	while (true)
	{
		char izbor;
		cin >> izbor;
		cin.get();

		if (izbor=='k')
		{
			break;
		}
		ljudi[n] = nullptr;
		switch (izbor)
		{
		case 'o':
			ljudi[n] = new Osoba;
			break;
		case 'd':
			ljudi[n] = new Djak;
			break;
		case 'z':
			ljudi[n] = new Zaposleni;
			break;
		}
		if (ljudi[n])
		{
			ljudi[n++]->citaj();
		}


	}

	cout << "\nPrikaz osoba : " << endl;
	for (int i = 0; i < n; i++)
	{
		cout << endl; ljudi[i]->pisi();

	}

	for (int i = 0; i < n; i++)
	{
		delete ljudi[i];
	}
	*/

	//knjige
	
	/*
	Knjiga* knjige[] = {
		new Knjiga("Mark Tven", "Starac i more", 1000),
		new Knjiga_tvrdo_kor("Lav Tolstoj", "Rat i mir", 2000, 100),
		new Knjiga_polovna("Viktor Igo", "Jadnici", 1600, 10)
	};

	Polica polica;
	for (auto pk : knjige) {
		polica += pk;
	}
	cout << polica;
	for (auto pk : knjige) {
		delete pk;
	}
	*/


	//liste

	/*
	N_Lista lst1;
	U_Lista lst2;

	cout << "Niz : ";

	do
	{
		int b;
		cin >> b;
		lst1 += b;
		lst2 += b;


	} while (cin.get()!='\n');

	cout << "Neuredjeno : " << lst1 << endl;
	cout << "Uredjeno : " << lst2 << endl;

	N_Lista lst3;

	cout << "Niz : ";

	do
	{
		int b;
		cin >> b;
		lst3 += b;


	} while (cin.get() != '\n');


	cout << "Neuredjeno : " << (lst1+=lst3) << endl;
	cout << "Uredjeno : " << (lst2+=lst3) << endl;
	cout << "usao";
	lst1 += lst1;
	lst2 += lst2;
	

	cout << "Neuredjeno : " << lst1 << endl;
	cout << 'e';
	cout << "Uredjeno : " << lst2 << endl;

	*/

	/*
	5 9 3 7 1
	6 2 8 4 0
	*/


	//predmeti


	/*
	Predmet* p[100];
	
	double q = 0;
	int n = 0;

	char tip;

	while (true)
	{
		cin >> tip;
		if (tip=='.')
		{
			break;
		}

		switch (tip)
		{
		case 's':
			p[n] = new Sfera; break;

		case 'k':
			p[n] = new Kvadar; break;
		
		}
		 
		if (p[n])
		{
			cin >> *p[n];
			cout << *p[n] << " : q = " << p[n]->q() << endl;
			q += p[n++]->q();

		}



	}

	if (n)
	{
		q /= n;
	}

	cout << "qsr = " << q << endl;
	for (int i = 0; i < n; i++)
	{
		if (p[i]->q() > q)
		{
			cout << *p[i] << " q = " << p[i]->q() << endl;
		}

	}
	*/
	

	//figure

	struct Elem {
		Figura* f;
		Elem* sled;

		Elem(Figura* pf, Elem* s=nullptr) : f(pf), sled(s) {};
		~Elem() {
			delete f;
		}

	};
	

	Elem* prvi = nullptr, * posl = nullptr;
	while (true) {
		Figura* pf = nullptr;
		char vrsta; cin >> vrsta;
		switch (vrsta) {
		case 'o': pf = new Krug;    break;
		case 'k': pf = new Kvadrat; break;
		case 't': pf = new Trougao; break;
		}
		if (!pf) break;
		cin >> *pf;
		Elem* novi = new Elem(pf);
		posl = (!prvi ? prvi : posl->sled) = novi;
	}

	// Prikazivanje sadržaja liste na standardnom izlazu.
	for (Elem* tek = prvi; tek; tek = tek->sled) cout << *tek->f << endl;

	// Èitanje pomeraja za pomeranje figura.
	double dx, dy; cin >> dx >> dy;
	cout << "\ndx, dy= " << dx << ", " << dy << "\n\n";

	// Stvaranje kopije liste uz pomeranje figura.
	Elem* poc = nullptr, * kraj = nullptr;
	for (Elem* tek = prvi; tek; tek = tek->sled) {
		Elem* novi = new Elem(tek->f->kopija());
		novi->f->pomeri(dx, dy);
		kraj = (!poc ? poc : kraj->sled) = novi;
	}

	// Uništavanje prve liste.
	while (prvi) { Elem* stari = prvi; prvi = prvi->sled; delete stari; }
	posl = nullptr;

	// Prikazivanje sadržaja kopirane liste na standardnom izlazu.
	for (Elem* tek = poc; tek; tek = tek->sled) cout << *tek->f << endl;

	// Uništavanje druge liste.
	while (poc) { Elem* stari = poc; poc = poc->sled; delete stari; }
	kraj = nullptr;





	return 0;
}