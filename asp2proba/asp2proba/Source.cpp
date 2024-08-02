#include <iostream>
#include <cstdlib>
#include <string>
#include "stekStabla.h"
#include "stekBrojeva.h"
#include <iomanip>
#include "niz.h"


using namespace std;







void inorder(Cvor* root)
{
    if (root == nullptr) {
        return;
    }

    inorder(root->levi);
    cout << root->broj << " ";
    inorder(root->desni);
}


void preorder(Cvor* root) {
    if (root == nullptr)
    {
        return;
    }
    cout << root->broj << " ";
    preorder(root->levi);
    preorder(root->desni);

}



// fja za pravljenje stabla od niza(probna)
//radi obicno pravljenje stabla od niza



Cvor* napraviBST(int niz[], int n) { //treba dodati fju za postavljanje oca cvora
    int low = 0;
    Cvor* otac;
    int high = n - 1;
    StekStabla stekStabla(100);
    StekBrojevi stekLow(100);
    StekBrojevi stekHigh(100);

    int mid = (low + high) / 2;

    Cvor* root = new Cvor(niz[mid]);

    Cvor* novi = root;
    stekStabla.push(novi);
    stekLow.push(mid + 1);
    stekHigh.push(high);
    high = mid - 1;

    while (low < high)
    {

        novi->levi = new Cvor();
        otac = novi;
        novi = novi->levi;
        novi->postaviOca(otac);
        mid = (low + high) / 2;
        novi->postaviBroj(niz[mid]);
        if (mid == 0)
        {
            novi->levi = nullptr;
            novi->desni = nullptr;
            break;

        }


        stekStabla.push(novi);
        stekLow.push(mid + 1);
        stekHigh.push(high);
        high = mid;


    }
    //novi->levi = nullptr;

    while (!stekHigh.prazan())
    {
        novi = stekStabla.pop();
        low = stekLow.pop();
        high = stekHigh.pop();

        if (low <= high)
        {
            novi->desni = new Cvor();
            otac = novi;
            novi = novi->desni;
            novi->postaviOca(otac);
            mid = (low + high) / 2;
            novi->postaviBroj(niz[mid]);
            stekStabla.push(novi);
            stekLow.push(mid + 1);
            stekHigh.push(high);

            high = mid - 1;

            while (low <= high)
            {
                novi->levi = new Cvor();
                otac = novi;
                novi = novi->levi;
                novi->postaviOca(otac);
                mid = (low + high) / 2;
                novi->postaviBroj(niz[mid]);
                stekStabla.push(novi);
                stekLow.push(mid + 1);
                stekHigh.push(high);
                high = mid - 1;

            }
            novi->levi = nullptr;


        }
        else
        {
            novi->desni = nullptr;
        }


    }

    return root;
};

void crtaj(Cvor* stb, int nivo) {

    if (stb)
    {
        crtaj(stb->desni, nivo + 1);
        cout << setw(4 * nivo) << "" << stb->broj << endl;
        crtaj(stb->levi, nivo + 1);
    }

}



double eval(Cvor* root, int niz[], int n) {
    int k = 0;
    int br = 0;
    for (int i = 0; i < n; i++)
    {
        Cvor* c = root->pronadjiCvor(root, niz[i], k);
        br += k;
    }

    double o = (double)br / n;
    return o;

}


