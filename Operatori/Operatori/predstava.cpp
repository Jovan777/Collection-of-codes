#include "predstava.h"

void Predstava::kopiraj(const Predstava& p) {
	naslov = p.naslov;
	datum = p.datum;
	duz_red = p.duz_red;
	br_red = p.br_red;

	karte = new Karta * *[br_red];
	for (int i = 0; i < br_red; i++)
	{
		karte[i] = new Karta * [duz_red];
		for (int j = 0; j < duz_red; j++)
		{
			karte[i][j] = p.karte[i][j] ? new Karta(*p.karte[i][j]) : nullptr;
		}

	}

}


void Predstava::brisi() {
	if (!karte)
	{
		return;
	}
	for (int i = 0; i < br_red; i++)
	{
		for (int j = 0; j < duz_red; j++)
		{
			delete karte[i][j];
		}
		delete[] karte[i];
	}

	delete[] karte;
}


bool Predstava::operator+=(const Karta& k) {
	int red = k.dohvRed();
	int sed = k.dohvSed();
	if (red < 0 || sed<0 || red>=br_red || sed>=duz_red || karte[red][sed])
	{
		return false;
	}
	karte[red][sed] = new Karta(k);
	return true;


}

float Predstava::vrednost() const {
	float v = 0;
	for (int i = 0; i < br_red; i++)
	{
		for (int j = 0; j < duz_red; j++)
		{
			if (karte[i][j])
			{
				v += karte[i][j]->dohvCenu();
			}
		}
	}

	return v;


}


ostream& operator<<(ostream& it, Predstava& p) {
	for (int i = 0; i < p.br_red; i++)
	{
		for (int j = 0; j < p.duz_red; j++)
		{
			it << (p.karte[i][j] ? "#" : "_") << " ";
		}
		it << endl;
	}

	return it;
}