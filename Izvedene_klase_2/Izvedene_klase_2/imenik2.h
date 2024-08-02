#ifndef _imenik2_h_
#define _imenik2_h_


#include "osoba2.h"
#include <iostream>
#include <cstdlib>

using namespace std;


class Imenik : public Osoba {

	Osoba** ljudi;
	int kap, n;

public:
	explicit Imenik(int kap = 10) : ljudi(new Osoba* [kap]), kap(kap), n(0) {};
	Imenik(const Imenik&) = delete;
	Imenik& operator=(const Imenik&) = delete;
	~Imenik() {
		for (int i = n; i >0;)
		{
			delete ljudi[i--];
		}
		delete[] ljudi;


	};

	Imenik& uredi() {
		for (int i = 0; i < n-1; i++)
		{
			for (int j = i+1; j < n; j++)
			{
				if (*ljudi[i]<*ljudi[j])
				{
					Osoba* pom = ljudi[i];
					ljudi[i] = ljudi[j];
					ljudi[j] = pom;

				}


			}
		}
		return *this;
	}


	Imenik& operator+=(Osoba* oso) {
		if (n==kap)
		{
			exit(2);
		}
		ljudi[n++] = oso;
		return *this;

	}

	int kapacitet() const { return kap; }
	int vel() const { return n; }


	friend ostream& operator<<(ostream& it, const Imenik& im) {
		for (int i = 0; i < im.n; i++)
		{
			it << *im.ljudi[i] << endl;
		}
		return it;
	}



};





#endif // !_imenik2_h_
