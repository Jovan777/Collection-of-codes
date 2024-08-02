#ifndef rec_h
#define rec_h

#include <iostream>
using namespace std;

class PremasenIndeks : public exception {

public:
	const char* what() {
		return "Indeks je veci od broja elemenata u nizu";
	}

};


#include "skup.h"


class Rec
{
	Skup rec;

public:
	Rec(string str) : rec(str) {};
	


	int operator+() {
		Skup::El* temp = rec.first;
		int br = 0;
		while (temp)
		{
			br++;
			temp = temp->sled;
		}

		return br;
	}


	int operator~() ;

	char operator[](int ind);


	int operator()(int n);

	friend void operator>>(istream& it, Rec& r) {
		string str;
		it >> str;
		int k = str.length();

		
		Skup::El* temp = r.rec.first;
		while (temp)
		{
			Skup::El* st = temp;
			temp = temp->sled;
			delete st;

		}
		r.rec.first = nullptr;
		r.rec.last = nullptr;

		char c;


		for (int i = 0; i < k; i++)
		{
			c = str.at(i);
			Skup::El* novi = new Skup::El(str.at(i));

			

			r.rec.last = (r.rec.first ? r.rec.last->sled : r.rec.first) = novi;

		}
		
	}


	friend bool operator^(Rec& r1, Rec& r2) {
		int br1 = ~r1;
		int br2 = ~r2;

		int s1 = r1(-1);
		int s2 = r2(-1);

		char c1 = r1[s1];
		char c2 = r2[s2];


		if (br1 == 1 || br2 == 1)
		{
			return c1 == c2;

		}

		int s11 = r1(-2);
		int s22 = r2(-2);

		char c11 = r1[s11];
		char c22 = r2[s22];

		if (c1==c2 && c11==c22)
		{
			return true;
		}



		return false;
	
	};


	friend ostream& operator<<(ostream& it, const Rec& r) {
		Skup::El* temp = r.rec.first;
		while (temp)
		{
			cout << temp->znak;
			temp = temp->sled;
		}
		return it;
	}



};

#endif // !rec_h
