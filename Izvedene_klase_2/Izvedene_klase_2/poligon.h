
#ifndef _poligon_h_
#define _poligon_h_

#include "izlomljena.h"

namespace Linije {
    class Poligon : public Izlomljena {
    public:
        Poligon(const Tacka* niz, int k)        // Inicijalizacija nizom taèaka.
            : Izlomljena(niz, k) {}
        double duzina() const override          // Dužina poligona.
        {
            return Izlomljena::duzina() + Duz(tem[0], tem[n - 1]).duzina();
        }
        Poligon* kopija() const& override       // Kopija poligona kopiranjem.
        {
            return new Poligon(*this);
        }
        Poligon* kopija() && override           // Kopija poligona premeštanjem.
        {
            return new Poligon(move(*this));
        }
    private:
        virtual void pisi(ostream& it) const override {  // Pisanje poligona.
            Linija::pisi(it); it << "[poligon: ";
            Tacka::pisiNiz(it, tem, n); it << ']';
        }
    };
}

#endif
