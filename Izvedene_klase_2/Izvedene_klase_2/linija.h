// linija.h - Apstraktna klasa linija u ravni.

#ifndef _linija_h_
#define _linija_h_

#include <iostream>
using namespace std;

static  int pos_id2 = 0 ;          // Poslednji identifikator.


namespace Linije {
    class Linija {
        int id{ ++pos_id2 };                     // Identifikator linije.
    public:
        Linija() = default;                    // Nova linija dobija nov broj.
        Linija(const Linija&) {}              // Kopija dobija nov broj.
        Linija& operator=(const Linija&)      // Levom operandu se ne menja
        {
            return *this;
        }                   //   broj.
        virtual ~Linija() {}                  // Virtuelan destruktor.
        virtual double duzina() const = 0;     // Dužina linije.
        virtual Linija* kopija() const& = 0;   // Kopija linije kopiranjem.
        virtual Linija* kopija() && = 0;       // Kopija linije premeštanjem.
    protected:
        virtual void pisi(ostream& it) const { it << id; } // Pisanje linije.
        friend ostream& operator<<(ostream& it, const Linija& lin)
        {
            lin.pisi(it); return it;
        }
    };
}

#endif