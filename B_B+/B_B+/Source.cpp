#include <iostream>

using namespace std; //////  B STABLO

class Cvor {

	int* niz;
	int t;  //red stabla
	Cvor** C;
	int n; //popunjenost cvora;
	bool jeList;

public:
	Cvor(int temp, bool list) {
		t = temp;
		jeList = list;

		niz = new int[2*t - 1];
		C = new Cvor * [2 * t];
		n = 0;

	}

	friend class BStablo;
	
	void prolaz() {

		int i;
		for ( i = 0; i < n; i++)
		{
			if (jeList==false)
			{
				C[i]->prolaz();
			}
			cout << " " << niz[i];

		}
		if (jeList==false)
		{
			C[i]->prolaz();
		}

	}

	Cvor* nadji(int k) {
		int i = 0;
		while (i<n && k>niz[i])
		{
			i++;
		}
		if (niz[i]==k)
		{
			return this;
		}
		if (jeList==true)
		{
			return nullptr;
		}

		return C[i]->nadji(k);


	}


	void ubaci_u_cvor(int k) {

		int i = n - 1;

		if (jeList==true)
		{
			while (i>=0 && niz[i]>k)
			{
				niz[i + 1] = niz[i];
				i--;
			}

			niz[i + 1] = k;
			n++;
		}
		else
		{
			while (i>=0 && niz[i]>k)
			{
				i--;
			}
			if (C[i+1]->n==2*t-1)
			{
				podeliCvor(i + 1, C[i + 1]);
				if (niz[i+1]<k)
				{
					i++;
				}


			}
			C[i + 1]->ubaci_u_cvor(k);


		}




	}

	void podeliCvor(int i, Cvor* y) {

		Cvor* z = new Cvor(y->t, y->jeList);
		z->n = t - 1;

		for (int j = 0; j < t-1; j++)
		{
			z->niz[j] = y->niz[j + t];
		}
		if (y->jeList==false)
		{
			for (int j = 0; j < t; j++)
			{
				z->C[j] = y->C[t + j];
			}

		}
		
		y->n = t - 1;
		for (int j = n; j >=i+1; j--)
		{
			C[j + 1] = C[j];

		}

		C[i + 1] = z;

		for (int j = n-1; j >=i; j--)
		{
			niz[j + 1] = niz[j];
		}
		niz[i] = y->niz[t - 1];
		n++;




	}

	int nadjiIndeks(int k) {
		int ind = 0;
		while (ind<n && niz[ind]<k)
		{
			++ind;
		}
		return ind;


	}

	void brisanje(int k) {
		int ind = nadjiIndeks(k);
		if (ind<n && niz[ind]==k)
		{
			if (jeList)
			{
				brisi_iz_lista(ind);
			}
			else
			{
				brisi_iz_stabla(ind);
			}


		}
		else
		{
			if (jeList)
			{
				cout << "Kljuc nije u stablu" << endl;
				return;
			}

			bool flag = ((ind == n) ? true : false);
			if (C[ind]->n<t)
			{
				popuni(ind);
			}

			if (flag && ind > n)
			{
				C[ind - 1]->brisanje(k);
			}
			else
			{
				C[ind]->brisanje(k);
			}



		}
		return;

	}

	void pozajmi_od_pred(int ind) {

		Cvor* child = C[ind];
		Cvor* sibling = C[ind - 1];

		for (int i = child->n - 1; i >= 0; --i)
			child->niz[i + 1] = child->niz[i];

		if (!child->jeList) {
			for (int i = child->n; i >= 0; --i)
				child->C[i + 1] = child->C[i];
		}

		child->niz[0] = niz[ind - 1];

		if (!child->jeList)
			child->C[0] = sibling->C[sibling->n];

		niz[ind - 1] = sibling->niz[sibling->n - 1];

		child->n += 1;
		sibling->n -= 1;

		return;



	}

	void pozajmi_od_sled(int idx) {

		Cvor* child = C[idx];
		Cvor* sibling = C[idx + 1];

		child->niz[(child->n)] = niz[idx];

		if (!(child->jeList))
			child->C[(child->n) + 1] = sibling->C[0];

		niz[idx] = sibling->niz[0];

		for (int i = 1; i < sibling->n; ++i)
			sibling->niz[i - 1] = sibling->niz[i];

		if (!sibling->jeList) {
			for (int i = 1; i <= sibling->n; ++i)
				sibling->C[i - 1] = sibling->C[i];
		}

		child->n += 1;
		sibling->n -= 1;

		return;


	}

