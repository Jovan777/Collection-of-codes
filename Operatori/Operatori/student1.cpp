#pragma once
#include "student1.h"
#include <cstdlib>

using namespace std;

Student::Student(string i, long id, int k) : ime{ i }, ind{ id }, kap{ k }, ocene{ new int[kap] }, br_oc{ 0 } {};


Student& Student::operator+=(int ocena) {
	if (br_oc==kap)
	{
		exit(1);
	}
	ocene[br_oc++] = ocena;
	return *this;

}

int& Student::operator[](int i) {
	if (i<0 || i>=br_oc)
	{
		exit(2);
	}
	return ocene[i];

}

int Student::operator[](int i) const {
	if (i<0 || i>=br_oc)
	{
		exit(2);
	}
	return ocene[i];
}

double Student::sr_ocena() const {
	double s = 0;
	for (int i = 0; i < br_oc; i++)
	{
		s += ocene[i];
	}
	
	if (br_oc>0)
	{
		return s / br_oc;
	}
	else
	{
		return 0;
	}

}