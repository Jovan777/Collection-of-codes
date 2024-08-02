#ifndef stekStabla_h_
#define stekStabla_h_

#include "stablo.h"




class StekStabla {

    Cvor** cvorovi;
    int top;
    int kap;

public:

    StekStabla(int n) {
        cvorovi = new Cvor * [n];
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
        if (top == -1)
        {
            cout << "Stek za cvorove je prazan" << endl;
            exit(1);
        }


        return cvorovi[top--];

    }

    bool prazan() const {
        return top == -1;
    }


};






#endif // !stekStabla_h_
