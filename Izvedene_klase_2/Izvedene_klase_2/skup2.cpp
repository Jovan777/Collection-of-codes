#include "skup2.h"

void Skup::kopiraj(const Skup& s) {
	prvi = posl = nullptr;
	for (Elem* temp = s.prvi; temp ; temp=temp->sled)
	{
		dodaj(*temp->obj);
	}

}

void Skup::brisi() {
	while (prvi)
	{
		Elem* stari = prvi;
		prvi = prvi->sled;
		delete stari;
	}
	posl = nullptr;

}

bool Skup::operator%(const Obj& o) const{
	for (Elem* temp = prvi; temp ; temp=temp->sled)
	{
		if (*temp->obj==o)
		{
			return true;
		}
	}
	return false;

}


Skup operator-(const Skup& s1, const Skup& s2) {
	Skup s;
	for (Skup::Elem* temp = s1.prvi; temp; temp=temp->sled)
	{
		if (!(s2 % *temp->obj))
		{
			s.dodaj(*temp->obj);
		}
	}
	return s;

}

Skup operator*(const Skup& s1, const Skup& s2) {
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

Skup& Skup::operator+=(const Skup& s2) {
	for (Elem* temp = s2.prvi; temp ; temp=temp->sled)
	{
		if (!(*this%*temp->obj))
		{
			dodaj(*temp->obj);
		}
	}
	return *this;

}


ostream& operator<<(ostream& it, const Skup& s) {
	it << " { ";
	for (Skup::Elem* temp = s.prvi; temp; temp=temp->sled)
	{
		it << *temp->obj;
		if (temp->sled)
		{
			it << " , ";
		}
	}
	it << " } ";
	return it;

}