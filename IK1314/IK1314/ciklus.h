// ciklus.h - Klasa ciklusa.

#ifndef _ciklus_h_
#define _ciklus_h_

#include "izraz.h"
using Izrazi::Izraz;
#include "naredba.h"

namespace Naredbe {
    class Ciklus : public Naredba {
       
        Izraz* usl;
        Naredba* nar;

        void kopiraj(const Ciklus& c) {
            usl = c.usl->kopija();
            nar = c.nar->kopija();
        }

        void brisi() {
            delete nar;
            delete usl;
        }

        void pisi(ostream& it) const {
            Naredba::pisi(it);
            it << "while(" << *usl << ")\n";
            int n = nivo;
            n++;
            it << *nar;
            n--;

        }

    public:
        Ciklus(const Izraz& usl, const Naredba& n) : usl(usl.kopija()), nar(n.kopija()) {};
        Ciklus(const Ciklus& c) {
            kopiraj(c);
        }
        Ciklus& operator=(const Ciklus& c) {
            if (this!=&c)
            {
                brisi();
                kopiraj(c);
            }
            return *this;
        }

        ~Ciklus()
        {
            brisi();
        }

        void izvrsi() const  {
            while (usl->vredn())
            {
                nar->izvrsi();
            }

        }
        Ciklus* kopija() const {
            return new Ciklus(*this);
        }





    }; // class Ciklus
} // namespace Naredbe

#endif
