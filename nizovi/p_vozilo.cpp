#include "p_vozilo.h"

P_vozilo::P_vozilo(const Osoba* vozac, float sop_t, int kap) : Vozilo(vozac, sop_t), kap(kap), osobe(new const Osoba*[kap]) {
	for (int i = 0; i < kap; i++)
	{
		osobe[i] = nullptr;
	}

}

bool P_vozilo::operator+=(const Osoba* o) {
	int i = 0;
	while (i<kap && osobe[i]==nullptr)
	{
		i++;
	}
	if (i==kap)
	{
		return false;
	}
	else
	{
		osobe[i] = o; return true;
	}

}


bool P_vozilo::operator-=(const Osoba* o) {
	int i = 0;
	while (i<kap && osobe[i]!=o)
	{
		i++;
	}
	if (i==kap)
	{
		return false;
	}
	osobe[i] = nullptr; return true;


}

void P_vozilo::pisi(ostream& it) const {
	Vozilo::pisi(it);
	bool prvi = true;
	it << "{ ";
	for (int i = 0; i < kap; i++)
	{
		if (osobe[i])
		{
			if (!prvi)
			{
				it << "|";
			}
			it << *osobe[i];
			prvi = false;
		}
	}
	it << " }";
}



float P_vozilo::tezina() const {
	float t = Vozilo::tezina();
	for (int i = 0; i < kap; i++)
	{
		if (osobe[i])
		{
			t += osobe[i]->getTez();
		}
	}
	return t;

}

