#include <iostream>

#include <string>


using namespace std;



class Vreme {

	long datum, kad;


public:
	Vreme(long d=20131025, long k=190000) : datum(d), kad(k) {};

	int uporedi(const Vreme& v) {
		if (datum!=v.datum)
		{
			return datum - v.datum;
		}
		return kad - v.kad;

	}

	void pisi() const {
		string date = to_string(datum);
		string time = to_string(kad);

		cout << date[6] << date[7]<<"." << date[4] <<
			date[5] << "." << date[0] << date[1] << date[2] << date[3] << 
			".("<<time[0]<<time[1]<<":"<<time[2]<<time[3]<<":"<<time[4]<<time[5]<<")";

	}





};


 
class Dogadjaj {

	Vreme vrm;
	string opis;

public:
	Dogadjaj(Vreme v, string o) : vrm(v), opis(o) {};


	void pisi() const {
		vrm.pisi();
		cout << "|" << opis << endl;
	}
	Vreme getV()  {
		return vrm;
	}
	string getO()  {
		return opis;
	}




};



class Dnevnik {

	string ime;
	struct Elem {
		Dogadjaj dog;
		Elem* sled;
		Elem(Dogadjaj d, Elem* s = nullptr) : dog(d), sled(s) {};

	};

	Elem* prvi, * posl;
public:

	Dnevnik(string i) :ime(i) ,  prvi(nullptr), posl(nullptr) {};

	void dodaj(Dogadjaj d) {

		Elem* temp = prvi;
		Elem* pret = nullptr;

		while (temp && (temp->dog.getV().uporedi(d.getV()))<=0)
		{
			pret = temp;
			temp = temp->sled;
		}
		Elem* novi = new Elem(d);

		(pret ? pret->sled : prvi) = novi;
		novi->sled = temp;




	}

	void pisi() const {
		cout << ime << endl;
		for (Elem* temp = prvi; temp ; temp=temp->sled)
		{
			temp->dog.pisi();
		}
	}


};

class Tacka {


	double x, y;

public:
	Tacka(double xx, double yy) : x(xx), y(yy) {};

	double rast(const Tacka& t = Tacka(0, 0)) const {
		return sqrt((x - t.x) * (x - t.x)
			+ (y - t.y) * (y - t.y));

	}

	void pisi() const {
		cout << "(" << x<<"," << y << ")";
	}




};

class Trougao {

	string ime;
	Tacka* niz[3];

public:
	Trougao( Tacka* t[3], string i) : ime(i) {
		for (int i = 0; i < 3; i++)
		{
			niz[i] = t[i];
		}
	}

	Trougao(const Trougao& tr) {
		for (int i = 0; i < 3; i++)
		{
			niz[i] = tr.niz[i];
		}
		ime = tr.ime + "_kopija";

	}

	Tacka& dohvTeme(int id) const{
		if (id<0 || id>2)
		{
			exit(1);
		}
		return *niz[id];

	}

	double srRast() const {
		return (niz[0]->rast() +
			niz[1]->rast() + niz[2]->rast()) / 3;
	}



	void pisi() const {
		cout << ime << "[";
		niz[0]->pisi(); cout << ", ";
		niz[1]->pisi(); cout << ", ";
		niz[2]->pisi(); cout << ": ";
		cout << srRast() << "]";

	}




};

class Mreza {

	string ime;
	struct Elem {
		Trougao t;
		Elem* sled;

		Elem(const Trougao& tt, Elem* s = nullptr) : t(tt), sled(s) {};




	};

	Elem* prvi, * posl;


public:

	Mreza(string i) : ime(i), prvi(nullptr), posl(nullptr) {};
	Mreza(const Mreza& m) {
		ime = m.ime + "_deo";
		for (Elem* temp = prvi; temp ; temp=temp->sled)
		{
			posl = (prvi ? posl->sled : prvi) = new Elem(temp->t);
		}

	} Mreza(Mreza&& m) {
		prvi = m.prvi; posl = m.posl;
		ime = m.ime; m.prvi = m.posl = nullptr;
	}

	~Mreza()
	{
		while (prvi)
		{
			Elem* old = prvi;
			prvi = prvi->sled;
			delete old;
		}
		prvi=posl = nullptr;
	}

	void dodaj(const Trougao& t) {
		posl = (prvi ? posl->sled : prvi) = new Elem(t);
	}



	Mreza napraviNovu(double min, double max) const {

		if (min > max) exit(2);
		Mreza m = Mreza(ime + "_deo");
		Elem* tek = prvi;
		while (tek) {
			if (min <= tek->t.srRast() &&
				max >= tek->t.srRast())
				m.dodaj(tek->t);
			tek = tek->sled;
		}
		return m;
	}




	void pisi() const {

		cout << ime << endl;
		for (Elem* temp = prvi; temp ; temp=temp->sled)
		{
			temp->t.pisi();
			cout << endl;
		}


	}



	

};


class Stavka {


