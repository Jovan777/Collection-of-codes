#ifndef b_stablo_h
#define b_stablo_h

#include <climits>
#include <fstream>

#include <iostream>
#include <sstream>
using namespace std;


class Cvor {



public:

    friend class BStablo;
    Cvor** cvorovi;
    bool jeList;

    int duz;
    int m;
    long long int* niz;
    string* infoNiz;

    Cvor(int mm = 3) {
        m = mm;
        niz = new long long int[m];
        infoNiz = new string[m];
        cvorovi = new Cvor * [m + 1];
    }

    void brisiCvorove(Cvor* temp, int duz) {
        for (int i = duz; i >= 0; i--)
        {
            if (temp->cvorovi[i] == nullptr)
            {
                return;
            }
            else
            {
                delete temp->cvorovi[i];

            }
        }


    }




};



class BStablo {

public:

    int m;
    Cvor* koren;
    BStablo(int mm = 3) {

        m = mm;
        koren = new Cvor(mm);
        koren = nullptr;

    }


    ~BStablo()
    {
        if (koren == nullptr)
        {
            return;
        }
        for (int i = 0; i < koren->duz + 1; i++)
        {
            delete koren->cvorovi[i];

        }
        delete koren;
    }

    Cvor* uzmiRoditelja(Cvor* temp, Cvor* dete) {
        Cvor* rod = nullptr;
        if ((temp->cvorovi[0])->jeList || temp->jeList)
        {
            return nullptr;
        }

        int i;
        for (i = 0; i < temp->duz + 1; i++)
        {
            if (temp->cvorovi[i] == dete)
            {
                rod = temp; return temp;
            }
            else
            {
                rod = uzmiRoditelja(temp->cvorovi[i], dete);
                if (rod != nullptr)
                {
                    return rod;
                }
            }

        }
        return rod;




    }

    void ukloniCvor(long long int k);

    void obrisiUnutrasnji(long long int x, Cvor* temp, Cvor* dete);



    void dodaj(long long int n) {
        int i, j;
        if (koren == nullptr)
        {
            koren = new Cvor(m);
            koren->niz[0] = n;
            koren->jeList = true;

            koren->duz = 1;



        }
        else
        {
            Cvor* rod = nullptr;
            Cvor* temp = koren;

            while (temp->jeList == false)   ////
            {
                rod = temp;
                for (i = 0; i < temp->duz; i++) {
                    if (n < temp->niz[i]) {
                        temp = temp->cvorovi[i];
                        break;
                    }
                    if (i == temp->duz - 1) {
                        temp = temp->cvorovi[i + 1];
                        break;
                    }
                }



            }/////
            if (temp->duz < m)
            {
                i = 0;
                while (i < temp->duz && n > temp->niz[i])  ////
                    i++;
                for (j = temp->duz; j > i; j--) {
                    temp->niz[j] = temp->niz[j - 1];
                }
                temp->duz++;
                temp->niz[i] = n;
                temp->cvorovi[temp->duz] = temp->cvorovi[temp->duz - 1];
                temp->cvorovi[temp->duz - 1] = nullptr;



            }
            else
            {
                Cvor* novi = new Cvor(m);

                long long  int* vint = new long long int[m + 1];


                for (i = 0; i < m; i++) {
                    vint[i] = temp->niz[i];
                }
                i = 0;
                while (n > vint[i] && i < m)
                    i++;
                for (j = m + 1; j > i; j--) {
                    vint[j] = vint[j - 1];
                }
                vint[i] = n;
                novi->jeList = true;
                temp->duz = (m + 1) / 2;
                novi->duz = m + 1 - temp->duz;
                temp->cvorovi[temp->duz] = novi;
                novi->cvorovi[novi->duz] = temp->cvorovi[m];
                temp->cvorovi[m] = nullptr;
                for (i = 0; i < temp->duz; i++) {
                    temp->niz[i] = vint[i];
                }
                for (i = 0, j = temp->duz; i < novi->duz; i++, j++) {
                    novi->niz[i] = vint[j];
                }
                if (temp == koren) {
                    Cvor* tempKoren = new Cvor(m);
                    tempKoren->niz[0] = novi->niz[0];
                    tempKoren->cvorovi[0] = temp;
                    tempKoren->cvorovi[1] = novi;

                    tempKoren->duz = 1;

                    tempKoren->jeList = false;
                    koren = tempKoren;
                }
                else {
                    ubaciUnutrasnji(novi->niz[0], rod, novi);
                }









            }


        }



    }

