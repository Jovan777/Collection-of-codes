#ifndef _student2_h_
#define _student2_h_



#include "osoba2.h"
#include <iostream>
#include <cstdlib>

using namespace std;


class Student : public Osoba {

	int* ocene;
	int kap, n;

public:
	Student(string i, int g, int k=20) : Osoba(i, g), ocene(new int[k]), kap(k), n(0) {};
	~Student() { delete[] ocene; }       // Uništavanje objekta.
	Student& operator+=(int oc) {         // Dodavanje ocene.
		if (n == kap) exit(1);
		ocene[n++] = oc;
		return *this;
	}
	int jos() const { return kap - n; }   // Broj slobodnih mesta.
	double sr_ocena() const {

		double s = 0;
		int k = 0;
		for (int i = 0; i < n; i++)
		{
			if (ocene[i]>5)
			{
				s += ocene[i];
				k++;
			}
		}
		if (k)
		{
			s /= k;
		}
		return s;

	};              // Srednja ocena.
private:
	void pisi(ostream& it) const override // Pisanje studenta.
	{
		Osoba::pisi(it); it << '/' << sr_ocena();
	}

};





#endif // !_student2_h_
