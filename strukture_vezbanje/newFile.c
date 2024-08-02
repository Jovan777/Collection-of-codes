#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

//Polinomi
/*
//struktura polinom i fje za obradu polinoma
typedef struct {

	double a[21];
	int n;

}Poli;


Poli zbir(Poli p1, Poli p2) {//
	Poli p;

	p.n = (p1.n > p2.n) ? p1.n : p2.n;

	for (int i = 0; i <=p.n; i++)
	{
		if (i > p2.n)
		{
			p.a[i] = p1.a[i];
		}
		else if (i > p1.n)
		{
			p.a[i] = p2.a[i];
		}
		else
		{
			p.a[i] = p1.a[i] + p2.a[i];
		}

	}
	while (p.n>=0 && p.a[p.n]==0)
	{
		p.n--;

	}

	return p;
}

Poli razlika(Poli p1, Poli p2) {//

	Poli p;
	p.n = (p1.n > p2.n) ? p1.n : p2.n;

	for (int i = 0; i <= p.n; i++)
	{
		if (i>p2.n)
		{
			p.a[i] = p1.a[i];
		}
		else if (i>p1.n)
		{
			p.a[i] = -p2.a[i];
		}
		else
		{
			p.a[i] = p1.a[i] - p2.a[i];
		}

	}

	while (p.n>=0 && p.a[p.n]==0)
	{
		p.n--;
	}

	return p;


}

Poli proizvod(Poli p1, Poli p2) {//

	Poli p;
	p.n = (p1.n < 0 || p2.n < 0) ? -1 : p1.n + p2.n;
	for (int i = 0; i <= p.n; p.a[i++] = 0);

	for (int i = 0; i <=p1.n ; i++)
	{
		for (int j = 0; j <=p2.n; j++)
		{
			p.a[i + j] += p1.a[i] * p2.a[j];

		}
	}

	return p;
}


Poli kolicnik(Poli p1, Poli p2,Poli *ostatak) {//

	Poli p;
	p.n = p1.n - p2.n;

	for (int i = p.n; i >=0; i--)
	{
		p.a[i] = p1.a[p2.n + i] / p2.a[p2.n];
		for (int j = 0; j <=p2.n; j++)
		{
			p1.a[j+i] -= p2.a[j] * p.a[i];

		}

	}

	while (p1.n >= 0 && p1.a[p1.n]==0)
	{
		p1.n--;
	
	}
	*ostatak = p1;
	return p;



}



Poli citajPoli() {//

	Poli p;
	scanf("%d", &p.n);

	for (int i = p.n; i >=0; i--)
	{
		scanf("%lf", &p.a[i]);
	}

	return p;

}


void pisiPoli(Poli p, char f[]) {//

	printf("p[");
	for (int i = p.n; i >= 0; i--)
	{
		printf(f, p.a[i]);
		if (i>0)
		{
			putchar('+');
		}

	}
	putchar(']');

}
*/


