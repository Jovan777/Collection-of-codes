#pragma once

#include <iostream>
#include <string>
using namespace std;

class Pilot {

	string ime;
	int sati;
	bool aktivan;

public:
	Pilot(string i, int s, bool a = false) : ime(i), sati(s), aktivan(a) {};

	Pilot(const Pilot& p) = delete;


	string getIme() const {
		return ime;
	}
	int getSati() const {
		return sati;
	}
	bool getA() const {
		return aktivan;
	}

	void povecaj(int s) {
		this->sati += s;
	}

	void promeniStanje() {
		if (this->aktivan == true)
		{
			this->aktivan = false;
		}
		else
		{
			this->aktivan = true;
		}

	}

	friend ostream& operator<<(ostream& it, Pilot& p) {
		return it << p.getIme() << " ( " << p.getSati() << " ) " << (p.getA() == true ? "L" : "N") << endl;
	}


};

class Avion {


	string ime;
	Pilot* kapetan;
	Pilot* kopilot;
	int maxP;

public:

	Avion(string i, int m) : ime(i), maxP(m) {};
	Avion(const Avion& a) = delete;

	Pilot* getKap() {
		return this->kapetan;
	}
	Pilot* getKop() {
		return this->kopilot;
	}

	string getIme() const {
		return ime;
	}
	int getMax() const {
		return maxP;
	}


	
	void setKap(Pilot* kap) {
		if (kap->getSati()>=100)
		{
			kapetan = kap;
			kap->promeniStanje();
		}
		else
		{
			exit(1);
		}


	};

	void setKop(Pilot* kop) {
		kopilot = kop;
		kop->promeniStanje();
	};

	

	friend ostream& operator<<(ostream& it, Avion& a) {
		return it << "AVION : " << a.getIme() << " - " << a.getMax()<<" "<< endl;
	}



};