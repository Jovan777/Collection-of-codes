#ifndef skup_h
#define skup_h


#include <iostream>
using namespace std;




class Skup
{
	
	
public:

	struct El {
		char znak;
		El* sled;

		El(char z, El* sl = nullptr) : znak(z), sled(sl) {};

	};

	El* first, * last;


	Skup(string rec) {
		char c;


		for (int i = 0; i < rec.length(); i++)
		{
			c = rec.at(i);
			last = (first ? last->sled : first) = new El(c);

		}

	}


	Skup(const Skup& s) = delete;
	Skup& operator=(const Skup& s) = delete;
	~Skup()
	{
		El* temp = first;
		while (temp)
		{
			El* old = temp;
			temp = temp->sled;
			delete old;
		}

		last = nullptr;
	}

	bool ima(char z) {
		El* temp = first;
		while (temp)
		{
			if (temp->znak == z)
			{
				return true;
			}
			temp = temp->sled;
		}
	}

	bool operator()(char zn) {
		
		if (ima(zn))
		{
			return true;
		}
		return false;
	}



	void operator+=(char z) {
		if (ima(z))
		{
			return;
		}
		last = (first ? last->sled : first) = new El(z);

	}

	void pisi() {
		for (El* temp = first; temp ; temp=temp->sled)
		{
			cout << temp->znak;
		}

	}


};

#endif // !skup_h
