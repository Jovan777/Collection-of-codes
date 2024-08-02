#ifndef _skladiste_h_
#define _skladiste_h_

#include "Kupa.h"
#include "zarubljena.h"

using namespace std;







class Skladiste
{

	struct Elem {
		Kupa* k;
		Elem* sled;
		Elem(Kupa* kk, Elem* s = nullptr) : k(kk), sled(s) {};
	

	};

	Elem* prvi, * posl;
	void kopiraj(const Skladiste& s);
	void premesti(Skladiste& s) {
		prvi = s.prvi; posl = s.posl;
		s.prvi = nullptr; s.posl = nullptr;

	}
	void brisi() {
		delete prvi;
		delete posl;

	}

	

public:
	Skladiste() : prvi(nullptr), posl(nullptr) {};
	Skladiste(const Skladiste& s) {
		kopiraj(s);
	}
	Skladiste(Skladiste&& s) {
		premesti(s);
	}

	~Skladiste()
	{
		brisi();
	}

	Skladiste& operator+=(Kupa* k) {
		posl = (prvi ? posl->sled : prvi) = new Elem(k);
		return *this;
	}

	int operator()(double v1, double v2);

	friend ostream& operator<<(ostream& it, const Skladiste& s) {
		it << "[";
		for (Skladiste::Elem* temp = s.prvi; temp ; temp=temp->sled)
		{
			
			it << *temp->k;
			if (temp->sled) it << "|";
		}
		it << "]";
		return it;
	}






};

#endif // !_skladiste_h_
