#include <iostream>

using namespace std;

#include "strofa.h"


int main() {

	/*
	Skup s1("string");

	//s1('g');

	string str = "novi string";
	char c;

	for (int i = 0; i < str.length(); i++)
	{
		c = str.at(i);
		cout << c << endl;

	}
	*/

	/*
	Skup s1("string");

	s1.pisi();
	cout << endl;

	s1 += 'a';
	s1.pisi();
	cout << endl;
	s1 += 'a';
	s1.pisi();

	cout << endl;
	cout << endl;


	Rec r1("telefon");

	cout << +r1 << endl;

	cout << endl << endl;

	cout << "Duzina slogova r1 : ";
	cout << ~r1 << endl;
	cout << endl << endl;

	cout << r1(-3) << endl;

	cout << endl << endl;
	
	Rec r2("NEBO");
	//r2.operator>>(cin);
	cout << endl << endl;

	cout << "unesi rec" << endl;
	//r2.operator>>(cin);

	//cout << "Ispis iz maina" << endl;
	//r2.pisi();

	cout << endl << endl;

	//cin >> r2;
	cout << endl << endl;
	cout << "Ispis iz maina" << endl;
	cout << r2 << endl;
	cout << endl;
	//cout << r2[0] << endl;

	cout << "ispis" << endl;
	int b = r2(-1);
	//cout << b << endl;
	cout << r2[b] << endl;
	*/

	//cout << endl << endl << "Jednoslozno" << endl;

	/*
	cout << "Unesi r1"<<endl;
	cin >> r1;
	cout << "Unesi r2" << endl;
	cin >> r2;

	cout << "Rimuju se  : " << (r1 ^ r2);

	*/

	/*
	Stih stih1;

	stih1 += &r1;
	stih1 += &r2;

	//cout << stih1 << endl;

	Stih stih2;

	cout << "Unesi stih" << endl;
	cin >> stih2;

	cout << endl << endl;
	cout << "Unet stih" << endl;
	cout << stih2;

	cout << endl << "Broj reci u stihu : " << endl;
	cout << +stih2 << endl;
	cout << ~stih2 << endl;
	cout << *stih2[2] << endl;
	stih2(0);
	cout << stih2<<endl;
	
	stih2(&r2, 2);
	cout << stih2 << endl;
	cout << endl;


	//cout << endl << endl << endl;

	//cout << "Unesite nove stihove : " << endl;

	Stih stih3;
	cout << "Unesite stih 3 : " << endl;
	cin >> stih3;

	cout<<(stih2^ stih3)<<endl;


	//cin >> stih3;
	//cin >> stih4;

	//cout << endl << endl << endl;

	//cout << stih3;
	//cout << stih4;


	
	*/

	/*
	Strofa strofa1(3);

	cout << endl << endl;

	cout << "Unesite stihove : " << endl;

	Stih s5;
	Stih s6;
	Stih s7;

	cin >> s5;
	cin >> s6;
	cin >> s7;

	strofa1 += s5;
	strofa1 += s6;
	strofa1 += s7;



	cout << "Prva strofa" << endl;
	cout << strofa1 << endl;

	cout << endl << endl;
	
	cout << strofa1.getBr() << endl;
	cout << "Brojevi stihova" << endl;
	cout << +strofa1 << endl;
	cout << endl;
	//-strofa1;

	//cout << strofa1 << endl;

	Stih s_novi = strofa1[1];

	cout << endl << endl;
	cout << s_novi << endl;
	cout << endl << endl;


	strofa1(1, 2);
	cout << strofa1 << endl;
	*/
	
	Stih s5;
	Stih s6;
	Stih s7;
	Stih s8;


	cout << "Unesite katren : " << endl;

	cin >> s5;
	cin >> s6;
	cin >> s7;
	cin >> s8;

	Katren kat1;

	kat1 += s5;
	kat1 += s6;
	kat1 += s7;
	kat1 += s8;

	cout << endl << "KATREN : " << endl;

	cout << kat1 << endl;

	cout << endl;
	cout << "Rimuju : " << *kat1 << endl;

	kat1(0, 1);


	cout << endl << "KATREN : " << endl;

	cout << kat1 << endl;

	cout << endl;
	cout << "Rimuju : " << *kat1 << endl;


	return 0;
}