#include <cstdlib>


using std::exit;

class Trougao {

private:
	double a, b, c;

public:

	static bool moze(double a, double b, double c) {

		if (a>0 && b>0 && c>0 && (a+b)>c && (a+c)>b && (b+c)>a)
		{
			return true;
		}
		return false;
	}


	Trougao(double aa=1, double bb=1, double cc=1) {
		if (!moze(aa, bb, cc))
		{
			exit(1);
		}
		a = aa; b = bb; c = cc;

	}


	double dohvA() const { return a; }
	double dohvB() const { return b; }
	double dohvC() const { return c; }

	double O() const { return a + b + c; }
	double P() const;

	bool citaj();
	void pisi() const;




};