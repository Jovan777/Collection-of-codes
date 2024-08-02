#ifndef fudbaler_h
#define fudbaler_h

#include <iostream>


using namespace std;





class Fudbaler
{

public:
	enum Pozicija{GK, DEF, MID, FWD};

	Fudbaler(string i, string rep, Pozicija poz) : ime(i), reprezentacija(rep), pozicija(poz) {};
	Fudbaler(const Fudbaler&) = delete;
	Fudbaler& operator=(const Fudbaler&) = delete;

	string dohvIme() const {
		return ime;
	}

	string dohvRepr() const {
		return reprezentacija;
	}

	Pozicija dohvPoz() const {
		return pozicija;
	}

	void promeniPoz(Pozicija poz) {
		pozicija = poz;
	}

	friend ostream& operator<<(ostream& it, const Fudbaler& f) {
		it << f.ime << "(";
		string pozicije[] = { "golman", "odbrambeni", "vezni", "napadac" };
		it << pozicije[f.pozicija] << ") :"<<f.reprezentacija;
		return it;
	}





private:

	string ime;
	string reprezentacija;

	Pozicija pozicija;


};

#endif // !fudbaler_h
