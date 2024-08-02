#ifndef tekst_h
#define tekst_h

#include "objekat.h"
#include <cstring>
#include <utility>
#include <string>

using namespace std;





class Tekst : public Objekat
{
	char* tks;

	void kopiraj(const char* niz) {
		if (niz && niz[0])
		{
			tks = new char[strlen(niz) + 1]; strcpy(tks, niz);
		}
		else
		{
			tks = nullptr;
		}
	}

	void premesti(Tekst& t) {
		tks = t.tks;
		t.tks = nullptr;
	}

	bool jednako(const Objekat& obj) const {
		return strcmp(tks, ((Tekst&)obj).tks) == 0;
	}

	void pisi(ostream& it) const {
		it << "[" << (tks ? tks : "") << "]";
	}

	void citaj(istream& ut) {
		char niz[80], zn;
		ut >> zn;
		ut.getline(niz, 80, ']');
		delete[] tks;
		kopiraj(niz);
		
	}

public:
	Tekst(const char* niz = "") {
		kopiraj(niz);
	}

	Tekst(const Tekst& t) : Objekat(t) {
		kopiraj(t.tks);
	}

	Tekst(Tekst&& t) : Objekat(move(t)) {
		premesti(t);
	}

	~Tekst()
	{
		delete[] tks;
	}

	string getClass() const override {
		return "Tekst";
	}

	Tekst* kopija() const& override {
		return new Tekst(*this);
	}

	Tekst* kopija() && override {
		return new Tekst(move(*this));
	}



};

#endif // !tekst_h
