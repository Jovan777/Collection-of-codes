#ifndef kvadar_h_
#define kvadar_h_




#include <cstdlib>
#include <iostream>

using namespace std;

class Kvadar
{


	static double Vmax;
	static double Vuk;

	double a, b, c;

	Kvadar(double aa, double bb, double cc) {
		a = aa;
		b = bb;
		c = cc;
	}

public:
	//Kvadar(const Kvadar&) = delete;

	static bool postaviVmax(double maxV) {
		if (maxV < Vuk)
		{
			return false;
		}
		Vmax = maxV; return true;
	}

	static double dohvVmax() { return Vmax; }
	static double dohvVuk() { return Vuk; }


};

#endif