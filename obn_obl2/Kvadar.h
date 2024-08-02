#ifndef kvadar_h_
#define kvadar_h_




#include <cstdlib>
#include <iostream>

using namespace std;

static double Vmax;
static double Vuk;
class Kvadar
{



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

	
	/*
	static Kvadar* pravi(double a, double b, double c) {
		double V = a * b * c;
		if (a <= 0 || b <= 0 || c <= 0 || Vuk + V > Vmax)
		{
			return nullptr;
		}
		Vuk += V;
		return new Kvadar(a, b, c);


	}


	static Kvadar* citaj() {
		double a, b, c;
		cin >> a >> b >> c;
		return pravi(a, b, c);
	}
	~Kvadar()
	{
		Vuk -= a * b * c;
	}

	double V() const {
		return a * b * c;
	}
	void pisi() const {
		cout << "[" << a << "," << b << "," << c << "]";
	}

	*/





};

#endif // !kvadar_h_
