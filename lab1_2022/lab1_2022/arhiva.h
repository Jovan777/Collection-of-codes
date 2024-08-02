#ifndef arhiva_h_
#define arhiva_h_

#include "let.h"

using namespace std;






class Arhiva
{

	struct Elem {
		Let let;
		Elem* sled;

		Elem(Let l, Elem* s = nullptr) : let(l), sled(s) {};


	};
	Elem* prvi, * posl;


public:
	Arhiva() : prvi(nullptr), posl(nullptr) {};

	void dodaj(Let l) {
		posl = (prvi ? posl->sled : prvi) = new Elem(l);
	}

	void pisi() const{
		cout << "ARHIVA" << endl;
		Elem* temp = prvi;
		while (temp)
		{
			temp->let.pisi(); cout << endl;
			temp = temp->sled;
		}

	}

	Arhiva istoP(string polaziste) {
		Arhiva ar;

		Elem* temp = prvi;
		while (temp)
		{
			if (temp->let.getP()==polaziste)
			{
				ar.posl = (ar.prvi ? ar.posl->sled : ar.prvi) = new Elem(temp->let);
			}

			temp = temp->sled;
		}



		return ar;
	}

	Arhiva istoD(string dolaziste) {
		Arhiva ar;

		Elem* temp = prvi;
		while (temp)
		{
			if (temp->let.getD() == dolaziste)
			{
				ar.posl = (ar.prvi ? ar.posl->sled : ar.prvi) = new Elem(temp->let);
			}

			temp = temp->sled;
		}

		return ar;
	}

	Arhiva istoPD(string polaziste, string dolaziste) {

		Arhiva ar;

		Elem* temp = prvi;
		while (temp)
		{
			if (temp->let.getD() == dolaziste && temp->let.getP()==polaziste)
			{
				ar.posl = (ar.prvi ? ar.posl->sled : ar.prvi) = new Elem(temp->let);
			}

			temp = temp->sled;
		}

		return ar;

	}




};

#endif // !arhiva_h_
