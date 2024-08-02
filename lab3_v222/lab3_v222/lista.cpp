#include "lista.h"

template<typename T>
void List<T>::kopirajLst(const List& lst) {
	prvi = posl = nullptr;
	for (Elem* temp = lst.prvi; temp ; temp=temp->sled)
	{
		posl = (prvi ? posl->sled : prvi) = new Elem(temp->pod);
	}
	broj = lst.broj;

}

/*
template<typename T>
void List<T>::delLst() {
	Elem* temp = prvi;
	while (temp)
	{
		Elem* s = temp;
		temp = temp->sled;
		delete s;
	}
	broj = 0;
	posl = nullptr;

}
*/