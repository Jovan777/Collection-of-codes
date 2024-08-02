#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include "predstava.h"
#include "kvadar.h";
#include "poli.h"
#include <string>
#include "inventar.h"
#include "redna_veza.h"
#include "recnik.h"

using namespace std;

class Kompl {

	double re, im;

public:
	Kompl(double r=0, double i=0) : re(r), im(i) {};

	double getRe() {
		return re;
	}

	double getIm() {
		return im;
	}


	friend double abs(const Kompl& k) {
		return sqrt(k.re * k.re + k.im * k.im);
	}

	friend double arg(const Kompl& k) {
		return (k.re != 0 || k.im != 0) ? atan2(k.im, k.re) : 0;
	}

	Kompl operator~() {
		return Kompl(re, -im);
	}

	friend istream& operator>>(istream& ut, Kompl& k) {
		return ut >> k.re >> k.im;
	}

	friend ostream& operator<<(ostream& it, const Kompl& k) { //problem
		return it<<"("<<k.re << " " << k.im<<")";

	}

	friend Kompl operator+(const Kompl& a, const Kompl& b) {
		return Kompl(a.re + b.re, a.im + b.im);

	}
	friend Kompl operator-(const Kompl& a, const Kompl& b) {
		return Kompl(a.re - b.re, a.im - b.im);
	}
		
	friend Kompl operator*(const Kompl& a, const Kompl& b) {
		return Kompl(a.re*b.re - a.im*b.im, a.im*b.re - b.im*a.re);
	}

	friend Kompl operator/(const Kompl& a, const Kompl& b) {
		double c = b.re * b.re + b.im * b.im;

		return Kompl((a.re*b.re+a.im*b.im)/c, (a.im*b.re-a.re*b.im)/c);
	}


	Kompl& operator++() {
		re++;
		return *this;
	}

	Kompl& operator--() {
		re--;
		return *this;
	}

	Kompl operator++(int) {
		Kompl z = (*this);
		re++;
		return z;
	}
	Kompl operator--(int) {
		Kompl z = (*this);
		re--;
		return z;
	}

	friend bool operator==(const Kompl& a, const Kompl& b) {
		return (a.re == b.re && a.im == b.im);
	}

	friend bool operator!=(const Kompl& a, const Kompl& b) {
		return !(a == b);
	}

	Kompl& operator+=(const Kompl& b) {
		return *this = *this + b;
	}
	Kompl& operator-=(const Kompl& b) {
		return *this = *this - b;
	}
	Kompl& operator*=(const Kompl& b) {
		return *this = *this * b;
	}
	Kompl& operator/=(const Kompl& b) {
		return *this = *this / b;
	}

};

Kompl poli(const Kompl p[], int n, Kompl z) {
	Kompl s = p[n];
	for (int i = n - 1; i >= 0; (s *= z) += p[i--]);
	return s;
}

class Niz_kompl {

	int n;
	Kompl* niz;

	void kopiraj(const Niz_kompl& nk) {
		niz = new Kompl[n = nk.n];
		for (int i = 0; i < n; i++)
		{
			niz[i] = nk.niz[i];
		}
	}

	void premesti(Niz_kompl& nk) {
		n = nk.n;
		niz = nk.niz;
		nk.niz = nullptr;
	}
	
	void brisi() {
		delete[] niz;
	}

public:

	explicit Niz_kompl(int n = 10) : n(n), niz(new Kompl[n]) {};
	Niz_kompl(const Niz_kompl& nn) {
		kopiraj(nn);
	}

	Niz_kompl(Niz_kompl&& nn) {
		premesti(nn);
	}

	Niz_kompl& operator=(const Niz_kompl& nn) {
		if (this!=&nn)
		{
			brisi();
			kopiraj(nn);
		}

		return *this;
	}

	Niz_kompl& operator=(Niz_kompl&& nn) {
		if (this!=&nn)
		{
			brisi();
			premesti(nn);
		}
		return *this;
	}

	int duz() const {
		return n;
	}

	Kompl& operator[](int i) {
		return niz[i];
	}

	const Kompl& operator[](int i) const {
		return niz[i];
	}

};

class Student {

	string ime;
	long id;
	int kap;
	int* ocene;
	int brO;


public:
	Student(string i, long idd, int k=40) : ime(i), id(idd), kap(k) {
		ocene = new int[kap];
		brO = 0;
	};
	Student(const Student&) = delete;
	Student& operator=(const Student&) = delete;

	~Student()
	{
		delete ocene;
	}

	string getIme() const {
		return ime;
	}

	long getId() const {
		return id;
	}

	void setIme(string i) {
		ime = i;
	}
	void setId(long i) {
		id = i;
	}

	Student& operator+=(int ocena) {
		if (ocena<5 || ocena>10)
		{
			return *this;
		}


		ocene[brO++] = ocena;
		return *this;
	}

	int getBrO() const {
		return brO;
	}

	int operator[](int i) {
		if (i<0 || i>brO)
		{
			return -1;
		}
		return ocene[i];

	}

	double averageGrade() const {
		if (brO==0)
		{
			return 0;
		}
		int s = 0;
		for (int i = 0; i < brO; i++)
		{
			s += ocene[i];
		}

		return (double)s / brO;

	}

	friend ostream& operator<<(ostream& ut, const Student& s) {
		ut << s.ime << "|" << s.id << endl;
		ut << "Ocene : " << endl;
		for (int i = 0; i < s.brO; i++)
		{
			ut << s.ocene[i]<<" ";
		}
		ut << endl;
		ut << "Prosecna ocena : " << s.averageGrade() << endl;
		return ut;
	}

};

