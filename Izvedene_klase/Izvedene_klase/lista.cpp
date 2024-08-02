#include "lista.h"

void N_Lista::kopiraj(const N_Lista& lst) {
	duz = lst.duz;
	prvi = posl = nullptr;
	for (Elem* temp = lst.prvi; temp ; temp=temp->sled)
	{
		posl = (prvi ? posl->sled : prvi) = temp;
	}

}


void N_Lista::brisi() {

	while (prvi)
	{
		Elem* stari = prvi;
		prvi = prvi->sled;
		delete stari;
	}

	posl = nullptr;
	duz = 0;
}

N_Lista& N_Lista::operator+=(const N_Lista& lst) {
	if (this != &lst)
	{
		for (Elem* temp = lst.prvi; temp; temp = temp->sled)
		{
			*this += temp->br;
		}
	}
	else
	{
		*this += N_Lista(lst);
	}
	return *this;
}


ostream& operator<<(ostream& it, const N_Lista& lst) {
	it << "( ";
	for (N_Lista::Elem* temp = lst.prvi; temp; temp = temp->sled)
	{
		it << temp->br; if (temp->sled) it << " ";
	}
	return it << " )";
}

