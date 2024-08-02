// selekcija.h - Klasa selekcija.

#ifndef _selekcija_h_
#define _selekcija_h_

#include "izraz.h"
using Izrazi::Izraz;
#include "naredba.h"

namespace Naredbe {
    class Selekcija : public Naredba {
       
        Izraz* usl;
        Naredba* nar1, * nar2;
        void kopiraj(const Selekcija& s) {
            usl = s.usl->kopija();
            nar1 = s.nar1->kopija();
            nar2 = s.nar2->kopija();

        }

        void brisi() {
            delete usl; delete nar1; delete nar2;
        }

        void pisi(ostream& it) const override {
            Naredba::pisi(it);
            it << "if(" << *usl << ")\n";
            int n = nivo;
            n++;
            it << *nar1; 
            n--;
            it << "else\n";
            n++;
            it << *nar2;
            n--;

        }

    public:
        Selekcija(const Izraz& usl, const Naredba& n1, const Naredba& n2) : usl(usl.kopija()), nar1(n1.kopija()), nar2(n2.kopija()) {};
        Selekcija(const Selekcija& s) {
            kopiraj(s);
        }

        Selekcija& operator=(const Selekcija& s) {
            if (this!=&s)
            {
                brisi();
                kopiraj(s);
            }
            return *this;
        }



        ~Selekcija()
        {
            brisi();
        }

        void izvrsi() const override {
            if (usl->vredn())
            {
                nar1->izvrsi();
            }
            else {
                nar2->izvrsi();
            }

        }

        Selekcija* kopija() const override {
            return new Selekcija(*this);
        }


    }; // class Selekcija
} // namespace Naredbe

#endif