	string pitanje;
	int ocena=0;


public:
	Stavka(string p) : pitanje(p){};
	Stavka(const Stavka& s) {
		pitanje = s.pitanje;
	}


	string getP() const { return pitanje; }
	int getO() const { return ocena; }

	void setO(int o) { if (o > 0) ocena = o; }

	void pisi() const {
		cout << pitanje << "(" << ocena << ")";
	}


};

class Upitnik {

	int min, max;
	struct Elem {
		Stavka stv;
		Elem* sled;
		Elem(Stavka s, Elem* t = nullptr) : stv(s), sled(t) {};

	};
	Elem* prvi, * posl;

public:

	Upitnik(int min=1, int max=7) : min(min), max(max), prvi(nullptr), posl(nullptr) {};

	void dodaj(Stavka s) {
		posl = (prvi ? posl->sled : prvi) = new Elem(s);
	}

	void postaviOcenu(int r, int n) {
		if (n<min || n>max)
		{
			return;
		}
		Elem* temp = prvi;
		int br = 0;
		while (br<r)
		{
			temp = temp->sled;
			br++;
		}
		temp->stv.setO(n);


	}

	void pisi() const {
		Elem* temp = prvi;
		while (temp)
		{
			temp->stv.pisi();
			cout << endl;
			temp = temp->sled;
		}

	}


};

class Anketa {

	Upitnik** niz;
	int datum;
	int kap;
	int duz;


public:
	Anketa(int dat, int kap) : datum(dat), kap(kap), duz(0) {
		niz = new Upitnik * [kap];
	}

	Anketa(const Anketa&) = delete;

	~Anketa()
	{
		delete[] niz;
	}

	void dodaj(Upitnik* up) {
		if (duz<kap)
		{
			niz[duz++] = up;
		}
	}


	Upitnik* dohv(int id) {
		if (id>duz || id<0)
		{
			return nullptr;
		}
		return niz[id];
	}

	void pisi() const {
		cout << datum << endl;
		for (int i = 0; i < duz; i++)
		{
			niz[i]->pisi();
			cout << endl;
		}


	}



};


class Datum {

	int dan, mesec, godina;

public:
	Datum(int d, int m, int g) : dan(d), mesec(m), godina(g) {};

	int getD() const {
		return dan;
	}
	int getM() const {
		return mesec;
	}
	int getG() const {
		return godina;
	}

	bool veci(const Datum& d2) {
		if (godina>d2.godina || (godina==d2.godina && mesec>d2.mesec) || 
			(godina == d2.godina && mesec == d2.mesec && dan>d2.dan))
		{
			return true;
		}
		else
		{
			return false;
		}

	}

	void pisi() const {
		cout << dan << "." << mesec << "." << godina;
	}



};

static int lekId = 0;
class Lek {


	int id = lekId++;
	string komIme, naziv;
	double cena;
	Datum date;


public:
	Lek(string iime, string ggNaziv, double ccena,
		Datum rrok) :
		date(rrok) {
		komIme = iime; naziv = ggNaziv;
		cena = ccena;
	}

	Lek(const Lek& l) : date(l.date) {
		komIme = l.komIme;
		naziv = l.naziv;
		cena = l.cena;
		

	}




	int getId() const {
		return id;
	}
	string getIme() const {
		return komIme;
	}
	string getNaziv() const {
		return naziv;
	}
	double getC() const {
		return cena;
	}

	Datum getDate() const {
		return date;
	}

	void setCena(double c) {
		cena = c;
	}

	void pisi() const {
		cout << id << "-" << komIme << "(" << naziv << ")";
		date.pisi();
		cout << "-" << cena;
	}



};



class Apoteka {
	string ime;
	struct Elem {
		Lek* lek;
		Elem* sled;

		Elem(Lek* l, Elem* s = nullptr) : lek(l), sled(s){}

	};
	Elem* prvi, * posl;

	void brisi() {
		while (prvi)
		{
			Elem* stari = prvi;
			prvi = prvi->sled;
			delete stari;

		}

	}


public:
	Apoteka(string i) : ime(i),  prvi(nullptr), posl(nullptr) {};
	Apoteka(const Apoteka&) = delete;
	
	~Apoteka()
	{
		brisi();
	}

	Lek* dohvLek(int id) {
		Elem* temp = prvi;
		while (temp)
		{
			if (temp->lek->getId() == id) {
				return temp->lek;
			}
		}

	}

	void dodaj(Lek* l) {
		posl = (prvi ? posl->sled : prvi) = new Elem(l);

	}


	void pisi() const {
		Elem* temp = prvi;
		cout << ime << endl;
		while (temp)
		{
			temp->lek->pisi();
			temp = temp->sled;
			cout << endl;
		}

	}


};

class Artikal {

	string naziv;
	double cena;
	int popust;


public:
	Artikal(string n, double c, double p=0) : naziv(n), cena(c), popust(p) {};

	string getNaziv() const {
		return naziv;
	}

	double getCena() const {
		return (100. - popust) / 100 * cena;
	}

	double getPopust() const {
		return popust;
	}