int main() {



    cout << "                                       MENU          " << endl << endl;
    int izbor;
    bool nastavi = true;
    int* niz = nullptr;
    int* niz2 = nullptr;
    int* nizIndeksa = nullptr;
    int size;
    int key;
    int pos;
    int broj = 0;
    int m;
    int l;
    double e;
    int size2;
    int* niz3 = nullptr;
    int size3;
    string dat;

    Cvor* root = nullptr;
    Cvor* c = nullptr;


    while (nastavi)
    {

        cout << "1. Unesite niz kljuceva                                     7.Formiraj stablo" << endl;
        cout << "2. Generisi niz kljuceva                                    8.Ubaci cvor u stablo" << endl;
        cout << "3.M-arna pretraga na zadati kljuc                           9.Pretrazi stablo za zadati cvor" << endl;
        cout << "4.M-arna pretraga na niz kljuceva                           10.Crtaj stablo" << endl;
        cout << "5.Evaluacije m-arne pretrage                                11.Evaluacija stabla" << endl;
        cout << "6.Evaluacija m-arne pretrage na vise kljuceva               12.Brisi stablo" << endl;
        cout << "                                         0.Kraj rada" << endl;
        cout << endl << "Unesite opciju : " << endl;
        cin >> izbor;


        switch (izbor)
        {
        case 0:
            nastavi = false;
            break;

        case 1:
            cout << "Unesite velicinu niza : ";
            cin >> size;
            cout << "0.Unesite vas niz       1.Ucitajte niz iz datoteke" << endl;
            int izbor2;
            cin >> izbor2;

            switch (izbor2)
            {
            case 0:
                cout << "Unesite opadajuce uredjen niz sa " << size << " elemenata : " << endl;
                niz = new int[size];
                for (int i = 0; i < size; i++)
                {
                    cin >> niz[i];
                }

                ispisiNiz(niz, size);
                cout << endl;
                break;

            case 1:
                cout << "Unesite ime datoteke : ";
                cin >> dat;
                dat += ".txt";
                niz = ucitaj(size, dat);
                ispisiNiz(niz, size);
                cout << endl;
                break;
            default:
                cout << "Neispravan izbor za ovu opciju" << endl;
                break;

            }
            break;

        case 2:
            cout << "Unesite velicinu niza : ";
            cin >> size;
            cout << endl << "Unesite minamalni i maksimalni opseg : " << endl << "Min : ";
            int min, max;
            cin >> min;
            cout << "Max : "; cin >> max;
            niz = generisiNiz(size, min, max);
            cout << endl << "Generisani niz : ";
            ispisiNiz(niz, size);
            cout << endl << endl;
            break;

        case 3:
            cout << "Unesite kljuc : "; cin >> key;
            cout << "Unesite parametar m za pretragu : "; cin >> m;

            pos = n_pretraga(niz, size, m, key, broj);
            ispisiNiz(niz, size);
            cout << endl << "Broj : " << key << " se nalazi na poziciji : " << pos << endl << endl;
            break;

        case 4:
            cout << "Zadat niz : " << endl;
            ispisiNiz(niz, size); cout << endl;
            cout << "Koliko kljuceva hocete da pretrazite?" << endl;
            int z;
            cin >> z;
            niz2 = new int[z];
            cout << "Unesite kljuceve : " << endl;
            for (int i = 0; i < z; i++)
            {
                cin >> niz2[i];
            }
            nizIndeksa = new int[z];
            cout << "Unesite parametar m : "; cin >> m;
            l = n_optimizovano(niz, size, niz2, z, nizIndeksa, m, broj);
            cout << endl;
            ispisiNiz(niz, size); cout << endl;
            ispisiNiz(niz2, z); cout << endl;
            ispisiNiz(nizIndeksa, z); cout << endl;
            break;

        case 5:
            cout << "Za koliko brojeva hocete da radite evaluaciju?" << endl;
            cin >> l;
            m_eval(niz, size, l);
            cout << endl;
            break;

        case 6:
            cout << "Koliko kljuceva hocete da pretrazite?" << endl;
            cin >> l;
            cout << "Koliko puta hocete da radite poredjenje?" << endl;
            cin >> broj;

            m_eval_optimizovano(niz, size, l, broj);
            cout << endl;
            break;


        case 7:
            cout << "0.Iskoristi vec napravlje niz\n1.Unesite uredjen niz" << endl;
            cin >> l;
            switch (l)
            {
            case 0:
                niz2 = obrni(niz, size);
                root = napraviBST(niz2, size);
                size3 = size;
                break;
            case 1:
                cout << "Unesite broj elemenata niza : ";
                cin >> size2;
                niz3 = new int[size2];
                cout << "Unesite elemente niza : " << endl;
                for (int i = 0; i < size2; i++)
                {
                    cin >> niz3[i];
                }
                niz2 = obrni(niz3, size2);
                root = napraviBST(niz2, size2);
                size3 = size2;
                break;

            default:
                cout << "Neispravan izbor za ovu opciju" << endl;
                break;
            }
            break;

        case 8:
            cout << "Unesite broj koji hocete da ubacite u stablo : " << endl;
            cin >> broj;
            root->dodaj(root, broj);
            cout << endl;
            break;

        case 9:
            cout << "Cvorovi u stablu : ";
            inorder(root);
            cout << endl << "Unesite broj koji zelite da pretrazite : ";
            cin >> broj;
            c = c->pronadjiCvor(root, broj, l);
            if (c != nullptr) {
                cout << "Cvor pronadjen posle " << l << " koraka" << endl;
                cout << c->broj << endl;
            }

            break;


        case 10:
            cout << endl << endl;
            crtaj(root, 0);
            cout << endl;
            break;


        case 11:
            //cout << "Evaluacija se radi za niz od koga je formirano stablo "<<endl;
            e = eval(root, niz2, size3);
            cout << "Prosecan broj koraka za pretragu cvora u stablu je : " << e << endl;
            break;

        case 12:
            delete root;
            cout << endl;
            break;
        }

    }

    cout << "Kraj programa" << endl;
    return 0;
}
