#pragma once
#include "avion.h"



Pilot* Avion::getKap() {
	return this->kapetan;
}
Pilot* Avion::getKop() {
	return this->kopilot;
}
string Avion::getIme() const{
	return this->ime;
}
int Avion::getMax() const {
	return maxP;
}

void Avion::setKap(Pilot* kap) {
	if (kap->getSati()>=100)
	{
		kapetan = kap;
		kap->promeniStanje();

	}
	else
	{
		exit(1);
	}

}

void Avion::setKop(Pilot* kop) {
	kopilot = kop;
	kop->promeniStanje();

}