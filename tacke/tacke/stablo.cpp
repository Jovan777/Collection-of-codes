#include "stablo.h"


void Stablo::citaj(int n) {

	brisi(stb);
	for (int i = 0; i < n; i++)
	{
		int b;
		cin >> b;
		dodaj(b);
	}


}

void Stablo::balans(Cvor*& stb) {
	int k = vel(stb->levo) - vel(stb->desno);
	for (; k>1; k-=2)
	{
		dodaj(stb->desno, stb->broj);
		stb->broj = max(stb->levo);
		izost(stb->levo, stb->broj);


	}

	for (; k <=-1; k+=2)
	{
		dodaj(stb->levo, stb->broj);
		stb->broj = min(stb->levo);
		izost(stb->desno, stb->broj);


	}

	balans(stb->levo);
	balans(stb->desno);





}