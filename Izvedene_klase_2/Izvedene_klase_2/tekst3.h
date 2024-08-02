
#ifndef _tekst3_h_
#define _CRT_SECURE_NO_WARNINGS


#define _tekst3_h_


#include "objekat.h"
#include<cstring>
#include <utility>

using namespace std;



class Tekst : public Obj {

	char* tks;
	bool jednako(const Obj& ob) const {
		return strcmp(tks, ((Tekst&)ob).tks) == 0;  ////////////
 
	}

	void pisi(ostream& it) {
		it << " [ " << (tks ? tks : "") << " ] ";
	}

	void premesti(Tekst& t) {
		tks = t.tks;
		t.tks = nullptr;

	}

	/*
	bool jednako(const Obj& obj) const           // Da li su jednaki?
	{
		return strcmp(tks, ((Tekst&)obj).tks) == 0;
	}
	*/

	void pisi(ostream& it) const                // Pisanje objekta.
	{
		it << '[' << (tks ? tks : "") << ']';
	}
	


	void citaj(istream& ut) {

		char niz[81], zn;
		ut >> zn;
		ut.getline(niz, 81, ']');
		delete tks;
		kopiraj(niz);

	}
	
	

	void kopiraj(const char* niz) {

		if (niz && niz[0])
		{
			tks = new char[strlen(niz) + 1];
			strcpy(tks, niz);


		}
		else
		{
			tks = nullptr;
		}


	}


public:

	Tekst(const char* niz = "") {
		kopiraj(niz);
	}

	Tekst(const Tekst& t) : Obj(t) {
		kopiraj(t.tks);
	}

	Tekst(Tekst&& t) : Obj(move(t)) {
		premesti(t);
	}

	~Tekst()
	{
		delete[] tks;
	}

	Tekst& operator=(const Tekst& t) {
		if (this!=&t)
		{
			delete[] tks;
			Obj::operator=(t);
			kopiraj(t.tks);

		}
		return *this;
	}

	Tekst& operator=( Tekst&& t) {
		if (this!=&t)
		{
			delete[] tks;
			Obj::operator=(move(t));
			premesti(t);
		}
	}


	string klasa() const override {
		return "Tekst";
	}
	Tekst* kopija() const& override          // Kopija objekta kopiranjem.
	{
		return new Tekst(*this);
	}
	Tekst* kopija() && override              // Kopija objekta premeštanjem.
	{
		return new Tekst(move(*this));
	}




};





#endif // !_tekst3_h_
