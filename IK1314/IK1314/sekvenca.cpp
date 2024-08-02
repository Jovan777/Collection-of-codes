#include "sekvenca.h"


namespace Naredbe {

	void Sekvenca::kopiraj(const Sekvenca& s) {
		prva = nullptr;
		posl = nullptr;
		for (Elem* temp = s.prva; temp ; temp=temp->sled)
		{
			posl = (prva ? posl->sled : prva) = new Elem(temp->nar->kopija());
		}


	}

	void Sekvenca::pisi(ostream& it) const {
		Naredba::pisi(it);
		it << "{ ";
		int n = nivo;
		n++;
		for (Elem* temp = prva; temp ; temp=temp->sled)
		{
			it << *temp->nar;
		}
		n--;
		Naredba::pisi(it);
		it << "}\n";

	}

	void Sekvenca::izvrsi() const  {
		for (Elem* temp = prva; temp  ; temp=temp->sled)
		{
			temp->nar->izvrsi();
		}
	}









}