#include "skup1.h"
#include <iostream>

using namespace std;


void Skup::kopiraj(const Skup& s) {

	niz = new double[vel = s.vel];
	for (int i = 0; i < vel; i++)
	{
		niz[i] = s.niz[i];
	}

}


void Skup::unija(const Skup& s1, const Skup& s2) {

	Skup s;
	s.niz = new double[s1.vel + s2.vel];
	s.vel = 0;

	for (int i = 0, j=0; i < s1.vel || j<s2.vel; )
	{

		s.niz[vel++] = i == s1.vel ? s2.niz[j++] :
			j == s2.vel ? s1.niz[i++] :
			s1.niz[i]<s2.niz[j] ? s1.niz[i++] :
			s1.niz[i]>s2.niz[j] ? s2.niz[j++] :
			(j++, s1.niz[i++]);



	}
	brisi();
	kopiraj(s);


}



void Skup::presek(const Skup& s1, const Skup& s2) {


	Skup s;
	s.niz = new double[s1.vel > s2.vel ? s1.vel : s2.vel];

	s.vel = 0;

	for (int i = 0, j=0; i < s1.vel && j<s2.vel; )
	{
		if (s1.niz[i] < s2.niz[j])
		{
			i++;
		}
		else if (s1.niz[i]>s2.niz[j])
		{
			j++;
		}
		else
		{
			s.niz[vel++] = s1.niz[i++], j++;
		}



	}
	brisi();
	kopiraj(s);



}


void Skup::pisi() const {
	cout << "{ ";
	for (int i = 0; i < vel; i++)
	{
		cout << niz[i] << " , ";
	}
	cout << " } "<<endl;


}


void Skup::razlika(const Skup& s1, const Skup& s2) {

	Skup s;
	s.niz = new double[s1.vel];
	s.vel = 0;
	for (int i = 0, j=0; i < s1.vel ; )
	{
		if (j==s2.vel)
		{
			s.niz[s.vel++] = s1.niz[i++];
		}
		else if (s1.niz[i]<s2.niz[j])
		{
			s.niz[s.vel++] = s1.niz[i++];
		}
		else if (s1.niz[i] > s2.niz[j])
		{
			j++;
		}
		else
		{
			i++, j++;
		}

	}
	brisi();
	kopiraj(s);



}



void Skup::citaj() {

	brisi();
	int vel;
	cout << "Unesite velicinu : ";
	cin >> vel;
	for (int i = 0; i < vel; i++)
	{
		double broj;
		cin >> broj;
		unija(*this, broj);
	}




}