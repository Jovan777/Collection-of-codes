// sfera2.h - Klasa sfera.

#ifndef _sfera2_h_
#define _sfera2_h_

#include "telo1.h"
#include <utility>
using std::move;

class Sfera : public Telo {
    double r;                                    // Polupreènik sfere.
public:
    explicit Sfera(double r = 1) : r{ r } {}          // Stvaranje sfere.
    char vrsta() const override { return 'S'; }  // Oznaka vrste tela.
    double V() const override                    // Zapremina sfere.
    {
        return 4 * r * r * r * 3.14159 / 3;
    }
    Sfera* kopija() const& override              // Kopija sfere kopiranjem.
    {
        return new Sfera(*this);
    }
    Sfera* kopija() && override                  // Kopija sfere premeštanjem.
    {
        return new Sfera(move(*this));
    }
private:
    void pisi(ostream& it) const override        // Pisanje sfere.
    {
        it << "S(" << r << ')';
    }
};

#endif
