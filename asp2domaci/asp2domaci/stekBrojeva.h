#ifndef stekBrojeva_h_
#define stekBrojeva_h_

#include <iostream>
using namespace std;


class StekBrojevi {

    int* niz;
    int top;
    int kap;


public:
    StekBrojevi(int k) {
        niz = new int[k];
        kap = k;
        top = -1;
    };

    void push(int n) {
        if (top == kap - 1)
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
        if (top == -1)
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














#endif // !stekBrojeva_h_
