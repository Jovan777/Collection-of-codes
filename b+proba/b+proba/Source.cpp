#include <iostream>
#include "bStablo.h"

using namespace std;


int main() {

	BStablo stablo;
	stablo.dodaj(43000000001, "43000000001|4300000001|4300000001|Joshua Fowle Savings Account|1|6334235.05");
	stablo.dodaj(43000000002, "43000000002|4300000003|4300000001|Joshua Fowle Play Money|2|2731646.43");
	stablo.dodaj(43000000003, "43000000003|4300000004|4300000001|Joshua Fowle Emergency Expenses|2|7625683.59");

	stablo.prolaz(stablo.koren);

	return 0;
}