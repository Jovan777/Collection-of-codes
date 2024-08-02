#ifndef bstablo_h
#define bstablo_h





#include <climits>
#include <fstream>
#include <iostream>
#include <sstream>


using namespace std;
const int M = 3;


class Cvor {

	Cvor** cvorovi;
	friend class BStablo;
	int duz;
	int* niz;
	string* infoNiz;
	bool list;

public:
	Cvor() {
		niz = new int[M];
		infoNiz = new string[M];
		cvorovi = new Cvor * [M + 1];

	}





};




class BStablo
{
public:

	Cvor* koren;
	
	BStablo() {
		koren = NULL;
	}

	void prolaz(Cvor* temp) {

		if (temp != NULL)
		{
			for (int i = 0; i < temp->duz; i++)
			{
				cout << temp->niz[i] << "  " << "list : " << temp->list << "         ";
				//cout<<temp->infoNiz[i]<<endl;
			}
			cout << endl;
			if (temp->list == false)
			{
				for (int i = 0; i < temp->duz + 1; i++)
				{
					prolaz(temp->cvorovi[i]);
				}
			}

		}


	};
	void dodaj(int x, string info) {

		if (koren == NULL)
		{
			koren = new Cvor;
			koren->niz[0] = x;
			koren->infoNiz[0] = info;
			koren->list = true;
			koren->duz = 1;


		}
		else
		{
			Cvor* temp = koren;
			Cvor* rod = nullptr;
			while (temp->list == false)
			{
				rod = temp;
				for (int i = 0; i < temp->duz; i++)
				{
					if (x < temp->niz[i])
					{
						temp = temp->cvorovi[i];
						break;
					}
					if (i == temp->duz - 1)
					{
						temp = temp->cvorovi[i + 1];
						break;
					}

				}

			}
			if (temp->duz < M)  /// u cvoru smo u kom treba da se doda
			{
				int i = 0;
				while (x > temp->niz[i] && i < temp->duz)
				{
					i++;
				}
				for (int j = temp->duz; j > i; j--)
				{
					temp->niz[j] = temp->niz[j - 1];
					temp->infoNiz[j] = temp->infoNiz[j - 1];
				}
				temp->niz[i] = x;
				temp->infoNiz[i] = info;
				temp->duz++;
				temp->cvorovi[temp->duz] = temp->cvorovi[temp->duz - 1];
				temp->cvorovi[temp->duz - 1] = NULL;




			}
			else
			{
				Cvor* novi = new Cvor;
				int vint[M + 1];
				string vstr[M + 1];
				for (int i = 0; i < M; i++)
				{
					vint[i] = temp->niz[i];
					vstr[i] = temp->infoNiz[i];

				}
				int i = 0, j;
				while (x>vint[i] && i<M)
				{

					i++;
				}
				for ( j = M+1; j > i ; j--)
				{
					vint[j] = vint[j - 1];
					vstr[j] = vstr[j - 1];

				}

				vint[i] = x;
				vstr[i] = info;
				novi->list = true;
				novi->duz = M+ 1 - (M + 1) / 2;
				temp->duz = (M + 1) / 2;
				temp->cvorovi[temp->duz] = novi;
				novi->cvorovi[novi->duz] = temp->cvorovi[M];
				temp->cvorovi[M] = NULL;
				for ( i = 0; i < temp->duz; i++)
				{
					temp->niz[i] = vint[i];
					temp->infoNiz[i] = vstr[i];

				}
				for (i = 0, j = temp->duz; i < novi->duz; i++, j++)
				{
					novi->niz[i] = vint[j];
					novi->infoNiz[i] = vstr[j];

				}

				if (temp==koren)
				{
					Cvor* tempKoren = new Cvor;
					tempKoren->niz[0] = novi->niz[0];
					tempKoren->cvorovi[0] = temp;
					tempKoren->cvorovi[1] = novi;
					tempKoren->list = false;
					tempKoren->duz = 1;
					koren = tempKoren;





				}
				else
				{
					//ubaciUnutrasnjeg(novi->niz[0], rod, novi);
				}











			}





		}


	};
	Cvor* uzmiRoditelja(Cvor* temp, Cvor* dete) {







	};
	void ubaciUnutrasnjeg(int, Cvor* temp, Cvor* dete);

	





};

#endif // !bstablo_h
