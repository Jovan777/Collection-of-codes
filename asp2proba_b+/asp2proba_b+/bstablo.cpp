#include "bstablo.h"



void BStablo::ukloniCvor(long long int k) {



    if (koren == nullptr)
    {
        cout << "Stablo je prazno";
    }
    else
    {
        Cvor* temp = koren;
        Cvor* rod = nullptr;
        int desni, levi;

        while (temp->jeList == false)
        {
            for (int i = 0; i < temp->duz; i++)
            {
                rod = temp;
                levi = i - 1;
                desni = i + 1;
                if (k < temp->niz[i])
                {
                    temp = temp->cvorovi[i];
                    break;
                }
                if (i == temp->duz - 1)
                {
                    desni = i + 2;
                    levi = i;
                    temp = temp->cvorovi[i + 1];
                    break;

                }

            }



        }
        int pos;
        bool pronadjen = false;
        for (pos = 0; pos < temp->duz; pos++)
        {
            if (temp->niz[pos] == k)
            {
                pronadjen = true;
                break;

            }

        }
        if (pronadjen == false)
        {
            cout << "U stablu ne postoji zadati kljuc";
            return;
        }

        for (int i = pos; i < temp->duz; i++)
        {
            temp->infoNiz[i] = temp->infoNiz[i + 1];  ////pomeranje stringa

            temp->niz[i] = temp->niz[i + 1];  ////pomeranje stringa


        }
        temp->duz -= 1;  ////
        if (temp == koren)
        {
            for (int i = 0; i < m + 1; i++)
            {
                temp->cvorovi[i] = nullptr;


            }
            if (temp->duz == 0)
            {
                cout << "Obrisano stablo";
                delete[] temp->infoNiz;
                delete[] temp->niz;
                delete temp;
                koren = nullptr;


            }
            return;



        }

        temp->cvorovi[temp->duz] = temp->cvorovi[temp->duz + 1];
        temp->cvorovi[temp->duz + 1] = nullptr;
        if (temp->duz >= (m + 1) / 2)
        {
            return;
        }
        if (levi >= 0)
        {
            Cvor* LCvor = rod->cvorovi[levi];
            if (LCvor->duz >= (m + 1) / 2 + 1)
            {
                for (int i = temp->duz; i > 0; i--)
                {
                    temp->infoNiz[i] = temp->infoNiz[i - 1]; // mozda moramo i string da pomeramo

                    temp->niz[i] = temp->niz[i - 1]; // mozda moramo i string da pomeramo

                }
                temp->duz += 1;
                temp->cvorovi[temp->duz] == temp->cvorovi[temp->duz - 1];
                temp->cvorovi[temp->duz - 1] = nullptr;
                temp->infoNiz[0] = LCvor->infoNiz[LCvor->duz - 1];  ///mozda pomeranje stringa

                temp->niz[0] = LCvor->niz[LCvor->duz - 1];  ///mozda pomeranje stringa

                LCvor->duz -= 1;
                LCvor->cvorovi[LCvor->duz] = temp;
                LCvor->cvorovi[LCvor->duz + 1] = nullptr;
                rod->infoNiz[levi] = temp->infoNiz[0];  ///mozda pomeranje stringa
                rod->niz[levi] = temp->niz[0];  ///mozda pomeranje stringa

                return;



            }

        }
        if (desni <= rod->duz)
        {
            Cvor* DCvor = rod->cvorovi[desni];
            if (DCvor->duz >= (m + 1) / 2 + 1)
            {
                temp->duz += 1;
                temp->cvorovi[temp->duz] = temp->cvorovi[temp->duz - 1];  /////
                temp->cvorovi[temp->duz - 1] = nullptr;

                temp->infoNiz[temp->duz - 1] = DCvor->infoNiz[0];  ///mozda pomeranje stringa

                temp->niz[temp->duz - 1] = DCvor->niz[0];  ///mozda pomeranje stringa
                DCvor->duz -= 1;
                DCvor->cvorovi[DCvor->duz] = DCvor->cvorovi[DCvor->duz + 1];
                DCvor->cvorovi[DCvor->duz + 1] = nullptr;
                for (int i = 0; i < DCvor->duz; i++)
                {
                    DCvor->infoNiz[i] = DCvor->infoNiz[i + 1];  ///pomeranje stringa

                    DCvor->niz[i] = DCvor->niz[i + 1];  ///pomeranje stringa


                }
                rod->infoNiz[desni - 1] = DCvor->infoNiz[0]; /////pomeranje stringa

                rod->niz[desni - 1] = DCvor->niz[0]; /////pomeranje stringa
                return;



            }


        }
        if (levi >= 0)
        {
            Cvor* LCvor = rod->cvorovi[levi];
            for (int i = LCvor->duz, j = 0; j < temp->duz; j++, i++)
            {
                LCvor->infoNiz[i] = temp->infoNiz[j];  ///pomeranje stringa

                LCvor->niz[i] = temp->niz[j];  ///pomeranje stringa

            }
            LCvor->cvorovi[LCvor->duz] = nullptr;
            LCvor->duz += temp->duz;
            LCvor->cvorovi[LCvor->duz] = temp->cvorovi[temp->duz];
            obrisiUnutrasnji(rod->niz[levi], rod, temp);
            delete[] temp->infoNiz;
            delete[] temp->niz;
            delete[] temp->cvorovi;
            delete temp;



        }
        else if (desni <= rod->duz)
        {
            Cvor* DCvor = rod->cvorovi[desni];
            for (int i = temp->duz, j = 0; j < DCvor->duz; j++, i++)
            {
                temp->infoNiz[i] = DCvor->infoNiz[j];  ///pomeranje stringa

                temp->niz[i] = DCvor->niz[j];  ///pomeranje stringa



            }
            temp->cvorovi[temp->duz] = nullptr;
            temp->duz += DCvor->duz;
            temp->cvorovi[temp->duz] = DCvor->cvorovi[DCvor->duz];
            obrisiUnutrasnji(rod->niz[desni - 1], rod, DCvor);
            delete[] DCvor->infoNiz;
            delete[] DCvor->niz;
            delete[] DCvor->cvorovi;
            delete DCvor;




        }








    }








}



