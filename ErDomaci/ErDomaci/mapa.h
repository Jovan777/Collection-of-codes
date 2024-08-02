#ifndef mapa_h_
#define mapa_h_





#include "polje_sa_putem.h"
#include "polje_sa_sumom.h"

class Mapa
{
	Polje*** matrix;
	int brKolona;
	int brVrsta;

	void kopiraj(const Mapa& m);
	void premesti(Mapa& m);
	void brisi();



public:
	Mapa(int bV, int bK) : brKolona(bK), brVrsta(bV) {
		matrix = new Polje * *[brVrsta];
		for (int i = 0; i < brVrsta; i++)
		{
			matrix[i] = new Polje * [brKolona];
			for (int j = 0; j < brKolona; j++)
			{
				matrix[i][j] = new Polje;
			}

		}



	}

	Mapa(const Mapa& m) {
		kopiraj(m);
	}

	Mapa(Mapa&& m) {
		premesti(m);
	}

	

	Mapa& operator=(const Mapa& m) {
		if (this!=&m)
		{
			brisi();
			kopiraj(m);
		}
		return *this;
	}
	Mapa& operator=( Mapa&& m) {
		if (this != &m)
		{
			brisi();
			premesti(m);
			return *this;
		}
	}

	void zamena(int vrsta, int kolona, unsigned int gustina);
	void zamena(int vrsta, int kolona, VrstaPuta vp);

	void operator+=(int broj);
	void operator-=(int broj);

	friend ostream& operator<<(ostream& it, const Mapa& m) {
		for (int i = 0; i < m.brVrsta; i++)
		{
			for (int j = 0; j < m.brKolona; j ++)
			{
				it << *m.matrix[i][j] << "\t";
			}
		}
		return it;
	}



};

#endif // !mapa_h_
