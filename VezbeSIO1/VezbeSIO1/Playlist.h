#ifndef playlist_h
#define playlist_h

#include "Pesma.h"
#include <iostream>








class Playlist
{

	int min, sek;

	struct Elem {
		Pesma* pesma;
		Elem* sled;
		Elem(Pesma* p, Elem* s = nullptr) : pesma(p), sled(s) {};


	};

	Elem* prvi, * posl;

	

public:
	Playlist() : prvi(nullptr), posl(nullptr), min(0), sek(0) {};

	void dodaj(Pesma* p) {

		posl = (prvi ? posl->sled : prvi) = new Elem(p);
		min += p->getMin();
		sek += p->getSek();
		if (sek>=60)
		{
			min++;
			sek = sek % 60;
		}


	}

	~Playlist()
	{
		while (prvi)
		{
			Elem* stari = prvi;
			prvi = prvi->sled;
			delete stari;
		}
		posl = nullptr;
	}

	void pisi() const {
		cout << "Lista - trajanje : " << min << " : " << sek << endl;
		Elem* tek = prvi;
		while (tek)
		{
			Pesma* p = tek->pesma;
			cout<< *p << endl;
			tek = tek->sled;
		}

	}

	void uredi() {
		for (Elem* tek = prvi; tek ; tek=tek->sled)
		{
			for (Elem* sled = tek->sled; sled ; sled=sled->sled)
			{
				if (tek->pesma->trajanje() > sled->pesma->trajanje())
				{
					Pesma* p = tek->pesma;
					tek->pesma = sled->pesma;
					sled->pesma = p;

				}

			}

		}


	}
	



};

#endif // !playlist_h