    void ubaciUnutrasnji(long long int n, Cvor* temp, Cvor* dete) {
        if (temp->duz < m) {
            int i = 0;
            while (n > temp->niz[i] && i < temp->duz)
                i++;
            for (int j = temp->duz; j > i; j--) {
                temp->niz[j] = temp->niz[j - 1];
            }
            for (int j = temp->duz + 1; j > i + 1; j--) {
                temp->cvorovi[j] = temp->cvorovi[j - 1];
            }
            temp->niz[i] = n;
            temp->duz++;
            temp->cvorovi[i + 1] = dete;
        }
        else {
            Cvor* novi = new Cvor(m);
            long long int* vint = new long long int[m + 1];

            Cvor** vcvor = new Cvor * [m + 2];   /////ovde ce puci



            for (int i = 0; i < m; i++) {
                vint[i] = temp->niz[i];
            }
            for (int i = 0; i < m + 1; i++) {
                vcvor[i] = temp->cvorovi[i];
            }
            int i = 0, j;
            while (n > vint[i] && i < m)
                i++;
            for (int j = m + 1; j > i; j--) {
                vint[j] = vint[j - 1];
            }
            vint[i] = n;
            for (int j = m + 2; j > i + 1; j--) {
                vcvor[j] = vcvor[j - 1];
            }
            vcvor[i + 1] = dete;
            novi->jeList = false;
            temp->duz = (m + 1) / 2;
            novi->duz = m - (m + 1) / 2;
            for (i = 0, j = temp->duz + 1; i < novi->duz; i++, j++) {
                novi->niz[i] = vint[j];
            }
            for (i = 0, j = temp->duz + 1; i < novi->duz + 1; i++, j++) {
                novi->cvorovi[i] = vcvor[j];
            }
            if (temp == koren) {
                Cvor* tempKoren = new Cvor(m);
                tempKoren->niz[0] = temp->niz[temp->duz];
                tempKoren->cvorovi[0] = temp;
                tempKoren->cvorovi[1] = novi;
                tempKoren->jeList = false;
                tempKoren->duz = 1;
                koren = tempKoren;
            }
            else {
                ubaciUnutrasnji(temp->niz[temp->duz], uzmiRoditelja(koren, temp), novi);
            }
        }

    };




    void pronadjiIndex(long long int n, int k, ofstream& izlaz) {
        int korak = 1;
        int i;
        if (koren == nullptr) {
            return;
        }
        else {
            Cvor* temp = koren;
            while (temp->jeList != true) {  ////
                for (i = 0; i < temp->duz; i++, korak++) {
                    if (n < temp->niz[i]) {
                        temp = temp->cvorovi[i];
                        break;
                    }
                    if (i == temp->duz - 1) {
                        temp = temp->cvorovi[i + 1];
                        break;
                    }
                }
            }
            for (i = 0; i < temp->duz; i++, korak++) {
                if (temp->niz[i] == n) {
                    break;
                }
            }
            for (int j = 0; j < k; j++)
            {
                if (i == temp->duz)
                {
                    temp = temp->cvorovi[temp->duz];
                    i = 0;
                }
                //cout << temp->infoNiz[i++]<<endl;
                izlaz << temp->infoNiz[i++] << endl;
            }

            //cout << "Nije pronadjen" << endl;
            cout << "Pretraga je zavrsena za " << korak << " koraka" << endl;

            return;
        }


    }


    string pronadjiKljuc(long long int n, int& k) {

        int korak = 0;
        int i;
        if (koren == nullptr) {
            return "";
        }
        else {
            Cvor* temp = koren;
            while (temp->jeList != true) {  ////
                for (i = 0; i < temp->duz; i++, korak++) {
                    if (n < temp->niz[i]) {
                        temp = temp->cvorovi[i];
                        break;
                    }
                    if (i == temp->duz - 1) {
                        temp = temp->cvorovi[i + 1];
                        break;
                    }
                }
            }
            for (i = 0; i < temp->duz; i++, korak++) {
                if (temp->niz[i] == n) {
                    //cout << "Potrebno za pretragu : " << korak << endl;
                    k = korak;
                    return temp->infoNiz[i];
                }
            }
            cout << "Nije pronadjen" << endl;
            return "";
        }


    };

    void prikaziStablo(Cvor* temp) {

        if (temp != nullptr) {
            for (int i = 0; i < temp->duz; i++) {
                cout << temp->niz[i] << " : " << temp->infoNiz[i] << endl;
            }
            cout << "\n";
            if (temp->jeList != true) {
                for (int i = 0; i < temp->duz + 1; i++) {
                    prikaziStablo(temp->cvorovi[i]);
                }
            }
        }
    };


    void ubaciInfo(long long int n, string info) {
        if (koren == nullptr)
        {
            return;
        }
        else
        {
            Cvor* curs = koren;
            while (curs->jeList == false)
            {
                for (int i = 0; i < curs->duz; i++)
                {
                    if (n < curs->niz[i])
                    {
                        curs = curs->cvorovi[i];
                        break;
                    }
                    if (i == curs->duz - 1)
                    {
                        curs = curs->cvorovi[i + 1]; break;
                    }

                }


            }
            for (int i = 0; i < curs->duz; i++)
            {
                if (curs->niz[i] == n)
                {
                    curs->infoNiz[i] = info;
                    return;
                }


            }
            cout << "Nije nasao";
            return;



        }
    };



};


#endif b_stablo_h