#ifndef korisnik_h_
#define korisnik_h_


#include <iostream>
#include <string>
using namespace std;




class Korisnik
{
	string name, password;
	bool moze(string pass) {

		bool flag = false;
		bool slovo = false;
		bool broj = false;

		if (pass.length() >= 8)
		{
			for (int i = 0; i < pass.length(); i++)
			{
				if (pass[i] >= 'a' && pass[i] <= 'z' || pass[i] >= 'A' && pass[i] <= 'Z')
				{
					slovo = true;
				}

				if (pass[i] >= '1' && pass[i] <= '9')
				{
					broj = true;
				}


			}

		}
		slovo && broj;

		return slovo && broj;

	}

public:

	Korisnik(string n, string pass)  {
		if (moze(pass))
		{
			name = n;
			password = pass;
		}
	};


	string getName() const { return name; }
	string getPass() const { return password; }

	void changePass(string oldPass, string newPass) {
		if (oldPass==password)
		{
			if (moze(newPass))
			{
				password = newPass;
			}
		}

	}

	friend bool operator==(const Korisnik& k1, const Korisnik& k2) {
		return k1.name == k2.name;

	}

	friend ostream& operator<<(ostream& it, const Korisnik& k) {
		return it << k.name;
	}









};

#endif // !korisnik_h_