//Dinamicki nizovi
/*
//struktura dinamicki niz i fje za obradu din. niza
typedef struct {

	int* a;//pokazivac na elemente niza//u sustini pokazivac na memoriju koja postaje niz
	int n;//duzina niza

}Din_niz;


Din_niz sastavi(int* a, int n) {// od nekog statickog niza pravimo dinamicki

	Din_niz dn;
	dn.n = n;
	
	dn.a = malloc(dn.n * sizeof(int));

	for (int i = 0; i < n; i++)
	{
		dn.a[i] = a[i];
	}

	return dn;

}


Din_niz citaj() {//fja preko koje unosimo dinamicki niz

	Din_niz dn;
	printf("Unesite duzinu niza: ");
	scanf("%d", &dn.n);

	if (dn.n>0)
	{
		if ((dn.a=malloc(dn.n*sizeof(int)))==NULL)//alociranje memorije za din_niz
		{
			exit(1);
		}
		printf("Elementi niza: ");
		for (int i = 0; i < dn.n; i++)
		{
			scanf("%d", &dn.a[i]);
		}
		
	}
	else
	{
		dn.a = NULL;
	}

	return dn;

}


void pisi(Din_niz dn) {//

	for (int i = 0; i < dn.n; i++)
	{
		printf("%6d", dn.a[i]);
		if (i%10==9 || i==dn.n-1)
		{
			putchar('\n');
		}
	}


}

void razlozi(Din_niz dn, int* a, int *n) {//razlaganje dinamickog niza na obican niz i dobijanje te duzine

	for (int i = 0; i < dn.n; i++)
	{
		a[i] = dn.a[i];
	}
	*n = dn.n;

}

Din_niz kopiraj(Din_niz dn) {//

	Din_niz dn2;

	dn2.n = dn.n;

	if ((dn2.a=malloc(dn2.n*sizeof(int)))==NULL)//alociranje memorije za novi din_niz
	{
		exit(-1);
	}

	for (int i = 0; i < dn.n; i++)
	{
		dn2.a[i] = dn.a[i];
	}

	return dn2;

}

void obrni(Din_niz dn) {//

	for (int* a = dn.a, *b=a+dn.n-1 ;  a< b; a++, b--)
	{
		int c = *a;
		*a = *b;
		*b = c;
	}


}

void izostavi(Din_niz *dn, int k) {//

	int j = 0;

	for (int i = 0; i < dn->n; i++)
	{
		if (dn->a[i]!=k)
		{
			dn->a[j++] = dn->a[i];
		}
	}

	dn->n = j;
	dn->a = realloc(dn->a,j* sizeof(int));//realloc(sta se realocira, koliko cega se alocira)


}
*/

//Dinamicke matrice
/*
typedef struct {

	float** a;//memorija u koju ce uci nasi elementi

	int m, n;
}Din_mat;

Din_mat stvori(int m, int n) {//

	Din_mat dm = { malloc(m * sizeof(float*)), m, n };

	for (int i = 0; i < m; i++)
	{
		dm.a[i] = malloc(n * sizeof(float));
	}

	return dm;
}


void unisti(Din_mat dm) {

	for (int i = 0; i < dm.m; i++)
	{
		free(dm.a[i]);
	}

	free(dm.a);

}

Din_mat citaj(int m, int n) {//

	Din_mat dm = stvori(m, n);
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			scanf("%f", &dm.a[i][j]);
		}
	}

	return dm;

}


void pisi(Din_mat dm, const char* frm, int max) {//

	for (int i = 0; i < dm.m; i++)
	{
		for (int j = 0; j < dm.n; j++)
		{
			printf(frm, dm.a[i][j]);
			putchar((j % max == max - 1 || j == dm.n - 1) ? '\n' : ' ');
		}
		if (dm.n>max)
		{
			putchar('\n');
		}

	}


}

Din_mat kopiraj(Din_mat dm) {//

	Din_mat dm2 = stvori(dm.m, dm.n);

	for (int i = 0; i < dm2.m; i++)
	{
		for (int j = 0; j < dm2.n; j++)
		{
			dm2.a[i][j] = dm.a[i][j];
		}
	}

	return dm2;

}

Din_mat transpon(Din_mat dm) {//

	Din_mat dm2 = stvori(dm.n, dm.m);

	for (int i = 0; i < dm.m; i++)
	{
		for (int j = 0; j < dm.n; j++)
		{
			dm2.a[j][i] = dm.a[i][j];

		}

	}

	return dm2;

}


Din_mat zbir(Din_mat dm1, Din_mat dm2) {//

	Din_mat dm3 = stvori(dm1.m, dm1.n);

	for (int i = 0; i < dm3.m; i++)
	{
		for (int j = 0; j < dm3.n; j++)
		{
			dm3.a[i][j] = dm1.a[i][j] + dm2.a[i][j];

		}

	}


	return dm3;
}

Din_mat razlika(Din_mat dm1, Din_mat dm2) {

	Din_mat dm3 = stvori(dm1.m, dm1.n);

	for (int i = 0; i < dm1.m; i++)
	{
		for (int j = 0; j < dm1.n; j++)
		{
			dm3.a[i][j] = dm1.a[i][j] - dm2.a[i][j];
		}
	}

	return dm3;
}


Din_mat proizvod(Din_mat dm1, Din_mat dm2) {

	Din_mat dm3 = stvori(dm1.m, dm2.n);

	for (int i = 0; i < dm3.m; i++)
	{
		for (int k = 0; k < dm3.n; k++)
		{
			dm3.a[i][k] = 0;
			for (int j = 0; j < dm2.n; j++)
			{
				dm3.a[i][k] += dm1.a[i][j] * dm2.a[j][k];
			}

		}


	}

	return dm3;



}
*/


