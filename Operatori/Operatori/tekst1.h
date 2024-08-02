#pragma once
#include <iostream>
#include <cstring>
#include <cstdlib>

using namespace std;


class Tekst {

	char* niz;
	void kopiraj(const char*);
	void premesti(Tekst& t) {
		niz = t.niz;
		t.niz = nullptr;
	}
	void brisi() {
		delete[] niz;
	}

public:
	Tekst() { niz = nullptr; }
	Tekst(const char* n) {
		kopiraj(n);
	}
	Tekst(const Tekst& t) {
		kopiraj(t.niz);
	}

	Tekst(Tekst&& t) {
		premesti(t);
	}

	~Tekst()
	{
		brisi();
	}

	Tekst& operator=(const Tekst& t) {
		if (this!=&t)
		{
			brisi();
			kopiraj(t.niz);
		}
		return *this;
	}

	Tekst& operator=(Tekst&& t) {
		if (this!=&t)
		{
			brisi();
			premesti(t);
		}
		return *this;
	}

	friend int len(const Tekst& t) {
		return t.niz ? strlen(t.niz) : 0;
	}

	friend Tekst operator+(const Tekst&, const Tekst&);
	Tekst& operator+=(const Tekst& t) {
		return *this = *this + t;
	}

	char& operator[](int i) {
		if (i<0 || len(*this)<=i)
		{
			exit(1);
		}
		else
		{
			return niz[i];
		}
	}

	const char& operator[](int i) const {
		if (i < 0 || len(*this) <= i)
		{
			exit(1);
		}
		else
		{
			return niz[i];
		}
	}
	
	Tekst operator()(int, int) const;

	friend int operator%(const Tekst&, const Tekst&);
	
	friend ostream& operator<<(ostream& it, Tekst& t) {
		if (t.niz)
		{
			it << t.niz;
			return it;
		}

	}

	friend istream& operator>>(istream& ut, Tekst& t) {
		char n[81];
		ut >> n;
		t = n;
		return ut;
	}



};