#include "red2.h"
#include <iostream>
#include <cstdlib>



using namespace std;

Red::Red(int k) {
	niz = new int[kap = k];
	duz = prvi = posl = 0;
}

Red::Red(const Red& rd) {
	niz = new int[rd.kap];

	for (int i = 0; i < kap; i++)
	{
		niz[i] = rd.niz[i];
	}

	duz = rd.duz;
	prvi = rd.prvi;
	posl = rd.posl;


}

Red::Red(Red&& rd) {

	niz = rd.niz;
	duz = rd.duz; prvi = rd.prvi; posl = rd.posl; kap = rd.kap;
	rd.niz = nullptr;

}


void Red::stavi(int b) {
	if (duz==kap)
	{
		exit(1);
	}
	niz[posl++] = b;
	if (posl==kap)
	{
		posl = 0;
	}
	duz++;


}

int Red::uzmi() {
	if (duz==0)
	{
		exit(2);
	}

	int b = niz[prvi++];
	duz--;
	if (prvi==kap)
	{
		prvi = 0;
	}

	return b;

}


void Red::pisi() const {

	for (int i = 0; i < duz; i++)
	{
		cout << niz[(prvi + i)%kap] << " ";
	}


}
