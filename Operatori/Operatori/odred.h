#include <iostream>
#include <string>

using namespace std;



class Odred {

	string poj, prev;


public:

	Odred(string po, string pre) : poj(po), prev(pre) {};

	bool operator==(string poj) {
		return this->poj == poj;
	}

	friend bool operator==(const Odred& od1, const Odred& od2) {
		return od1.poj == od2.poj && od1.prev == od2.prev;

	}

	friend bool operator<(const Odred& od1, const Odred& od2) {
		return od1.poj < od2.poj || od1.poj == od2.poj && od1.prev < od2.prev;
	}

	friend ostream& operator<<(ostream& it, const Odred& od) {
		return it << od.poj << " : " << od.prev;
	}
	




};