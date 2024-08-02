#ifndef _krug2_h_
#define _krug2_h_
#include "figura1.h"


class Krug : public Figura {
    double r;                                            // Polupreènik kruga.
public:
    Krug(double r = 1, const Tacka& t = ORG)                 // Konstruktor.
        : Figura(t), r{ r } {}
    double O() const override { return 2 * r * PI; }     // Obim kruga.
    double P() const override { return r * r * PI; }     // Površina kruga.
    Krug* kopija() const override                      // Kopija kruga.
    {
        return new Krug(*this);
    }
private:
    void citaj(istream& ut) override                   // Èitanje kruga.
    {
        Figura::citaj(ut); ut >> r;
    }
    void pisi(ostream& it) const override {           // Pisanje kruga.
        it << "krug    ["; Figura::pisi(it);
        it << ", r=" << r << ", O=" << O() << ", P=" << P() << ']';
    }
};







#endif // !_krug2_h_
