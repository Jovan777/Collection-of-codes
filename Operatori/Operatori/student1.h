#pragma once

#include <string>
using namespace std;

class Student {

	string ime;
	long ind;
	int* ocene;
	int br_oc, kap;

public:

	Student(string i, long id, int kap = 40);

	~Student()
	{
		delete[] ocene;
	}

	Student(const Student&) = delete;
	Student& operator=(const Student&) = delete;

	string dohvIme() const {
		return ime;
	}
	long dohvId() const {
		return ind;
	}

	Student& promeniIme(string i) {
		ime = i;
		return *this;
	}
	Student& promeniId(long id) {
		ind = id;
		return *this;
	}

	Student& operator+=(int ocena);
	int br_ocena() const {
		return br_oc;
	}

	int& operator[](int i);
	int operator[](int i) const;
	double sr_ocena() const;



};