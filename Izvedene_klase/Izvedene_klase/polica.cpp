#include "polica.h"

Polica::Polica(int brm) : knjige(new const Knjiga* [brm]), br_mesta(brm), br_knjiga(0) {
	for (int i = 0; i < br_mesta; i++)
	{
		knjige[i] = nullptr;
	}
};



bool Polica::operator+=(const Knjiga* k) {
	int i = 0;
	if (br_knjiga==br_mesta)
	{
		return false;
	}
	while (knjige[i])
	{
		i++;
	}
	knjige[i] = k;
	return true;


}


const Knjiga* Polica::operator-=(int poz) {
	if (poz<0 || poz>=br_mesta || !knjige[poz])
	{
		return nullptr;
	}

	const Knjiga* k = knjige[poz];
	knjige[poz] = nullptr;
	br_knjiga--;
	return k;


}

double Polica::uk_vrd() const {

	double v = 0;
	for (int i = 0; i < br_mesta; i++)
	{
		if (knjige[i])
		{
			v += knjige[i]->vrednost();
		}
	}

	return v;
}

ostream& operator<<(ostream& it, const Polica& p) {

	for (int i = 0; i < p.br_mesta; i++)
	{
		if (p.knjige[i])
		{
			p.knjige[i]->pisi(it);
			it << endl;
		}

	}
	it << "=========================================\n";
	it << "Ukupna vrednost : " << p.uk_vrd() << endl;

	return it;
}

