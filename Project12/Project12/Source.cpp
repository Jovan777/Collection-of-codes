#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <stdlib.h>
#include <stdio.h>


using namespace std;


void redukcija(int niz[], const char maska[], int* n) {

	int i, j, k; char m;

	for ( i = j=k=0; i < *n; i++)
	{
		if (i%8==0)
		{
			m = maska[k++];
		}
		if (m%1)
		{
			niz[j++] = niz[i];
		}
		m >>= 1;


	}
	*n = j;


}

double skal_pro(const double* a, const double* b, int n) {
	return n ? (*a) * (*b) + skal_pro(a + 1, b + 1, n - 1) : 0;
}


typedef struct {
	int vel;
	double* niz;

}Skup;


Skup presek(Skup s1, Skup s2) {

	int velicina = s1.vel > s2.vel ? s1.vel : s2.vel;
	double* niz =(double*) malloc(velicina * sizeof(double));
	int k = 0;
	for (int i = 0; i < s1.vel; i++)
	{
		int j = 0;
		while (j<s2.vel && s2.niz[j]!=s1.niz[i])
		{
			j++;
		}
		if (j<s2.vel)
		{
			niz[k++] = s2.niz[j];
		}

	}

	Skup s = { k,(double*) realloc(niz, k * sizeof(double)) };
	return s;

}

typedef struct elem {
	float broj;
	struct elem* sled;

}Elem;


Elem* obrni(Elem* lista) {

	Elem* tek = lista, * pret = NULL, * sled;

	while (tek)
	{
		sled = tek->sled;
		tek->sled = pret;
		pret = tek;
		tek = sled;

	}

	return pret;
}

Elem* citaj() {

	Elem* head = nullptr, * last = head , * tek = nullptr;
	int broj;

	while (true)
	{
	
		cin >> broj;
		if (broj==999)
		{
			break;
		}
		tek = new Elem;
		tek->broj = broj;
		tek->sled = nullptr;
		if (!head)
		{
			head = tek;
		}
		else
		{
			last->sled = tek;
		}
		last = tek;





	}

	return head;
}

void pisi(Elem* niz) {

	Elem* tek = niz;
	while (tek)
	{
		cout << tek->broj << " ";
		tek = tek->sled;
	}


}

void zameni(int& x, int& y) {

	int t = x;
	x = y;
	y = t;

}

int podeli(int a[], int n) {

	int& b = a[n - 1], i = -1, j = n - 1;
	while (i<j)
	{
		do
		{
			i++;
		} while (a[i]<b);
		do
		{
			j--;
		} while (j >= 0 && a[j] > b);

		zameni(a[i], (i < j) ? a[j] : b);
	}

	return i;

}

void uredi(int a[], int n) {
	if (n>1)
	{
		int i = podeli(a, n);
		uredi(a, i);
		uredi(a + i + 1, n - i - 1);

	}

}



void brisi(Elem* lst) {

	while (lst)
	{
		Elem* stari = lst;
		lst = lst->sled;
		delete stari;
	}

}


double P(double a, double b, double c) {
	double s = (a + b + c) / 2;
	return sqrt(s * (s - a) * (s - b) * (s - c));
}


struct Red {
	Elem* prvi, * posl;


};
inline Red pravi() {
	Red r;
	r.prvi = nullptr, r.posl = r.prvi;
	return r;

}
inline bool prazan(const Red& r) {
	return r.prvi == nullptr;
}

void dodaj(Red& r, int n) {

	Elem* novi = new Elem;
	novi->broj = n;
	novi->sled = nullptr;

	if (!r.prvi)
	{
		r.prvi = novi;
	}
	else
	{
		r.posl->sled = novi;
	}
	r.posl = novi;


}


int uzmi(Red& r) {

	if (!r.prvi)
	{
		exit(1);
	}
	int b = r.prvi->broj;
	Elem* stari = r.prvi;
	r.prvi = r.prvi->sled;
	if (!r.prvi)
	{
		r.posl = nullptr;
	}
	delete stari;


	return b;
}



int duz(const Red& r) {
	int d = 0;
	Elem* tek = r.prvi;
	while (tek)
	{
		d++;
		tek = tek->sled;

	}


	return d;
}




void pisi(const Red& r) {


	for (Elem* tek = r.prvi; tek ; tek=tek->sled)
	{
		cout << tek->broj << " ";
	}


}


void brisi(Red& r) {
	while (r.prvi)
	{
		Elem* stari = r.prvi;
		r.prvi = r.prvi->sled;
		delete stari;
	}

	r.posl = nullptr;
}


int main() {

	Red r = pravi();
	for (bool dalje = true; dalje; )
	{
		cout << "1.Dodaj          4.Pisi" << endl;
		cout << "2.Uzmi		 5.Brisi" << endl;
		cout << "3.Duzina         0.Kraj" << endl;
		cout << "Vas izbor : ";

		int izb; cin >> izb;
		switch (izb)
		{
		case 1:
			int b;
			cout << "Unesite broj : ";
			cin >> b;
			dodaj(r, b);
			break;
		case 2:
			if (!prazan(r))
			{
				cout << "Broj : " << uzmi(r) << endl;
			}
			else
			{
				cout << "Red je prazan" << endl;
			}
			break;

		case 3:
			cout << "Duzina : " << duz(r) << endl;
			break;
		case 4:
			cout << "Red : ";
			pisi(r);
			cout << endl;
			break;
		case 5:
			brisi(r);
			break;
		case 0:
			dalje = false;
			break;

		default:
			cout << "Nevalidan izbor" << endl;
			break;
		}




	}




	return 0;
}
