#include <iostream>
#include <string>

#include "Playlist.h"
#include "Kvadar.h"


using namespace std;

const int MAX = 100;


struct Elem {

	int broj;
	Elem* sled;

	

};

Elem* citaj() {
	Elem* prvi, * tek, * posl;
	prvi = posl = nullptr;

	while (true)
	{
		int broj;
		cin >> broj;
		if (broj==0)
		{
			break;
		}
		tek = new Elem();
		tek->broj = broj;
		tek->sled = nullptr;
		
		posl = (prvi ? posl->sled : prvi) = tek;



	}


	return prvi;
}


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


class Tacka {

	double x, y;

public:
	Tacka(double xx=1, double yy=1) : x(xx), y(yy) {};

	double getX()const { return x; }
	double getY()const { return y; }

	void setX(double xx) { x = xx; }
	void setY(double yy) { y = yy; }

	double rastojanje( const Tacka& t2) {
		return sqrt(pow(t2.x - x, 2) + pow(t2.y - y, 2));
	}

	void citaj() {
		double xx, yy;
		cout << "Unesite koordinate tacke : " << endl;
		cin >> xx >> yy;
		x = xx;
		y = yy;

	}

	void pisi(ostream& it) const {
		it << "T(" << x << "," << y << ")";

	}

	friend ostream& operator<<(ostream& it, const Tacka& t) {
		t.pisi(it);
		return it;
	}


};




int main() {

	/*
	Izvodjac i("Eminem", REP);
	Izvodjac i2("Queen", ROK);
	Izvodjac i3("Michael Jackson", POP);
	Izvodjac i4("50 cent", REP);

	Pesma p1("Dont stoop me tonight", 5, 48, 2);
	p1.dodaj(&i2);
	p1.dodaj(&i3);

	Pesma p2("Till I collapse", 4, 15, 2);
	p2.dodaj(&i);
	p2.dodaj(&i4);

	Playlist play1;
	play1.dodaj(&p1);
	play1.dodaj(&p2);

	play1.pisi();
	play1.uredi();
	play1.pisi();
	*/

	Kvadar::postaviVmax(100);
	cout << Kvadar::dohvVmax() << endl;



	return 0;
}