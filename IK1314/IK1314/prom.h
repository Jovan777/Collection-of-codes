#ifndef _prom_h_
#define _prom_h_



#include "izraz.h"
#include <string>

using namespace std;

struct Elem {
	string ime;
	double vrd;
	int br_kor;
	Elem* pret, * sled;
	Elem(string i, double v, Elem* p = nullptr, Elem* s = nullptr) : ime(i), vrd(v), pret(p), sled(s), br_kor(1) {};
};
static  Elem* prv{ nullptr }; // Poèetak liste svih promenljivih.

namespace Izrazi {
	class Prom : public Izraz {

		
		Elem* prvi = prv;
		Elem* ovaj;


		void pravi(string ime, double vr) {
			Elem* tek = prvi, * pret = nullptr;
			while (tek && tek->ime<ime)
			{
				pret = tek;
				tek = tek->sled;
			}
			if (tek && tek->ime==ime)
			{
				ovaj = tek;
				ovaj->br_kor++;
			}
			else
			{
				Elem* novi = new Elem(ime, vr);
				if (tek)
				{
					tek->pret = novi;
				}
				(!pret ? prvi : pret->sled) = novi;
				ovaj = novi;



			}

		}


		void pisi(ostream& it) const override {
			it << ovaj->ime;
		}

	public:

		Prom(string i, double vr = 0) {
			pravi(i, vr);
		}

		Prom(string i, const Izraz& iz) {
			pravi(i, iz.vredn());
		}
		Prom(const Prom& p) {
			ovaj = p.ovaj;
			ovaj->br_kor++;
		}

		~Prom()
		{
			if (--ovaj->br_kor==0)
			{
				(ovaj->pret ? ovaj->pret->sled : prvi) = ovaj->sled;
				if (ovaj->sled)
				{
					ovaj->sled->pret = ovaj->pret;
				}
				delete ovaj;
			}


		}

		Prom& operator=(double v) {
			ovaj->vrd = v;
			return *this;
		}

		Prom& operator=(const Izraz& i) {
			ovaj->vrd = i.vredn();
			return *this;
		}
		Prom& operator=(const Prom& p) {
			ovaj->vrd = p.vredn();
			return *this;
		}

		Prom* kopija() const override {
			return new Prom(*this);
		}

		double vredn() const override {
			return ovaj->vrd;
		}

		friend istream& operator>>(istream& ut, Prom& p) {
			return ut >> p.ovaj->vrd;
		}


		 void pisiSve(ostream& it) {
			for (Elem* temp = prvi; temp ; temp=temp->sled)
			{
				it << temp->ime << " ";
			}
			it << endl;

		}






	};



}








#endif // !_prom_h_

