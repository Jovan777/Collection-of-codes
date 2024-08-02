#include <iostream>
#include "komp1.h"
#include "vreme.h"
#include "niz_komp1.h"
#include "Poli.h"
#include <iomanip>
#include "student1.h"
#include "tekst1.h"
#include "red1.h"
#include "predstava.h"
#include "inventar.h"
#include "redna_veza.h"
#include "recnik.h"
#include "skup_trou.h"

using namespace std;


Kompl poli(const Kompl p[], int n, Kompl z) {

	Kompl s = p[n];
	for (int i = n - 1; i >= 0; (s *= z) += p[i--]);

	return s;

}


Red citaj(string nasl) {
	Red r; int n, a, i;
	cin >> n;
	cout << nasl << " : ";
	for ( i = 0; i < n; i++)
	{
		cin >> a;
		cout << " " << a;
		r += a;
	}

	cout << endl;
	return r;


}

void pisi(string nasl, const Red& red) {
	Red r = red;
	cout << nasl << " :";
	while (r.duzina())
	{
		cout << ' ' << r.uzmi();
	}

	

	cout << endl;

}
/*
void pisi(string nasl, const Red& red) {
	Red r = red;
	cout << nasl << " :";
	while (r.duzina()) cout << ' ' << r.uzmi();
	cout << endl;
}
*/


