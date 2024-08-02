#ifndef knjigaa_h_
#define knjiga_h



#include <iostream>
#include <string>
using namespace std;


static int stat_id = 0;


class Knjiga
{
	int id = stat_id++;

	string naziv;
	string autor;



public:
	Knjiga(string n, string a) : naziv(n), autor(a) {};
	
	Knjiga(const Knjiga& k) = delete;

	string getN() const { return naziv; }
	string getA() const { return autor; }
	int getID() const { return id; }

	Knjiga* operator!() {
		Knjiga* k = new Knjiga(naziv, autor);
		return k;
	}



	friend ostream& operator<<(ostream& it, const Knjiga& k) {
		return it << k.id << " " << k.autor << " " << k.naziv << endl;
	}


};

#endif // !knjigaa_h_
