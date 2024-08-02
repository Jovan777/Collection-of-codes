#include "strofa.h"

void Strofa::operator+=(const Stih& s)  
{
	if (duz==kap)
	{
		return;
	}

	if (!imaPrvi)
	{
		stihovi[0] = s;
		duz++;
		slogovi = ~s;
		imaPrvi = true;

		return;
	}
	else
	{
		int sl = ~s;
		if (sl!=slogovi)
		{
			return;
		}
		stihovi[duz++] = s;

	}

}

void Strofa::operator-()
{
	if (duz>0)
	{
		duz--;
	}
}



Stih Strofa::operator[](int ind)
{
	if (ind>=duz)
	{
		throw PremasenIndeks();
	}

	return stihovi[ind];
}


void Strofa::operator()(int i, int j)
{
	if (i >= duz || j>=duz)
	{
		throw PremasenIndeks();
	}

	Stih b = stihovi[i];
	stihovi[i] = stihovi[j];
	stihovi[j] = b;


}
