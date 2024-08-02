#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>


typedef struct elem {

	float broj;
	struct node* next;

}Elem;

Elem* napravi() {

	float n;
	Elem* head = NULL;
	Elem* last = NULL;

	while ((scanf("%f", &n)==1))
	{
		if (n<=0)
		{
			//return NULL;
			break;
		}
		Elem* novi = malloc(1 * sizeof(Elem));
		if (novi==NULL)
		{
			printf("MEM_GRESKA\n");
			exit(-1);
		}
		novi->broj = n;
		novi->next = NULL;


		if (last==NULL)
		{
			head = novi;
		}
		else
		{
			last->next = novi;
		}

		last = novi;

	}

	return head;

}

void ispis(Elem* lst) {

	if (lst==NULL)
	{
		return;
	}
	for (Elem* trenutni = lst; trenutni!=NULL; trenutni=trenutni->next)
	{
		printf("%.2f->", trenutni->broj);
	}
	printf("NULL\n");

}


void izbrisi(Elem* lst) {

	Elem* trenutni = lst;
	while (trenutni!=NULL)
	{
		Elem* stari = trenutni;
		trenutni = trenutni->next;
		free(stari);
	}
}




void obrada(Elem* lst, float kl, float kil) {

	//7.5 8.2 1.3 4.1 11 6 -5
	int flag = 1;
	Elem* trenutni = lst;
	Elem* temp = trenutni->next;

	while (trenutni) 
	{

		if (temp==NULL)
		{
			if (trenutni->broj>kl)
			{
				Elem* novi = malloc(1 * sizeof(Elem));
				if (novi == NULL)
				{
					printf("MEM_GRESKA\n");
					exit(-1);
				}
				novi->broj = trenutni->broj - kl;
				novi->next = NULL;
				trenutni->next = novi;
				trenutni->broj = kil;

			}
			ispis(lst);
			break;

		}


		if (flag==1)
		{
			ispis(lst);
			flag = 0;
		}

		if (trenutni->broj > kl)
		{

			if (temp->broj > kl)//dodajemo novi cvor
			{
				Elem* novi = malloc(1 * sizeof(Elem));
				if (novi == NULL)
				{
					printf("MEM_GRESKA\n");
					exit(-1);
				}
				novi->broj = trenutni->broj - kl;
				novi->next = NULL;
				Elem* p = trenutni->next;
				trenutni->next = novi;
				novi->next = temp;
				trenutni->broj = kil;
				flag = 1;

			}
			else
			{
				temp->broj = temp->broj + trenutni->broj - kl;
				trenutni->broj = kil;

				flag = 1;
			}

		}

		trenutni = trenutni->next;
		Elem* p = trenutni->next;
		temp = p;

	}



}


int main() {

	float lit;
	float kil;
	scanf("%f%f", &kil, &lit);
	if (lit<=0 || kil<=0)
	{
		printf("GRESKA\n");
	}
	else
	{
		Elem* lst = napravi();
		float kl = kil/lit;

		if (lst==NULL)
		{
			return 0;
		}

		obrada(lst, kl, kil);

	
		izbrisi(lst);
	}


	return 0;
}