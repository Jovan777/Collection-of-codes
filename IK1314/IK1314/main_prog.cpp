// naredba_t.cpp - Ispitivanje klasa naredbi.

#include "konst.h"
#include "prom.h"
#include "dodela.h"
#include "oper.h"
using namespace Izrazi;
#include "prosta.h"
#include "sekvenca.h"
#include "selekcija.h"
#include "ciklus.h"
using namespace Naredbe;
#include <iostream>
using std::cin; using std::cout;using std::endl;

int main() {

    
    Prom n("n"), i("i"), f("f");
    Sekvenca telo;
    telo += Prosta(Dodela(i, Zbir(i, Konst(1))));
    telo += Prosta(Dodela(f, Proizv(f, i)));
    Ciklus cikl(Razlika(n, i), telo);
    Sekvenca prog;
    prog += Prosta(Dodela(i, Konst(0)));
    prog += Prosta(Dodela(f, Konst(1)));
    prog += cikl;
    cout << "Program:\n" << prog << endl;
    while (true) {
        cout << "n? "; cin >> n;
        if (n.vredn() < 0) break;
        prog.izvrsi();
        cout << "f= " << f.vredn() << endl;
    }
}