	void popuni(int idx) {
		if (idx != 0 && C[idx - 1]->n >= t)
			pozajmi_od_pred(idx);

		else if (idx != n && C[idx + 1]->n >= t)
			pozajmi_od_sled(idx);

		else {
			if (idx != n)
				spoj(idx);
			else
				spoj(idx - 1);
		}
		return;


	}


	void brisi_iz_lista(int ind) {
		for (int i = ind+1; i < n ; i++)
		{
			niz[i - 1] = niz[i];
		}
		n--;

	}

	void brisi_iz_stabla(int ind) {
		int k = niz[ind];
		if (C[ind]->n>=t)
		{
			int pred = prethodnik(ind);
			niz[ind] = pred;
			C[ind]->brisanje(pred);
		}
		else if (C[ind+1]->n>=t)
		{
			int sled = sledbenik(ind);
			niz[ind] = sled;
			C[ind + 1]->brisanje(sled);

		}
		else
		{
			spoj(ind);
			C[ind]->brisanje(k);

		}

	}

	void spoj(int ind) {
		Cvor* deca = C[ind];
		Cvor* brat = C[ind + 1];

		deca->niz[t - 1] = niz[ind];
		for (int i = 0; i < brat->n ; i++)
		{
			deca->niz[i + t] = brat->niz[i];
		}
		if (!deca->jeList)
		{
			for (int i = 0; i <=brat->n; i++)
			{
				deca->C[i + t] = brat->C[i];
			}
		}

		for (int i = ind+1; i < i < n ; i++)
		{
			niz[i - 1] = niz[i];
		}
		for (int i = ind+2; i <=n; i++)
		{
			C[i - 1] = C[i];
		}

		deca->n += brat->n + 1;
		n--;

		delete(brat);
		return;



	};


	int prethodnik(int ind) {
		Cvor* temp = C[ind];
		while (!temp->jeList)
		{
			temp = temp->C[temp->n];
		}
		return temp->niz[temp->n - 1];

	}

	int sledbenik(int ind) {
		Cvor* temp = C[ind + 1];
		while (!temp->jeList)
		{
			temp = temp->C[0];
		}
		return temp->niz[0];

	}




};


class BStablo {

	Cvor* koren;
	int t;

public:
	BStablo(int temp) {
		koren = NULL;
		t = temp;

	}

	void prolaz() {
		if (koren!=NULL)
		{
			koren->prolaz();
		}
	}

	Cvor* nadji(int k) {
		return (koren != NULL) ? koren->nadji(k) : NULL;

	}

	void brisanje_iz_stabla(int k) {

		if (!koren)
		{
			cout << "Stablo je prazno";
		}
		koren->brisanje(k);
		if (koren->n==0)
		{
			Cvor* temp = koren;
			if (koren->jeList)
			{
				koren = nullptr;
			}
			else
			{
				koren = koren->C[0];
			}
			delete temp;

		}
		return;

	}

	void ubaci(int k) {
		if (koren==NULL)
		{
			koren = new Cvor(t, true);
			koren->niz[0] = k;
			koren->n = 1;
		}
		else
		{
			if (koren->n==2*t-1)
			{
				Cvor* s = new Cvor(t, false);
				s->C[0] = koren;
				s->podeliCvor(0, koren);

				int i = 0;
				if (s->niz[0] < k)
				{
					i++;
				}
				s->C[i]->ubaci_u_cvor(k);
				koren = s;


			}
			else
			{
				koren->ubaci_u_cvor(k);
			}



		}
		




	}


};




int main() {

	BStablo t(3);
	t.ubaci(8);
	t.ubaci(9);
	t.ubaci(10);
	t.ubaci(11);
	t.ubaci(15);
	t.ubaci(16);
	t.ubaci(17);
	t.ubaci(18);
	t.ubaci(20);
	t.ubaci(23);
	
	cout << "B stablo : ";
	t.prolaz();
	cout << endl;

	t.brisanje_iz_stabla(20);

	cout << "B stablo : ";
	t.prolaz();





	return 0;
}