#include "skup_trou.h"


void Skup_trou::kopiraj(const Skup_trou& st) {
	prvi = posl = nullptr;
	for (Elem* temp = st.prvi; temp ; temp=temp->sled)
	{
		posl = (prvi ? posl->sled : prvi) = new Elem(temp->t);
	}

}

void Skup_trou::brisi() {

	while (prvi)
	{
		Elem* stari = prvi;
		prvi = prvi->sled;
		delete stari;

	}
	posl = nullptr;
}


bool Skup_trou::ima(const Trougao& tr) const{
	for (Elem* tek = prvi; tek ; tek=tek->sled)
	{
		if (tek->t==tr)
		{
			return true;
		}
	}
	return false;
}


Skup_trou& Skup_trou::operator+=(const Trougao& tr) {
	if (!ima(tr))
	{
		posl = (prvi ? posl->sled : prvi) = new Elem(tr);
	}
	return *this;
}

double Skup_trou::ukP() const {
	double p = 0;
	for (Elem* temp = prvi; temp ; temp=temp->sled)
	{
		p += temp->t.P();
	}

	return p;
}


ostream& operator<<(ostream& it, const Skup_trou& st) {
	it << " { ";
	for (Skup_trou::Elem* temp = st.prvi; temp; temp=temp->sled)
	{
		it << temp->t;
		if (temp->sled)
		{
			it << " , ";
		}
	}
	return it << " }";
}