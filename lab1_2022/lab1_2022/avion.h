#ifndef avion_h_
#define avion_h_
#include "pilot.h"









class Avion
{
	
	
	string name;
	Pilot* kap;
	Pilot* kop;
	int max;


public:
	Avion(string n, int m) : name(n), max(m) {};
	Avion(const Avion&) = delete;
	Avion(Avion&&) = delete;

	string getName() const {
		return name;
	}

	int getMax() const {
		return max;
	}

	Pilot* getKap() const {
		return kap;
	}

	Pilot* getKop() const {
		return kop;
	}

	void setKap(Pilot* k) {
		if (k->getHours()>=100)
		{
			kap = k;
			kap->changeFly(true);
		}
		return;
	}

	void setKop(Pilot* k) {
		kop = k;
		kop->changeFly(true);
	}


	void pisi() const {
		cout << "AVION:" << name << "-" << max;
	}





};

#endif // !avion_h_
