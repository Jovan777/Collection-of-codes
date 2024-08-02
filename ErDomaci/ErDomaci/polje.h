#ifndef polje_h_
#define polje_h_

#include <iostream>
#include <string>

using namespace std;










class Polje
{
protected:

	int neprohodnost;

	virtual void pisi(ostream& it) const {
		it << oznaka()<<"_" << neprohodnost;
	}

public:
	Polje(int n = 100) : neprohodnost(n) {};


	Polje& operator++() {
		if (neprohodnost<1000)
		{
			neprohodnost++;
		}
		return *this;

	}

	Polje& operator--() {
		if (neprohodnost >  0)
		{
			neprohodnost--;
		}
		return *this;

	}

	int getNep()const { return neprohodnost; }

	virtual char oznaka() const { return 'P'; }


	friend ostream& operator<<(ostream& it, const Polje& p) {
		p.pisi(it);
		return it;
	}





};

#endif // !polje_h_
