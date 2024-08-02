#ifndef polje_sa_putem_h_
#define polje_sa_putem_h_


#endif // !polje_sa_putem_h_


#include "polje.h"



enum VrstaPuta{ZEMLJANI,KAMENI};

class Polje_sa_putem :
    public Polje
{

    VrstaPuta vrsta;

    void pisi(ostream& it) const override {
        it << oznaka() << "_" << neprohodnost;
    }


public:
    Polje_sa_putem(VrstaPuta vp, int n=100) : Polje(n), vrsta(vp) {};
     
    char oznaka() const override {
        switch (vrsta)
        {
        case ZEMLJANI:
            return 'Z';
            break;
        case KAMENI:
            return 'K';
            break;
        }

    }
    


};

