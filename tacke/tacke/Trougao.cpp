#include "trouglovi.h"

#include<iostream>
#include<cmath>
using namespace std;


double Trougao::P() const {

	double s = O() / 2;
	return sqrt(s * (s - a) * (s - b) * (s - c));


}

bool Trougao::citaj() {
	double aa, bb, cc;
	cin >> aa >> bb >> cc;
	if (!moze(aa, bb, cc))
	{
		return false;

	}
	a = aa; b = bb; c = cc;
	return true;


}

void Trougao::pisi() const {

	cout << "Trougao ( " << a << " , " << b << " , " << c<<" )" ;

}