#ifndef lista_h
#define lista_h


#include <iostream>
using namespace std;

class PremasenOpseg {

public:
	friend ostream& operator<<(ostream& it, const PremasenOpseg& p) {
		it << "Pozicija je van opsega liste" << endl;
		return it;
	}

};


template<typename T>
class List {

	struct Elem {
		T pod;
		Elem* sled;

		Elem(T p, Elem* s = nullptr) : pod(p), sled(s) {};


	};

	int broj;
	Elem* prvi, * posl;

	void kopirajLst(const List& lst);
	void premLst(List& lst) {
		prvi = lst.prvi;
		posl = lst.posl;
		broj = lst.broj;

		lst.broj = 0;
		lst.prvi = nullptr;

		lst.posl = nullptr;
	}

	void delLst() {
		Elem* temp = prvi;
		while (temp)
		{
			Elem* s = temp;
			temp = temp->sled;
			delete s;
		}
		broj = 0;
		posl = nullptr;
	};

public:
	List() : posl(nullptr), broj(0), prvi(nullptr) {};
	List(const List& lst) {
		kopirajLst(lst);

	}
	List(List&& lst) {
		premLst(lst);

	}

	List& operator=(const List& lst) {
		if (this!=lst)
		{
			delLst();
			kopirajLst(lst);
		}
		return *this;
	}

	List& operator=(List&& lst) {
		if (this != lst)
		{
			delLst();
			premLst(lst);
		}
		return *this;


	}
	~List()
	{
		delLst();
	}

	int getBR() const {
		return broj;
	}

	void operator+=(const T& p) {
		posl = (prvi ? posl->sled : prvi) = new Elem(p);
		broj++;
	}

	T& operator[](int ind) {
		if (ind>broj)
		{
			throw PremasenOpseg();
		}

		Elem* temp = prvi;
		int i = 0;
		while (i<ind)
		{
			temp = temp->sled;
			i++;
		}

		return temp->pod;
	}




	friend ostream& operator<<(ostream& it, const List& l) {
		Elem* temp = l.prvi;
		while (temp)
		{
			it << temp->pod;
			if (temp->sled)
			{
				it << " ";
			}

			temp = temp->sled;
		}

		return it;
	}





};







#endif // !lista_h
