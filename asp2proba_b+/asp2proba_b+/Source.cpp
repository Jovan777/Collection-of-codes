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
	//u jednom redu ima 6 podataka razdvojenih sa |
	string prim;
	string dva, tri, cetiri, pet, sest;

	cout << "Unesite ime fajla : ";
	string unos;
	cin >> unos;
	unos += ".txt";

	ifstream file(unos);
	string str;
	char c;

	long long int idKey;

	long long int niz[100];
	int n = 0;
	int b = 10;
	char* end;

	Lista lst;


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

	//cout << endl << endl<<endl;

	for (int i = 0; i < n; i++)
	{
		//cout << niz[i]+10 << endl;
	}
	//cout << endl << endl << endl<<endl<<endl;

	//lst.pisi();

	Lista::Elem* temp = lst.prvi;
	Lista::Elem* temp2 = lst.prvi;

	while (temp)
	{
		//cout << temp->broj << endl << temp->podatak << endl;
		temp = temp->sled;
	}

	//cout << n;

	Podatak* nizP = new Podatak[n];
	temp = lst.prvi;
	long long int* nizLong = new long long int[n];
	string* nizString = new string[n];


	for (int i = 0; i < n; i++)
	{
		nizP[i].primKey = temp->broj;
		nizP[i].info = temp->podatak;
		nizLong[i] = temp->broj;
		nizString[i] = temp->podatak;


		temp = temp->sled;

	}


	for (int i = 0; i < n; i++)
	{
		//cout << nizP[i].primKey << endl << nizP[i].info << endl;
	}

	/*
	string brojS = "9876543210";
	const char* numberString = brojS.c_str();

	long long int number;

	number = strtoll(numberString, &end, b);

	cout << number << endl;
	*/



	/*
	if (getline(file, prim, '|') && getline(file, dva, '|') && getline(file, tri, '|') &&
		getline(file, cetiri, '|') && getline(file, pet, '|') && getline(file, sest, '\n'))
	{
		cout << prim << endl << dva << endl<<tri<<endl << cetiri << endl << pet << endl << sest << endl;
	}

	string pun = prim + "|" + dva + "|" + tri + "|" + cetiri + "|" + pet + "|" + sest + "\n";

	cout << endl<<pun<<endl;
	*/



	/*
	ifstream file ("text.txt");
	string str;
	while (getline(file, str))
	{
		cout << str << endl;
	}
	*/


	int stepen;
	cout << "Stepen : ";
	cin >> stepen;

	char chr;
	BStablo stablo(stepen);

	/*
	cout << "NIZOVI" << endl;
	for (int i = 0; i < n; i++)
	{
		cout << nizLong[i] << endl;
		cout << nizString[i] << endl;
	}
	cout << "NIZOVI" << endl;

	cout << endl;
	cout << endl;
	cout << endl;
	*/



	/*
	stablo.dodaj(43000000001);
	stablo.dodaj(43000000002);
	stablo.dodaj(43000000003);
	stablo.dodaj(43000000004);
	stablo.dodaj(43000000005);
	stablo.dodaj(43000000006);
	stablo.dodaj(43000000011);
	stablo.dodaj(43000000012);
	stablo.dodaj(43000000013);

	stablo.dodaj(43000000014);

	stablo.ubaciInfo(43000000001, "43000000001|4300000001|4300000001|Joshua Fowle Savings Account|1|6334235.05");
	stablo.ubaciInfo(43000000002, "43000000002|4300000003|4300000001|Joshua Fowle Play Money|2|2731646.43");
	stablo.ubaciInfo(43000000003, "43000000003|4300000004|4300000001|Joshua Fowle Emergency Expenses|2|7625683.59");
	stablo.ubaciInfo(43000000004, "43000000004|4300000005|4300000001|Joshua Fowle Vacation Account|2|79823.44");
	stablo.ubaciInfo(43000000005, "43000000005|4300000010|4300000001|Joshua Fowle Healthcare Fund|2|1104436.03");
	stablo.ubaciInfo(43000000006, "43000000006|4300000008|4300000001|Joshua Fowle New Car Account|1|1594842.08");
	stablo.ubaciInfo(43000000011, "43000000011|4300000004|4300000002|Willie Swigert Joint Account|1|-9093725.95");
	stablo.ubaciInfo(43000000012, "43000000012|4300000003|4300000002|Willie Swigert Business Account|1|9288893.44");
	stablo.ubaciInfo(43000000013, "43000000013|4300000007|4300000002|Willie Swigert College Fund|1|8096128.80");
	stablo.ubaciInfo(43000000014, "43000000014|4300000006|4300000002|Willie Swigert Flexible Spending|0|9638415.62");

	stablo.prikaziStablo(stablo.koren);

	cout << endl << endl << endl << endl << endl;

	stablo.ukloniCvor(43000000002);

	//node.pronadjiKljuc(43000000005);

	stablo.prikaziStablo(stablo.koren);



	cout << endl << endl << endl << endl << endl;

	long long int nizLong1[3];
	nizLong1[0] = 43000000001;
	nizLong1[1] = 43000000005;
	nizLong1[2] = 43000000014;


	ofstream izlaz1;
	izlaz1.open("text1.txt");
	int sumK = 0;
	int nk;


	for (int i = 0; i < 3; i++)
	{
		str=stablo.pronadjiKljuc(nizLong1[i], nk);
		sumK += nk;
		cout << str << endl;
		izlaz1 << str<<endl;

	}
	cout << "Ukupno za pretragu : " << sumK << endl;
	izlaz1.close();



	cout << endl << endl<<endl;

	ofstream izlaz2;

	long long int pkljuc = 43000000003;

	int su = 5;

	izlaz2.open("text2.txt");

	stablo.pronadjiIndex(43000000003, 7, izlaz2);

	*/


	/*
	for (int i = 0; i < 10; i++)
	{
		stablo.dodaj(nizP[i].primKey);

	}

	for (int i = 0; i < 10; i++)
	{
		stablo.ubaciInfo(nizP[i].primKey, nizP[i].info);

	}
	*/

	//stablo.prikaziStablo(stablo.koren);

	int izbor;
	cout << endl;
	while (true)
	{


		cout << "=======================MENI======================" << endl;
		cout << "1.Formiranje stabla            4.Brisanje kljuca" << endl;
		cout << "2.Ispis stabla                 5.Pretraga n kljuceva" << endl;
		cout << "3.Dodaj novi kljuc             6.Pretraga n sukcesivnih kljuceva" << endl;
		cout << "                      0.Kraj" << endl;

		cin >> izbor;


		if (izbor == 1)
		{
			for (int i = 0; i < n; i++)
			{
				stablo.dodaj(nizP[i].primKey);

			}

			for (int i = 0; i < n; i++)
			{
				stablo.ubaciInfo(nizP[i].primKey, nizP[i].info);

			}



		}

		if (izbor == 2)  ///prikazivanje stabla
		{
			stablo.prikaziStablo(stablo.koren);
		}

		if (izbor == 3) ///dodavanje kljuca u stablo
		{

			getchar();
			cout << "Unesite podatak : ";
			string noviPod;
			getline(cin, noviPod);

			//cout << noviPod << endl;
			//cout << noviPod.length() << endl;

			const char* broj = noviPod.c_str();

			int i = 0;
			char* pKey = new char[10];

			for (int i = 0; i < 11; i++)
			{
				if (broj[i] == '|')
				{
					break;
				}
				pKey[i] = broj[i];

			}

			char* end;

			long long int pKljuc = strtoll(pKey, &end, 10);

			stablo.dodaj(pKljuc);
			stablo.ubaciInfo(pKljuc, noviPod);



		}

		if (izbor == 4) //uklanjanje cvora
		{
			getchar();
			cout << "Unesite primarni kljuc : ";
			string obrisani;
			getline(cin, obrisani);

			const char* delKljuc = obrisani.c_str();

			long long int del = strtoll(delKljuc, &end, 10);

			//cout << del + 10 << endl;
			int l;
			string stari = stablo.pronadjiKljuc(del, l);
			cout << "Brisanje podatka : " << stari << endl;
			stablo.ukloniCvor(del);


		}

		if (izbor == 5)
		{
			getchar();
			cout << "Unesite broj primarnih kljuceva za pretragu : ";
			cin >> n;
			long long int* nizPrimarnih = new long long int[n];
			for (int i = 0; i < n; i++)
			{
				cout << "Unosenje kljuca " << i + 1 << " : ";
				cin >> nizPrimarnih[i];
			}



			ofstream izlaz1;
			izlaz1.open("text1.txt");
			int sumK = 0;
			int nk;


			for (int i = 0; i < n; i++)
			{
				str = stablo.pronadjiKljuc(nizPrimarnih[i], nk);
				sumK += nk;
				cout << str << endl;
				izlaz1 << str << endl;

			}
			cout << "Ukupno za pretragu : " << sumK << endl;
			izlaz1.close();



		}

		if (izbor == 6)
		{
			getchar();

			cout << "Unesite primarni kljuc : ";

			ofstream izlaz2;

			string sLong;
			getline(cin, sLong);

			const char* sKljuc = sLong.c_str();

			long long int suK = strtoll(sKljuc, &end, 10);

			cout << "Unesite broj sukcesivnih kljuceva za pretragu : ";
			cin >> n;


			izlaz2.open("text2.txt");

			stablo.pronadjiIndex(suK, n, izlaz2);



		}



		if (izbor == 0)
		{
			cout << "Kraj rada";
			break;
		}




	}


	return 0;
}