#ifndef _tacka5_h_
#define _tacka5_h_

#include "pokretan.h"
#include "vektor1.h"
#include "brzina.h"

using namespace std;

static int pos_id = 0;

class Tacka : public Pokretan {

	int id = ++pos_id;
	Vektor r;
	Brzina v;

public:
	Tacka(const Vektor& r = Vektor(), const Brzina& v = Brzina()) : r(r), v(v) {};

	Tacka(const Tacka& t) : r(t.r), v(t.v) {};

	Tacka& operator=(const Tacka& t) {
		r = t.r; v = t.v;
		return *this;
	}

	Vektor R() const {
		return r;
	}

	Tacka& proteklo(double dt) override {
		r = r + v * dt;
		return *this;
	}
 
	friend double rastojanje(const Tacka& t1, const Tacka& t2) {
		return (t2.r + t1.r * - 1).intenz();
	}

	friend ostream& operator<<(ostream& it, const Tacka& t) {
		it << "T"<<t.id << t.r;
		return it;
	}




};







#endif // !_tacka5_h_
