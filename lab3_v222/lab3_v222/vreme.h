#ifndef vreme_h
#define vreme_h


#include <iostream>
using namespace std;

class Vreme
{
	int min;
	int sat;

public:
	Vreme(int s, int m) : min(m), sat(s) {};


	friend bool operator>(const Vreme& v1, const Vreme& v2) {
		if (v1.sat>v2.sat)
		{
			return true;
		}
		else if (v1.sat==v2.sat && v1.min > v2.min)
		{
			return true;
		}
		else
		{
			return false;
		}

	}

	friend Vreme operator + ( const Vreme& v1, const Vreme& v2) {
		int min1;
		int sat1;

		sat1 = v1.sat + v2.sat;

		min1 = v1.min + v2.min;
		if (min1>=60)
		{
			sat1++;
			min1 = min1 % 60;

		}

		return Vreme(sat1, min1);

	}


	friend ostream& operator<<(ostream& it, const Vreme& v1) {
		if (v1.sat<10)
		{
			it << "0"<<v1.sat<<":";
		}
		else
		{
			it << v1.sat << ":";
		}
		if (v1.min < 10)
		{
			it << "0" << v1.min;
		}
		else
		{
			it << v1.min ;
		}

		return it;
	}


};



#endif 