typedef struct elem {

	int broj;
	struct elem* sled;

}Elem;


//ulancane liste iterativno
/*
Elem* citaj2(int n) {

	Elem* prvi = NULL;
	Elem* posl = NULL;

	for (int i = 0; i < n; i++)
	{
		Elem* novi = malloc(1 * sizeof(int));
		scanf("%d", &novi->broj);
		novi->sled = NULL;
		if (!prvi)
		{
			prvi = novi;
		}
		else
		{
			posl->sled = novi;
		}
		posl = novi;
	}

	return prvi;

}

Elem* citaj3(int n) {

	Elem* prvi = NULL;
	Elem* posl = NULL;

	for (int i = 0; i < n; i++)
	{
		Elem* novi = malloc(1 * sizeof(int));
		scanf("%d", &novi->broj);
		novi->sled = NULL;
		if (!prvi)
		{
			prvi = novi;
		}
		else
		{
			posl->sled = novi;
		}

		posl = novi;

	}

	return prvi;

}



Elem* citaj(int n) {

	Elem* prvi = NULL;
	for (int i = 0; i < n; i++)
	{
		Elem* novi = malloc(1 * sizeof(int));
		scanf("%d", &novi->broj);
		novi->sled = prvi;
		prvi = novi;

	}

	return prvi;
}


void pisi(Elem* lst) {

	while (lst)
	{
		printf("%d ", lst->broj);
		lst = lst->sled;
	}

}


void brisi(Elem* lst) {

	while (lst)
	{
		Elem* stari = lst;
		lst = lst->sled;
		free(stari);
	}
}


int duzina(Elem* lst) {
	int brojac = 0;
	while (lst)
	{
		brojac++;
		lst = lst->sled;
	}

	return brojac;
}


Elem* na_pocetak(Elem* lst, int b) {

	Elem* novi = malloc(1 * sizeof(int));
	novi->broj = b;
	novi->sled = lst;
	lst = novi;

	return lst;
}


Elem* na_kraj(Elem* lst, int b) {

	Elem* novi = malloc(1 * sizeof(int));
	novi->broj = b;
	novi->sled = NULL;
	if (!lst)
	{
		return novi;
	}
	else
	{
		Elem* tekuci = lst;
		while (tekuci->sled)
		{
			tekuci = tekuci->sled;
		}

		tekuci->sled = novi;
		return lst;

	}
}


Elem* umetni(Elem* lst, int b) {

	Elem* tek = lst, * pret = NULL;
	while (tek && tek->broj<b)
	{
		pret = tek;
		tek = tek->sled;

	}

	Elem* novi = malloc(1 * sizeof(int));
	novi->broj = b;

	novi->sled = tek;
	if (!pret)
	{
		lst = novi;
	}
	else
	{
		pret->sled = novi;
	}

	return lst;

}

Elem* izostavi(Elem* lst, int b) {

	Elem* tek = lst, * pret = NULL;

	while (tek)
	{
		if (tek->broj!=b)
		{
			pret = tek;
			tek = tek->sled;
		}
		else
		{
			Elem* stari = tek;
			tek = tek->sled;
			if (!pret)
			{
				lst = tek;
			}
			else
			{
				pret->sled = tek;
			}
			free(stari);

		}

	}

	return lst;

}
*/


//ulancane liste rekurzivno

int duz(Elem* lst) {

	return lst ? duz(lst->sled) + 1 : 0;

}


void pisi(Elem* lst) {
	if (lst)
	{
		printf("%d ", lst->broj);
		pisi(lst->sled);
	}

}


Elem* na_pocetak(Elem* lst, int b) {
	Elem* novi = malloc(1 * sizeof(Elem));
	novi->broj = b; novi->sled = lst;

	return novi;
}


