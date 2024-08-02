// tekst3.cpp - Metode klase tekstova.

#include "tekst3.h"

void Tekst::kopiraj(const char* niz) {               // Kopiranje u objekat.
    if (niz && niz[0]) {
        tks = new char[strlen(niz) + 1]; strcpy(tks, niz);
    }
    else tks = nullptr;
}
void Tekst::citaj(istream& ut) {                     // Èitanje objekta.
    char niz[81], zn; ut >> zn; ut.getline(niz, 81, ']');
    delete[] tks; kopiraj(niz);
}
