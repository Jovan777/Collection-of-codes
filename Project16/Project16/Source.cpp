#include <iostream>
using namespace std;




template<typename T>
class Sekvenca {

	struct Elem {
		T pod;
		Elem* sled;

		Elem(T p, int b = 0, Elem* s = nullptr) : pod(p),  sled(s) {};

	};
	Elem* prvi, * posl;
	int duz;
	bool uzeoPrvi;

public:
	Sekvenca() : prvi(nullptr), posl(nullptr), duz(0), uzeoPrvi(false) {};

	void dodaj(T pod, int broj = 0) {
		if (uzeoPrvi)
		{
			throw "Uzet prvi";
		}
		posl = (prvi ? posl->sled : prvi) = new Elem(pod, broj);
		duz++;
	}


	T getPrvi() const {
		uzeoPrvi = true;
		return prvi->pod;

	}

	T& operator[](int ind){
		if (ind>duz)
		{
			throw "Los indeks";
		}
		int i = 0;
		Elem* temp = prvi;
		while (temp && i<duz)
		{
			temp = temp->sled;
			i++;
		}


		return temp->pod;
	}



	int getDuz() const {
		return duz;
	}
	



	void pisi() const {
		for (Elem* temp = prvi; temp; temp = temp->sled)
		{
			cout << temp->pod  << endl;
		}

	}


};


class Razlomak {

	int brojilac;
	int imenilac;


public:
	Razlomak(int b, int i=1) : brojilac(b), imenilac(i) {};


	friend bool operator>(const Razlomak& r1, const Razlomak& r2) {
		double b1 = r1.brojilac / r1.imenilac;
		double b2 = r2.brojilac / r2.imenilac;

		return b1 > b2;

	}

	friend Razlomak operator+(const Razlomak& r1, const Razlomak& r2) {

		double broj = r1.brojilac * r2.imenilac + r2.brojilac * r1.imenilac;
		double im = r1.imenilac * r2.imenilac;

		return Razlomak(broj, im);

	}




	friend ostream& operator<<(ostream& it, const Razlomak& r) {
		return it << r.brojilac << "/" << r.imenilac;
	}

};

class Znak {

	Razlomak trajanje;


public:
	Znak(Razlomak r) : trajanje(r) {};

	Razlomak getTrajanje() const {
		return trajanje;
	}

	friend Razlomak operator+(const Znak& z1, const Znak& z2) {
		return Razlomak(z1.trajanje + z2.trajanje);
	}

	operator Razlomak() const {
		return trajanje;
	}

	virtual string opis() const = 0;

	friend ostream& operator<<(ostream& it, const Znak& z) {
		return it << z.opis() << "(" << z.trajanje << ")";
	}


};


class Nota : public Znak {

	int oktava;
public:
	enum Visina{DO, RE, MI, FA, SOL, LA, SI};
	Visina v;
	
	Nota(int o, Razlomak t, Visina vv) : oktava(o), Znak(t), v(vv) {};

	void operator<<=(int pomeraj) {
		oktava -= pomeraj;
		if (oktava<1)
		{
			oktava = 1;
		}
		if (oktava > 5)
		{
			oktava = 5;
		}


	}

	void operator>>=(int pomeraj) {
		oktava += pomeraj;
		if (oktava < 1)
		{
			oktava = 1;
		}
		if (oktava > 5)
		{
			oktava = 5;
		}


	}

	string opis() const override {
		
		switch (v)
		{
		case Nota::DO:
			return "DO";
			break;
		case Nota::RE:
			return "RE";

			break;
		case Nota::MI:
			return "MI";

			break;
		case Nota::FA:
			return "FA";

			break;
		case Nota::SOL:
			return "SOL";

			break;
		case Nota::LA:
			return "LA";

			break;
		case Nota::SI:
			return "SI";

			break;
		default:
			break;
		}

	}





};


class Pauza : public Znak {

public:
	Pauza(Razlomak t) : Znak(t) {};
	

	string opis() const override{
		return "_";
	}


};


class Takt {


	Razlomak trajanje;
	Razlomak trenutno;
	bool zavrsen = false;



public:
	Sekvenca<Znak*> znakovi;

	Takt(Razlomak t) : trajanje(t),  znakovi(), trenutno(0, 1) {};

	Razlomak getTr() const {
		return trajanje;
	}

	void dodaj(Znak* z) {
		if (zavrsen==true)
		{
			return;
		}

		if (trenutno+z->getTrajanje()>trajanje)
		{
			return;
		}

		znakovi.dodaj(z);
		trenutno =trajanje+ z->getTrajanje();

	}

	void zavsrsi() {
		zavrsen = true;
	}

	bool nepotpun() const {
		return trajanje > trenutno;
	}

	bool proveriZavrsen() const {
		return zavrsen == true;
	}

	friend ostream& operator<<(ostream& it,  Takt& t) {
		for (int i = 0; i < t.znakovi.getDuz(); i++)
		{
			it << *t.znakovi[i] << " ";
		}
		return it << "|";


	}








};













int main() {


	Sekvenca<int> sek;

	sek.dodaj(5);
	sek.dodaj(7);
	sek.dodaj(3);


	sek.pisi();

	cout << endl << endl;


	Razlomak r1(1, 3);
	Razlomak r2(1, 5);

	cout << r1 << endl << r2 << endl << (r1 > r2) << endl << r1 + r2 << endl;

	cout << endl << endl << endl;



	Nota n1(3, r1, Nota::MI);
	cout << n1 << endl;

	Pauza p1(r2);

	cout << p1 << endl;

	Nota n2(1, r1, Nota::RE);

	Pauza p2(r1);

	Razlomak r3(10, 2);


	Takt t1(r3);

	t1.dodaj(&n1);
	t1.dodaj(&p1);
	t1.dodaj(&n2);
	t1.dodaj(&p2);

	cout << endl << endl;

	//cout << t1 << endl;

	cout<<*t1.znakovi[0]<<endl;
	cout << t1.znakovi.getDuz() << endl;


	return 0;
}