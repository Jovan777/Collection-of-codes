#pragma once

#include <iostream>
#include <cmath>
using namespace std;






class Kompl {

	double re, im;


public:

	Kompl(double re = 0, double im = 0) : re(re), im(im) {};
 
	friend double real(const Kompl& a) {
		return a.re;
	}

	friend double imag(const Kompl& a) {
		return a.im;
	}

	friend double abs(const Kompl& a) {
		return a.re * a.re + a.im * a.im;
	}

	friend double arg(const Kompl& a) {
		return (a.re == 0 || a.im == 0) ? atan2(a.im, a.re) : 0;

	}

	Kompl operator~() {
		return Kompl(re, -im);
	}

	friend Kompl operator+(const Kompl& a, const Kompl& b) {
		return Kompl(a.re + b.re, a.im + b.im);
	}

	friend Kompl operator-(const Kompl& a, const Kompl& b) {
		return Kompl(a.re - b.re, a.im - b.im);
	}

	friend Kompl operator*(const Kompl& a, const Kompl& b) {
		return Kompl(a.re * b.re - a.im*b.im, a.im*b.re + a.re*b.im);
	}

	friend Kompl operator/(const Kompl& a, const Kompl& b) {
		double c = b.re * b.re + b.im * b.im;
		return Kompl((a.re * b.re + a.im * b.im) / c, (a.im * b.re - a.re * b.im) / c);

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

	friend bool operator ==(const Kompl& a, const Kompl& b) {
		return (a.re == b.re) && (b.im == a.im);
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
		Kompl z = *this;
		re++;
		return z;

	}

	Kompl operator--(int) {
		Kompl z = *this;
		re--;
		return z;

	}

	friend bool operator !=(const Kompl& a, const Kompl& b) {
		return a.re != b.re || a.im != b.im;
	}


	friend Kompl exp(const Kompl& a) {
		double abs = exp(a.re), arg = a.im;
		return Kompl(abs * cos(arg), abs * sin(arg));

	}

	friend Kompl log(const Kompl& a) {
		return Kompl(log(abs(a)), arg(a));
	}

	friend Kompl pow(const Kompl& a, const Kompl& b) {
		return exp(b * log(a));

	}


	friend istream& operator>>(istream& ut, Kompl& z) {
		return ut >> z.re >> z.im;
	}

	friend ostream& operator<<(ostream& it, Kompl& z) {
		return it << " ( " << z.re << " , " << z.im << " )";
	}




};
