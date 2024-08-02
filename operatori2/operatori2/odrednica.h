#ifndef odrednica_h
#define odrednica_h

#include <iostream>
#include <string>

using namespace std;






class Odrednica
{
	string pojam, prevod;

public:
	Odrednica(string po, string pr) : pojam(po), prevod(pr) {};

	bool operator==(string po) {
		if (pojam==po)
		{
			return true;
		}
		return false;
	}

	bool operator==(Odrednica o2) {
		if (pojam==o2.pojam)
		{
			if (prevod==o2.prevod)
			{
				return true;
			}
			
		}
		return false;
	}

	friend bool operator<(const Odrednica& o1, const Odrednica& o2) {
		return o1.pojam < o2.pojam || o1.pojam == o2.pojam && o1.prevod < o2.prevod;
	}

	friend ostream& operator<<(ostream& it, const Odrednica& o1) {
		return it << o1.pojam << ":" << o1.prevod << endl;
	}




};

#endif // !odrednica_h
