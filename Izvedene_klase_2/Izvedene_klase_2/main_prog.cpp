#include "tacka6.h"
#include "linija.h"
#include "duz1.h"
#include "izlomljena.h"
#include "poligon.h"
using namespace Linije;
#include "skup2.h"
#include "kompl2.h"
#include "tekst3.h"
#include <iostream>
#include <cstdlib>
#include "sfera2.h"
#include "valjak2.h"
#include "red_tela.h"
#include <iostream>
#include "imenik2.h"
#include "student2.h"
#include "osoba2.h"
#include <string>

using namespace std;


int main() {
  
	Imenik imen;

	while (true)
	{

		cout << "Vrsta : ";
		char vrs; cin >> vrs;
		if (vrs=='.')
		{
			break;
		}
		cout << "Ime : "; string ime; cin >> ime;
		cout << "Godine : "; int god; cin >> god;
		if (vrs=='o')
		{
			imen += new Osoba(ime, god);
		}
		else
		{
			Student* stud = new Student(ime, god);
			while (true)
			{
				cout << "Ocene : ";
				int oce; cin >> oce;
				if (oce==0)
				{
					break;
				}
				stud += oce;

			}
			imen += stud;
		}



	}

	cout << endl;
	cout << imen;



}
