#ifndef multimedija_h_
#define multimedija_h_



using namespace std;
#include <string>
#include <iostream>

class Multimedija
{

	string ime;

	void pisi(ostream& it) {
		it <<ime<<":"<< getDescription();

	}

public:
	Multimedija(string i) : ime(i) {};

	virtual int getByte() const = 0;
	virtual string getDescription()  = 0;

	friend ostream& operator<<(ostream& it,  Multimedija& m) {
		m.pisi(it);
		return it;
	}




};

#endif // !multimedija_h_
