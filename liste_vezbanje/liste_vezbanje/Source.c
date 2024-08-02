#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

/*
typedef struct elem {

	int broj;
	struct elem* sled;

}Elem;


int duz(Elem* lst) {

	int duz = 0;
	while (lst)
	{
		duz++;
		lst = lst->sled;

	}

	return duz;
}

void pisi_l(Elem* lst) {

	while (lst)
	{
		printf("%d->", lst->broj);
		lst = lst->sled;
	}

	printf("NULL\n");
}

Elem* na_pocetak(Elem* lst, int n) {

	Elem* novi = malloc(sizeof(Elem));
	novi->broj = n;
	novi->sled = lst;
	lst = novi;

	return lst;
}

Elem* na_kraj(Elem* lst, int n) {

	Elem* novi = malloc(sizeof(Elem));
	novi->broj = n;
	novi->sled = NULL;
	Elem* tek = lst;
	while (tek->sled)
	{
		tek = tek->sled;
	}
	tek->sled = novi;


	return lst;
}

Elem* citaj2(int n) {

	Elem* prvi = NULL;
	Elem* posl = NULL;
	for (int i = 0; i < n; i++)
	{
		Elem* novi = malloc(sizeof(Elem));
		scanf("%d", &novi->broj);
		novi->sled = NULL;
		if (prvi==NULL)
		{
			prvi = novi;
		}
		else
		{
			posl->sled = novi;
		}
		posl = novi;

	}


	return prvi;
}


Elem* citaj1(int n) {

	Elem* prvi = NULL;
	for (int i = 0; i < n; i++)
	{
		Elem* novi = malloc(sizeof(Elem));
		scanf("%d", &novi->broj);
		novi->sled = prvi;
		prvi = novi;

	}

	return prvi;
}

Elem* concatenate(Elem* lst1, Elem* lst2) {

	Elem* tek = lst1;
	while (tek->sled)
	{
		tek = tek->sled;
	}
	tek->sled = lst2;


	return lst1;

}

Elem* umetni(Elem* lst, int n){

	Elem* novi = malloc(sizeof(Elem));
	novi->broj = n;
	Elem* tek = lst, * pret = NULL;
	while (tek && tek->broj < n)
	{
		pret = tek;
		tek = tek->sled;
	}
	novi->sled = tek;
	if (!pret)
	{
		lst = novi;
	}
	else
	{
		pret->sled = novi;
	}


	return lst;
}

void brisi(Elem* lst) {

	while (lst)
	{
		Elem* stari = lst;
		lst = lst->sled;
		free(stari);
	}
}

Elem* izostavi(Elem* lst, int n) {
	Elem* tek = lst, * pret = NULL;
	while (tek)
	{
		if (tek->broj!=n)
		{
			pret = tek;
			tek = tek->sled;
		}
		else
		{
			Elem* stari = tek;
			tek = tek->sled;
			if (!pret)
			{
				lst = tek;
			}
			else
			{
				pret->sled = tek;
			}
			free(stari);


		}
	}

	return lst;
}

Elem* obrni(Elem* lst) {
	Elem* tek = lst, * pret = NULL;
	while (tek)
	{
		Elem* sled = tek->sled;
		tek->sled = pret;
		pret = tek;
		tek = sled;


	}

	return pret;
}


void uredi(Elem* lst) {
	for (Elem* i = lst; i; i = i->sled)
	{
		for (Elem* j = i->sled; j; j = j->sled)
		{
			if (i->broj > j->broj)
			{
				int t = i->broj;
				i->broj = j->broj;
				j->broj = t;

			}

		}

	}


}

Elem* fuzija(Elem* lst1, Elem* lst2) {

	Elem* lst = NULL, * posl = NULL, * tek;
	while (lst1 && lst2)
	{
		if (lst1->broj < lst2->broj)
		{
			tek = lst1;
			lst1 = lst1->sled;
		}
		else
		{
			tek = lst2;
			lst2 = lst2->sled;
		}
		tek->sled = NULL;
		if (!lst)
		{
			lst = tek;
		}
		else
		{
			posl->sled = tek;
		}
		posl = tek;

	}

	if (lst1)
	{
		if (!lst)
		{
			lst = lst1;
		}
		else
		{
			posl->sled = lst1;
		}
	}
	else
	{
		if (!lst)
		{
			lst = lst2;
		}
		else
		{
			posl->sled = lst2;
		}

	}



	return lst;
}
*/

/*
typedef struct {

	int* niz, kap, vrh;

}Stek;

Stek stvori(int k) {

	//return (Stek) { malloc(k * sizeof(int)), k, 0 };

	Stek s;
	s.niz = malloc(k * sizeof(int));
	s.kap = k;
	s.vrh = 0;

	return s;
}

int uzmi(Stek* stk){

	if (stk->vrh==0)
	{
		exit(2);
	}
	return stk->niz[--stk->vrh];

}

void stavi(Stek* stk, int n) {
	if (stk->vrh == stk->kap)
	{
		exit(1);
	}
	stk->niz[stk->vrh++] = n;

}

int prazan(Stek stk) {

	return stk.vrh == 0;
}

int pun(Stek stk) {

	return stk.vrh == stk.kap;

}

void pisi(Stek stk) {

	for (int i = stk.vrh; i > 0; printf("%d ", stk.niz[--i]));

}

void prazni(Stek* stk) {

	stk->vrh = 0;

}

void unisti(Stek* stk) {

	free(stk->niz);
}
*/

