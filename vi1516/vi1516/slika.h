#ifndef slika_h_
#define slika_h_


#include <iostream>
using namespace std;

#include "multimedija.h"
#include <string>


class Slika : public Multimedija
{
	int visina, sirina;
	int byte;



public:
	Slika( int v, int s, int b, string i="") : Multimedija(i) {
		if (v>0 && s>0 && b>0)
		{
			visina = v;
			sirina = s;
			byte = b;
		}
		
	}

	int Multimedija::getByte() const {
		return visina * sirina * byte;
	}

	string Multimedija::getDescription()  {
		return "[" + to_string(sirina) + 'x' + to_string(visina) + "->" + to_string(byte) + ']';
	}


	




};

#endif // !slika_h_
