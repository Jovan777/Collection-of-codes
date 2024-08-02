// tacka5.h - Klasa pokretnih ta�aka.

#ifndef _tacka5_h_
#define _tacka5_h_

#include "pokretan.h"
#include "vektor1.h"
#include "brzina.h"

static  int pos_id2{ 0 };                  // Poslednji identifikator.


class Tacka : public Pokretan {
    const int id{ ++pos_id2 };                       // Identifikator ta�ke.
    Vektor r;                                     // Vektor polo�aja.
    Brzina v;                                     // Vektor brzine.
public:
    Tacka(const Vektor& r = Vektor(),               // Nova ta�ka dobija nov 
        const Brzina& v = Brzina())               //   identifikator.
        : r{ r }, v{ v } {}
    Tacka(const Tacka& T)                         // Kopija ta�ke dobija nov
        : r{ T.r }, v{ T.v } {}                         //   identifikator.
    Tacka& operator=(const Tacka& T)              // Levom operandu se ne
    {
        r = T.r; v = T.v; return *this;
    }         //   menja identifikator.
    Tacka& proteklo(double dt) override           // Promena polo�aja zbog
    {
        r = r + v * dt; return *this;
    }           //   proteklog vremena.
    Vektor R() const { return r; }                // Trenutni polo�aj.
    friend double rastojanje(const Tacka& T1, const Tacka& T2) // Rastojanje
    {
        return (T2.r + T1.r * -1).intenz();
    }                  //   dve ta�ke
    friend ostream& operator<<(ostream& it, const Tacka& T)   // Pisanje.
    {
        return it << 'T' << T.id << T.r;
    }
};

#endif