/*
typedef struct elem {
	int broj;
	struct elem* sled;

}Elem;

typedef Elem* Stek;


Stek stvori_s(void) {

	return NULL;
}

void stavi_s(Stek* stk, int b) {
	Elem* novi = malloc(sizeof(Elem));
	novi->broj = b;
	novi->sled = *stk;
	*stk = novi;

}

int uzmi_s(Stek* stk) {

	if (*stk==NULL)
	{
		exit(2);
	}
	int b = (*stk)->broj;
	Elem* stari = *stk;
	*stk = (*stk)->sled;
	free(stari);

	return b;
}

int prazan_s(Stek stk) {
	return stk == NULL;
}

void pisi_s(Stek stk) {

	for (Elem* tek = stk; tek; tek = tek->sled)
	{
		printf("%d ", tek->broj);
	}

}

void prazni(Stek* stk) {

	while (*stk)
	{
		Elem* stari = *stk;
		(*stk) = (*stk)->sled;
		free(stari);

	}

}

void unisti(Stek* stk) {
	prazni(stk);
}



typedef struct {

	int* niz, kap, duz, prvi, posl;

}red;

red stvori(int k) {

	red r;
	r.niz = malloc(k * sizeof(int));
	r.kap = k;
	r.duz = 0;
	r.prvi = 0;
	r.posl = 0;

	return r;
}

void stavi(red* rd, int b) {

	if (rd->duz==rd->kap)
	{
		exit(1);
	}
	rd->niz[rd->posl++] = b;
	rd->duz++;
	if (rd->posl == rd->kap)
	{
		rd->posl = 0;
	}

}

int uzmi(red* rd) {

	if (rd->duz==0)
	{
		exit(2);
	}

	int b = rd->niz[rd->prvi++];
	rd->duz--;
	if (rd->prvi == rd->kap)
	{
		rd->prvi = 0;
	}

	return b;
}

_Bool prazan(red rd) {

	return rd.duz == 0;
}
_Bool pun(red rd) {

	return rd.duz == rd.kap;
}

void pisi(red rd) {

	for (int i = 0; i < rd.duz; i++)
	{
		printf("%d ", rd.niz[rd.prvi + i] % rd.kap);
	}

}

*/


typedef struct elem {
	int broj;
	struct elem* sled;

}Elem;

typedef struct {

	Elem* prvi, * posl;

}Red;

Red stvori() {

	Red rd;
	rd.posl = NULL;
	rd.prvi = NULL;

	return rd;
}

void stavi(Red* rd, int b) {

	Elem* novi = malloc(sizeof(Elem));
	novi->broj = b;
	novi->sled = NULL;
	if (!rd->posl)
	{
		rd->prvi = novi;
	}
	else
	{
		rd->posl->sled = novi;
	}
	rd->posl = novi;

}


int uzmi(Red* rd) {

	if (!rd->prvi)
	{
		exit(2);
	}
	int b = rd->prvi->broj;
	Elem* stari = rd->prvi;
	rd->prvi = rd->prvi->sled;
	free(stari);
	if (!rd->prvi)
	{
		rd->posl = NULL;
	}

	return b;
}

_Bool prazan(Red rd) {

	return rd.prvi == NULL;
}

void pisi(Red rd) {

	for (Elem* tek = rd.prvi; tek ; tek=tek->sled)
	{
		printf("%d ", tek->broj);
	}

}



int main() {

	/*
	int n = 5;

	//1 2 3 4 5 

	printf("Unesite elemente prve liste:\n");
	Elem* head = citaj2(n);
	printf("Unesite elemente druge liste:\n");
	Elem* head2 = citaj2(n);
	pisi(head);
	pisi(head2);
	Elem* head3 = fuzija(head, head2);
	pisi(head3);
	*/

	Red rd = stvori();
	_Bool kraj = 0;
	while (!kraj)
	{


		printf("\n1.Stvaranje steka\n"
			"2.Stavljanje podataka na stek\n"
			"3.Uzimanje podataka sa steka\n"
			"4.Ispisivanje\n"
			"5.Praznjenje\n"
			"0.Kraj rada\n"
			"Vas izbor?\n");

		int izbor;
		scanf("%d", &izbor);
		switch (izbor)
		{

		case 1:
				printf("Broj: ");
				int b;
				scanf("%d", &b);
				stavi(&rd, b);
			

			break;

		case 2:
			if (!prazan(rd))
			{
				printf("Broj: %d\n", uzmi(&rd));
			}
			else
			{
				printf("Red je prazan\n");
			}

			break;

		case 3:
			printf("Red:  ");
			pisi(rd);
			putchar('\n');

			break;

		case 0:
			kraj = 1; //kraj rada
			break;

		default:
			printf("Nedozvoljen izbor\n");
			break;
		}


	}


	return 0;
}