int main(int barg, char* varg[]) {

	//kompleksni brojevi
	/*
	cout << "Red polinoma : ";
	int n; cin >> n;
	Kompl* p = new Kompl[n + 1];
	cout << "\nKoeficijenti : ";
	for (int i = n; i >= 0; cin >> p[i--]);
	cout << "\nz0, dz, k : ";
	Kompl z, dz;
	int k;
	cin >> z >> dz;
	cin >> k;
	cout << endl;
	for (int i = 0; i < k; i++, z+=dz)
	{
		Kompl r = poli(p, n, z);
		cout << z << "\t" << r << endl;


	}

	*/

	//vreme
	/*
	while (true)
	{
		int k; cin >> k;

		if (!k)
		{
			break;
		}
		Vreme t1, t2;
		cin >> t1 >> t2;

		long s1 = Sek(t1);
		long s2 = Sek(t2);

		cout << k << endl;
		cout << "t1 : " << t1 << "    t2 : " << t2 << endl;
		cout << "s1 : " << s1 << "   :    " << Vreme(s1) << endl;
		cout << "s2 : " << s2 << "   :    " << Vreme(s2) << endl;

		cout << "-t1 : " << -t1 << endl;
		cout << "++t1 : " << ++t1 << endl;
		cout << "t2 : " << t2++ << endl;
		cout << "t1 > t2 : " << (t1 > t2) << endl;
		cout << "t1*k : " << t1 * k << endl;
		cout << "t1+t2 : " << t1 + t2 << endl;
		cout << "s1+t2*k : " << Vreme(s1) + t2 * k << " ( " << s1 + Sek(t2 * k) << " )";



	}
	*/

	//niz komp brojeva
	/*
	while (true)
	{

		int n;
		cout << " n : ";
		cin >> n;
		if (n<=0)
		{
			break;
		}

		Niz_komp a(n);
		cout << " a : ";
		for (int i = 0; i < n; cin >> a[i++]);

		Kompl s = 0;
		for (int i = 0; i < a.duz(); i++)
		{
			s += a[i];
		}
		cout << "s = " << s << endl;


	}
	*/


	//polinomi
	/*
	Poli p1, p2, p3;
	cout << "Unesite p1" << endl;
	cin >> p1; cout << "p1 : " << p1 << endl;
	cin >> p2; cout << "p2 : " << p2 << endl;

	p3 = p1 + p2; cout << "p1+p2 : " << p3 << endl;
	p3 = p1 - p2; cout << "p1-p2 : " << p3 << endl;
	p3 = p2 - p1; cout << "p2+p1 : " << p3 << endl;
	p3 = p1 * p2; cout << "p1*p2 : " << p3 << endl;
	p3 = p1 - p1; cout << "p1-p1 : " << p3 << endl;


	double* a = new double[p1.red() + 1];
	int n;
	p1.niz(a, n);
	cout << "a : ";
	for (int i = n; i >= 0; i--)
	{
		cout << a[i] << " ";
	}

	p3 = Poli(a, n);
	cout << "p(a, n) : ";
	for (int i = 0; i < p3.red(); i++)
	{
		cout << p3[i] << " ";
	}
	cout << endl;
	delete[] a;

	Poli* pp4 = new Poli(p1);
	cout << "pp4 : " << *pp4 << endl;
	delete pp4;

	double xmin = -1; double xmax = 1; double dx = 0.25;
	cout << "\n     x     p1(x)\n=================\n" << fixed;
	for (double x = xmin; x <= xmax; x+=dx)
	{
		cout << setprecision(2) << setw(6) << x << setprecision(6) << setw(12) << p1(x) << endl;

	}
	*/


	//Studenti
	
	/*
	int n; cin >> n;

	Student** s = new Student* [n];
	for (int i = 0; i < n; i++)
	{
		string ime; long ind; cin >> ime >> ind;
		Student* t = new Student(ime, ind);
		int br_oc; cin >> br_oc;
		for (int j = 0; j < br_oc; j++)
		{
			int oc;
			cin >> oc;
			*t += oc;
		}

		int k = i;
		while (k>0 && s[k-1]->sr_ocena() < t->sr_ocena())
		{
			s[k] = s[k - 1];
			k--;
		}
		s[k] = t;


	}

	for (int i = 0; i < n; i++)
	{
		cout << s[i]->dohvIme() << '\t' << s[i]->sr_ocena() << endl;

	}

	for (int i = 0; i < n; i++)
	{
		delete s[i];
	}

	delete[] s;
	*/
	

	//Tekstovi
	/*
	Tekst t;
	while (--barg)
	{
		t += *++varg;
		if (barg>1)
		{
			t += " ";
		}
	}
	cout << len(t) << " - " << t << endl;
	int k = 1;
	for (int i = 0; i < len(t); i++)
	{
		if (t[i]==' ')
		{
			k++;
		}
	}
	cout << "Broj reci je : " << k << endl;
	int i;
	while ((i=t % " ")>=0)
	{
		Tekst r = t(0, i - 1);
		cout << len(r) << " - " << r << endl;
		t = t(i + 1, len(t) - 1);

	}
	cout << len(t) << " - " << t << endl;
	*/
	

	//Redovi
	
	/*
	Red r1 = citaj("niz1 ");
	pisi("r1  ", r1);

	Red r2 = citaj("niz2 ");
	pisi("r2  ", r2);
	pisi("r1 + r2  ", r1 + r2);
	pisi("r1+=r2   ", r1 += r2);
	pisi("vodeci  ", r1.vodeci());
	pisi("uzmi    ", r1.uzmi());
	pisi("r1   ", r1);
	int a; cin >> a;
	pisi("a  ", a);
	pisi("r1-a  ", r1 - a);
	pisi("r1-=a  ", r1 -= a);
	pisi("~r1  ", ~r1);
	*/
	
	//Karte
	
	/*
	Predstava p("Naslov", 20090308, 4, 6);

	p += Karta(0, 3, 800);
	p += Karta(3, 5, 200);
	p += Karta(2, 1, 500);
	cout << p << endl << p.vrednost() << endl;
	*/

	//Zapis i inventar

	/*
	Inventar inv(8);
	inv += new Zapis("kruska", "kg", 95);
	inv += new Zapis("mleko", "l", 75);
	inv += new Zapis("kabl", "m", 120);

	*inv["kruska"] += 8;
	*inv["mleko"] += 35;
	*inv["kabl"] += 155;
	cout << inv;
	*/

	//Otpornici

	/*
	int n = 4;
	Redna_veza rv(n);
	for (int i = 0; i < n; i++)
	{
		cout << "r, d : ";
		Otpornik r;
		cin >> r;
		rv += r;
	}

	while (rv.dohvDuz())
	{
		cout << rv << " = " << rv.otp() << endl;
		for (Otpornik& r : rv) {
			--r;
		}
		rv.izbaci();

	}
	*/
	
	//recnici
	/*
	Recnik rec;
	rec += Odred("gotov", "ready");
	rec += Odred("jezik", "speech");
	rec += Odred("dobar", "kind");
	rec += Odred("jezik", "tongue");
	rec += Odred("dobar", "good");
	rec += Odred("gotov", "completed");
	rec += Odred("jezik", "language");
	rec += Odred("gotov", "fihished");
	
	cout << rec << endl << endl;
	cout << (rec << "gotov") << endl;
	*/


	//skup trouglova
	Skup_trou s;
	s += Trougao(Tacka(1, 1), Tacka(2, 5), Tacka(4, 3));
	s += Trougao(Tacka(-1, 1), Tacka(-2, 5), Tacka(-4, 3));
	s += Trougao(Tacka(1, 1), Tacka(2, 5), Tacka(4, 3));
	s += Trougao(Tacka(-1, 1), Tacka(-2, 5), Tacka(-4, 3));
	cout << s << endl << s.ukP() << endl;


	
	return 0;
}