#ifndef nota_h_
#define nota_h_


#include "Znak.h"
#include <iostream>
#include <string>

using namespace std;





class Nota : public Znak
{
	
	

public:

	enum Visina {
		DO, RE, MI, FA, SOL, LA, SI
	};


	Nota(int ok, Visina vi, Razlomak t)
		:Znak(t), oktava(ok), n(vi) {}

	Nota& operator<<=(int p) {
		if (oktava-p>=1)
		{
			oktava -= p;
		}
		return *this;

	}
	Nota& operator>>=(int p) {
		if (oktava + p <= 5)
		{
			oktava += p;
		}
		return *this;

	}

	string opis() const override {

		switch (n)
		{
		case Nota::DO:
			return "DO";
			break;
		case Nota::RE:
			return "RE";
			break;
		case Nota::MI:
			return "MI";

			break;
		case Nota::FA:
			return "FA";
			break;
		case Nota::SOL:
			return "SOl";

			break;
		case Nota::LA:
			return "LA";

			break;
		case Nota::SI:
			return "SI";

			break;
		default:
			break;
		}


	}

private:
	int oktava;
	Visina n;



};

class Pauza : public Znak {

public:
	Pauza(Razlomak t) : Znak(t) {};

	string opis() const override {
		return "_";
	}



};




#endif // !nota_h_
