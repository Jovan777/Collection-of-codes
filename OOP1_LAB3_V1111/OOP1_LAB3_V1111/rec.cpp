#include "rec.h"


bool nosioc(Skup::El* pret, Skup::El* temp, Skup::El* sled) {
	if (temp->znak=='o' || temp->znak=='O' || temp->znak == 'i' || temp->znak == 'I' || 
		temp->znak == 'a' || temp->znak == 'A' || temp->znak == 'u' || temp->znak == 'U'
		|| temp->znak == 'e' || temp->znak == 'E')
	{
		return true;
	}

	if (temp->znak=='n' || temp->znak=='N' || temp->znak=='R' || temp->znak=='r'
		|| temp->znak=='L' || temp->znak=='l')
	{
		if (pret!=nullptr)
		{
			if (pret->znak == 'o' || pret->znak == 'O' || pret->znak == 'i' || pret->znak == 'I' ||
				pret->znak == 'a' || pret->znak == 'A' || pret->znak == 'u' || pret->znak == 'U'
				|| pret->znak == 'e' || pret->znak == 'E')
			{
				return false;
			}
		}
		

		if (sled!=nullptr)
		{
			if (sled->znak == 'o' || sled->znak == 'O' || sled->znak == 'i' || sled->znak == 'I' ||
				sled->znak == 'a' || sled->znak == 'A' || sled->znak == 'u' || sled->znak == 'U'
				|| sled->znak == 'e' || sled->znak == 'E')
			{
				return false;
			}
		}
		

		if (temp->znak == 'n' || temp->znak == 'N' || temp->znak == 'L' || temp->znak == 'l')
		{
			if (sled!=nullptr)
			{
				if (sled->znak == 'j' || sled->znak == 'J')
				{
					return false;
				}
			}
		}

		return true;

	}



	return false;
}



int Rec::operator()(int n) {

	int duz = n;
	int k;
	if (n<0)
	{
		int duz = ~*this; ////
		//cout << duz << endl;
		duz += n;
		k = duz;

	}
	if (n>=0)
	{
		k = n;
	}

	if (n>duz)
	{
		throw PremasenIndeks();
	}

		int z = 0;
		int i = 0;
		Skup::El* temp = rec.first;
		Skup::El* pret = nullptr;
		Skup::El* sled = temp->sled;

		while (temp && i <= k)
		{
			if (nosioc(pret, temp, sled))
			{
				i++;
				//cout << temp->znak << endl;
			}
			pret = temp;
			temp = temp->sled;
			if (temp != nullptr)
			{
				sled = temp->sled;
			}
			z++;

		}

		return z - 1;

}




int Rec::operator~() {
	Skup::El* temp= rec.first;
	Skup::El* pret=nullptr;
	Skup::El* sled=temp->sled;


	int u = 0;

	while (temp)
	{
		if (nosioc(pret, temp, sled))
		{
			u++;
		}
		pret = temp;
		temp = temp->sled;
		if (temp!=nullptr)
		{
			sled = temp->sled;
		}


	}


	
	return u;
}



char Rec::operator[](int ind) {
	Skup::El* temp;
	temp = rec.first;
	int i = 0;

	while (temp && i<ind)
	{
		i++;
		temp = temp->sled;
	}

	if (temp==nullptr)
	{
		return ' ';
	}

	return temp->znak;
}


/*
friend bool Rec::operator^( Rec& r1,  Rec& r2)
{
	int br1 = ~r1;
	int br2 = ~r2;

	int s1 = r1(-1);
	int s2 = r2(-1);

	char c1 = r1[s1];
	char c2 = r2[s2];


	if (br1==1 || br2==1)
	{
		return c1 = c2;

	}


	return false;
}
*/