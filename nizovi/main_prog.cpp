#include <iostream>
#include "t_vozilo.h"
#include "p_vozilo.h"
#include <string>
#include "tacka5.h"
#include "brzina.h"


using namespace std;


int main() {

    /*
    Vozilo* vozila[100]; int br_vozila = 0;
    Osoba* osobe[100];  int br_osoba = 0;
    while (true) {
        cout << "\nVrsta vozila (T,P,*)? "; char vrs; cin >> vrs;
        if (vrs == '*') break;
        cout << "Ime vozaca?           "; string ime; cin >> ime;
        cout << "Tezina vozaca?        "; float tezina; cin >> tezina;
        Osoba* vozac = osobe[br_osoba++] = new Osoba(ime, tezina);
        cout << "Tezina vozila?        "; float tez_vozila; cin >> tez_vozila;
        switch (vrs) {
        case 't': case 'T': {
            cout << "Nosivost vozila?      "; float nosivost; cin >> nosivost;
            T_vozilo* tv = new T_vozilo(vozac, tez_vozila, nosivost);
            cout << "Tezina tereta?        "; float teret; cin >> teret;
            *tv += teret;
            vozila[br_vozila++] = tv;
            break;
        }
        case 'p': case 'P': {
            cout << "Broj mesta?           ";   int br_mesta; cin >> br_mesta;
            P_vozilo* pv = new P_vozilo(vozac, tez_vozila, br_mesta);
            while (true) {
                cout << "Ime putnika?          "; string ime;   cin >> ime;
                if (ime == "*") break;
                cout << "Tezina putnika?       "; float tezina; cin >> tezina;
                *pv += osobe[br_osoba++] = new Osoba(ime, tezina);
            }
            vozila[br_vozila++] = pv;
            break;
        }
        default:
            cout << "*** Nepoznata vrsta vozila! ***\n";
        }
    }
    cout << "\nNosivost mosta?       "; double nosivost; cin >> nosivost;
    cout << "\nMogu da predju most:\n";
    for (int i = 0; i < br_vozila; i++)
        if (vozila[i]->tezina() <= nosivost)
            cout << *vozila[i] << " - " << vozila[i]->tezina() << endl;
    for (int i = 0; i < br_vozila; delete vozila[i++]);
    for (int i = 0; i < br_osoba; delete osobe[i++]);
    */

    cout << "Broj tacaka? "; int n; cin >> n;
    Tacka** tacke = new Tacka * [n];
    for (int i = 0; i < n; i++) {
        cout << "Koordinate tacke " << i << "? ";
        double x, y, z; cin >> x >> y >> z;
        cout << "Komponente brzine? ";
        double vx, vy, vz; cin >> vx >> vy >> vz;
        tacke[i] = new Tacka{ Vektor(x,y,z), Brzina(vx,vy,vz) };
    }

    cout << "\nBroj koraka? "; int k; cin >> k;
    cout << "Trajanje koraka? "; double dt; cin >> dt;
    const Tacka org;
    cout << "ORG   " << org << "\n\n";

    for (int i = 0; i < k; i++) {
        for (int j = 0; j < n; tacke[j++]->proteklo(dt));
        double min = rastojanje(org, *tacke[0]); int m = 0;
        for (int j = 1; j < n; j++) {
            double d = rastojanje(org, *tacke[j]);
            if (d < min) { min = d; m = j; }
        }
        cout << i << ' ' << *tacke[m] << ' ' << min << endl;
    }

    for (int i = 0; i < n; i++) delete tacke[i];
    delete[] tacke;


	return 0;
}