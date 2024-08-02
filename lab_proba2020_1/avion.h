#pragma once
#include<string>
#include <iostream>
#include "pilot.h"
using namespace std;


class Avion {
	string ime;
	Pilot* kapetan;
	Pilot* kopilot;
	int maxP;



public:
	Avion(string i, int m) : ime(i), maxP(m) {};
	Avion() {};
	
	Avion(const Avion&) = delete;

	Pilot* getKap();
	Pilot* getKop();
	string getIme() const;
	int getMax() const;
	void setKap(Pilot* kap);
	void setKop(Pilot* kop);


	friend ostream& operator<<(ostream& it, Avion& a) {
		return it << "AVION : " << a.getIme() << " - " << a.getMax() << " " << endl;
	}





};