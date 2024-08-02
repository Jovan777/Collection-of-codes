#ifndef pilot_h_
#define pilot_h_


#include <iostream>
#include <string>

using namespace std;

class Pilot
{

	string name;
	int hours;
	bool fly;

	

public:
	Pilot(string n, int h, bool f = false) : name(n), hours(h), fly(f) {};
	Pilot(const Pilot&) = delete;
	Pilot(Pilot&& ) = delete;

	string getName() const {
		return name;
	}

	int getHours() const { return hours; }

	bool getFly() const { return fly; }

	void increaseHours(int inc) {
		hours += inc;
	}

	void changeFly(bool f) {
		fly = f;
	}

	void pisi() const {
		cout << name << "(" << hours << ")" << "-" << (fly ? "L" : "N");
	};



};

#endif // !pilot_h_
