#ifndef _sekvenca_h_
#define _sekvenca_h_


#include "naredba.h"

namespace Naredbe {
	class Sekvenca : public Naredba {

		struct Elem {
			Naredba* nar;
			Elem* sled;
			Elem(Naredba* n) : nar(n), sled(nullptr) {};
			~Elem()
			{
				delete nar;
				delete sled;
			}


		};
		Elem* prva, * posl;
		void kopiraj(const Sekvenca&);
		void brisi() { delete prva; }
		void pisi(ostream& it) const override;


	public:
		Sekvenca() : prva(nullptr), posl(nullptr) {};
		Sekvenca(const Sekvenca& s) {
			kopiraj(s);
		}
		~Sekvenca()
		{
			brisi();
		}

		Sekvenca& operator=(const Sekvenca& s) {
			if (this!=&s)
			{
				brisi();
				kopiraj(s);
			}
			return *this;
		}

		Sekvenca& operator+=(const Naredba& nar) {
			posl = (prva ? posl->sled : prva) = new Elem(nar.kopija());
			return *this;
		}

		void izvrsi() const override;

		Sekvenca* kopija() const override {
			return new Sekvenca(*this);
		}








	};






}




#endif // !_sekvenca_h_
