// Searching on a B+ tree in C++

#include <climits>
#include <fstream>
#include <iostream>
#include <sstream>
using namespace std;
const int MAX = 3;

// BP node
class Cvor {
    


public:

    friend class BStablo;
    Cvor** cvorovi;
    bool jeList;

    int duz;
    int m;
    long long int* niz;
    string* infoNiz;

    Cvor(int mm=3) {
        m = mm;
        niz = new long long int[m];
        infoNiz = new string[m];
        cvorovi = new Cvor * [m + 1];
    }

    void brisiCvorove(Cvor* temp,int duz) {
        for (int i = duz; i >=0 ; i--)
        {
            if (temp->cvorovi[i]==nullptr)
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

// BP tree
class BStablo {
    

public:
    int m;
    Cvor* koren;
    BStablo(int mm=3) {

        m = mm;
        koren = new Cvor(mm);
        koren = nullptr;

    }

  

    ~BStablo()
    {
        for (int i = 0; i < koren->duz+1; i++)
        {
            delete koren->cvorovi[i];

        }
        delete koren;
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
            long long int* vint=new long long int[m + 1];
            
            Cvor** vcvor=new Cvor*[m + 2];   /////ovde ce puci
           


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
                Cvor* tempKoren = new Cvor;
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



    Cvor* uzmiRoditelja(Cvor* temp, Cvor* dete) {

        Cvor* parent = nullptr;
        if (temp->jeList || (temp->cvorovi[0])->jeList) {
            return nullptr;
        }
        for (int i = 0; i < temp->duz + 1; i++) {
            if (temp->cvorovi[i] == dete) {
                parent = temp;
                return parent;
            }
            else {
                parent = uzmiRoditelja(temp->cvorovi[i], dete);
                if (parent != nullptr)
                    return parent;
            }
        }
        return parent;
    };



    void pronadjiKljuc(long long int n) {
        if (koren == NULL) {
            cout << "Tree is empty\n";
        }
        else {
            Cvor* temp = koren;
            while (temp->jeList == false) {
                for (int i = 0; i < temp->duz; i++) {
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
            for (int i = 0; i < temp->duz; i++) {
                if (temp->niz[i] == n) {
                    //cout << "Found\n";
                    cout << temp->infoNiz[i] << endl;
                    return;
                }
            }
            cout << "Not found\n";
        }


    };



    void dodaj(long long int n) {
        if (koren == nullptr) {
            koren = new Cvor(m);
            koren->niz[0] = n;
            koren->jeList = true;
            koren->duz = 1;
        }
        else {
            Cvor* temp = koren;
            Cvor* rod = nullptr;
            while (temp->jeList == false) {
                rod = temp;
                for (int i = 0; i < temp->duz; i++) {
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
            if (temp->duz < m) {
                int i = 0;
                while (n > temp->niz[i] && i < temp->duz)
                    i++;
                for (int j = temp->duz; j > i; j--) {
                    temp->niz[j] = temp->niz[j - 1];
                }
                temp->niz[i] = n;
                temp->duz++;
                temp->cvorovi[temp->duz] = temp->cvorovi[temp->duz - 1];
                temp->cvorovi[temp->duz - 1] = nullptr;
            }
            else {
                
                long long  int* vint=new long long int[m + 1];
                Cvor* novi = new Cvor(m);


                for (int i = 0; i < m; i++) {
                    vint[i] = temp->niz[i];
                }
                int i = 0, j;
                while (n > vint[i] && i < m)
                    i++;
                for (int j = m + 1; j > i; j--) {
                    vint[j] = vint[j - 1];
                }
                vint[i] = n;
                novi->jeList = true;
                temp->duz = (m + 1) / 2;
                novi->duz = m + 1 - (m + 1) / 2;
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
                    tempKoren->jeList = false;
                    tempKoren->duz = 1;
                    koren = tempKoren;
                }
                else {
                    ubaciUnutrasnji(novi->niz[0], rod, novi);
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


    void ukloniCvor(long long int k){
        

        if (koren==nullptr)
        {
            cout << "Stablo je prazno";
        }
        else
        {
            Cvor* temp = koren;
            Cvor* rod = nullptr;
            int desni, levi;

            while (temp->jeList==false)
            {
                for (int i = 0; i < temp->duz; i++)
                {
                    rod = temp;
                     levi = i - 1;
                     desni = i + 1;
                    if (k<temp->niz[i])
                    {
                        temp = temp->cvorovi[i];
                        break;
                    }
                    if (i==temp->duz-1)
                    {
                        desni = i + 2;
                        levi = i;
                        temp = temp->cvorovi[i+1];
                        break;

                    }

                }



            }
            int pos;
            bool pronadjen = false;
            for ( pos = 0; pos < temp->duz; pos++)
            {
                if (temp->niz[pos]==k)
                {
                    pronadjen = true;
                    break;

                }

            }
            if (pronadjen==false)
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
            if (temp==koren)
            {
                for (int i = 0; i < m+1; i++)
                {
                    temp->cvorovi[i] = nullptr;


                }
                if (temp->duz==0)
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
            if (temp->duz>=(m+1)/2)
            {
                return;
            }
            if (levi>=0)
            {
                Cvor* LCvor = rod->cvorovi[levi];
                if (LCvor->duz >= (m + 1) / 2 + 1)
                {
                    for (int i = temp->duz; i > 0 ; i--)
                    {
                        temp->infoNiz[i] = temp->infoNiz[i - 1]; // mozda moramo i string da pomeramo

                        temp->niz[i] = temp->niz[i - 1]; // mozda moramo i string da pomeramo

                    }
                    temp->duz+=1;
                    temp->cvorovi[temp->duz] == temp->cvorovi[temp->duz - 1];
                    temp->cvorovi[temp->duz - 1] = nullptr;
                    temp->infoNiz[0] = LCvor->infoNiz[LCvor->duz - 1];  ///mozda pomeranje stringa

                    temp->niz[0] = LCvor->niz[LCvor->duz - 1];  ///mozda pomeranje stringa
                    
                    LCvor->duz-=1;
                    LCvor->cvorovi[LCvor->duz] = temp;
                    LCvor->cvorovi[LCvor->duz + 1] = nullptr;
                    rod->infoNiz[levi] = temp->infoNiz[0];  ///mozda pomeranje stringa
                    rod->niz[levi] = temp->niz[0];  ///mozda pomeranje stringa

                    return;



                }

            }
            if (desni<=rod->duz)
            {
                Cvor* DCvor = rod->cvorovi[desni];
                if (DCvor->duz>=(m+1)/2+1)
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
            if (levi>=0)
            {
                Cvor* LCvor = rod->cvorovi[levi];
                for (int i = LCvor->duz, j=0; j<temp->duz;j++, i++)
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
            else if (desni<=rod->duz)
            {
                Cvor* DCvor = rod->cvorovi[desni];
                for (int i = temp->duz, j=0; j<DCvor->duz ;j++, i++)
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


    void obrisiUnutrasnji(long long int x, Cvor* temp, Cvor* dete) {
        
        if (temp==koren)
        {
            if (temp->duz==1)
            {
                if (temp->cvorovi[0]=dete)
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
                else if (temp->cvorovi[1]==dete)
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
        for ( p = 0; p < temp->duz; p++)
        {
            if (temp->niz[p]==x)
            {
                break;
            }

        }

        for (int i = p; i < temp->duz; i++)
        {
            temp->niz[i] = temp->niz[i + 1];  /// string


        }
        
        for ( p = 0; p < temp->duz+1; p++)
        {
            if (temp->cvorovi[p]==dete)
            {
                break;
            }
        }
        for (int i = p; i < temp->duz+1; i++)
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
                temp->duz+=1;
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


    Cvor* uzmiKoren() {
        return koren;
    };
};















int main() {
    BStablo node(3);
    node.dodaj(43000000001);
    node.dodaj(43000000002);
    node.dodaj(43000000003);
    node.dodaj(43000000004);
    node.dodaj(43000000005);
    node.dodaj(43000000006);
    node.dodaj(43000000011);
    node.dodaj(43000000012);
    node.dodaj(43000000013);

    node.dodaj(43000000014);


    node.ubaciInfo(43000000001, "43000000001|4300000001|4300000001|Joshua Fowle Savings Account|1|6334235.05");
    node.ubaciInfo(43000000002, "43000000002|4300000003|4300000001|Joshua Fowle Play Money|2|2731646.43");
    node.ubaciInfo(43000000003, "43000000003|4300000004|4300000001|Joshua Fowle Emergency Expenses|2|7625683.59");
    node.ubaciInfo(43000000004, "43000000004|4300000005|4300000001|Joshua Fowle Vacation Account|2|79823.44");
    node.ubaciInfo(43000000005, "43000000005|4300000010|4300000001|Joshua Fowle Healthcare Fund|2|1104436.03");
    node.ubaciInfo(43000000006, "43000000006|4300000008|4300000001|Joshua Fowle New Car Account|1|1594842.08");
    node.ubaciInfo(43000000011, "43000000011|4300000004|4300000002|Willie Swigert Joint Account|1|-9093725.95");
    node.ubaciInfo(43000000012, "43000000012|4300000003|4300000002|Willie Swigert Business Account|1|9288893.44");
    node.ubaciInfo(43000000013, "43000000013|4300000007|4300000002|Willie Swigert College Fund|1|8096128.80");
    node.ubaciInfo(43000000014, "43000000014|4300000006|4300000002|Willie Swigert Flexible Spending|0|9638415.62");



    node.prikaziStablo(node.uzmiKoren());

    cout << endl << endl << endl << endl << endl;

    node.ukloniCvor(43000000002);

    //node.pronadjiKljuc(43000000005);

    node.prikaziStablo(node.uzmiKoren());



    return 0;
}