// vektor1.h – Klasa vektora u prostoru.

#ifndef _vektor1_h_
#define _vektor1_h_

#include <iostream>
#include <cmath>
using std::ostream ;using std::sqrt;

class Vektor {
    double x, y, z;                                  // Komponente vektora.
public:
    Vektor() { x = y = z = 0; }                            // Konstruktori.
    Vektor(double x, double y, double z)
        : x{ x }, y{ y }, z{ z } {}
    virtual ~Vektor() = default;                            // Destruktor.
    double intenz() const { return sqrt(x * x + y * y + z * z); }    // Intenzitet.
    friend Vektor operator+(const Vektor& v1, const Vektor& v2) // v1 + v2
    {
        return Vektor(v1.x + v2.x, v1.y + v2.y, v1.z + v2.z);
    }
    friend Vektor operator*(const Vektor& v1, double s)         // v1 * s
    {
        return Vektor(v1.x * s, v1.y * s, v1.z * s);
    }
protected:
    virtual void pisi(ostream& it) const                        // Pisanje.
    {
        it << '(' << x << ',' << y << ',' << z << ')';
    }
    friend ostream& operator<<(ostream& it, const Vektor& v)
    {
        v.pisi(it); return it;
    }
};

#endif
