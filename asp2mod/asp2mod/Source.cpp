#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;



class Cvor {

public:
	int broj;
	Cvor* levi, * desni, * otac;


	Cvor(int b = 0, Cvor* o = nullptr, Cvor* l = nullptr, Cvor* d = nullptr) :
		broj(b), levi(l), desni(d), otac(o) {};


	void postaviOca(Cvor* o) {
		otac = o;
	}

	void postaviBroj(int b) {
		broj = b;
	}

	void pisi() const {
		cout << "Cvor u stablu : " << broj;
	}

	void dodaj(Cvor* root, int br) {

		if (root==nullptr)
		{
			root = new Cvor(br);
			return;
		}

		Cvor* temp = root;
		Cvor* otac = nullptr;
		while (temp)
		{
			if (temp->broj>br)
			{
				otac = temp;
				temp = temp->levi;
			}
			else
			{
				otac = temp;
				temp = temp->desni;
			}



		}
		temp = new Cvor(br);
		if (temp->broj>otac->broj)
		{
			otac->desni = temp;
		}
		else
		{
			otac->levi = temp;
		}




		return;

	}

	void inorder(Cvor* root) {
		if (root==nullptr)
		{
			return;
		}

		inorder(root->levi);
		cout << root->broj << " ";
		inorder(root->desni);



	}


};


void inorder(Cvor* root)
{
	if (root == nullptr) {
		return;
	}

	inorder(root->levi);
	cout << root->broj << " ";
	inorder(root->desni);
}


vector<int> napraviListu(Cvor* root, vector<int>& lista) {
	if (root==NULL)
	{
		return lista;
	}

	napraviListu(root->levi, lista);
	lista.push_back(root->broj);
	napraviListu(root->desni, lista);

	return lista;
}


void par(Cvor* root, int broj) {

	vector<int> niz1;
	vector<int> niz2 = napraviListu(root, niz1);

	int low = 0;
	int high = (int)niz2.size() - 1;

	while (low<high)
	{
		if (niz2[low]+niz2[high]==broj)
		{
			cout << "Pronadjen par : " << niz2[low] << " + " << niz2[high] << endl;
			return;
		}
		if (niz2[low] + niz2[high] > broj)
		{
			high--;

		}
		if (niz2[low] + niz2[high] < broj)
		{
			low++;
		}


	}

	cout << "Par nije pronadjen";
	return;

}

void crtaj(Cvor* stb, int nivo) {

	if (stb)
	{
		crtaj(stb->desni, nivo + 1);
		cout << setw(4 * nivo) << "" << stb->broj << endl;
		crtaj(stb->levi, nivo + 1);
	}

}


Cvor* pronadjiPretka(Cvor* root, int n1, int n2) {


	if (root==NULL)
	{
		return nullptr;
	}
	

	if (root->broj==n1 || root->broj==n2)
	{
		return root;
	}

	Cvor* leviPredak = pronadjiPretka(root->levi, n1, n2);
	Cvor* desniPredak = pronadjiPretka(root->desni, n1, n2);

	if (leviPredak && desniPredak)
	{
		return root;
	}

	return (leviPredak != NULL) ? leviPredak : desniPredak;


}


void modifikuj(Cvor* root, int* sum){
	
	if (root==NULL)
	{
		return;
	}

	modifikuj(root->desni, sum);
	*sum = *sum + root->broj;
	root->broj = *sum;

	modifikuj(root->levi, sum);

}

void modifikujBST(Cvor* root) {
	int sum = 0;
	modifikuj(root, &sum);

}



int* spojiNizove(int niz1[], int niz2[], int m, int n) {
	int* niz = new int[m + n];
	int i = 0, j = 0, k = 0;


	while (i < m && j < n)
	{
		if (niz1[i]<niz2[j])
		{
			niz[k] = niz1[i];
			i++;

		}
		else
		{
			niz[k] = niz2[j];
			j++;
		}
		k++;


	}

	while (i<m)
	{
		niz[k] = niz1[i];
		i++;
		k++;

	}
	while (j<n)
	{
		niz[k] = niz2[j];
		k++; j++;

	}


	return niz;

}




void ubaciInorder(Cvor* c, int* niz, int* index) {
	if (c==NULL)
	{
		return;
	}

	ubaciInorder(c->levi, niz, index);
	niz[*index] = c->broj;
	(*index)++;
	ubaciInorder(c->desni, niz, index);
}



Cvor* NizUstablo(int niz[], int low, int high) {

	if (low>high)
	{
		return NULL;
	}

	int mid = (low + high) / 2;
	Cvor* c = new Cvor(niz[mid]);
	c->levi = NizUstablo(niz, low, mid - 1);
	c->desni = NizUstablo(niz, mid + 1, high);



	return c;

}


Cvor* spojiStabla(Cvor* c1, Cvor* c2, int m, int n) {
	int* niz1 = new int[m];
	int i = 0;
	ubaciInorder(c1, niz1, &i);


	int* niz2 = new int[n];
	int j = 0;
	ubaciInorder(c2, niz2, &j);

	int* niz = spojiNizove(niz1, niz2, m, n);



	return NizUstablo(niz, 0, m + n - 1);


}




















int main() {

	Cvor* root=new Cvor(13);
	root->dodaj(root, 15);
	root->dodaj(root, 21);
	root->dodaj(root, 10);
	root->dodaj(root, 25);
	root->dodaj(root, 1);
	root->dodaj(root, 27);
	root->dodaj(root, 7);
	

	inorder(root);
	cout << endl << endl;
	vector<int> niz1;
	niz1 = napraviListu(root, niz1);
	for (int i = 0; i < niz1.size(); i++)
	{
		cout << niz1[i] << " ";

	}

	cout << endl;
	par(root, 35);
	cout << endl;
	cout << endl;

	crtaj(root, 0);
	cout << endl;
	cout << endl;cout << endl;
	cout << endl;

	Cvor* c = pronadjiPretka(root, 21, 10);
	cout << c->broj << endl;
	cout << endl; cout << endl;
	cout << endl;

	modifikujBST(root);
	crtaj(root, 0);
	cout << endl;
	cout << endl;
	
	
	Cvor* root2 = new Cvor(13);
	root2->dodaj(root2, 15);
	root2->dodaj(root2, 21);
	root2->dodaj(root2, 10);
	root2->dodaj(root2, 25);

	Cvor* root3 = spojiStabla(root, root2, 8, 5);

	crtaj(root3, 0);

	return 0;
}