class Red {

	struct Elem {
		int broj;
		Elem* sled;
		Elem(int br, Elem* s=nullptr) : broj(br), sled(s) {};

	};

	Elem* prvi, * posl;
	int duz;

	void kopiraj(const Red& r) {
		Elem* temp = r.prvi;

		while (temp)
		{
			posl = (prvi ? posl->sled : prvi) = new Elem(temp->broj);
			temp = temp->sled;

		}


	}

	void premesti(Red& r) {
		duz = r.duz;
		prvi = r.prvi;
		posl = r.posl;
		r.prvi = nullptr;
		r.posl = nullptr;
	}

	void brisi() {
		while (prvi)
		{
			Elem* old = prvi;
			prvi = prvi->sled;
			delete old;
		}
		prvi = nullptr;
		posl = nullptr;
		duz = 0;
	}

public:
	Red() : duz(0), prvi(nullptr), posl(nullptr) {};
	Red(int br) : duz(1) {
		prvi = new Elem(br);
		posl = prvi;
	}

	Red(const Red& r) { kopiraj(r); }
	Red(Red&& r) { premesti(r); }

	Red& operator=(const Red& r) {
		if (this!=&r)
		{
			brisi();
			kopiraj(r);
		}
		return *this;
	}

	~Red()
	{
		brisi();
	}

	int getDuz() const {
		return duz;
	}

	bool prazan() const {
		return duz == 0;
	}

	Red& operator+=(const Red& r) {
		Red s(r);
		
		posl=(prvi ? posl->sled : prvi) = s.prvi;

		posl = s.posl;

		s.prvi = s.posl = nullptr;

		duz += r.duz;

		return *this;
	}

	Red operator-(int k) {
		Red r;
		for (Elem* temp = prvi; temp ; temp=temp->sled)
		{
			if (temp->broj!=k)
			{
				r += temp->broj;
			}

		}

		return r;
	}

	Red& operator-=(int k) {
		
		return *this=*this-k;
	}

	void pisi(ostream& it) {
		Elem* temp = prvi;
		while (temp)
		{
			it << temp->broj<<" ";
			temp = temp->sled;
		}


	}

	Red& citaj(int n) {
		for (int i = 0; i < n; i++)
		{
			int br;
			cin >> br;
			posl = (prvi ? posl->sled : prvi) = new Elem(br);

		}

		return *this;
	}

	int front() const {
		return prvi->broj;
	}

	int get() {
		int b = prvi->broj;
		Elem* temp = prvi;
		prvi = temp->sled;

		
		return b;
	}
	

	friend ostream& operator<<(ostream& it, Red& r) {
		r.pisi(it);
		return it;

	}
};


class Tekst {

	char* niz;

	void kopiraj(const char* t) {
		niz = new char[strlen(t)+1];
		strcpy(niz, t);
	}

	void premesti(Tekst& t) {
		niz = t.niz;
		t.niz = nullptr;

	}

	void brisi() {
		delete[] niz;
	}

public:

	Tekst() : niz(nullptr) {};
	Tekst(const char* t) {
		kopiraj(t);
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
		if (this != &t)
		{
			brisi();
			premesti(t);
		}
		return *this;
	}

	int duz() const {
		return strlen(niz);
	}

	friend Tekst operator+(const Tekst& t1, const Tekst& t2) {
		Tekst t;
		t.niz = new char[t1.duz() + t2.duz()+1];
		strcpy(t.niz, t1.niz);
		strcat(t.niz, t2.niz);

		return t;
	}

	char& operator[](int i) {
		return niz[i];
	}

	Tekst& operator+=(const Tekst& t) {
		return *this = *this + t;
	}

	Tekst operator()(int i, int j) {
		if (i<0 || j<i || this->duz()<=j)
		{
			exit(1);
		}
		Tekst t;
		int d = j-i + 1;
		t.niz = new char[d + 1];
		strncpy(t.niz, t.niz + i, d);
		t.niz[d] = '\0';


		return t;
	}

	friend int operator%(const Tekst& t1, const Tekst& t2) {
		int d1 = t1.duz(); int d2 = t2.duz();
		for (int i = 0; i < d1-d2+1; i++)
		{
			int j;
			for ( j = 0; j < d2 && t1.niz[i+1]==t2.niz[j]; j++)
			{
				if (j==d2)
				{
					return i;
				}
			}


		}

		return -1;
	}


	friend ostream& operator<<(ostream& it, const Tekst& t) {
		if (t.niz)
		{
			return it << t.niz << endl;
		}

	}

	friend istream& operator>>(istream& it, Tekst& t) {
		char n[80];
		it >> n;
		t = n;
		return it;

	}


};





int main(int barg, char* varg[]) {
	
	Odrednica r1("Mobilni", "Phone");
	Odrednica r2("Mobilni", "Telephone");
	Odrednica r3("Sto", "Table");
	Odrednica r4("Vecera", "Dinner");
	Odrednica r5("Olovka", "Pen");

	Recnik rec1;
	rec1 += r1;
	rec1 += r2;
	rec1 += r3;
	rec1 += r4;
	rec1 += r5;

	cout << rec1;

	Recnik rec2;
	rec2 = rec1 << "Mobilni";

	cout << "Recnik2" << endl;
	cout << rec2;




	return 0;
}