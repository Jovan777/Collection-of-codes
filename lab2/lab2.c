#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Node
{
	int id;
	int nivo;
	int magicni;
	int savrseni;
	int* used;
	int** matrix;
	struct Node* roditelj;
	struct Node** potomak;
};
typedef struct Node node;

struct Element {

	node* value;
	struct element* sledeci;
};
typedef struct Element elem;



int main() {
	



	return 0;
}


elem* newEl(node* data) {//
	elem* new = malloc(sizeof(elem));
	new->value = data;
	new->sledeci = NULL;
	return new;
}

node* newNode(int n) {

	node* new = malloc(sizeof(node));
	new->matrix = malloc(n * sizeof(int*));
	new->potomak = malloc((n * n) * sizeof(node*));
	new->roditelj = NULL;
	new->used = calloc((n * n), sizeof(int));
	new->id = 0;
	new->nivo = 0;
	new->magicni = -1;
	new->savrseni = -1;

	return new;
}

void push_insert(elem** prvi, node* broj) {//

	elem* novi = newEl(broj);
	if (*prvi == NULL) {
		*prvi = novi;
		return;
	}
	novi->sledeci = *prvi;
	*prvi = novi;
	return;
}
void stek(elem** prvi) {
	if ((*prvi) == NULL)
	{
		return NULL;
	}
	node* t = (*prvi)->value;
	(*prvi) = (*prvi)->sledeci;
	return t;

}


/*
node* DELETE_QUEUE(elem** prvi)//
{
	if ((*prvi) == NULL) return NULL;
	if ((*prvi)->sledeci == NULL)
	{
		node* tmp = (*prvi)->value;
		*prvi = NULL;
		return tmp;
	}

	elem* tail = *prvi;
	while (tail->sledeci != NULL) {
		tail = tail->sledeci;
	}
	tail = tail->sledeci;
	elem* tmp = tail->value;
	tail->sledeci = NULL;
	return tmp;
}
*/
node* POP_STACK(elem** prvi)
{
	if ((*prvi) == NULL) return NULL;
	node* t = (*prvi)->value;
	(*prvi) = (*prvi)->sledeci;
	return t;
}
node* DELETE_QUEUE(elem** prvi)
{
	if ((*prvi) == NULL) return NULL;
	if ((*prvi)->sledeci == NULL)
	{
		node* t = (*prvi)->value;
		*prvi = NULL;
		return t;
	}
	elem* x = *prvi;
	while (x->sledeci != NULL) x = x->sledeci;
	
	elem* t = x->value;
	x->sledeci = NULL;
	return t;
}


node* start(node* koren, int* n) {//
	printf("Unesite dimenzije matrice:\n");
	scanf("%d", n);
	int brojevi = calloc((*n) * (*n), sizeof(int));
	printf("\nUnesite brojeve:\n");
	for (int i = 0; i < (*n)*(*n); i++)
	{
		scanf("%d", &brojevi[(int*)i]);
	}
	koren = newNode(*n);
	printf("\nUnesite inc stanje:\n");
	for (int i = 0; i < *n; i++)
	{
		(koren->matrix)[i] = malloc((*n) * sizeof(int));
		for (int j = 0; j < *n; j++)
		{
			scanf("%d", &((koren->matrix)[i][j]));
			for (int z = 0; z < (*n)*(*n); z++)
			{
				if (brojevi[(int*)z]==(koren->matrix)[i][j])
				{
					koren->used[z] = 1;
					break;
				}
			}
		}
	}
	koren->magicni = check(koren->matrix, *n);
	if (koren->magicni==0)
	{
		del(koren, *n);
		koren = NULL;
	}
	return koren;

}

int Msum(int n) {
	int sum = ((n * ((n * n) + 1)) / 2);

	return sum;
}

int check(int** t, int n) {//

	int sum = Msum(n);
	int suma = 0;
	int f = 0;
	int t1 = 0;

	for (int i = 0; i < n; i++)
	{
		suma = 0;
		t1 = 0;
		for (int j = 0; j < n; j++)
		{
			suma += t[i][j];
			if (t[i][j]==0)
			{
				f = 1;
				t1 = 1;
			}
		}
		if (suma>sum || (!t1 && suma!=sum))
		{
			return 0;
		}
	}
	for (int i = 0; i < n; i++)
	{
		suma = 0;
		t1 = 0;
		for (int j = 0; j < n; j++)
		{
			suma += t[j][i];
			if (t[j][i]==0)
			{
				t1 = 1;
			}
			if (suma>sum || (!t1 && suma!=sum))
			{
				return 0;
			}

		}

	}
	return f == 1 ? -1 : 1;
}

void ispis(node* t, int n) {
	if (t==NULL)
	{
		return;
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			printf("%d", t->matrix[i][j]);
		}
		printf("\n");
	}
}

int find(int* i, int* j, int n, int** matrix) {

	for ( (*i) = 0; (*i) < n; (*i)++)
	{
		for ((*j) = 0; (*j) < n; (*j)++) {
			if (matrix[*i][*j]==0)
			{
				return 1;
			}

		}
	}
	return 0;
}

int del(node* t, int n) {

	free(t->used);
	if (t->matrix != NULL) {
		for (int i = n-1; i >=0 ; i--)
		{
			free((t->matrix)[i]);
		}
	}
	free(t->matrix);
	free(t->potomak);
	free(t);
}

void ispis1(node* t, int n)
{
	if (t == NULL) return;
	for (int i = 0; i < n; i++)
	{
		for (int i = 0; i < t->nivo; i++)
			for (int j = 0; j < n; j++) printf(" ");
		for (int j = 0; j < n; j++)
			printf("%d", t->matrix[i][j]);
		printf("\n");
	}
}

void preorder(node* koren, int n, int p) {
	elem* stek = NULL;
	push_insert(&stek, koren);
	while (stek!=NULL)
	{
		node* sledeci = POP_STACK(&stek);
		if (p == 1) {
			ispis1(sledeci, n);
		}
		else
		{
			ispis(sledeci, n);
		}
		for (int i = n*n-1; i >=0 ; i--)
		{
			if (sledeci->potomak[i]!=NULL)
			{
				push_insert(&stek, sledeci->potomak[i]);
			}
		}
	}


}

void make(int n, node* koren) {
	if (koren==NULL)
	{
		return;
	}
	elem* red = NULL;
	push_insert(&red, koren);
	elem* stek = NULL;

	while (red!=NULL)
	{
		node* t = DELETE_QUEUE(&red);
		t->magicni = check(t->matrix, n);
		if (t->magicni==0)
		{
			continue;
		}
		int i = 0;
		int j = 0;
		int pom = find(&i, &j, n, t->matrix);
		for (int z = 0; z <n*n ; z++)
		{
			if (t->used[z]==0)
			{

				t->potomak[z] = newNode(n);
				t->potomak->id = z;


			}


		}


	}



}
