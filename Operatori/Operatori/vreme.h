#pragma once

#include <iostream>
using namespace std;





class Vreme {

	long t;
	using CV = const Vreme;


public:
	Vreme(int h, int m, int s) : t((h * 60L + m) * 60 + s) {};

	Vreme(long s = 0) : t(s) {};

	friend int cas(CV& v) {
		return v.t / 3600;
	}

	friend int min(CV& v) {
		return (v.t / 60) % 60;
	}

	friend int sek(CV& v) {
		return v.t % 60;
	}

	friend long Sek(CV& v) {
		return v.t;
	}

	Vreme operator+ () const { return *this; }
	Vreme operator-() const { return Vreme(-t); }

	Vreme& operator++() { ++t; return *this; }
	Vreme& operator--() { --t; return *this; }

	Vreme operator++(int) { Vreme w(*this); t++; return w; }
	Vreme operator--(int) { Vreme w(*this); t--; return w; }

	friend Vreme operator+(CV& v, CV& w) {
		return Vreme(v.t + w.t);
	}

	friend Vreme operator-(CV& v, CV& w) {
		return Vreme(v.t - w.t);
	}

	friend Vreme operator*(CV& v, int k) {
		return Vreme(v.t * k);
	}
	friend Vreme operator/(CV& v, int k) {
		return Vreme(v.t / k);
	}


	Vreme& operator+=(CV& v) {
		t += v.t;
		return *this;
	}
	Vreme& operator-=(CV& v) {
		t -= v.t;
		return *this;
	}

	Vreme& operator *=(int k) {
		t *= k;
		return *this;

	}

	Vreme& operator /=(int k) {
		t /= k;
		return *this;

	}


	friend bool operator >(CV& v, CV& w) {
		return v.t > w.t;
	}
	friend bool operator >=(CV& v, CV& w) {
		return v.t >= w.t;
	}
	friend bool operator <(CV& v, CV& w) {
		return v.t < w.t;
	}
	friend bool operator <=(CV& v, CV& w) {
		return v.t <= w.t;
	}
	friend bool operator ==(CV& v, CV& w) {
		return v.t == w.t;
	}
	friend bool operator !=(CV& v, CV& w) {
		return v.t != w.t;
	}

	friend istream& operator >>(istream& ut, Vreme& v) {
		int h, m, s;
		ut >> h >> m >> s;
		v = Vreme(h, m, s);
		return ut;

	}

	friend ostream& operator <<(ostream& ot, CV& v) {
		Vreme w(v);
		if (w.t<0)
		{
			ot << '-';
			w = -w;
		}
		return ot << cas(w) << " : " << min(w) << " : " << sek(w);
	}




};
