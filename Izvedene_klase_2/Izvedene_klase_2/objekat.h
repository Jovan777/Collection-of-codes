#ifndef _objekat_h_
#define _objekat_h_

#include <iostream>
#include <string>
#include <typeinfo>
using namespace std;
static  int pos_id= 0 ;      // Poslednji identifikator.


class Obj {
    const int id{ ++pos_id };           // Identifikator objekta.
    virtual bool jednako(const Obj& obj) const = 0;       // Da li su jednaki?
    virtual void pisi(ostream& it) const = 0;            // Pisanje objekta.
    virtual void citaj(istream& ut) = 0;                  // Èitanje objekta.

public:
    Obj() = default;                   // Nov objekat dobija nov identifikator.
    Obj(const Obj&) {}               // Kopija dobija nov identifikator.
    Obj& operator=(const Obj&)       // Levom operandu se ne menja identifik.
    {
        return *this;
    };
    virtual ~Obj() = default;         // Uništavanje.
    virtual string klasa() const = 0; // Ime klase.
    virtual Obj* kopija() const& = 0; // Kopija objekta kopiranjem.
    virtual Obj* kopija() && = 0;     // Kopija objekta premeštanjem.
    friend bool operator==(const Obj& o1, const Obj& o2)      // o1 == o2
    {
        return typeid(o1) == typeid(o2) && o1.jednako(o2);
    }
    friend bool operator!=(const Obj& o1, const Obj& o2)      // o1 != o2
    {
        return !(o1 == o2);
    }
    friend ostream& operator<<(ostream& it, const Obj& obj)   // it << obj
    {
        it << obj.klasa()[0] << obj.id; obj.pisi(it); return it;
    }
    friend istream& operator>>(istream& ut, Obj& obj)         // ut >> obj
    {
        obj.citaj(ut); return ut;
    }
};

#endif
