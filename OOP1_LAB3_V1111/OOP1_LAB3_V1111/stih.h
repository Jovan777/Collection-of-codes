#ifndef stih_h
#define stih_h

#include <iostream>
#include "rec.h"
#include <string>

using namespace std;



class Stih
{

	struct Elem {

		Rec* rec;
		Elem* sled;

		Elem(Rec* rr, Elem* s = nullptr) : rec(rr), sled(s) {};

	};

	Elem* prvi;
	Elem* posl;

	void kopirajStih(const Stih& s);

	void obrisiStih();

	void premestanje(Stih& s) {
		prvi = s.prvi;
		posl = s.posl;

		s.prvi = nullptr;
		s.posl = nullptr;
	}


public:
	
	Stih() : prvi(nullptr), posl(nullptr) {};
	///kopiranje i premestanje
	Stih(const Stih& s) {
		kopirajStih(s);
	}
	Stih(Stih&& s) {
		premestanje(s);
	}

	Stih& operator=(const Stih& s) {
		if (this!=&s)
		{
			obrisiStih();
			kopirajStih(s);
		}

		return *this;
	}

	Stih& operator=( Stih&& s) {
		if (this != &s)
		{
			obrisiStih();
			premestanje(s);
		}

		return *this;
	}



	~Stih()
	{
		obrisiStih();
	}



	void operator+=(Rec* rec) {
		posl = (prvi ? posl->sled : prvi) = new Elem(rec);
	}

	int operator+();

	int operator~() const;

	Rec* operator[](int ind);

	void operator()(int ind);

	Stih& operator()(Rec* rec, int ind);

	friend bool operator^(Stih& s1, Stih& s2);


	friend void operator>>(istream& it, Stih& s) {
		string str;
		
		getline(cin, str);
		char c;

		string temp_str = "";
		for (int i = 0; i < str.length(); i++)
		{
			c = str.at(i);
			if (c!=' ')  
			{
				temp_str += c;
			}
			else
			{
				Rec* nova_rec = new Rec(temp_str);
				s.posl = (s.prvi ? s.posl->sled : s.prvi) = new Elem(nova_rec);
				temp_str = "";
			}

		}
		Rec* nova_rec = new Rec(temp_str);
		s.posl = (s.prvi ? s.posl->sled : s.prvi) = new Elem(nova_rec);

	};

	friend ostream& operator<<(ostream& it, Stih& s) {
		for (Elem* temp = s.prvi; temp ; temp=temp->sled)
		{
			it << *temp->rec;
			if (temp->sled)
			{
				it << " ";
			}

		}
		return it << "\n";

	}






};


#endif // !stih_h
