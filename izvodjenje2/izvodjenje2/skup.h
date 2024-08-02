#ifndef skup_h
#define skup_h


#include "objekat.h"
#include <iostream>

using namespace std;



class Skup
{
	struct Elem {
		Objekat* obj;
		Elem* sled;
		Elem(Objekat* o, Elem* s = nullptr) : obj(o), sled(s) {};


	};
	Elem* prvi, * posl;

	void dodaj(const Objekat& obj) {
		Elem* novi = new Elem(obj.kopija());
		posl = (prvi ? posl->sled : prvi) = novi;

	}
	void dodaj( Objekat&& obj) {
		Elem* novi = new Elem(move(obj).kopija());
		posl = (prvi ? posl->sled : prvi) = novi;
	}

	void kopiraj(const Skup& s) {
		prvi = posl = nullptr;
		Elem* temp = s.prvi;
		while (temp)
		{
			dodaj(*temp->obj);
		}
	}

	void premesti(Skup& s) {
		prvi = s.prvi;
		posl = s.posl;
		s.prvi = nullptr;
		s.posl = nullptr;

	}

	void brisi() {
	
		while (prvi)
		{
			Elem* temp = prvi;
			prvi = prvi->sled;
			delete temp;


		}
		prvi = posl = nullptr;

	}

public:
	Skup() {
		prvi = posl = nullptr;
	}

	Skup(const Objekat& obj) {
		prvi = posl = new Elem(obj.kopija());
	}

	Skup(const Skup& s) {
		kopiraj(s);
	}
	Skup(Skup&& s) {
		premesti(s);
	}
	~Skup()
	{
		brisi();
	}
	Skup& operator=(const Skup& s) {
		if (this!=&s)
		{
			brisi();
			kopiraj(s);
		}
		return *this;
	}

	Skup& operator=(Skup&& s) {
		if (this!=&s)
		{
			brisi();
			premesti(s);
			
		}
		return *this;

	}

	bool operator%(const Objekat& obj) const {
		Elem* temp = prvi;
		while (temp)
		{
			if (*temp->obj==obj)
			{
				return true;
			}

		}
		return false;
	}

	friend Skup operator-(const Skup& s1, const Skup& s2) {  //razlika dva skupa
		Skup s;
		for (Skup::Elem* temp = s1.prvi; temp ; temp=temp->sled)
		{
			if (!(s2%*temp->obj))
			{
				s.dodaj(*temp->obj);
			}
		}
		return s;
	}

	friend Skup operator+(const Skup& s1, const Skup& s2) {
		return Skup(s1) += s2;
	}

	friend Skup operator*(const Skup& s1, const Skup& s2) {  //razlika dva skupa
		Skup s;
		for (Skup::Elem* temp = s1.prvi; temp; temp = temp->sled)
		{
			if ((s2 % *temp->obj))
			{
				s.dodaj(*temp->obj);
			}
		}
		return s;
	}

	Skup& operator+=(const Skup& s) {
		for (Elem* temp = s.prvi; temp ; temp=temp->sled)
		{
			if (!(*this%*temp->obj))
			{
				dodaj(*temp->obj);
			}
		}
		return *this;
	}

	Skup& operator-=(const Skup& s) {
		return *this = *this - s;
	}

	Skup& operator*=(const Skup& s) {
		return *this = *this * s;
	}





	friend ostream& operator<<(ostream& it, const Skup& s) {
		it << "{";
		for (Skup::Elem* temp = s.prvi; temp ; temp=temp->sled)
		{
			it << *temp->obj<<(temp->sled ? ", " : "");
		}
		return it << "}";
	}





};

#endif // !skup_h
