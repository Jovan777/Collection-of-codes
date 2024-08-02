#ifndef izvodjac_h_
#define izvodjac_h_


#include <iostream>
#include <string>


using namespace std;

typedef enum {POP, REP, ROK} ZANR;


class Izvodjac
{
	string name;
	ZANR zanr;

	void pisi(ostream& it)const {
		it << name << "(";
		switch (zanr)
		{
		case POP:
			it << "pop";
			break;
		case ROK:
			it << "rok";
			break;
		case REP:
			it << "rep";
			break;

		}
		it << ")";


	}

public:
	Izvodjac(string n, ZANR z) {
		name = n;
		zanr = z;
	}

	friend ostream& operator<<(ostream& it, const Izvodjac& i) {
		i.pisi(it);
		return it;
	}

	string getZ() const {
		switch (zanr)
		{
		case POP:
			return  "pop";
			break;
		case ROK:
			return "rok";
			break;
		case REP:
			return "rep";
			break;

		}
	}

};

#endif // !izvodjac_h_
