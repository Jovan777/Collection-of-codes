#include "knjiga.h"

#ifndef _polica_h
#define _polica_h

#include <iostream>
using namespace std;



class Polica {

	const Knjiga** knjige;
	int br_mesta;
	int br_knjiga;


public:
	Polica(int brm = 10) ;
	Polica(const Polica&) = delete;
	void operator=(const Polica&) = delete;
	~Polica()
	{
		delete[] knjige;
	}

	bool operator+=(const Knjiga* k);
	const Knjiga* operator-=(int poz);

	double uk_vrd() const;
	friend ostream& operator<<(ostream& it, const Polica& p);



};





#endif // !_polica_h
