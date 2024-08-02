#include <iostream>
#include <fstream>
#include <chrono>
#include <thread>
#include "heap.h"


using namespace std;


using namespace std::chrono;










void promeni_red(Hip& h,int k, int& bk) {

	int* novi = new int[h.n];
	int j = 0;

	for (int i = h.n - 1; i >= 0; i--)
	{
		
		novi[j++] = h.niz[i];
		

	}

	for (int i = 0; i < j; i++)
	{
		//cout << novi[i] << " ";
	}

	Hip h1(j, novi, k);

	h1.napraviHip(bk);

	//cout << endl << "napravljen hip" << endl;
	for (int i = 0; i < h.n; i++)
	{
		//cout << h1.niz[i] << " ";
	}
	cout << endl; 

	h.niz = h1.niz;



}

Hip spoji(Hip h1, Hip h2, int m, int& bk) {
	int* niz = new int[h1.n + h2.n];

	bk = 0;
	int j = 0;
	for (int i = 0; i < h1.n; i++)
	{
		niz[j++] = h1.niz[i];
	}
	for (int i = 0; i < h2.n; i++)
	{
		niz[j++] = h2.niz[i];
	}

	Hip h(j, niz, m);

	h.napraviHip(bk);

	return h;

}




int main() {



	int* d1 = new int[10];
	int* d2 = new int[100];
	int* d3 = new int[1000];
	int* d4 = new int[10000];
	int* d5 = new int[100000];

	ifstream f1;
	ifstream f2;
	ifstream f3;
	ifstream f4;
	ifstream f5;

	f1.open("dat1.txt");
	f2.open("dat2.txt");
	f3.open("dat3.txt");
	f4.open("dat4.txt");
	f5.open("dat5.txt");

	int z = 0;

	while (f1>>d1[z])
	{
		z++;
	}
	int duz1 = z;

	f1.close();

	z = 0;

	while (f2 >> d2[z])
	{
		z++;
	}

	int duz2 = z;

	f2.close();
	
	z = 0;

	while (f3 >> d3[z])
	{
		z++;
	}

	int duz3 = z;

	f3.close();

	z = 0;

	while (f4 >> d4[z])
	{
		z++;
	}

	int duz4 = z;

	f4.close();

	z = 0;

	while (f5 >> d5[z])
	{
		z++;
	}

	int duz5 = z;

	f5.close();


	/*
	for (int i = 0; i < duz1; i++)
	{
		cout << d1[i] << " ";
		if (i%100==0 && i!=0)
		{
			cout << endl;
		}
	}
	cout << endl << endl;

	Hip h10(duz1, d1, 2);
	cout << endl << endl;

	int brojac = 0;

	h10.napraviHip(brojac);

	for (int i = 0; i < h10.n; i++)
	{
		cout << h10.niz[i] << " ";
	}
	cout << endl << endl;
	
	int u;

	h10.ubaci(17, u);

	cout << endl << "broj koraka : " << u << endl;
	cout << endl << "broj koraka algoritma : " << brojac << endl;

	h10.izbaci(u);
	h10.del(u);
	cout << endl << "broj koraka brisanja: " << u << endl;
	for (int i = 0; i < h10.n; i++)
	{
		cout << h10.niz[i] << " ";
	}


	int niz[] = { 10, 9, 6, 7, 8 ,4, 5, 3, 2 ,15, 18, 21, 99, 55, 77, 33,57,63,64,100,86 };
	int n = 20;
	int k = 3;

	Hip h20(n, niz, k);

	h20.napraviHip(u);
	cout << endl << endl;
	for (int i = 0; i < h20.n; i++)
	{
		cout << h20.niz[i] << " ";
	}


	Hip h30=spoji(h10, h20, 4, u);

	cout << endl << endl;
	for (int i = 0; i < h30.n; i++)
	{
		cout << h30.niz[i] << " ";
	}

	cout << endl << "broj koraka pri spajanju : " << u << endl;

	*/

	auto start = high_resolution_clock::now();


	std::this_thread::sleep_for(seconds(1));


	auto end = high_resolution_clock::now();


	duration<double, std::milli> time_ellapsed_ms = end - start;

	Hip h1002(100, d2, 2);
	Hip h1004(100, d2, 4);
	Hip h1008(100, d2, 8);

	Hip h10002(1000, d3, 2);
	Hip h10004(1000, d3, 4);
	Hip h10008(1000, d3, 8);


	Hip h100002(10000, d4, 2);
	Hip h100004(10000, d4, 4);
	Hip h100008(10000, d4, 8);

	Hip h1000002(100000, d5, 2);
	Hip h1000004(100000, d5, 4);
	Hip h1000008(100000, d5, 8);


	int bk;
	int bk2 = 0;
	
	cout << "      \t\t\t\t\t\t\t       MERENJE  PERFOMANSI " << endl<<endl<<endl;


	cout << "Broj elemenata, red\t\tVreme umetanja\t\tBroj koraka za umetanje\t\tVreme izbacivanja\t\tBroj Koraka izbacivanja";
	cout << endl;
	
	
	start= high_resolution_clock::now();
	h1002.napraviHip(bk);
	end = high_resolution_clock::now();
	time_ellapsed_ms = end - start;
	cout << "100, 2\t\t\t\t";
	cout << time_ellapsed_ms.count() << "\t\t\t" << bk<<"\t\t\t\t";

	start = high_resolution_clock::now();

	bk2 = 0;
	while (h1002.n!=0)
	{
		h1002.del(bk);
		bk2 += bk;

	}
	end = high_resolution_clock::now();
	cout << time_ellapsed_ms.count() << "\t\t\t\t" << bk2 << endl;


	start = high_resolution_clock::now();
	h1004.napraviHip(bk);
	end = high_resolution_clock::now();
	time_ellapsed_ms = end - start;
	cout << "100, 4\t\t\t\t";
	cout << time_ellapsed_ms.count() << "\t\t\t" << bk << "\t\t\t\t";

	start = high_resolution_clock::now();

	bk2 = 0;
	while (h1004.n != 0)
	{
		h1004.del(bk);
		bk2 += bk;

	}
	end = high_resolution_clock::now();
	cout << time_ellapsed_ms.count() << "\t\t\t\t" << bk2 << endl;


	start = high_resolution_clock::now();
	h1008.napraviHip(bk);
	end = high_resolution_clock::now();
	time_ellapsed_ms = end - start;
	cout << "100, 8\t\t\t\t";
	cout << time_ellapsed_ms.count() << "\t\t\t" << bk << "\t\t\t\t";

	start = high_resolution_clock::now();

	bk2 = 0;
	while (h1008.n != 0)
	{
		h1008.del(bk);
		bk2 += bk;

	}
	end = high_resolution_clock::now();
	cout << time_ellapsed_ms.count() << "\t\t\t\t" << bk2 << endl;


	start = high_resolution_clock::now();
	h10002.napraviHip(bk);
	end = high_resolution_clock::now();
	time_ellapsed_ms = end - start;
	cout << "1000, 2\t\t\t\t";
	cout << time_ellapsed_ms.count() << "\t\t\t" << bk << "\t\t\t\t";

	start = high_resolution_clock::now();

	bk2 = 0;
	while (h10002.n != 0)
	{
		h10002.del(bk);
		bk2 += bk;

	}
	end = high_resolution_clock::now();
	cout << time_ellapsed_ms.count() << "\t\t\t\t" << bk2 << endl;


	start = high_resolution_clock::now();
	h10004.napraviHip(bk);
	end = high_resolution_clock::now();
	time_ellapsed_ms = end - start;
	cout << "1000, 4\t\t\t\t";
	cout << time_ellapsed_ms.count() << "\t\t\t" << bk << "\t\t\t\t";

	start = high_resolution_clock::now();

	bk2 = 0;
	while (h10004.n != 0)
	{
		h10004.del(bk);
		bk2 += bk;

	}
	end = high_resolution_clock::now();
	cout << time_ellapsed_ms.count() << "\t\t\t\t" << bk2 << endl;

	

	start = high_resolution_clock::now();
	h10008.napraviHip(bk);
	end = high_resolution_clock::now();
	time_ellapsed_ms = end - start;
	cout << "1000, 8\t\t\t\t";
	cout << time_ellapsed_ms.count() << "\t\t\t" << bk << "\t\t\t\t";

	start = high_resolution_clock::now();

	bk2 = 0;
	while (h10008.n != 0)
	{
		h10008.del(bk);
		bk2 += bk;

	}
	end = high_resolution_clock::now();
	cout << time_ellapsed_ms.count() << "\t\t\t\t" << bk2 << endl;


	start = high_resolution_clock::now();
	h100002.napraviHip(bk);
	end = high_resolution_clock::now();
	time_ellapsed_ms = end - start;
	cout << "10000, 2\t\t\t";
	cout << time_ellapsed_ms.count() << "\t\t\t" << bk << "\t\t\t\t";

	start = high_resolution_clock::now();

	bk2 = 0;
	while (h100002.n != 0)
	{
		h100002.del(bk);
		bk2 += bk;

	}
	end = high_resolution_clock::now();
	cout << time_ellapsed_ms.count() << "\t\t\t\t" << bk2 << endl;


	start = high_resolution_clock::now();
	h100004.napraviHip(bk);
	end = high_resolution_clock::now();
	time_ellapsed_ms = end - start;
	cout << "10000, 4\t\t\t";
	cout << time_ellapsed_ms.count() << "\t\t\t" << bk << "\t\t\t\t";

	start = high_resolution_clock::now();

	bk2 = 0;
	while (h100004.n != 0)
	{
		h100004.del(bk);
		bk2 += bk;

	}
	end = high_resolution_clock::now();
	cout << time_ellapsed_ms.count() << "\t\t\t\t" << bk2 << endl;



	start = high_resolution_clock::now();
	h100008.napraviHip(bk);
	end = high_resolution_clock::now();
	time_ellapsed_ms = end - start;
	cout << "10000, 8\t\t\t";
	cout << time_ellapsed_ms.count() << "\t\t\t" << bk << "\t\t\t\t";

	start = high_resolution_clock::now();

	bk2 = 0;
	while (h100008.n != 0)
	{
		h100008.del(bk);
		bk2 += bk;

	}
	end = high_resolution_clock::now();
	cout << time_ellapsed_ms.count() << "\t\t\t\t" << bk2 << endl;

	
	start = high_resolution_clock::now();
	h1000002.napraviHip(bk);
	end = high_resolution_clock::now();
	time_ellapsed_ms = end - start;
	cout << "100000, 2\t\t\t";
	cout << time_ellapsed_ms.count() << "\t\t\t" << bk << "\t\t\t\t";

	start = high_resolution_clock::now();

	bk2 = 0;
	while (h1000002.n != 0)
	{
		h1000002.del(bk);
		bk2 += bk;

	}
	end = high_resolution_clock::now();
	cout << time_ellapsed_ms.count() << "\t\t\t\t" << bk2 << endl;


	start = high_resolution_clock::now();
	h1000004.napraviHip(bk);
	end = high_resolution_clock::now();
	time_ellapsed_ms = end - start;
	cout << "100000, 4\t\t\t";
	cout << time_ellapsed_ms.count() << "\t\t\t" << bk << "\t\t\t\t";

	start = high_resolution_clock::now();

	bk2 = 0;
	while (h1000004.n != 0)
	{
		h1000004.del(bk);
		bk2 += bk;

	}
	end = high_resolution_clock::now();
	cout << time_ellapsed_ms.count() << "\t\t\t\t" << bk2 << endl;


	start = high_resolution_clock::now();
	h1000008.napraviHip(bk);
	end = high_resolution_clock::now();
	time_ellapsed_ms = end - start;
	cout << "100000, 8\t\t\t";
	cout << time_ellapsed_ms.count() << "\t\t\t" << bk << "\t\t\t\t";

	start = high_resolution_clock::now();

	bk2 = 0;
	while (h1000008.n != 0)
	{
		h1000008.del(bk);
		bk2 += bk;

	}
	end = high_resolution_clock::now();
	cout << time_ellapsed_ms.count() << "\t\t\t\t" << bk2 << endl;


	cout << endl << endl << endl;


	char izbor;

	int brojac;
	Hip h10(10, d1, 2);
	h10.napraviHip(brojac);



	while (true)
	{
		cout << "                         MENI                      "<<endl<<
			"1.Stvaranje hipa                2.Dodavanje elementa u hip" << endl <<
			"3.Dohvatanje min. elementa      4.Brisanje min elementa" << endl <<
			"5.Pretvaranje hipa u novi red   6.Unija dva hipa" << endl <<
			"7.Ispis Hipa			8.Brisanje proizvoljnog kljuca" << endl <<
			"                          0.Kraj rada                          " << endl;


		cin >> izbor;
		cout << endl;

		if (izbor=='0')
		{
			break;
		}

		if (izbor=='1')
		{
			cout << "Unesite red Hipa : ";
			int r1;
			cin >> r1;

			cout << endl << "Izaberite"<<endl << "1.Vec postojeci niz iz datoteke     2.Unesite niz" << endl;
			char izbor2;
			cin >> izbor2;
			cout << endl;
			

			if (izbor2=='1')
			{
				int brojac2;
				h10.napraviHip(brojac);
				promeni_red(h10, r1, brojac2);

				cout << "Hip napravljen u : " << brojac << " koraka" << endl;
				h10.printHeap();
				cout << endl;

			}
			else if (izbor2=='2')
			{
				cout << "Unesite broj elemenata niza : ";
				int nti;
				cin >> nti;
				int* novi = new int[nti];
				cout << "Unesite elemente niza : " << endl;
				for (int i = 0; i < nti; i++)
				{
					cin >> novi[i];
				}
				Hip h20(nti, novi, r1);
				h20.napraviHip(brojac);

				cout << "Hip napravljen u : " << brojac << " koraka" << endl;
				h20.printHeap();
				cout << endl;


			}

			


			



		}

		if (izbor=='7')
		{
			h10.printHeap();
		}

		
		if (izbor == '2')
		{

			int novi_br;
			cout << "Unesite broj : ";
			cin >> novi_br;
			h10.ubaci(novi_br, brojac);
			cout << "Broj dodat u : " << brojac << " koraka" << endl;
			cout << "Novi Hip : " << endl;
			h10.printHeap();
			cout << endl;


		}

		if (izbor=='3')
		{
			cout << "Minimalni element u Hipu : "<<h10.niz[0]<<endl;


		}

		if (izbor == '4')
		{
			cout << "Minimalni element u Hipu : " << h10.niz[0] << endl;

			h10.izbaci(brojac);
			h10.printHeap();


		}


		if (izbor=='5')
		{
			cout << "Unesite novi red : ";
			int novi_red;
			cin >> novi_red;

			h10.printHeap(); cout << endl;
			promeni_red(h10, novi_red, brojac);
			h10.printHeap(); cout << endl;

		}


		if (izbor=='6')
		{
			
			cout << "Unesite broj elemenata niza : ";
			int nti;
			cin >> nti;
			int* novi = new int[nti];
			cout << "Unesite elemente niza : " << endl;
			for (int i = 0; i < nti; i++)
			{
				cin >> novi[i];
			}
			Hip h20(nti, novi, 2);
			h20.napraviHip(brojac);

			cout << "Unesite red konacnog Hipa : ";
			int redH;
			cin >> redH;

			int* niz_br = new int[h10.n + h20.n];
			int j = 0;
			for (int i = 0; i < h10.n; i++)
			{
				niz_br[j++] = h10.niz[i];
			}
			for (int i = 0; i < h20.n; i++)
			{
				niz_br[j++] = h20.niz[i];
			}



			Hip h3(j, niz_br, redH);
			h3.napraviHip(brojac);

			cout << "Konacni Hip : " << endl;
			h3.printHeap();
			cout << endl;



		}


		if (izbor=='8')
		{
			cout << "Unesite kljuc za brisanje : ";
			int kljuc;
			cin >> kljuc;

			bool nasao = false;
			for (int i = 0; i < h10.n; i++)
			{
				if (h10.niz[i]==kljuc)
				{
					nasao = true;
					break;
				}
			}
			if (nasao==false)
			{
				cout << "Kljuc se ne nalazi u Hipu"<<endl;
			}
			else
			{
				h10.printHeap(); cout << endl;
				h10.izbaci_po_vrednosti(kljuc, brojac);
				h10.printHeap(); cout << endl;


			}


		}






	}

	cout << endl << "Kraj rada" << endl;

	return 0;
}