	void pisi() const {
		cout << naziv << "(" << getCena() << ")";
	}




};


class Stavka1 {

	Artikal art;
	int broj;
	int kolicina;

public:

	Stavka1(Artikal a, int kol) : art(a), kolicina(kol) {};

	double iznos() const {
		return art.getCena() * kolicina;
	}

	Artikal getArt() const {
		return art;
	}


	void pisi() const {
		cout << "S" << broj << "("; art.pisi(); cout << ":" << kolicina << "|" << iznos();

	}
	void dodeliRdBr(int br) { broj = br; }

};


class Racun {

	struct Elem {
		Stavka1 stavka;
		Elem* sled;
		Elem(Stavka1 s, Elem* sl = nullptr) : stavka(s), sled(sl) {};




	};

	int popust;
	int br = 0;
	Elem* prvi, * posl;

public:
	Racun() : popust(0), prvi(nullptr), posl(nullptr) {};


	void setPopust(int p) {
		popust=p;
	}

	void dodaj(Stavka1 s1) {
		s1.dodeliRdBr(br++);
		posl = (prvi ? posl->sled : prvi) = new Elem(s1);

	}

	double iznos() const {
		double bez = 0;
		double sa = 0;
		for (Elem* temp = prvi; temp ; temp=temp->sled)
		{
			if (temp->stavka.getArt().getPopust()>0)
			{
				sa += temp->stavka.iznos();
			}
			else
			{
				bez += temp->stavka.iznos();
			}


		}

		bez = (100. - popust) / 100 * bez;

		return bez + sa;

	}



	void pisi() const {
		cout << "Racun : " << iznos() << endl;
		Elem* temp = prvi;
		while (temp)
		{
			temp->stavka.pisi();
			if (temp->stavka.getArt().getPopust() == 0) {
				double nova = (100. - popust) / 100 * temp->stavka.iznos();
				cout << "[" << nova << "]";
			}
			cout << endl;
			temp = temp->sled;

		}
	}




};


int main() {

	/*
	Vreme v;
	v.pisi();
	Vreme v2(20121025);
	cout << v.uporedi(v2) << endl;

	Dogadjaj d(v, "Koncert");

	Dogadjaj d2(v2, "Utakmica");

	Dnevnik dnv("Milan");


	dnv.dodaj(d);
	dnv.dodaj(d2);

	dnv.pisi();
	*/


	/*
	Mreza m("Mreza");
	Tacka t1(1, 1), t2(2, 2), t3(3, 3),
		t4(1, 2), t5(3, 4);
	Tacka* niz1[] = { &t1, &t2, &t3 };
	Tacka* niz2[] = { &t1, &t4, &t5 };
	Tacka* niz3[] = { &t3, &t4, &t5 };
	m.dodaj(Trougao(niz1, "t1"));
	m.dodaj(Trougao(niz2, "t2"));
	m.dodaj(Trougao(niz3, "t3"));
	m.pisi();
	Mreza novaM = m.napraviNovu(2, 3);
	novaM.pisi();
	*/

	/*
	Stavka f("Fizika");
	Stavka h("Hemija");
	Stavka s("Srpski");

	f.setO(3);
	s.setO(5);

	Upitnik up(1, 5);
	up.dodaj(f);
	up.dodaj(h);
	up.dodaj(s);

	//up.pisi();

	cout << endl;

	up.postaviOcenu(0, 3);
	up.postaviOcenu(1, 4);
	up.postaviOcenu(2, 5);

	//up.pisi();

	Stavka m("Matematika");
	Stavka b("Biologija");

	Upitnik u2(1, 5);
	u2.dodaj(m);
	u2.dodaj(b);

	u2.postaviOcenu(0, 5);
	u2.postaviOcenu(1, 5);

	Anketa an(20151023, 3);

	an.dodaj(&up);
	an.dodaj(&u2);

	an.pisi();
	*/

	/*
	Datum d1(12, 12, 2012);
	Datum d2(12, 12, 2013);

	d1.pisi();
	cout << endl;
	d2.pisi();
	cout << endl << d2.veci(d1);

	Lek l1("Brufen", "Ibuprofen", 1000, d1);
	Lek l2("Panklav", "Antibiotik", 1200, d2);

	cout << endl;
	l1.pisi();
	cout << endl;
	l2.pisi();

	Lek l3(l1);

	cout << endl;
	l3.pisi();
	cout << endl;

	Apoteka ap("Zdravlje");

	ap.dodaj(&l1);
	ap.dodaj(&l2);
	ap.dodaj(&l3);

	ap.pisi();
	*/

		
Artikal a1("Plazma", 100);
Artikal a2("Mleko", 200, 5);
Artikal a3("Kafa", 500, 10);

Stavka1 s1(a3, 3);
Stavka1 s2(a2, 2);
Stavka1 s3(a1, 1);

Racun r1;
r1.dodaj(s1);
r1.dodaj(s2);
r1.dodaj(s3);

r1.pisi();


	return 0;
}