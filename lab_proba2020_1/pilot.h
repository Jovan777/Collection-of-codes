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


