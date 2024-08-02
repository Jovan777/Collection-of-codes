#include <iostream>
using namespace std;


class Hip {

public:
	int* niz;
	int n;
	int k;

	Hip(int nn, int* ni, int kk) : k(kk) {
		n = nn;
		niz = new int[nn];

		for (int i = 0; i < nn; i++)
		{
			niz[i] = ni[i];
		}

	}



	bool prazan() {
		return n == 0;
	}

	int get() {
		return niz[0];
	}

	void hipuj(int ind, int& bk) {
		bk = 0;
		int* deca = new int[k + 1];
		while (1)
		{
			bk++;
			for (int i = 1; i <= k; i++)
			{
				deca[i] = ((k * ind + i) < n) ? (k * ind + i) : -1;  //indeksi dece
			}

			int min_c = 1000000;
			int min_i;
			for (int i = 1; i <= k; i++)
			{
				if (deca[i] != -1 && niz[deca[i]] < min_c)  //nalazi najmanji od dece
				{
					min_i = deca[i];
					min_c = niz[deca[i]];

				}

			}

			if (min_c == 1000000)
			{
				break;
			}

			if (niz[ind] > niz[min_i])
			{
				int t = niz[ind];
				niz[ind] = niz[min_i];
				niz[min_i] = t;


			}
			ind = min_i;


		}



	}


	void napraviHip(int& bk) {
		int z = 0;
		for (int i = (n - 1) / k; i >= 0; i--) {
			hipuj(i, bk);
			z += bk;

		}
		bk = z;

	}

	void printHeap() {
		for (int i = 0; i < n; i++)
		{
			cout << niz[i] << " ";
		}
		cout << endl;

	}


	int izbaci(int& bk) {
		if (n <= 0)
		{
			return 0;
		}

		int k = niz[0];
		niz[0] = niz[n - 1];
		n--;
		hipuj(0, bk);

		return k;
	}

	void del(int& bk) {
		int z = 0;

		if (n <= 0)
		{
			return;
		}
		niz[0] = niz[n - 1];
		n--;
		hipuj(0, bk);



	}


	void podigni(int i, int& br) {
		int ind = i;
		br = 0;

		int par = (ind - 1) / k;

		while (par >= 0)
		{
			br++;
			if (niz[ind] < niz[par])
			{
				int t = niz[ind];
				niz[ind] = niz[par];
				niz[par] = t;


				ind = par;
				par = (ind - 1) / k;

			}
			else
			{
				break;
			}



		}



	}

	void ubaci(int i, int& br) {
		niz[n] = i;
		n++;
		podigni(n - 1, br);
		br++;

	}

	void izbaci_po_vrednosti(int broj, int& bk) {

		int* novi = new int[n - 1];
		int j = 0;

		for (int i = n - 1; i >= 0; i--)
		{
			if (niz[i] != broj)
			{
				novi[j++] = niz[i];
			}

		}

		for (int i = 0; i < j; i++)
		{
			//cout << novi[i] << " ";
		}

		Hip h(j, novi, k);




		h.napraviHip(bk);

		//cout <<endl<< "napravljen hip" << endl;
		for (int i = 0; i < h.n; i++)
		{
			//cout << h.niz[i] << " ";
		}
		cout << endl;

		niz = h.niz;
		n--;


	}



};