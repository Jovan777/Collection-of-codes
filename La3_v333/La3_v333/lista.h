#ifndef lista_h
#define lista_h

#include <iostream>
using namespace std;

class TempNull {
public:
	friend ostream& operator<<(ostream& it, const TempNull& t) {
		return it << "Tekuci element ne postoji" << endl;
	}


};


template<typename T>
class Lst {

	struct Elem {
		T pod;
		Elem* sled;

		Elem(T p, Elem* s = nullptr) : pod(p), sled(s) {};


	};

	Elem* prvi, * posl;
	mutable Elem* temp, * pret;

public:
	Lst() : temp(nullptr), posl(nullptr), pret(nullptr), prvi(nullptr) {}
	Lst& operator=(const Lst&) = delete;
	Lst(const Lst&) = delete;

	~Lst()
	{
		for ( naPrvi(); tempPod(); )
		{
			Elem* s = temp;
			temp = temp->sled;
			delete s;

		}

		posl = nullptr;
	}


	void naPrvi() const {
		temp = prvi;
	}

	void naSled() {
		temp = temp->sled;
	}

	bool tempPod() const {
		return temp != nullptr;
	}

	T getTemp() const {
		if (!temp)
		{
			throw TempNull();
		}
		
		return temp->pod;
	}

	void operator<<=(const T& pod) {
		posl = (prvi ? posl->sled : prvi) = new Elem(pod);
	}

	void operator>>=(const T& pod) {
		Elem* novi = new Elem(pod);
		novi->sled = prvi;
		prvi = novi;

	}


	friend ostream& operator<<(ostream& it,  Lst& l) {
		l.naPrvi();
		while (l.tempPod())
		{
			it << l.getTemp();
			l.naSled();
			if (l.tempPod())
			{
				it << " ";
			}

		}
		return it;
	}


};







#endif // !lista_h
