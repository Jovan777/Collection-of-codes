#ifndef takt_h_
#define takt_h_





#include "Znak.h"
#include "sekvenca.h"
using namespace std;



class Takt
{
	Sekvenca<Znak*> s;
	Razlomak max;
	Razlomak tek;
	bool kraj ;
	
public:
	Takt(Razlomak m ) : max(m), tek(0), kraj(false) {};
	Takt(const Takt&) = delete;
	Takt(Takt&&) = delete;
	Takt& operator=(const Takt&) = delete;
	Takt& operator=( Takt&&) = delete;

	Razlomak maxTrajanje() const {
		return max;
	}

	void dodaj(Znak& z) {
		//Razlomak trajanje = tek + z->getT();
		if ( !kraj)
		{
			cout << "usao ";
			s.dodaj(&z);
			

		}

	}

	void zavrsi()  {
		kraj = true;
	}

	bool zavrsen() const {
		return kraj;

	}

	bool nepotpun() const {
		return max>tek;
	}

	


	friend ostream& operator<<(ostream& it,  Takt& t) {
		for (int i = 0; i < t.s.duz(); i++)
		{
			it << " takt ";
			it << *t.s.pocetak() << " ";
		}
		it << "|";
		return it;

	}





};

#endif // !takt_h_
