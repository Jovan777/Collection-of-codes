#ifndef _dodela_h_
#define _dodela_h_

#include "izraz.h"
#include "prom.h"

namespace Izrazi {

	class Dodela : public Izraz {

		Prom* a;
		Izraz* b;

		void pisi(ostream& it) const override {
			it << "(" << *a << "=" << *b << ")";
		}
		void kopiraj(const Dodela& d) {
			a = d.a->kopija();
			b = d.b->kopija();
		}

		void brisi() {
			delete a; delete b;
		}

	public:
		Dodela(const Prom& aa, const Izraz& bb) : a(aa.kopija()), b(bb.kopija()) {};

		Dodela(const Dodela& d) {
			kopiraj(d);
		}

		~Dodela()
		{
			brisi();
		}

		Dodela& operator=(const Dodela& d) {
			if (this!=&d)
			{
				brisi();
				kopiraj(d);
			}
			return *this;
		}

		double vredn() const override {
			return (*a = *b).vredn();
		}


		Dodela* kopija() const override {
			return new Dodela(*this);
		}


	};


}







#endif // !_dodela_h_
