#ifndef _lista_h
#define _lista_h

#include <iostream>
using namespace std;


class N_Lista {

protected:

	struct Elem {
		int br;
		Elem* sled;
		Elem(int b, Elem* s = nullptr) : br(b), sled(s) {};


	};

	Elem* prvi, * posl;
	int duz;

private:
	void kopiraj(const N_Lista& lst);
	void premesti(N_Lista& lst) {
		prvi = lst.prvi;
		posl = lst.posl;
		duz = lst.duz;
		lst.prvi = nullptr;
		lst.posl = nullptr;
		lst.duz = 0;

	}
	void brisi();




public:
	

	N_Lista() : prvi(nullptr), posl(nullptr), duz(0) {};
	N_Lista(int b)  {
		prvi = posl = new Elem(b);
		duz = 1;
	};
	N_Lista(const N_Lista& lst) {
		kopiraj(lst);
	}
	N_Lista(N_Lista&& lst) {
		N_Lista::premesti(lst);  ////////
	}

	~N_Lista()
	{
		brisi();
	}

	N_Lista& operator=(const N_Lista& lst) {
		if (this!=&lst)
		{
			brisi();
			kopiraj(lst);
		}
		return *this;
	}

	N_Lista& operator=(N_Lista&& lst) {
		if (this!=&lst)
		{
			brisi();
			premesti(lst);
		}
		return *this;
	}

	int duzina() const {
		return duz;
	}

	virtual N_Lista& operator+=(int b) {
		Elem* novi = new Elem(b);
		duz++;
		posl = (prvi ? posl->sled : prvi) = novi;


		return *this;
	}

	N_Lista& operator+=(const N_Lista& lst);
	friend ostream& operator<<(ostream& it, const N_Lista& lst);


};





#endif // !_lista_h
