// kompl2.h - Klasa kompleksnih brojeva.

#ifndef _kompl2_h_
#define _kompl2_h_

#include "objekat.h"
#include <utility>
using namespace std;

class Kompl : public Obj {
    double re, im;                                     // Sadržaj objekta.
    bool jednako(const Obj& obj) const override        // Da li su jednaki?
    {
        return re == ((Kompl&)obj).re && im == ((Kompl&)obj).im;
    }
    void pisi(ostream& it) const override             // Pisanje objekta.
    {
        it << '(' << re << ',' << im << ')';
    }
    void citaj(istream& ut) override                   // Èitanje objekta.
    {
        char zn; ut >> zn >> re >> zn >> im >> zn;
    }
public:
    Kompl(double re = 0, double im = 0) : re{ re }, im{ im } {} // Inicijalizacija.
    string klasa() const override { return "Kompl"; }  // Ime klase.
    Kompl* kopija() const& override            // Kopija objekta kopiranjem.
    {
        return new Kompl(*this);
    }
    Kompl* kopija() && override                // Kopija objekta premeštanjem.
    {
        return new Kompl(move(*this));
    }
};

#endif
