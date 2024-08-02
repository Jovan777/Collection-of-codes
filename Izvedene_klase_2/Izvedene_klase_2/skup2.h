// skup2.h - Klasa skupova apstraktnih objekata.

#ifndef _skup2_h_
#define _skup2_h_

#include "objekat.h"
#include <utility>
using std::move;

class Skup {
    struct Elem {                                     // Element skupa:
        Obj* obj;                                       // - sadržaj,
        Elem* sled;                                     // - sledeæi element,
        Elem(Obj* ob, Elem* sl = 0) : obj{ ob }, sled{ sl } {} // - konstruktor,
        ~Elem() { delete obj; }                         // - destruktor.
    };

    Elem* prvi, * posl;                      // Elementi skupa.
    void dodaj(const Obj& obj) {            // Dodavanje objekta kopiranjem.
        Elem* novi = new Elem(obj.kopija());
        posl = (posl ? posl->sled : prvi) = novi;
    }
    void dodaj(Obj&& obj) {                 // Dodavanje objekta premeštanjem.
        Elem* novi = new Elem(move(obj).kopija());
        posl = (posl ? posl->sled : prvi) = novi;
    }
    void kopiraj(const Skup& s);            // Kopiranje u skup.
    void premesti(Skup& s) {                // Premeštanje u skup.
        prvi = s.prvi; posl = s.posl;
        s.prvi = s.posl = nullptr;
    }
    void brisi();                           // Oslobaðanje memorije.

public:                                             // Stvaranje skupa:
    Skup() { prvi = posl = nullptr; }                 // - prazan skup,
    Skup(const Obj& obj)                              // - od jednog objekta,
    {
        prvi = posl = new Elem(obj.kopija());
    }
    Skup(const Skup& s) { kopiraj(s); }               // - kopiranjem,
    Skup(Skup&& s) { premesti(s); }                   // - premeštanjem.
    ~Skup() { brisi(); }                              // Uništavanje skupa.
    Skup& operator=(const Skup& s) {                  // Dodela vrednosti
        if (this != &s) { brisi(); kopiraj(s); }        //    kopiranjem.
        return *this;
    }
    Skup& operator=(Skup&& s) {                       // Dodela vrednosti
        if (this != &s) { brisi(); premesti(s); }       //    premeštanjem.
        return *this;
    }
    bool operator%(const Obj& obj) const;             // Element skupa?
    friend Skup operator+(const Skup& s1, const Skup& s2)         // Unija.
    {
        return Skup(s1) += s2;
    }
    friend Skup operator-(const Skup& s1, const Skup& s2);        // Razlika.
    friend Skup operator*(const Skup& s1, const Skup& s2);        // Presek.
    Skup& operator+=(const Skup& s);                              // Unija.
    Skup& operator-=(const Skup& s) { return *this = *this - s; } // Razlika.
    Skup& operator*=(const Skup& s) { return *this = *this * s; } // Presek.
    friend ostream& operator<<(ostream& it, const Skup& s);       // Pisanje.
};

#endif
