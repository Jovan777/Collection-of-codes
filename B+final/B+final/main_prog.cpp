#include <fstream>
#include <string>
#include <climits>
#include <fstream>
#include <iostream>
#include <sstream>
#include "bstablo.h"

using namespace std;

struct Podatak {

	long long int primKey;
	string info;


};


class Lista {



public:
	struct Elem {

		long long int broj;
		string podatak;
		Elem* sled;

		Elem(long long int b, string p, Elem* s = nullptr) : broj(b), podatak(p), sled(s) {};

	};

	Elem* prvi, * posl;

	Lista() : prvi(nullptr), posl(nullptr) {};

	Lista& dodaj(long long int idPrim, string pod) {
		posl = (prvi ? posl->sled : prvi) = new Elem(idPrim, pod);
		return *this;

	}

	void pisi() const {
		Elem* temp = prvi;
		while (temp)
		{
			cout << temp->broj << endl << temp->podatak << endl;
			temp = temp->sled;
		}


	}





};


int main() {

	string prim;
	string dva, tri, cetiri, pet, sest;


	string str;
	char c;

	cout << "Unesite ime fajla : ";
	string unos;
	cin >> unos;
	unos += ".txt";

	ifstream file(unos);

	long long int idKey;

	long long int niz[100];
	int n = 0;
	int b = 10;
	char* end;

	Lista lst;
	Lista::Elem* temp = nullptr;
	Lista::Elem* temp2 = nullptr;

	while (true)
	{
		if (getline(file, prim, '|') && getline(file, dva, '|') && getline(file, tri, '|') &&
			getline(file, cetiri, '|') && getline(file, pet, '|') && getline(file, sest, '\n'))
		{
			//cout << prim << endl << dva << endl << tri << endl << cetiri << endl << pet << endl << sest << endl;
		}
		else
		{
			break;
		}

		string pun = prim + "|" + dva + "|" + tri + "|" + cetiri + "|" + pet + "|" + sest + "\n";

		//cout << endl << pun << endl;

		const char* tekstPrim = prim.c_str();

		idKey = strtoll(tekstPrim, &end, b);
		niz[n++] = idKey;

		lst.dodaj(idKey, pun);

	}


	int stepen;
	//cout << "Unesite stepen stabla : ";

	//cin >> stepen;
	BStablo stablo(3);


	int izbor;
	cout << endl;
	while (true)
	{
		

		cout << "=======================MENI======================"<<endl;
		cout << "1.Formiranje stabla            4.Brisanje kljuca"<<endl;
		cout << "2.Ispis stabla                 5.Pretraga n kljuceva"<<endl;
		cout << "3.Dodaj novi kljuc             5.Pretraga n sukcesivnih kljuceva" << endl;
		cout << "                      0.kraj" << endl;

		cin >> izbor;
		
		switch (izbor)
		{
		case 1:
			


			
			//citanje iz fajla radi
			/* 
			temp = lst.prvi;
			while (temp)
			{
				cout << temp->broj << endl << temp->podatak << endl;
				temp = temp->sled;
			}

			cout << n;
			*/
			temp = lst.prvi;
			temp2 = lst.prvi;

			

			break;

		case 2:
			stablo.prikaziStablo(stablo.koren);
			break;



















		case 0:
			cout << "Kraj rada";
			return 0;

		}



















	}








	return 0;
}