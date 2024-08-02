#ifndef _osoba2_h_
#define _osoba2_h_

#include <iostream>
#include <compare>
#include <string>

using namespace std;

class Osoba {
    string ime;                             // Ime osobe.
    int god;                                // Godine starosti.
public:
    Osoba(string ime="", int god=5)              // Stvaranje objekta.
        : ime{ ime }, god{ god } {}
    Osoba(const Osoba&) = delete;            // Ne sme da se kopira.
    Osoba& operator=(const Osoba&) = delete; // Ne sme da se dodeljuje.
    virtual ~Osoba() {}                     // Virtuelan destruktor.
    bool operator<(const Osoba& o2) const // Uporeðivanje osoba.
    {
        return god < o2.god;
    }
    bool operator>(const Osoba& o2) const // Uporeðivanje osoba.
    {
        return god > o2.god;
    }
    bool operator==(const Osoba& o2) const { return god == o2.god; }

protected:
    virtual void pisi(ostream& it) const    // Pisanje osobe.
    {
        it << ime << '(' << god << ')';
    }
    friend ostream& operator<<(ostream& it, const Osoba& oso)
    {
        oso.pisi(it); return it;
    }
};



#endif // !_osoba2_h_
