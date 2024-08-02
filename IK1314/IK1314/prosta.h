#ifndef _prosta_h_
#define _prosta_h_


#include "naredba.h"
#include "izraz.h"

using namespace Izrazi;
using namespace std;

namespace Naredbe {
	class Prosta : public Naredba {

		Izraz* izr;

		void kopiraj(const Prosta& p) {
			izr = p.izr ? p.izr->kopija() : nullptr;
		}
		void brisi() {
			delete izr;
		}
		void pisi(ostream& it) const override{
			Naredba::pisi(it);
			if (izr)
			{
				it << *izr << ";\n";
			}
		}

	public:
		Prosta(const Izraz& iz) : izr(iz.kopija()) {};
		Prosta(const Prosta& pr) {
			kopiraj(pr);
		}
		Prosta& operator=(const Prosta& pr) {
			if (this!=&pr)
			{
				brisi();
				kopiraj(pr);
			}
			return *this;
		}
		~Prosta()
		{
			brisi();
		}

		void izvrsi() const override {
			if (izr)
			{
				izr->vredn();
			}
		}

		Prosta* kopija() const override {
			return new Prosta(*this);
		}



	};



}



#endif // !_prosta_h_