Elem* na_kraj(Elem* lst, int b) {

	if (!lst)
	{
		lst = malloc(1 * sizeof(Elem));
		lst->broj = b;
		lst->sled = NULL;
	}
	else
	{
		lst->sled = na_kraj(lst->sled, b);
	}

	return lst;

}


Elem* citaj1(int n) {
	if (n==0)
	{
		return NULL;
	}
	else
	{
		Elem* novi = malloc(1 * sizeof(Elem));
		novi->sled = citaj1(n - 1);
		scanf("%d", &novi->broj);

		return novi;

	}

}


Elem* citaj2(int n) {

	if (n==0)
	{
		return NULL;
	}
	else
	{
		Elem* novi = malloc(1 * sizeof(Elem));
		scanf("%d", &novi->broj);
		novi->sled = citaj2(n - 1);
		return novi;

	}

}


void brisi(Elem* lst) {

	if (lst)
	{
		brisi(lst->sled);
		free(lst);
	}

}


Elem* umetni(Elem* lst, int b) {

	if (!lst || lst->broj>=b)
	{
		Elem* novi = malloc(1 * sizeof(Elem));
		novi->broj = b;
		novi->sled = lst;

	}
	else
	{
		lst->sled = umetni(lst->sled, b);
	}

	return lst;

}

Elem* obrni(Elem* lst) {//
	Elem* tek = lst, * pret = NULL;
	while (tek)
	{
		Elem* sled = tek->sled;
		tek->sled = pret;
		pret = tek;
		tek = sled;

	}

	return pret;
}


void uredi(Elem* lst) {//

	for (Elem* i = lst; i ; i=i->sled)
	{
		for (Elem* j = i->sled; j ; j=j->sled)
		{
			if (j->broj < i->broj)
			{
				int b = i->broj;
				i->broj = j->broj;
				j->broj = b;
			}
		}
	}
}

//spajanje dve liste
Elem* fuzija(Elem* lst1, Elem* lst2) {

	Elem* lst = NULL, * posl = NULL, * tek;

	while (lst1 && lst2)
	{
		if (lst1->broj < lst2->broj)
		{
			tek = lst1;
			lst1 = lst1->sled;
		}
		else
		{
			tek = lst2;
			lst2 = lst2->sled;
		}
		tek->sled = NULL;
		if (!lst)
		{
			lst = tek;
		}
		else
		{
			posl->sled = tek;
		}
		posl = tek;

	}

	if (lst1)
	{
		if (!lst)
		{
			lst = lst1;
		}
		else
		{
			posl->sled = lst1;
		}
	}

	if (lst2)
	{
		if (!lst)
		{
			lst = lst2;
		}
		else
		{
			posl->sled = lst2;
		}

	}

	return lst;

}



