#ifndef lista_h_
#define lista_h_

#include "korisnik.h"
using namespace std;






class Lista
{
	struct Elem {

		Korisnik* user;
		Elem* sled;

		Elem(Korisnik* u, Elem* s = nullptr) : user(u), sled(s) {};



	};

	Elem* prvi, * posl;

public:
	Lista() : prvi(nullptr), posl(nullptr) {};

	Lista& operator+=(Korisnik* k) {
		posl = (prvi ? posl->sled : prvi) = new Elem(k);
		return *this;
	}



	friend ostream& operator<<(ostream& it, const Lista& l) {
		l.pisi(it);
		return it;
	}


	int brojKorisnika() const {
		int n = 0;
		for (Elem* temp = prvi; temp ; temp=temp->sled)
		{
			n++;
		}
		return n;

	}

	Korisnik* operator[](int i) {
		int n = 0;
		for (Elem* temp = prvi; temp; temp=temp->sled, n++)
		{
			if (n==i)
			{
				return temp->user;
			}

		}
		return nullptr;

	}

	void operator()(int i)
	{
		int num = 0;
		if (i > brojKorisnika()) return;
		if (i == 0)
		{
			Elem* old = prvi;
			prvi = prvi->sled;
			delete old;
		}
		for (Elem* p = prvi; p != nullptr; p = p->sled)
		{
			if (num == i - 1)
			{
				Elem* old = p->sled;
				p->sled = p->sled->sled;
				if (p->sled == nullptr) posl = p;
				delete old;
				return;
			}
			num++;
		}
	}

protected:
	void pisi(ostream& it) const {
		for (Elem* temp = prvi; temp ; temp=temp->sled)
		{
			it << *temp->user << endl;
		}
	}



};

#endif // !lista_h_
