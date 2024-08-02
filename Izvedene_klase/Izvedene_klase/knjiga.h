
#ifndef _knjiga_h_

#define _knjiga_h_


#include <iostream>
#include <string>


using namespace std;



class Knjiga {

	string autor;
	string naslov;
	double cena;

public:
	
	Knjiga(string a, string n, double c) : autor(a), naslov(n), cena(c) {};

	virtual double vrednost() const { return cena; }

	virtual void pisi(ostream& it) const{
		it << autor << ": \"" << naslov << "\" (" << vrednost() << ")";
	}

};


#endif // !_knjiga_h_
