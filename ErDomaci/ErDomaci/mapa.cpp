#include "mapa.h"

void Mapa::brisi() {

	for (int i = 0; i < brVrsta; i++)
	{
		for (int j = 0; j <brKolona ; j++)
		{
			delete matrix[i][j];
		}
		delete[] matrix[i];

	}
	brKolona = 0;
	brVrsta = 0;

	delete matrix;
	matrix = nullptr;

}


void Mapa::kopiraj(const Mapa& m) {
	matrix = new Polje * *[m.brVrsta];
	for (int i = 0; i < m.brVrsta; i++)
	{
		matrix[i] = new Polje * [m.brKolona];
		for (int j = 0; j < m.brKolona; j++)
		{
			matrix[i][j] = m.matrix[i][j];
		}

	}
	brKolona = m.brKolona;
	brVrsta = m.brVrsta;


}

void Mapa::operator+=(int broj) {
	for (int i = 0; i < brVrsta; i++)
	{
		for (int j = 0; j <brKolona ; j++)
		{
			for (int k = 0; k < broj; k++)
			{
				matrix[i][j]->operator++();
			}

		}
	}


}

void Mapa::operator-=(int broj) {
	for (int i = 0; i < brVrsta; i++)
	{
		for (int j = 0; j < brKolona; j++)
		{
			for (int k = 0; k < broj; k++)
			{
				matrix[i][j]->operator--();
			}

		}
	}


}


void Mapa::zamena(int vrsta, int kolona, unsigned int gustina) {
	int n = matrix[vrsta][kolona]->getNep();
	matrix[vrsta][kolona] = new Polje_sa_sumom(gustina, n);

}


void Mapa::zamena(int vrsta, int kolona, VrstaPuta vp) {
	int n = matrix[vrsta][kolona]->getNep();

	matrix[vrsta][kolona] = new Polje_sa_putem(vp,n);

}


void Mapa::premesti(Mapa& m) {
	matrix = m.matrix;
	brVrsta = m.brVrsta;
	brKolona = m.brKolona;
	m.matrix = nullptr;
	m.brKolona = 0; m.brVrsta = 0;
	

}