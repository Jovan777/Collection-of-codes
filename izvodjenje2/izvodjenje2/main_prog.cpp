#include <iostream>
#include <string>
#include <utility>

#define _CRT_SECURE_NO_WARNINGS 
using namespace std;


class Osoba {

	string ime;
	double tez;

public:
	Osoba(string i, double t) : ime(i), tez(t) {};
	Osoba(const Osoba&) = delete;
	Osoba& operator=(const Osoba&) = delete;

	string getI() const {
		return ime;
	}

	double getTez() const {
		return tez;
	}

	friend ostream& operator<<(ostream& it, const Osoba& o) {
		it << o.ime << "(" << o.tez << ")";
		return it;

	}





};

class Vozilo {

	Osoba* vozac;
	double sop_tez;


public:
	Vozilo(Osoba* o, double sop) : vozac(o), sop_tez(sop) {};
	Vozilo(const Vozilo&) = delete;
	Vozilo& operator=(const Vozilo&) = delete;

	virtual char oznaka() const  = 0;
	virtual double  uk_tezina() {

		return sop_tez + vozac->getTez();

	}

protected:
	virtual void pisi(ostream& it) const{
		it << "[" << *vozac << ", " << sop_tez << "]";
	}

	friend ostream& operator<<(ostream& it, const Vozilo& v) {
		v.pisi(it);
		return it;
	}



};

class Teretno_vozilo : public Vozilo {
	double nosivost;
	double teret;

public:
	Teretno_vozilo(Osoba* voz, double sop, double nos) : Vozilo(voz, sop), nosivost(nos), teret(0) {};


	char oznaka() const override {
		return 'T';
	}

	double uk_tezina() override{
		return Vozilo::uk_tezina() + teret;
	}

	bool operator+=(double tovar) {
		if ((teret+tovar)>nosivost)
		{
			return false;
		}
		teret += tovar;
		return true;

	}
	bool operator-=(double tovar) {
		if ((teret - tovar) <0)
		{
			return false;
		}
		teret -= tovar;
		return true;

	}

private:
	void pisi(ostream& it) const override {
		it << "Teretno"; Vozilo::pisi(it);
		it << "(" << teret << "/" << nosivost << ")";
	}




};


class Putnicko_vozilo : public Vozilo {

	Osoba** niz;
	int kap, duz;

public:
	Putnicko_vozilo(int k , Osoba* vozac, double sop_tez) :Vozilo(vozac, sop_tez), kap(k), duz(0), niz(new Osoba* [kap]) {
		for (int i = 0; i < kap; i++)
		{
			niz[i] = nullptr;
		}
	};

	char oznaka() const override {
		return 'P';
	}

	double uk_tezina() override {
		double t = Vozilo::uk_tezina();
		for (int i = 0; i < duz; i++)
		{
			t += niz[i]->getTez();
		}

		return t;
	}

	bool operator+=(Osoba* o) {
		int i = 0;
		while (i<kap && niz[i])
		{
			i++;
		}
		if (i==kap)
		{
			return false;
		}
		niz[i] = o;
		return true;

	}

	bool operator-=(Osoba* o) {
		int i = 0;
		while (i<kap && niz[i]!=o)
		{
			i++;
		}
		if (i==kap)
		{
			return false;
		}
		niz[i] = nullptr;
		return true;

	}

private:
	void pisi(ostream& it) const override {
		it << "Putnicko"; Vozilo::pisi(it);
		it <<"{";
		for (int i = 0; i < kap; i++)
		{
			if (niz[i])
			{
				it << *niz[i]<<"|";
			}

		}
		it<< "}";
	}


};









int main() {
	Osoba o1("v1", 50);
	Osoba o2("p1", 70);
	Osoba o3("v2", 60);
	Osoba o4("p2", 90);
	Osoba o5("p3", 70);

	Putnicko_vozilo p1(5, &o1, 500);
	p1 += &o2;

	Teretno_vozilo t1(&o2, 500, 2000);

	Putnicko_vozilo p2(5, &o3, 200);
	p2 += &o4;
	p2 += &o5;
	
	cout << p1 << endl;
	cout << t1 << endl;
	cout << p2 << endl;



	return 0;
}