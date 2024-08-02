#include "red2.h"
#include <iostream>
#include "skup1.h"
#include "trouglovi.h"
//#include "datum1.h"
//#include "lista2.h"
#include "stablo.h"
#include "niz_mat_tac.h"
#include "lista_dat.h"
#include "imenik.h"

#include "Kvadar.h"

using namespace std;

void radi(Stablo& stb, void (Stablo::* pf)(int)) {
	int b;
	cout << "Brojevi : ";
	do
	{
		cin >> b;
		(stb.*pf)(b);

	} while (cin.get()!='\n');

}



int main() {

	//redovi
	/*
	Red* rd = new Red(5); 
	bool kraj = false;

	while (!kraj)
	{

		cout << "\n.1 Stvaranje reda\n"
			"2. Stavljanje podataka u red\n"
			"3. Uzimanje podataka iz reda\n"
			"4. Ispisivanje sadrzaja iz reda\n"
			"5. Praznjenje reda\n"
			"0. Kraj rada\n"
			"Unesite izbor\n";

		int izbor;
		cin >> izbor;

		switch (izbor)
		{

		case 1: 
			cout << "Kapacitet : " << endl;
			int kap;
			cin >> kap;
			if (kap>0)
			{
				delete rd;
				rd = new Red(kap);
			}
			else
			{
				cout << "Neispravan izbor";
			}
			break;
		case 2:
			if (!rd->pun())
			{
				cout << "Unesite broj : ";
				int b;
				cin >> b;
				rd->stavi(b);
				


			}
			else
			{
				cout << "Red je pun" << endl;

			}
			break;


		case 3:

			if (!rd->prazan())
			{
				cout << "Broj : " << rd->uzmi() << endl;
			}
			else
			{
				cout << "Red je prazan" << endl;
			}
			break;

		case 4:
			cout << "Red : ";
			rd->pisi();
			cout << endl;
			break;

		case 5: 
			rd->prazni();
			break;

		case 0:
			kraj = true;
			break;

		default:
			cout << "Nedozvoljen izbor" << endl;
			break;
		}




	}
	*/

	//skupovi

	//trouglovi
	/*
	int n;
	cout << "Broj trouglova : ";
	cin >> n;

	Trougao* nizT = new Trougao[n];
	for (int i = 0; i < n;)
	{
		cout << "Trougao " << i + 1 << " : ";
		double aa, bb, cc;
		cin >> aa >> bb >> cc;
		if (Trougao::moze(aa, bb, cc))
		{
			nizT[i++] = Trougao(aa, bb, cc);
		}
		else
		{
			cout << "Neprihvatljiv izbor";
		}

	}


	//uredjivanje niza trouglova
	for (int i = 0; i < n; i++)
	{
		for (int j = i+1; j < n; j++)
		{
			if (nizT[i].P()>nizT[j].P())
			{
				Trougao t = nizT[i];
				nizT[i] = nizT[j];
				nizT[j] = t;


			}

		}


	}

	for (int i = 0; i < n; i++)
	{
		cout << "Trougao " << i + 1; 
		nizT[i].pisi();
		cout << " : P = " << nizT[i].P() << endl;

	}

	*/
	

	//kvadar
	
	/*
	cout << "Datum1 : ";
	Datum dat1 = Datum::citaj();
	cout << "Datum2 : ";
	Datum dat2 = Datum::citaj();

	dat1.pisi();

	cout << " je " << dat1.imeDan() << ", " << dat1.danUgod() << ". dan u godini" << endl;
	cout << "Rodili ste se u : " << dat2.imeDan() << " , i imate" << razlika(dat1, dat2) << " dana";
	*/

	//liste
	/*
	Lista lst;
	cout << "Unesite listu od 5 elemenata : ";
	lst.citaj2(5);
	cout << endl << "Ispis : ";
	lst.pisi();
	lst.izostavi(4);
	cout << endl << "Ispis : ";
	lst.pisi();

	lst.na_kraj(7);
	cout << endl << "Ispis : ";
	lst.pisi();
	*/
	
	//materijalna tacka
	/*
	while (true)
	{
		Niz_mat_tac niz;
		while (true)
		{
			cout << "m, x, y ,z : ";
			double m, x, y, z;
			cin >> m >> x >> y >> z;
			if (m<0)
			{
				break;
			}
			niz.dodaj(Mat_tacka(m, x, y, z));



		}
		if (niz.vel() == 0)
		{
			break;
		}
		cout << "Niz tacaka : " << endl;
		niz.pisi();
		cout << "Najjaca tacka : ";
		niz.maxF(Mat_tacka()).pisi(); cout << endl;


	}
	*/

	/*
	a
	5 7 4 3 9 8 2 6 5 1
	*/

	//stabla
	
	/*
	Stablo stb;
	bool kraj=false;

	while (!kraj)
	{
		cout << endl <<
			"a)Dodavanje brojeva           Pisanje stabla:\n"
			"b)Izostavljanje brojeva       1.Koren-levo-desno\n"
			"c)Citanje stabla              2.Levo-koren-desno\n"
			"d)Najmanji element            3.Levo-desno-koren\n"
			"e)Najveci element             4.Crtanje\n"
			"f)Pretrazivanje               i)Velicina stabla\n"
			"g)Balansiranje                j)Zbir elemenata\n"
			"h)Praznnjenje                 k)Broj pojavljivanja\n"
			"                              z)Kraj rada\n"
			"Vas izbor : \n";
		char izbor; 
		cin >> izbor;

		switch (izbor)
		{
			int broj;
		case 'a':
			radi(stb, &Stablo::dodaj);
			break;
		case 'b':
			radi(stb, &Stablo::izost);
			break;
		case 'c':
			cout << "Duzina : "; int n; cin >> n;
			cout << "Brojevi : ";
			stb.citaj(n);
			break;
		case 'd': case 'e':
			if (!stb.prazno())
			{
				switch (izbor)
				{
				case 'd':
					cout << "Min : " << stb.min() << endl;
					break;
				case 'e':
					cout << "Max : " << stb.max() << endl;
					break;

				}


			}
			else {
				cout << "Prazno stablo" << endl;
			}
			break;

		case 'f':
			cout << "Broj : ";
			cin >> broj;
			cout << "Broj se nalazi : " << (stb.nadji(broj) ? "" : "NE") << " nalazi u stablu" << endl;
			break;
		case 'g':
			stb.balans();
			break;
		case 'h':
			stb.prazni();
			break;
		case 'i':
			cout << "Vel = " << stb.vel() << endl;
			break;
		case 'j':
			cout << "Zbir = " << stb.zbir() << endl;
			break;
		case 'k':
			cout << "Broj : "; cin >> broj;
			cout << "Broj se pojavljuje : " << stb.pojav(broj) << " puta\n";
			break;
		case '1':
			cout << "Stablo : "; stb.pisiKLD(); cout << endl;
			break;
		case '2':
			cout << "Stablo : "; stb.pisiLKD(); cout << endl;
			break;

		case '3':
			cout << "Stablo : "; stb.pisiLDK(); cout << endl;
			break;

		case '4':
			stb.crtaj(); cout << endl;
			break;
		case 'z':
			kraj = true;
			break;







		default:
			cout << "Nedozvoljen izbor" << endl;
			break;
		}










	}
	*/
	
	/*
	while (true)
	{
		Lista lst;
		while (true)
		{
			int d, m, g;
			cout << "Datum (d, m, g) : ";
			cin >> d >> m >> g;
			if (!Datum::moze(d, m, g))
			{
				break;
			}
			lst.dodaj(Datum(d, m, g));

		}
		if (lst.duzina()==0)
		{
			break;
		}
		cout << "Lista : ";
		lst.pisi();
		cout << endl;
		cout << "Najkasnije : "; lst.max()->pisi(); cout << endl;




	}
	*/
	
	/*
	Imenik im;
	im.dodaj(Osoba("Marko", JMBG("1205986110022")));
	im.dodaj(Osoba("Milan", JMBG("3112969235052")));
	im.dodaj(Osoba("Zoran", JMBG("1511990872035")));
	im.dodaj(Osoba("Petar", JMBG("0207000345678")));
	im.dodaj(Osoba("Stevo", JMBG("2503973123024")));
	im.pisi();
	*/
	
Kvadar::postaviVmax(1000);
cout << Kvadar::dohvVmax() << endl;

	

}