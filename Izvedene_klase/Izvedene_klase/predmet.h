// predmet1.h – Apstraktna klasa predmeta.

#ifndef _predmet1_h_
#define _predmet1_h_

#include <iostream>
using namespace std;

class Predmet {
    double sigma;        // Specifièna teina.
public:
    Predmet(double sigma = 1) : sigma{ sigma } {}              // Konstruktor.
    virtual double V() const = 0;                          // Zapremina.
    double q() const { return V() * sigma; }              // Teina.
protected:
    virtual void citaj(istream& ut) { ut >> sigma; }      // Èitanje.
    friend istream& operator>>(istream& ut, Predmet& p)
    {
        p.citaj(ut); return ut;
    }
    virtual void pisi(ostream& it) const { it << sigma; } // Pisanje.
    friend ostream& operator<<(ostream& it, const Predmet& p)
    {
        p.pisi(it); return it;
    }
};

#endif
