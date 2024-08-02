#ifndef objekat_h
#define objekat_h

#include <iostream>

using namespace std;






class Objekat
{
	static int pos_id;
	int id = ++pos_id;

public:

    virtual bool jednako(const Objekat& obj) const = 0;       // Da li su jednaki?
    virtual void pisi(ostream& it) const = 0;            // Pisanje objekta.
    virtual void citaj(istream& ut) = 0;                  // Èitanje objekta.

public:
    Objekat() = default;                   // Nov objekat dobija nov identifikator.
    Objekat(const Objekat&) {}               // Kopija dobija nov identifikator.
    Objekat& operator=(const Objekat&)       // Levom operandu se ne menja identifik.
    {
        return *this;
    };
    virtual ~Objekat() = default;         // Uništavanje.
    virtual string getClass() const = 0; // Ime klase.
    virtual Objekat* kopija() const& = 0; // Kopija objekta kopiranjem.
    virtual Objekat* kopija() && = 0;     // Kopija objekta premeštanjem.
    friend bool operator==(const Objekat& o1, const Objekat& o2)      // o1 == o2
    {
        return typeid(o1) == typeid(o2) && o1.jednako(o2);
    }
    friend bool operator!=(const Objekat& o1, const Objekat& o2)      // o1 != o2
    {
        return !(o1 == o2);
    }
    friend ostream& operator<<(ostream& it, const Objekat& obj)   // it << obj
    {
        it << obj.getClass()[0] << obj.id; obj.pisi(it); return it;
    }
    friend istream& operator>>(istream& ut, Objekat& obj)         // ut >> obj
    {
        obj.citaj(ut); return ut;
    }


};

#endif // !objekat_h
