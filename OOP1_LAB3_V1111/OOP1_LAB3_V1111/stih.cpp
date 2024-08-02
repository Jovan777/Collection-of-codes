#include "stih.h"


void Stih::kopirajStih(const Stih& s)
{   
    prvi = posl = nullptr;
    Elem* temp = s.prvi;
    while (temp)
    {
        posl = (prvi ? posl->sled : prvi) = new Elem(temp->rec);
        temp = temp->sled;
    }

}

void Stih::obrisiStih()
{
    Elem* temp = prvi;
    while (temp)
    {
        Elem* del = temp;
        temp = temp->sled;
        delete del;
    }
}

int Stih::operator+()
{
    int z = 0;
    Elem* temp = prvi;
    while (temp)
    {
        z++;
        temp = temp->sled;
    }

    return z;
}

int Stih::operator~() const
{
    int z = 0;
    Elem* temp = prvi;
    while (temp)
    {
        z += ~*temp->rec;
        //cout << ~temp->rec << endl;
        temp = temp->sled;
    }


    return z;
}

Rec* Stih::operator[](int ind)
{
    int i = 0;
    Elem* temp = prvi;
    while (temp && i<ind)
    {
        i++;
        temp = temp->sled;
    }

    if (temp==nullptr)
    {
        return new Rec(" ");
    }

    return temp->rec;
}

void Stih::operator()(int ind)
{
    int i = 0;
    Elem* temp = prvi;
    Elem* pret = nullptr;

    while (temp && i < ind)
    {
        pret = temp;
        i++;
        temp = temp->sled;
    }

    Elem* o = temp;
    (pret ? pret->sled : prvi) = temp->sled;


    delete o;

}

Stih& Stih::operator()(Rec* rec, int ind)
{
    int i = 0;
    Elem* temp = prvi;
    Elem* pret = nullptr;

    while (temp && i < ind)
    {
        pret = temp;
        i++;
        temp = temp->sled;
    }

    Elem* novi = new Elem(rec);
    pret->sled = novi;
    novi->sled = temp;

    if (novi->sled==nullptr)
    {
        posl = novi;
    }

    return *this;
}

bool operator^(Stih& s1, Stih& s2)
{

    int br1 = +s1;
    int br2 = +s2;

   // cout << br1 << endl;
    //cout << br2 << endl;

    br1--;
    br2--;

    Rec* r1 = s1[br1];
    Rec* r2 = s2[br2];

    //cout << *r1 << endl;
    //cout << *r2 << endl;

    return *r1 ^ *r2;

}
