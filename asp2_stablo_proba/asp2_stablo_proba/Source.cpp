#include <iostream>
#include <iomanip>
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


	Cvor(int b=0, Cvor* o = nullptr, Cvor* l = nullptr, Cvor* d = nullptr) : broj(b), otac(o), levi(l), desni(d) {
        dupliPrvi = nullptr;
    };


    void postaviBroj(int b) {
        broj = b;
    }

    void pisi() const {
        cout << "Cvor u stablu : " << broj;
    }

    void postaviOca(Cvor* o){
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

    Cvor* pronadjiCvor(Cvor* root,int br, int& n) {
        Cvor* p = root;
        n = 0;
        while (p)
        {
            if (p->broj==br)
            {
                return p;
            }
            else if (p->broj>br)
            {
                p = p->levi;
            }
            else
            {
                p = p->desni;
            }
            n++;

        }
        if (p!=nullptr)
        {
            cout << "Cvor pronadjen posle " << n << "koraka" << endl;
            return p;
        }
        else {
            cout << "Cvor nije pronadjen";
            return nullptr;
        }


    }


    void dodaj(Cvor* root, int br) {

        Cvor* temp = root;
        Cvor* otac = nullptr;
        while (temp)
        {
            if (br<temp->broj)
            {
                otac = temp;
                temp = temp->levi;
            }
            else if (br>temp->broj)
            {
                otac = temp;
                temp = temp->desni;
            }
            else if (br==temp->broj)
            {
                temp->dodajDupli();
                return;
            }

        }
        temp = new Cvor(br);
        temp->postaviOca(otac);
        if (temp->broj>otac->broj)
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


class StekStabla {

    Cvor** cvorovi;
    int top;
    int kap;

public:

    StekStabla(int n) {
        cvorovi = new Cvor*[n];
        kap = n;
        top = -1;

    }

    void push(Cvor* c) {
        //cout << "Push" << endl;
        if (top == kap - 1) {
            cout << "Stek za cvorove je pun" << endl;
            exit(1);
        }
        cvorovi[++top] = c;

    }

    Cvor* pop() {
        if (top==-1)
        {
            cout << "Stek za cvorove je prazan"<<endl;
            exit(1);
        }
       
        
        return cvorovi[top--];

    }

    bool prazan() const {
        return top == -1;
    }


};


class StekBrojevi {

    int* niz;
    int top;
    int kap;


public:
    StekBrojevi(int k)  {
        niz = new int[k];
        kap = k;
        top = -1;
    };

    void push(int n) {
        if (top==kap-1)
        {
            cout << "Stek brojeva je pun";
            exit(1);
        }
        else
        {
            niz[++top] = n;
        }


    }

    int pop() {
        if (top==-1)
        {
            cout << "Stek brojeva je prazan";
            exit(1);
        }
        return niz[top--];

    }

    bool prazan() const {
        return top == -1;
    }



};





Cvor* insert(Cvor* root, int key)
{
    // if the root is null, create a new node and return it
    if (root == nullptr) {
        return new Cvor(key);
    }

    // if the given key is less than the root node, recur for the left subtree
    if (key < root->broj) {
        root->levi = insert(root->levi, key);
    }
    // if the given key is more than the root node, recur for the right subtree
    else {
        root->desni = insert(root->desni, key);
    }

    return root;
}


void inorder(Cvor* root)
{
    if (root == nullptr) {
        return;
    }

    inorder(root->levi);
    cout << root->broj << " ";
    inorder(root->desni);
}


void preorder(Cvor* root){
    if (root==nullptr )
    {
        return;
    }
    cout << root->broj << " ";
    preorder(root->levi);
    preorder(root->desni);

}



// fja za pravljenje stabla od niza(probna)
//radi obicno pravljenje stabla od niza
Cvor* napraviStablo(int niz[], int n) {

    Cvor* root = new Cvor(niz[0]);
    for (int i = 1; i < n; i++)
    {
        insert(root, niz[i]);

    }
    

    return root;

}


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

    while (low<high)
    {
        
        novi->levi = new Cvor();
        otac = novi;
        novi = novi->levi;
        novi->postaviOca(otac);
        mid = (low + high) / 2;
        novi->postaviBroj(niz[mid]);
        if (mid==0)
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

        if (low<=high)
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

            while (low<=high)
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

//    int array[] = { 3 ,5,8,14,7, 15, 12, 9, 1 };


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

  
    int niz[9] = { 1,2, 3, 4, 5, 6, 7, 8, 9 };

    Cvor* root = napraviBST(niz, 9);
    root->dodaj(root,10);
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


}