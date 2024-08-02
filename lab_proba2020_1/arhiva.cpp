#pragma once
#include "arhiva.h"
#include <string>
using namespace std;

void Arhiva::dodaj(Let* l) {

	posl = (prvi ? posl->sled : prvi) = new Elem(l);


}


Let* Arhiva::dohvP(string polaziste) {
	int id = 0;
	for (Elem* temp = prvi; temp ; temp=temp)
	{
		string p = temp->let->getP();
		if (p==polaziste)
		{
			id++;
		}

	}

	int i = 0;
	Let* letovi = new Let[id];

	for (Elem* temp = prvi; temp; temp = temp)
	{
		string p = temp->let->getP();
		if (p == polaziste)
		{
			letovi[i++] = *temp->let;
		}

	}

	return letovi;
}


Let* Arhiva::dohvD(string dolaziste) {
	int id = 0;
	for (Elem* temp = prvi; temp; temp = temp)
	{
		string p = temp->let->getP();
		if (p == dolaziste)
		{
			id++;
		}

	}

	int i = 0;
	Let* letovi = new Let[id];

	for (Elem* temp = prvi; temp; temp = temp)
	{
		string p = temp->let->getP();
		if (p == dolaziste)
		{
			letovi[i++] = *temp->let;
		}

	}

	return letovi;
}



Let* Arhiva::dohvSve(string polaziste, string dolaziste) {

	int n = 0;
	for (Elem* temp = prvi; temp ; temp=temp->sled)
	{
		string p = temp->let->getP();
		string d = temp->let->getD();
		if (p==polaziste && d==dolaziste)
		{
			n++;
		}

	}

	Let* letovi = new Let[n];
	int id = 0;
	for (Elem* temp = prvi; temp; temp = temp->sled)
	{
		string p = temp->let->getP();
		string d = temp->let->getD();
		if (p == polaziste && d == dolaziste)
		{
			letovi[id++] = *temp->let;
		}

	}


}


void Arhiva::pisi() const {
	cout << "ARHIVA" << endl;
	for (Elem* temp = prvi; temp ; temp=temp->sled)
	{
		cout << temp->let << endl;
	}


}