int main() {

	//polinomi
	/*
	Poli p1=citaj();
	Poli p2=citaj();

	printf("P1:    ");
	pisi(p1, "%.2fx");
	putchar('\n');

	printf("P2:    ");
	pisi(p2, "%.2fx");
	putchar('\n');


	printf("P1+P2:    ");
	Poli p3 = zbir(p1, p2);
	pisi(p3, "%.2fx");
	putchar('\n');

	Poli px;

	printf("P1-P2:    ");
	Poli p4 = razlika(p1, p2);
	pisi(p4, "%.2fx");
	putchar('\n');


	printf("P1*P2:    ");
	Poli p5 = proizvod(p1, p2);
	pisi(p5, "%.2fx");
	putchar('\n');

	printf("P1/P2:    ");
	Poli p6 = kolicnik(p1, p2, &px);
	pisi(p6, "%.2fx");
	putchar('\n');


	printf("P1%P2:    ");
	pisi(px, "%.2fx");
	putchar('\n');
	*/

	//dinamicki nizovi
	
	//dinamicki nizovi
	/*
	Din_niz dn1;
	Din_niz dn2;


	while ((dn1=citaj()), dn1.a!=NULL)
	{
		printf("Unesite broj koji se izostavlja: ");
		int k;
		scanf("%d", &k);
		putchar('\n');


		printf("Procitani niz:    ");
		pisi(dn1);
		putchar('\n');
		dn2 = kopiraj(dn1);

		printf("Kopirani niz:     ");
		pisi(dn2);
		putchar('\n');

		printf("Obrnuti niz:      ");
		obrni(dn2);
		pisi(dn2);
		putchar('\n');

		int niz[50], n;

		razlozi(dn1, niz, &n);
		printf("Razlozeni niz:    ");
		for (int i = 0; i < n; i++)
		{
			printf("%6d", niz[i]);
		}
		putchar('\n');
		putchar('\n');

		Din_niz dn3 = sastavi(niz, n);

		printf("Sastavljeni niz:  ");
		pisi(dn3);
		putchar('\n');


		izostavi(&dn3, k);
		printf("Redukovani niz:   ");
		pisi(dn3);

		putchar('\n');


		free(dn1.a);
		free(dn2.a);
		free(dn3.a);


	}



	printf("Kraj rada");
	*/

	//dinamicke matrice
	/*
while (1)
{

	printf("Unesite m1 i n1: ");
	int m, n;
	scanf("%d%d", &m, &n);
	if (m<=0 || n<=0)
	{
		break;
	}
	printf("\nMatrica1:\n");
	Din_mat dm1 = citaj(m, n);

	putchar('\n');

	pisi(dm1, "%8.2f", 8);

	putchar('\n');

	Din_mat dm2 = kopiraj(dm1);
	pisi(dm2, "%8.2f", 8);
	putchar('\n');

	dm2 = transpon(dm1);
	pisi(dm2, "%8.2f", 8);
	putchar('\n');

	Din_mat dm3 = zbir(dm1, dm2);
	pisi(dm3, "%8.2f", 8);
	putchar('\n');

	Din_mat dm4 = razlika(dm1, dm2);
	pisi(dm4, "%8.2f", 8);
	putchar('\n');


	Din_mat dm5 = proizvod(dm1, dm3);
	pisi(dm5, "%8.2f", 8);
	putchar('\n');

	unisti(dm1);
	unisti(dm2);
	unisti(dm3);
	unisti(dm4);
	unisti(dm5);



}
printf("Kraj rada");
*/
	
	//ulancane liste iterativno
	/*
Elem* lst = NULL;
_Bool kraj = 0;



while (1)
{

	printf("Vas izbor:\n");
	int n;
	scanf("%d", &n);

	switch (n)
	{

	case 1: case 2: case 3: case 4:
		printf("Unesite broj:    ");
		int broj;
		scanf("%d", &broj);
		switch (n)
		{
		case 1:
			lst = na_pocetak(lst, broj); break;
		case 2:
			lst = na_kraj(lst, broj); break;
		case 3:
			lst = umetni(lst, broj); break;
		//case 4:
			//lst = izostavi(lst, broj); break;



		}break;

	case 5:
		brisi(lst);
		lst = NULL;
		break;

	case 6: case 7:
		printf("\nUnesite duzinu:  ");
		int duzina;
		scanf("%d", &duzina);
		printf("Elementi:  ");
		brisi(lst);

		switch (n)
		{
		case 6:
			lst = citaj1(duzina);
			break;
		case 7:
			lst = citaj2(duzina);
			break;



		}break;
	case 9:
		printf("Lista:   ");
		pisi(lst);
		putchar('\n');
		break;




	default:
		break;
	}

}
*/

while (1)
{
	int n;
	printf("Duzina prve liste:    ");
	scanf("%d", &n);

	printf("\nElementi prve liste: ");
	Elem* lst1 = citaj2(n);

	printf("\nDuzina druge liste:  ");
	scanf("%d", &n);
	printf("\nElementi druge liste: ");

	Elem* lst2 = citaj2(n);

	lst1 = obrni(lst1);
	printf("\nObrnuta prva lista: ");
	pisi(lst1);

	lst2 = obrni(lst2);
	printf("\nObrnuta druga lista: ");
	pisi(lst2);
	putchar('\n');

	printf("Uredjena prva lista:  ");
	uredi(lst1);
	pisi(lst1);
	putchar('\n');

	printf("Uredjena druga lista:  ");
	uredi(lst2);
	pisi(lst2);
	putchar('\n');


	Elem* lst3 = fuzija(lst1, lst2);

	printf("Fuzija obe liste:   ");
	pisi(lst3);

	putchar('\n');



}


printf("\nKraj rada\n");



	return 0;
}