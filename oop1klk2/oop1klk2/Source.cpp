#include <iostream>

using namespace std;


class Polje {

	char kolona;
	int red;

public:
	Polje(char k, int r) {

		if (k < 'A' || k>'H' || r < 1 || r>8)
		{
			exit(1);
		}
		kolona = k;
		red = r;

	}

	friend bool operator==(const Polje& p1, const Polje& p2) {
		if (p1.kolona==p2.kolona && p1.red==p1.red)
		{
			return true;
		}
		return false;

	}

	friend bool operator+(const Polje& p1, const Polje& p2) {
		if (p1.kolona==p2.kolona || p1.red==p2.red)
		{
			return true;
		}
		return false;

	}

	friend bool operator/(const Polje& p1, const Polje& p2) {
		return abs(p1.kolona - p2.kolona) == abs(p1.red == p2.red);

	}

};

class Figura {

public:

	enum Boja{BELA, CRNA};

	Figura(Boja bb, Polje pp) :boja(bb), polje(pp) {}

	virtual bool mozePolje(Polje p) = 0;
	
	virtual bool mozeFigura(Figura* f) {
		if (mozePolje(f->polje) && boja!=f->boja)
		{
			return true;
		}
		return false;

	};

	void operator()(Polje p) {
		if (mozePolje(p))
		{
			polje = p;
		}

	}

	Boja getB() const {
		return boja;
	}

	Polje getP() const {
		return polje;
	}

	virtual char oznaka() const = 0;

	virtual int vrednost() const = 0;

	friend bool operator>(const Figura& f1, const Figura& f2) {
		return f1.vrednost() > f2.vrednost();
	}

	friend ostream& operator<<(ostream& it, const Figura& f) {
		return it << (char)(f.oznaka() + (f.boja == Figura::CRNA ? 32 : 0));
	}

	virtual Figura* kopija() const = 0;

protected:
	Boja boja;
	Polje polje;



};

class Top : public Figura {

public:
	Top(Boja b, Polje p) : Figura(b, p) {};

	bool mozePolje(Polje p) override {
		if (polje+p)
		{
			return true;
		}
		return false;
	}

	char oznaka() const override {
		return 'T';
	}

	int vrednost() const override {
		return 5;
	}

	Top* kopija() const override {
		return new Top(*this);
	}


};


class Odgovor {

	string tekst;
	bool tacan;
	double proc;

public:
	Odgovor(string t = "") : tekst(t) {};

	bool getT() const {
		return tacan;
	}

	double getProc() const {
		return proc;
	}

	void setT(bool t) {
		tacan = t;
	}

	void setProc(double pr) {
		proc = pr;
	}


	string getTekst() const {
		return tekst;
	}

	friend ostream& operator<<(ostream& it, const Odgovor& o) {
		return it << o.tekst << ": " << o.proc << "%";
	}




};

class Pitanje {

	string tekst;
	int poeni;
	int kap, duz;
	Odgovor* odgovori;


public:
	Pitanje(string t, int p, int k = 5) : tekst(t), poeni(p), kap(k), duz(0), odgovori(new Odgovor[k]){}

	Pitanje& operator+=(const Odgovor& o) {

	}










};





int main() {


	Polje p1('A', 3);
	Polje p2('B', 3);
	Polje p3('A', 3);

	Top tb(Figura::BELA, p1);

	cout << tb;



	return 0;


}