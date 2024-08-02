#ifndef _telo1_h_
#define _telo1_h_


#include <iostream>
using namespace std;


class Telo {


public:
	virtual ~Telo() {};
	virtual char vrsta() const = 0;
	virtual double V() const = 0;
	virtual Telo* kopija() const& = 0;
	virtual Telo* kopija() && = 0;

private:
	virtual void pisi(ostream& it) const = 0;
	friend ostream& operator<<(ostream& it, const Telo& t) {
		t.pisi(it);
		return it;
	}
};





#endif // !_telo1_h_

/*

class Telo {
public:
	virtual ~Telo() {}                    // Virtuelan destruktor.
	virtual char vrsta() const = 0;        // Oznaka vrste.
	virtual double V() const = 0;          // Zapremina tela.
	virtual Telo* kopija() const& = 0;     // Kopija tela kopiranjem.
	virtual Telo* kopija() && = 0;         // Kopija tela premeštanjem.
private:
	virtual void pisi(ostream&) const = 0; // Pisanje tela.
	friend ostream& operator<<(ostream& it, const Telo& t)
	{
		t.pisi(it); return it;
	}
};

*/


