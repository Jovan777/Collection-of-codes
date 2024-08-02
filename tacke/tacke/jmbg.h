#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstring>
using namespace std;


class JMBG {

	char jmbg[14];

public:

	JMBG(const char j[]) {
		strcpy_s(jmbg, j);
	}

	const char* dohvJMBG() const { return jmbg; }

	friend bool veci(const JMBG& j1, const JMBG& j2) {
		return strcmp(j1.jmbg, j2.jmbg) > 0;
	}

	void pisi() const { cout << jmbg; }





};