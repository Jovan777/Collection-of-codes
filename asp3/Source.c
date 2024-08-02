#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

//asp graf


typedef struct elem {

	int broj;
	struct elem* next;

}Elem;


typedef struct lista {

	Elem* head;

}Lista;

typedef struct graf {

	int V;
	Lista* niz;
}Graf;


Elem* novi_cvor(int n) {

	Elem* novi = malloc(1 * sizeof(Elem));
	novi->broj = n;
	novi->next = NULL;

	return novi;
}


Graf* napravi_graf(int v) {
	Graf* graf = malloc(1 * sizeof(Graf));

	graf->V = v;

	graf->niz = (Lista*)malloc(v * sizeof(Lista));

	for (int i = 0; i < v; i++)
	{
		graf->niz[i].head = NULL;
	}


	return graf;
}

void dodaj(Graf* graf, int cvor, int broj) {


	Elem* novi = novi_cvor(broj);
	novi->next = graf->niz[cvor].head;
	graf->niz[cvor].head = novi;

}

void prosiriGraf(Graf* graf) {

	int i = graf->V;
	graf->niz[i].head = NULL;
	graf->V++;


}


void ukloni_granu2(Graf* graf, int cvor, int broj) {//radi



	Elem* lst = graf->niz[cvor].head;
	while (lst->next)
	{
		if (lst->next->broj == broj)
		{
			Elem* temp = lst;
			lst = lst->next;//u tom broju smo

			Elem* stari = lst;
			lst = lst->next;

			temp->next = lst;

			free(stari);
			break;
		}
		else
		{
			lst = lst->next;
		}


	}

}


void ukloni_cvor(Graf* graf, int cvor) {//


	for (int i = 0; i < graf->V; i++)
	{
		ukloni_granu2(graf, i, cvor);
	}

	for (int i = cvor; i < graf->V; i++)
	{
		graf->niz[i] = graf->niz[i + 1];
	}
	graf->V--;

}






void ispis(Graf* graf) {

	for (int i = 0; i < graf->V; i++)
	{
		Elem* cvor = graf->niz[i].head;
		printf("Cvor %d: ", i);
		while (cvor)
		{
			printf("%d->", cvor->broj);
			cvor = cvor->next;
		}
		printf("NULL\n");

	}
}

void brisanjeGrafa(Graf* graf) {
	if (graf)
	{
		if (graf->niz)
		{
			for (int i = 0; i < graf->V; i++)
			{
				Elem* cvor = graf->niz[i].head;
				while (cvor)
				{
					Elem* stari = cvor;
					cvor = cvor->next;
					free(stari);
				}

			}
		}
		//free(graf->niz);
	}

	free(graf);
}


int main() {

	int i;
	int j;
	int V;

	printf("Unesite broj cvorova grafa: ");
	scanf("%d", &V);
	Graf* graf = napravi_graf(V);
	putchar('\n');

	int n;
	printf("----------UNESITE OPCIJU---------\n");
	printf("1.Dodaj granu u graf\n");
	printf("2.Ukloni granu iz grafa\n");
	printf("3.Ukloni cvor iz grafa\n");
	printf("4.Prosiri graf\n");
	printf("5.Ispisi graf\n");
	printf("6.Izbrisi graf\n");

	putchar('\n');
	putchar('\n');

	scanf("%d", &n);

	while (n > 0)
	{

		if (n == 1)
		{
			printf("Unesite cvorove za povezivanje: ");
			scanf("%d %d", &i, &j);
			dodaj(graf, i, j);

			printf("\n----------UNESITE OPCIJU---------\n");
			scanf("%d", &n);

		}
		if (n == 2)
		{
			putchar('\n');
			printf("Unesite cvor i drugi cvor koji je povezan sa njim: ");
			scanf("%d %d", &i, &j);
			ukloni_granu2(graf, i, j);
			printf("\n----------UNESITE OPCIJU---------\n");
			scanf("%d", &n);
		}
		if (n == 3)
		{
			printf("\nUnesite cvor koji zelite da uklonite: ");
			scanf("%d", &i);
			ukloni_cvor(graf, i);
			printf("\n----------UNESITE OPCIJU---------\n");
			scanf("%d", &n);
		}
		if (n == 4)
		{
			prosiriGraf(graf);
			printf("\n----------UNESITE OPCIJU---------\n");
			scanf("%d", &n);
		}
		if (n == 6)
		{
			brisanjeGrafa(graf);
			break;
		}
		if (n == 5)
		{
			putchar('\n');
			ispis(graf);
			printf("\n");
			scanf("%d", &n);
			printf("\n----------UNESITE OPCIJU---------\n");
			scanf("%d", &n);
		}

	}



	printf("\nKraj rada\n");


	return 0;
}