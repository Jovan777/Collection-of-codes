#include "trougao3.h"
#include <iostream>

using namespace std;


class Skup_trou {

	struct Elem {
		Trougao t;
		Elem* sled;
		Elem(Trougao t, Elem* s = nullptr) : t(t), sled(s) {};


	};
	Elem* prvi, * posl;
	void kopiraj(const Skup_trou& st);
	void premesti( Skup_trou& st) {
		prvi = st.prvi;
		posl = st.posl;
		st.prvi = nullptr;
		st.posl = nullptr;
	}
	void brisi();

public:

	Skup_trou() : prvi(nullptr), posl(nullptr) {};

	Skup_trou(const Skup_trou& st) {
		kopiraj(st);
	}
	Skup_trou(Skup_trou&& st) {
		premesti(st);
	}
	~Skup_trou()
	{
		brisi();
	}

	Skup_trou& operator=(const Skup_trou& st) {
		if (this!=&st)
		{
			brisi();
			kopiraj(st);
		}
		return *this;
	}

	Skup_trou& operator=( Skup_trou&& st) {
		if (this != &st)
		{
			brisi();
			premesti(st);
		}
		return *this;
	}


	bool ima(const Trougao& t) const;

	Skup_trou& operator+=(const Trougao& t);
	double ukP() const;
	friend ostream& operator<<(ostream& it, const Skup_trou& st);


};


