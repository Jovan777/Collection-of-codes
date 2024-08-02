#include <iostream>
#include "Kvadar.h"

using namespace std;


class Tacka {

	double x, y;



public:
	Tacka(double xx=1, double yy=1) : x(xx), y(yy) {};

	void postavi(double xx, double yy) {
		x = xx;
		y = yy;
	}

	double getX() const { return x; }
	double getY() const { return y; }

	void citaj() {

		cout << "Unesite x i y : ";
		cin >> x >> y;
	
	}

	void pisi() const {
		cout << "T(" << x << "," << y << ")";
	}



};


class Red {

	int* niz;
	int kap;
	int prvi, posl, duz;

public:
	Red(int k = 10) {
		duz = prvi = posl = 0;
		niz = new int[kap = 10];

	}

	Red(const Red& rd) {
		duz = rd.duz;
		prvi = rd.prvi;
		posl = rd.posl;
		niz = new int[kap = rd.kap];
		for (int i = 0; i < kap; i++)
		{
			niz[i] = rd.niz[i];
		}

	}
	Red(Red&& rd) {
		niz = rd.niz;
		posl = rd.posl;
		prvi = rd.prvi;
		duz = rd.duz;
		kap = rd.kap;
		rd.niz = nullptr;

	}
	~Red()
	{
		delete[] niz;
	}

	void dodaj(int b) {
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

	int uzmi() {
		int b = niz[prvi++];
		if (prvi==kap)
		{
			prvi = 0;
		}
		duz--;
		return b;
	}

	bool pun() const {
		return duz == kap;
	}
	bool prazan() const { return duz == 0; }

	void pisi() const {
		for (int i = 0; i < duz; i++)
		{
			cout << niz[i] << " ";
		}
		cout << endl;
	}

	void prazni() { duz = posl = prvi = 0; }

};




class Lista {

	struct Elem {
		int broj;
		Elem* sled;
		Elem(int b, Elem* s = nullptr) : broj(b), sled(s) {};

	};
		
	Elem* prvi, * posl;

public:
	Lista() : prvi(nullptr), posl(nullptr) {};
	Lista(int b) : prvi(new Elem(b)), posl(prvi) {};
	Lista(const Lista& lst) {
		for (Elem* temp = prvi; temp ; temp=temp->sled)
		{
			posl = (prvi ? posl->sled : prvi) = new Elem(temp->broj);
		}
	}

	Lista(Lista&& lst) {
		prvi = lst.prvi;
		posl = lst.posl;
		lst.prvi = nullptr;
		lst.posl = nullptr;
	}

	~Lista()
	{
		while (prvi)
		{
			Elem* old = prvi;
			prvi = prvi->sled;
			delete old;
		}
		posl = nullptr;

	}

	int broj() const {
		int br = 0;
		for (Elem* temp = prvi; temp ; temp=temp->sled)
		{
			br++;
		}
		return br;
	}

	void pisi() const {
		Elem* temp = prvi;
		while (temp)
		{
			cout << temp->broj << " ";
			temp = temp->sled;
		}
		cout << endl;

	}

	void naKraj(int b) {
		posl = (prvi ? posl->sled : prvi) = new Elem(b);

	}

	void naPoc(int b) {
		Elem* novi = new Elem(b);
		novi->sled = prvi;
		prvi = novi;
		if (prvi==posl)
		{
			posl = novi;
		}
	}

	void citajK(int n) {
		for (int i = 0; i < n; i++)
		{
			int b;
			cin >> b;
			Elem* novi = new Elem(b);

			posl = (prvi ? posl->sled : prvi) = novi;



		}


	}


	void citajP(int n) {

		for (int i = 0; i < n; i++)
		{
			int b;
			cin >> b;
			Elem* novi = new Elem(b);
			novi->sled = prvi;
			prvi = novi;
			if (prvi == posl)
			{
				posl = novi;
			}


		}


	}

	void uredi() const{

		for (Elem* temp = prvi; temp ; temp=temp->sled)
		{
			for (Elem* sled = temp->sled; sled ; sled=sled->sled)
			{
				if (temp->broj>sled->broj)
				{
					int t = temp->broj;
					temp->broj = sled->broj;
					sled->broj = t;

				}



			}

		}



	}

	void ubaci(int b) {
		Elem* novi = new Elem(b);
		Elem* temp = prvi;
		Elem* pret = nullptr;
			while (temp->broj<b)
			{
				pret = temp;
				temp = temp->sled;
			}
			(pret ? pret->sled : prvi) = novi;
			novi->sled = temp;


		



	}

	void izostavi(int b) {

		for (Elem* temp = prvi, *pret=nullptr; temp ;)
		{
			if (temp->broj==b)
			{
				Elem* old = temp;
				temp = temp->sled;
				(pret ? pret->sled : prvi) = temp;


				delete old;
			}
			else
			{
				pret = temp;
				temp = temp->sled;
			}
			

			

			

		}




	}



};





//   5 4 2 1 6 





int main() {

	Lista l(0);
	l.citajK(5);
	l.uredi();
	l.ubaci(3);
	l.izostavi(4);


	l.pisi();

	return 0;
}