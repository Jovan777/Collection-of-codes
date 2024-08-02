#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include "tekst1.h"


void Tekst::kopiraj(const char* n) {

	if (n  && strlen(n))
	{
		niz = new char[strlen(n) + 1];
		strcpy(niz, n);

	}
	else
	{
		niz = nullptr;
	}

}

Tekst operator+(const Tekst& t1, const Tekst& t2) {

	if (!t1.niz)
	{
		return t2;
	}
	if (!t2.niz)
	{
		return t1;
	}
	Tekst t;
	t.niz = new char[len(t1) + len(t2) + 1];
	strcpy(t.niz, t1.niz);
	strcat(t.niz, t2.niz);

	return t;
}


Tekst Tekst ::operator()(int i, int j) const{

	if (i<0 || j<i || len(*this)<=j)
	{
		exit(1);
	}
	Tekst t;
	int d = j - i + 1;
	t.niz = new char[d + 1];
	strncpy(t.niz, niz + 1, d);
	t.niz[d] = '\0';

	return t;
}


int operator&(const Tekst& t1, const Tekst& t2) {

	int d1 = len(t1), d2 = len(t2);
	if (!d1 || !d2)
	{
		return -1;
	}
	for (int i = 0; i < d1-d2+1; i++)
	{
		int j;
		for (j = 0; j < d2 && t1[i + 1] == t2[j]; j++);
		if (j==d2)
		{
			return i;
		}

	}

	return -1;
}


