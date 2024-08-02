#ifndef stablo_h_
#define stablo_h_

#include <iostream>
#include <cstdlib>



using namespace std;

struct Elem {
    int br;
    Elem* sled;
    Elem(int b, Elem* s = nullptr) : br(b), sled(s) {};


};



class Cvor {





public:
    int broj;
    Cvor* levi, * desni, * otac;
    Elem* dupliPrvi;
    Elem* dupliPosl;

    bool prvi = true;


    Cvor(int b = 0, Cvor* o = nullptr, Cvor* l = nullptr, Cvor* d = nullptr) : broj(b), otac(o), levi(l), desni(d) {
        dupliPrvi = nullptr;
    };


    void postaviBroj(int b) {
        broj = b;
    }

    void pisi() const {
        cout << "Cvor u stablu : " << broj;
    }

    void postaviOca(Cvor* o) {
        otac = o;
    }

    void dodajDupli() {

        dupliPosl = (dupliPrvi ? dupliPosl->sled : dupliPrvi) = new Elem(broj);
        /*
        if (prvi=true)
        {
            dupliPrvi = new Elem(broj);
            prvi = false;
        }
        else
        {
            dupliPrvi->sled = new Elem(broj);
            dupliPrvi = dupliPrvi->sled;
            //dupli->sled=nullptr;
        }
        */


    }

    int brojDuplih(Cvor* c) {
        int br = 1;
        Elem* el = c->dupliPrvi;
        while (el)
        {
            br++;
            el = el->sled;
        }
        return br;
    }

    void pisiDuple(Cvor* c) {
        Elem* e = c->dupliPrvi;
        cout << c->broj << "->";
        while (e) {
            cout << e->br << "->";
            e = e->sled;
        }
        cout << "nullptr" << endl;

    }

    Cvor* pronadjiCvor(Cvor* root, int br, int& n) {
        Cvor* p = root;
        n = 0;
        while (p)
        {
            if (p->broj == br)
            {
                return p;
            }
            else if (p->broj > br)
            {
                p = p->levi;
            }
            else
            {
                p = p->desni;
            }
            n++;

        }
        if (p != nullptr)
        {
            cout << "Cvor pronadjen posle " << n << "koraka" << endl;
            return p;
        }
        else {
            cout << "Cvor nije pronadjen"; cout << endl;
            return nullptr;
        }


    }


    void dodaj(Cvor* root, int br) {

        Cvor* temp = root;
        Cvor* otac = nullptr;
        while (temp)
        {
            if (br < temp->broj)
            {
                otac = temp;
                temp = temp->levi;
            }
            else if (br > temp->broj)
            {
                otac = temp;
                temp = temp->desni;
            }
            else if (br == temp->broj)
            {
                temp->dodajDupli();
                return;
            }

        }
        temp = new Cvor(br);
        temp->postaviOca(otac);
        if (temp->broj > otac->broj)
        {
            otac->desni = temp;
        }
        else
        {
            otac->levi = temp;
        }

        return;


    }


    ~Cvor()
    {
        delete levi;
        delete desni;
        cout << "Obrisan cvor sa kljucem : " << broj << endl;
    }


};














#endif // !stablo_h_
