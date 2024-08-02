#include <iostream>
using namespace std;


template<typename T>
class Lista {

	

public:

	struct Elem {

		T pod;
		Elem* sled;

		Elem(T p, Elem* s = nullptr) : pod(p), sled(s) {};

	};

	Elem* prvi, * posl;
	int broj;

	Lista() : prvi(nullptr), posl(nullptr), broj(0) {};

	void operator+=(T pod) {
		posl = (prvi ? posl->sled : prvi) = new Elem(pod);
		broj++;
	}

	int getBroj() const {
		return broj;
	}

	T& operator[](int ind) {
		
		Elem* temp = prvi;
		int i = 0;
		while (temp && i<ind)
		{
			temp = temp->sled;
			i++;
		}

		return temp->pod;
	}


	void pisi() {
		Elem* temp = prvi;
		while (temp)
		{
			cout << temp->pod;
			if (temp->sled)
			{
				cout << " ";
			}
			temp = temp->sled;
		}

	}

};


class Vreme {

	int sat, minut;

public:
	Vreme(int s, int min) : sat(s), minut(min) {};


	friend bool operator>(const Vreme& v1, const Vreme& v2) {
		if (v1.sat>v2.sat)
		{
			return true;
		}
		else if (v1.sat==v2.sat && v1.minut>v2.minut)
		{
			return true;
		}
		return false;

	}

	friend Vreme operator+(const Vreme& v1, const Vreme& v2) {
		int sat1 = v1.sat + v2.sat;
		int min1 = v1.minut + v2.minut;

		if (min1>=60)
		{
			sat1++;
			min1 %= 60;
		}

		return Vreme(sat1, min1);
	}



	friend ostream& operator<<(ostream& it, const Vreme& v) {
		return it << v.sat << ":" << v.minut;
	}



};

class Film {


	string ime;
	Vreme traj;
	Lista<int> ocene;

public:

	Film(string i, Vreme t) : ime(i), traj(t), ocene() {};

	void oceni(int oc) {
		ocene += oc;
	}

	Vreme getTraj() const {
		return traj;
	}

	double prosekOcena() {
		int duz = ocene.getBroj();
		int sum = 0;
		for (int i = 0; i < duz; i++)
		{
			sum += ocene[i];
		}

		if (duz)
		{
			return (double) sum / ocene.getBroj();
		}

		return 0;
	}

	virtual char oznaka() const = 0;

	virtual void pisi(ostream& it) {
		it << oznaka() << " " << ime << " " << traj << " " << prosekOcena();

	}

	friend ostream& operator<<(ostream& it,  Film& f) {
		f.pisi(it);
		return it;
	}


};


class Domaci : public Film {


public:
	Domaci(string i, Vreme v) : Film(i, v) {};

	char oznaka() const override {
		return 'D';
	}
};


class Strani : public Film {

	string zemlja;

public:
	enum Titl{TITLOVAN, SINHRONIZOVAN};
	Titl prevod;

	Strani(string i, Vreme v, string z, Titl t) : Film(i, v), zemlja(z), prevod(t) {};


	char oznaka() const override {
		return 'S';
	}

	void pisi(ostream& it) override {
		Film::pisi(it);
		it<<zemlja<<" "; if (prevod == TITLOVAN)
		{
			it << "titlovan";
		}
		else
		{
			it << "sinhronizovan";
		}
	}


};

template<typename T>
class List {
	struct Elem {
		T pod;
		Elem* sled;

		Elem(T p, Elem* s = nullptr) : pod(p), sled(s) {};

	};

	Elem* prvi, * posl;
	mutable Elem* temp;




public:
	List() : prvi(nullptr), posl(nullptr), temp(nullptr) {};

	void operator<<=(T pod) {

		posl = (prvi ? posl->sled : prvi) = new Elem(pod);
	}

	void operator>>=(T pod) {
		Elem* novi = new Elem(pod);
		novi->sled = prvi;
		prvi = novi;
	}

	void naPrvi() {
		temp = prvi;
	}

	bool imaTemp() const {
		return temp != nullptr;
	}

	T getTemp() {
		return temp->pod;
	}

	void naSled() {
		temp = temp->sled;
	}

	void pisi() {
		for ( naPrvi(); imaTemp(); naSled())
		{
			cout << getTemp() << endl;
		}

	}



};


class LosaBoja {
public:
	friend ostream& operator<<(ostream& it, const LosaBoja& b) {
		return it << "Boja nije crna ili bela" << endl;
	}

};

class Boja {


	int crv, plv, zel;

public:

	Boja(int c = 255, int z = 255, int p = 255)
	{
		if ((c < 0 || c>255) || (z < 0 || z>255) || (p < 0 || p>255)) {
			throw LosaBoja();
		}
		else {
			plv = p;
			crv = c;
			zel = z;
		}
	}

	friend bool operator==(const Boja& b1, const Boja& b2) {
		if (b1.crv==b2.crv && b1.plv==b2.plv && b1.zel==b2.zel)
		{
			return true;
		}
		return false;
	}


	friend Boja operator+(const Boja& b1, const Boja& b2) {
		return Boja(b1.crv + b2.crv, b1.zel + b2.zel, b1.plv + b2.plv);


	}

	void pisi() {
		cout << "Crvena : " << crv << " Zelena : " << zel << " Plava" << plv;
	}


};



class Ukras {

	Boja boj;
	int mas;


public:
	Ukras(Boja b, int m) : boj(b), mas(m) {};

	Boja getB() const {
		return boj;
	}

	int getMas() const {
		return mas;
	}

	virtual void pisi(ostream& it) const = 0;

	friend ostream& operator<<(ostream& it, const Ukras& u) {
		u.pisi(it);
		return it;
	}



};

class Kugla : public Ukras {

public:
	enum Velicina{MALA, SREDNJA, VELIKA};
	Velicina vel;
	Kugla(Boja b, int m, Velicina v) : Ukras(b, m), vel(v) {};

	void pisi(ostream& it) const override {
		switch (vel)
		{
		case Kugla::MALA:
			it << ".";
			break;
		case Kugla::SREDNJA:
			it << "o";
			break;
		case Kugla::VELIKA:
			it << "()";
			break;
		default:
			break;
		}

	}



};



int main() {

	/*
	Vreme v1(2, 30);
	Vreme v2(1, 45);

	Vreme v3 = v1 + v2;

	cout << v1 << endl << (v1 > v2) << endl << v3 << endl;


	Domaci d1("Balkanski Spijun", v2);
	d1.oceni(10);
	d1.oceni(9);


	cout << d1<<endl;

	Strani s1("Fast and furious 3", v2, "USA", Strani::TITLOVAN);

	s1.oceni(8);
	s1.oceni(9);

	cout << s1 << endl;
	*/


	List<int> lst1;

	lst1 <<= 5;
	lst1 >>= 7;

	lst1.pisi();

	cout << endl;

	Boja b1(5, 5, 5);
	Boja b2(7, 7, 7);

	Boja b3 = b1 + b2;

	b1.pisi();
	cout << endl;
	cout << (b1 == b2) << endl;
	b3.pisi();

	cout << endl;

	Kugla k1(b1, 5, Kugla::MALA);
	cout << k1 << endl;


	return 0;
}