#include <iostream>
#include <cstdlib>
#include <string>
#include <fstream>




using namespace std;


int* ucitaj(int n, string fajl) {
	int* niz  = new int[n];

	ifstream ulaz;
	ulaz.open(fajl.c_str());

	if (ulaz.is_open())
	{
		for (int i = 0; i < n; i++)
		{
			ulaz >> niz[i];

		}

		ulaz.close();
	}
	else
	{
		cout << "Ne postoji fajl";
	}


	return niz;
}

int* unesiNiz(int n) {


	int* niz = new int[n];
	cout << "Unesite elemente niza : " << endl;
	for (int i = 0; i < n; i++)
	{
		cin >> niz[i];
	}

	return niz;
}

void ispisiNiz(int* niz, int n)  {
	for (int i = 0; i < n; i++)
	{
		cout << niz[i] << " ";

	}

}

int* generisiNiz(int n, int min, int max) {

	int* niz = new int[n];
	niz[0] = rand() % (max - min + 1) + min;
	for (int i = 1; i < n; i++)
	{
		int br = 0;
		while (br<niz[i-1])
		{
			br = rand() % (max - min + 1) + min;
		}
		niz[i] = br;


	}

	for (int i = 0, j = n - 1; i < n / 2; i++, j--)
	{
		int temp = niz[i];
		niz[i] = niz[j];
		niz[j] = temp;
	}


	return niz;
}

int* obrni(int* niz, int n) {
	int* niz2 = new int[n];
	
	for (int i = 0, j=n-1; i < n; i++, j--)
	{
		niz2[i] = niz[j];
	}

	return niz2;
}

int interpolacija(int* niz, int l, int h, int x) {

	int low = l;
	int high = h;
	while (low <= high && x >= niz[low] && x <= niz[high])
	{
		if (low == high)
		{
			if (niz[low] == x) return low;
			return -1;
		}
		// Probing the position with keeping
		// uniform distribution in mind.
		int pos = low + (((double)(high - low) /
			(niz[high] - niz[low])) * (x - niz[low]));

		// Condition of target found
		if (niz[pos] == x)
			return pos;

		// If x is larger, x is in upper part
		if (niz[pos] < x)
			low = pos + 1;

		// If x is smaller, x is in the lower part
		else
			high = pos - 1;
	}
	return -1;
}


int n_pretraga(int* array, int size, int n, int k, int& broj) {
	broj = 0;

	int interval = size / n;
	int* niz = obrni(array,size);

	int* low = new int[n]; low[0] = 0;
	int* high = new int[n]; high[0] = interval - 1;

	for (int i = 1; i < n; i++)
	{
		low[i] = low[i - 1] + interval;
		high[i] = high[i - 1] + interval;

	}
	
	int pos;
	for (int i = 0; i < n; i++)
	{
		broj++;
		pos = interpolacija(niz, low[i], high[i], k);
		if (pos!=-1)
		{
			return size - pos - 1;
		}


	}

	int lastLow = high[n - 1] + 1;
	int lastHigh = size - 1;

	pos = interpolacija(niz, lastLow, lastHigh, k);

	broj++;
	if (pos!=-1)
	{
		return size - pos - 1;

	}
	return -1;
}



int n_optimizovano(int* niz, int n, int* kljucevi, int size, int* indeksi, int m, int broj) {

	int oc = 0;
	for (int i = 0; i < size; i++)
	{
		indeksi[i] = n_pretraga(niz, n,m, kljucevi[i], broj);
		oc+=broj;

	}
	
	return oc;
}



void m_eval(int* niz, int size, int duzSekv) {

	for (int i = 2; i <= 6 ; i++)
	{
		int oc = 0;

		for (int j = 0; j < duzSekv; j++)
		{

			int indeks = rand() & (size);
			int kljuc = niz[indeks];
			int broj;
			int pos = n_pretraga(niz, size, i, kljuc, broj);
			oc += broj;

		}
		double eval = (double)oc / duzSekv;
		cout << "Prosecan broj koraka za pretragu jednog elementa za m = " << i << " je : " << eval << endl;
	}


}



void m_eval_optimizovano(int* niz, int size, int duzNiza, int brPor) {
	for (int i = 2; i <= 6; i++)
	{
		int* nizKljuceva = new int[duzNiza];
		int* nizIndeksa = new int[duzNiza];
		int oc = 0;
		int br=0;
		int z=0;
		for (int j = 0; j < brPor; j++)
		{
			
			for (int k = 0; k < duzNiza; k++)
			{
				int id = rand() % (size);
				//cout <<"ID : "<< id << endl;
				//cout <<"niz[id]" << niz[id] << endl;
				nizKljuceva[k] = niz[id];
				//ispisiNiz(nizKljuceva, duzNiza);
			}

			br = n_optimizovano(niz, size, nizKljuceva, duzNiza, nizIndeksa, i, z);
			//ispisiNiz(nizKljuceva, duzNiza); cout << endl;
			//ispisiNiz(nizIndeksa, duzNiza); cout << endl;


			oc += br;

		}

		double rez= (double)oc / brPor;
		cout << "Prosecan broj koraka za pretragu " << duzNiza << " elemenata za m = " << i << " je : " << rez << endl;



	}

}







int main() {
	
	int* niz = ucitaj(10, "niz.txt");

	for (int i = 0; i < 10; i++)
	{
		cout << niz[i] << " ";
	}

	cout << endl << endl;

	//int* niz2 = unesiNiz(5);
	//ispisiNiz(niz, 5);
	cout << endl << endl<<endl;

	int* niz3 = generisiNiz(10, 543, 11543);
	ispisiNiz(niz3, 10);

	cout << endl;
	int niz5[] = { 1,2,3,4,5 };


	int mid;
	// mid = interpolacija(niz5, 5, 4);
	//cout << mid << endl;

	/*
	obrni(niz3, 10);
	
	ispisiNiz(niz3, 10);
	mid = interpolacija(niz3, 0, 9, 8711);
	cout << endl;
	cout << mid << endl;
	*/
	int* niz7 = obrni(niz3, 10);
	ispisiNiz(niz7, 10);
	cout << endl;
	mid = interpolacija(niz7, 0, 9, 8711);
	cout << endl;
	cout << mid << endl;

	cout << endl;
	cout << endl;
	cout << endl;
	cout << endl;
	cout << endl;
	
	int oc;
	mid = n_pretraga(niz3, 10, 3, 11490, oc);
	cout <<"Pozicija : "<< mid << endl;
	cout << "Element : " << niz3[mid] << endl;

	cout <<"Broj koraka : "<< oc << endl;

	cout << endl;
	cout << endl;
	cout << endl;

	int niz9[] = {11490, 11298, 8009};

	int* niz10 = new int[3];

	n_optimizovano(niz3, 10, niz9, 3, niz10, 3, oc);

	ispisiNiz(niz10, 3); cout << endl;
	//cout << oc << endl;

	cout << endl;
	cout << endl;
	cout << endl;
	

	m_eval(niz3, 10, 5);

	oc=n_optimizovano(niz3, 10, niz9, 3, niz10, 3, oc);
	//cout << oc << endl;
	ispisiNiz(niz9, 3); cout << endl;
	ispisiNiz(niz10, 3); cout << endl;

	cout << endl;
	cout << oc;
	cout << endl;
	cout << endl;

	m_eval_optimizovano(niz3, 10, 5, 3);


	return 0;
}
