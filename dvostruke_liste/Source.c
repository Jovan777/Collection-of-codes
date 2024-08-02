#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>


typedef struct elem{

	int broj;
	struct elem* pret;
	struct elem* sled;

}Elem;

typedef struct {

	Elem* prvi, *posl, *tek;

}Lista;


typedef enum{NAPRED, NAZAD} Smer;

Lista stvori() {

	return (Lista) { NULL, NULL, NULL };

}


void na_prvi(Lista* lst) {
	lst->tek = lst->prvi;
}

void na_posl(Lista* lst) {

	lst->tek = lst->posl;
}

void na_sled(Lista* lst) {

	if (lst->tek)
	{
		lst->tek = lst->tek->sled;
	}

}

void na_pret(Lista* lst) {

	if (lst->tek)
	{
		lst->tek = lst->tek->pret;
	}

}


void nadji_sled(Lista* lst, int b) {

	while (lst->tek && lst->tek->broj!=b)
	{
		lst->tek = lst->tek->sled;
	}


}

void nadji_pret(Lista* lst, int b) {

	while (lst->tek && lst->tek->broj != b)
	{
		lst->tek = lst->tek->pret;
	}
}

_Bool ima_tek(Lista lst) {

	return lst.tek != NULL;

}


int dohvati(Lista lst) {

	if (!lst.tek)
	{
		exit(-1);
	}
	return lst.tek->broj;
}


void promeni_tek(Lista lst, int b) {


	if (!lst.tek)
	{
		exit(-1);
	}

	lst.tek->broj = b;
}

void dodaj_poc(Lista* lst, int b) {/////dodavanje ispred prvog elementa

	Elem* novi = malloc(1 * sizeof(Elem));
	novi->broj = b;
	novi->sled = lst->prvi;
	novi->pret = NULL;
	if (!lst->prvi)
	{
		lst->posl = novi;
	}
	else
	{
		lst->prvi->pret = novi;
	}
	lst->prvi = lst->tek = novi;
}

void dodaj_kraj(Lista* lst, int b) {

	Elem* novi = malloc(1 * sizeof(Elem));
	novi->broj = b;
	novi->pret = lst->posl;
	novi->sled = NULL;
	if (!lst->posl)
	{
		lst->prvi = novi;
	}
	else
	{
		lst->posl->sled = novi;
	}
	lst->posl = lst->tek = novi;

}

void brisi_sve(Lista* lst) {

	while (lst->prvi)
	{
		Elem* stari = lst->prvi;
		lst->prvi = lst->prvi->sled;
		free(stari);
	}

	lst->posl = lst->tek = NULL;


}


void citaj(Lista* lst, int n, Smer smer) {
	brisi_sve(lst);
	for (int i = 0; i < n; i++)
	{
		int b;
		scanf("%d", &b);
		(smer == NAPRED) ? dodaj_kraj(lst, b) : dodaj_poc(lst, b);

	}

}

void pisi(Lista lst, Smer smer) {

	if (smer==NAPRED)
	{
		for (na_prvi(&lst); ima_tek(lst); na_sled(&lst))
		{
			printf("%d ", dohvati(lst));
		}

	}
	else
	{
		for (na_posl(&lst); ima_tek(lst); na_pret(&lst))
		{
			printf("%d ", dohvati(lst));
		}

	}
}


void dodaj_ispred(Lista* lst, int b) {/////dodavanje ispred tekuceg elementa

	Elem* novi = malloc(1 * sizeof(Elem));
	
	if (!lst->tek)
	{
		exit(-1);
	}

	novi->broj = b;
	novi->pret = lst->tek->pret;
	novi->sled = lst->tek;

	if (!lst->tek->pret)
	{
		lst->prvi = novi;
	}
	else
	{
		lst->tek->pret->sled = novi;
	}
	lst->tek->pret = lst->tek = novi;

}


void dodaj_iza(Lista* lst, int b) {/////dodavanje iza tekuceg elementa
	Elem* novi = malloc(1 * sizeof(Elem));
	if (!lst->tek)
	{
		exit(-1);
	}
	//povezivanje dodatog elementa sa elementima
	novi->broj = b;
	novi->sled = lst->tek->sled;
	novi->pret = lst->tek;

	//povezivanje liste sa elementom...odnosno prilagodjavanje

	if (!lst->tek->sled)
	{
		lst->posl = novi;
	}
	else
	{
		lst->tek->sled->pret = novi;
	}
	lst->tek->sled = lst->tek = novi;

}


void izbaci(Lista* lst, Smer smer) {//izbacivanje tekuceg elementa

	if (!lst->tek)
	{
		exit(-1);
	}

	Elem* stari = lst->tek;

	if (!lst->tek->pret)
	{
		lst->prvi = lst->tek->sled;
	}
	else
	{
		lst->tek->pret->sled = lst->tek->sled;
	}
	if (!lst->tek->sled)
	{
		lst->posl = lst->tek->pret;
	}
	else
	{
		lst->tek->sled->pret = lst->tek->pret;
	}

	lst->tek = (smer == NAPRED) ? lst->tek->sled : lst->tek->pret;

	free(stari);


}


//sve radi
int main() {


	Lista lst = stvori();
	while (1)
	{
		printf("Unesite n:   ");
		int n; scanf("%d", &n);
		if (n<=0)
		{
			break;
		}
		printf("Lista:       "); citaj(&lst, n, NAPRED);
		if (n==0)
		{
			putchar('\n');
		}
		printf("Izostavi:    "); int k; scanf("%d", &k);
		printf("Napred:      "); pisi(lst, NAPRED);
		putchar('\n');
		printf("Nazad:       "); pisi(lst, NAZAD);
		putchar('\n');
		

		na_prvi(&lst); nadji_sled(&lst, k);
		while (ima_tek(lst))
		{
			izbaci(&lst, NAPRED);
			nadji_sled(&lst, k);
		}
		printf("Skraceno     "); pisi(lst, NAPRED);
		printf("\n\n");

	}

	brisi_sve(&lst);
	printf("Kraj rada");

	return 0;
}