void BStablo::obrisiUnutrasnji(long long int x, Cvor* temp, Cvor* dete) {

    if (temp == koren)
    {
        if (temp->duz == 1)
        {
            if (temp->cvorovi[0] = dete)
            {
                delete[] dete->infoNiz;
                delete[] dete->niz;
                delete[] dete->cvorovi;
                delete dete;
                koren = temp->cvorovi[1];
                delete[] temp->infoNiz;
                delete[] temp->niz;
                delete[] temp->cvorovi;
                delete temp;
                return;



            }
            else if (temp->cvorovi[1] == dete)
            {
                delete[] dete->infoNiz;
                delete[] dete->niz;
                delete[] dete->cvorovi;
                delete dete;

                koren = temp->cvorovi[0];
                delete[] temp->infoNiz;
                delete[] temp->niz;
                delete[] temp->cvorovi;
                delete temp;
                return;




            }








        }




    }

    int p;
    for (p = 0; p < temp->duz; p++)
    {
        if (temp->niz[p] == x)
        {
            break;
        }

    }

    for (int i = p; i < temp->duz; i++)
    {
        temp->niz[i] = temp->niz[i + 1];  /// string


    }

    for (p = 0; p < temp->duz + 1; p++)
    {
        if (temp->cvorovi[p] == dete)
        {
            break;
        }
    }
    for (int i = p; i < temp->duz + 1; i++)
    {
        temp->cvorovi[i] = temp->cvorovi[i + 1];

    }
    temp->duz -= 1;
    if (temp == koren)
    {
        return;
    }


    if (temp->duz >= (m + 1) / 2 - 1) {
        return;
    }

    Cvor* rod = uzmiRoditelja(koren, temp);
    int desni, levi;
    for (p = 0; p < rod->duz + 1; p++) {
        if (rod->cvorovi[p] == temp) {
            desni = p + 1;
            levi = p - 1;

            break;
        }
    }

    if (levi >= 0) {
        Cvor* LC = rod->cvorovi[levi];
        if (LC->duz >= (m + 1) / 2) {
            for (int i = temp->duz; i > 0; i--) {
                temp->niz[i] = temp->niz[i - 1]; /////string
            }
            temp->niz[0] = rod->niz[levi]; //// string
            rod->niz[levi] = LC->niz[LC->duz - 1];
            for (int i = temp->duz + 1; i > 0; i--) {
                temp->cvorovi[i] = temp->cvorovi[i - 1];
            }
            temp->cvorovi[0] = LC->cvorovi[LC->duz];
            temp->duz += 1;
            LC->duz--;
            return;
        }
    }
    if (desni <= rod->duz) {
        Cvor* DC = rod->cvorovi[desni];
        if (DC->duz >= (m + 1) / 2) {
            temp->niz[temp->duz] = rod->niz[p];  ////string
            rod->niz[p] = DC->niz[0]; ////string
            for (int i = 0; i < DC->duz - 1; i++) {
                DC->niz[i] = DC->niz[i + 1];  ///string
            }
            temp->cvorovi[temp->duz + 1] = DC->cvorovi[0];
            for (int i = 0; i < DC->duz; ++i) {
                DC->cvorovi[i] = DC->cvorovi[i + 1];
            }
            DC->duz--;

            temp->duz++;
            return;
        }
    }
    if (levi >= 0) {
        Cvor* LC = rod->cvorovi[levi];
        LC->niz[LC->duz] = rod->niz[levi];  /////string
        for (int i = LC->duz + 1, j = 0; j < temp->duz; j++) {
            LC->niz[i] = temp->niz[j];  ////string
        }
        for (int i = LC->duz + 1, j = 0; j < temp->duz + 1; j++) {
            LC->cvorovi[i] = temp->cvorovi[j];
            temp->cvorovi[j] = nullptr;
        }
        LC->duz += temp->duz + 1;
        temp->duz = 0;
        obrisiUnutrasnji(rod->niz[levi], rod, temp);
    }
    else if (desni <= rod->duz) {
        Cvor* DC = rod->cvorovi[desni];
        temp->niz[temp->duz] = rod->niz[desni - 1]; ////string
        for (int i = temp->duz + 1, j = 0; j < DC->duz; j++) {
            temp->niz[i] = DC->niz[j];  ///string
        }
        for (int i = temp->duz + 1, j = 0; j < DC->duz + 1; j++) {
            temp->cvorovi[i] = DC->cvorovi[j];
            DC->cvorovi[j] = nullptr;
        }
        temp->duz += DC->duz + 1;
        DC->duz = 0;
        obrisiUnutrasnji(rod->niz[desni - 1], rod, DC);
    }




};