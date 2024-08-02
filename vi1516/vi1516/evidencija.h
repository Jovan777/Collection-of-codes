#ifndef evidencija_h_
#define evidencija_h_




#include "lista.h"
using namespace std;
#include <iostream>
#include <string>





class Evidencija
{

	Lista l;


public:
	Evidencija() {};


	Evidencija& operator+=(Korisnik* k) {
		l += k;
		return *this;
	}


	Korisnik* operator[](string ime) {
		for (int i = 0; i <l.brojKorisnika(); i++)
		{
			if (l[i]->getName()==ime)
			{
				return l[i];
			}
		}


	}

	void operator()(string ime) {

		for (int i = 0; i < l.brojKorisnika(); i++)
		{
			if (l[i]->getName() == ime)
			{
				l(i);
			}
		}
	}

	void changePassword(string user, string oldPass, string newPass) {
		for (int i = 0; i < l.brojKorisnika(); i++)
		{
			if (l[i]->getName() == user)
			{
				l[i]->changePass(oldPass, newPass);
			}
		}

	}








};

#endif // !evidencija_h_
