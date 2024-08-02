#ifndef _lista_6_h_
#define _lista_6_h_


#include "lista.h"



class U_Lista : public N_Lista {

public:
	U_Lista() = default;
	U_Lista(int b) : N_Lista(b) {};
	U_Lista& operator+=(int b) override;
	U_Lista& operator+=(const N_Lista& lst) {
		N_Lista::operator+=(lst);
		return *this;
	}



};



#endif // !_lista_6_
