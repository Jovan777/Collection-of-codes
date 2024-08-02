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

    /*
    //Stek za stabla i za brojeve radi
    /*
    Cvor* root = new Cvor(5);
    Cvor* novi = new Cvor(10);
    insert(root, 2);
    insert(root, 7);
    insert(root, 3);
    insert(root, 9);

    //inorder(root);

    StekStabla  ss(5);
    ss.push(root);
    ss.push(novi);


    while (!ss.prazan())
    {
        Cvor* c = ss.pop();
        c->pisi();
        cout << endl;

    }

    cout << endl << endl;

    StekBrojevi sb(5);
    sb.push(1);
    sb.push(2);
    sb.push(3);
    sb.push(4);
    sb.push(5);

    while (!sb.prazan())
    {
        cout << sb.pop();
        cout << " ";

    }
    */

    /*
    int niz[9] = { 1,2, 3, 4, 5, 6, 7, 8, 9 };

    Cvor* root = napraviBST(niz, 9);
    root->dodaj(root, 10);
    root->dodaj(root, 15);
    root->dodaj(root, 12);
    root->dodaj(root, 14);
    root->dodaj(root, 7);
    root->dodaj(root, 7);
    root->dodaj(root, 7);

    cout << "INORDER : ";
    inorder(root);
    cout << endl;
    cout << "PREORDER : ";
    preorder(root);
    cout << endl << endl;
    crtaj(root, 0);

    cout << endl << endl << endl;
    cout << root->brojDuplih(root->desni) << endl;
    root->pisiDuple(root->desni);

    cout << endl << endl;

    int n = 0;
    Cvor* sedam = root->pronadjiCvor(root, 1, n);
    cout << sedam->broj << endl;
    cout << sedam->brojDuplih(sedam) << endl;
    cout << "Broj koraka : " << n << endl;
    cout << sedam->otac->broj << endl;

    cout << endl << endl;
    int array[] = { 3 ,5,8,14,7, 15, 12, 9, 1 };
    double ocena = eval(root, array, 9);

    cout << "Evaluacija : " << ocena << endl;




    //delete root;
    */

    /*
    int* niz = ucitaj(10, "niz.txt");

    for (int i = 0; i < 10; i++)
    {
        cout << niz[i] << " ";
    }

    cout << endl << endl;

    //int* niz2 = unesiNiz(5);
    //ispisiNiz(niz, 5);
    cout << endl << endl << endl;

    int* niz3 = generisiNiz(10, 543, 11543);
    ispisiNiz(niz3, 10);

    cout << endl;
    int niz5[] = { 1,2,3,4,5 };


    int mid;
    // mid = interpolacija(niz5, 5, 4);
    //cout << mid << endl;

    /*
    obrni(niz3, 10);

    ispisiNiz(niz3, 10);
    mid = interpolacija(niz3, 0, 9, 8711);
    cout << endl;
    cout << mid << endl;
    */

    /*
    int* niz7 = obrni(niz3, 10);
    ispisiNiz(niz7, 10);
    cout << endl;
    mid = interpolacija(niz7, 0, 9, 8711);
    cout << endl;
    cout << mid << endl;

    cout << endl;
    cout << endl;
    cout << endl;
    cout << endl;
    cout << endl;

    int oc;
    mid = n_pretraga(niz3, 10, 3, 11490, oc);
    cout << "Pozicija : " << mid << endl;
    cout << "Element : " << niz3[mid] << endl;

    cout << "Broj koraka : " << oc << endl;

    cout << endl;
    cout << endl;
    cout << endl;

    int niz9[] = { 11490, 11298, 8009 };

    int* niz10 = new int[3];

    //n_optimizovano(niz3, 10, niz9, 3, niz10, 3, oc);

    //ispisiNiz(niz10, 3); cout << endl;
    //cout << oc << endl;

    cout << endl;
    cout << endl;
    cout << endl;


    m_eval(niz3, 10, 5);

    oc = n_optimizovano(niz3, 10, niz9, 3, niz10, 3, oc);
    //cout << oc << endl;
    ispisiNiz(niz9, 3); cout << endl;
    ispisiNiz(niz10, 3); cout << endl;

    cout << endl;
    cout << oc;
    cout << endl;
    cout << endl;

    m_eval_optimizovano(niz3, 10, 5, 3);
    */

    /*
    int* niz = generisiNiz(10, 250, 100000);
    ispisiNiz(niz, 10);
    niz=obrni(niz, 10);
    cout << endl;
    ispisiNiz(niz, 10);
    cout << endl;

    Cvor* root;
    root = napraviBST(niz, 10);
    crtaj(root, 0);
    */

    cout << "                                       MENU          " << endl << endl;
    int izbor;
    bool nastavi = true;
    int* niz=nullptr;
    int* niz2=nullptr;
    int* nizIndeksa = nullptr;
    int size;
    int key;
    int pos;
    int broj=0;
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
            cout << endl<<"Generisani niz : ";
            ispisiNiz(niz, size);
            cout << endl << endl;
            break;

        case 3:
            cout << "Unesite kljuc : "; cin >> key;
            cout << "Unesite parametar m za pretragu : "; cin >> m;

            pos = n_pretraga(niz, size,m, key, broj);
            ispisiNiz(niz, size);
            cout << endl << "Broj : " << key << " se nalazi na poziciji : " << pos << endl << endl;
            break;

        case 4:
            cout << "Zadat niz : "<<endl;
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
            cout << endl<<"Unesite broj koji zelite da pretrazite : ";
            cin >> broj;
            c = c->pronadjiCvor(root, broj, l);
            if (c != nullptr) {
                cout << "Cvor pronadjen posle " << l << " koraka"<<endl;
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

   


