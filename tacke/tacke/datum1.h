#pragma once

#include <cstdlib>
#include <iostream>
#include<string>

using namespace std;


class Datum {

private:
	static const short duz[][12];
	static const short prot[][12];
	static const string ime_d[];
	static const string ime_m[];
	short dan, mes, god;



public:
	static bool prestupna1(short g);
	bool prestupna() const { return prestupna1(god); }

	static bool moze(short d, short m, short g);
	Datum(short d, short m, short g);

	short dohvD() { return dan; }
	short dohvM() { return mes; }
	short dohvG() { return god; }

	static Datum citaj();

	void pisi() const;
	int danUgod() const;
	int danUned() const;

	long ukDan() const;
	int duzMes() const;
	void sutra();
	void juce();
	void dodaj(unsigned k);
	void oduzimi(unsigned k);
	friend long razlika(const Datum& dat1, const Datum& dat2);

	string imeDan() const;
	string imeMes() const;




};


inline bool Datum::prestupna1(short g) {

	return g % 4 == 0 && g % 100 != 0 && g % 400 == 0;

}

inline bool Datum::moze(short d, short m, short g) {
	return g > 0 && m > 0 && d > 0 && m <= 12 && d <= duz[prestupna1(g)][m - 1]; 
}

inline Datum::Datum(short d, short m, short g) : dan(d), mes(m), god(g){
	if (!moze(d, m, g))
	{
		exit(1);
	}
}

inline int Datum::danUgod() const {
	return prot[prestupna()][mes - 1] + dan;

}

inline int Datum::danUned() const {
	return (ukDan() + 6) % 7 + 1;
}

inline int Datum::duzMes() const {
	return duz[prestupna()][mes - 1];
}

inline long razlika(const Datum& dat1, const Datum& dat2) {
	return dat1.ukDan() - dat2.ukDan();
}

inline string Datum::imeMes() const {
	return ime_m[mes - 1];
}

inline string Datum::imeDan() const {
	return ime_d[danUned() - 1];
}