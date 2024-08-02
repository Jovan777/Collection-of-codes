#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <ctype.h>

//pretraga za neuredjen niz
int sekv(int niz[], int n, int x) {

	for (int i = 0; i < n; i++)
	{
		if (niz[i]==x)
		{
			return 1;
		}
	}
	return 0;

}

//pretraga za uredjen niz
int urd(int niz[], int n, int x) {

	int i = 0;
	while (i<n && niz[i]<x)
	{
		i++;
	}
	return i < n && niz[i] == x;
}

int binarno(int *niz, int n, int x) {

	int d = 0, g = n - 1;
	while (d<=g)
	{
		int s = (d + g) / 2;
		if (niz[s]==x)
		{
			return s;
		}
		else if (x<niz[s])
		{
			g = s - 1;
		}
		else
		{
			d = s + 1;
		}

	}
	return 0;
}

int bin_rekurzivno(int* niz, int n, int x) {

	int index = n / 2;
	if (niz[index]==x)
	{
		return index;
	}
	else if (niz[index]>x)
	{
		return bin_rekurzivno(niz, n / 2, x);
	}
	else
	{
		int novi_n = n / 2 - !(n & 1);
		int res = bin_rekurzivno(&niz[index + 1], novi_n, x);
		return res + n / 2 + 1;

	}

}

void redukcija(int niz[], int *n){

	int j = 0;
	for (int i = 0; i < *n; i++)
	{
		if (niz[j]!=niz[i])
		{
			niz[++j] = niz[i];

		}

	}
	*n = j + 1;


}



void bit32(unsigned long n, char bitovi[]) {

	for (int i = 31; i >= 0; i--)
	{
		bitovi[i] = n & 1;
		n=n>>1;
	
	}

}

void bit10(int n, int bit[]) {

	bit[0] = 0;
	bit[1] = 0;
	while (n)
	{
		bit[n % 2]++;
		n = n / 2;

	}


}


int jedan(unsigned long n) {
	int k = 0;
	while (n)
	{
		k += n & 1;
		n >>= 1;
	}

	return k;

}


int nula1(unsigned long n) {


	return jedan((~n));

}


unsigned obrni(unsigned n) {

	unsigned i = 0;
	for (unsigned j =~0; j!=0; j>>=1)
	{
		i = (i << 1) | (n & 1);
		n >>= 1;

	}
	return i;

}


int br_cifara(char niz[]) {

	int n = 0, i = 0;

	while (niz[i])
	{
		n += isdigit(niz[i++]) != 0;
	}

	return n;

}

void znakovi(int cifre[], int slova[]) {

	for (int i = 0; i < 10; i++)
	{
		cifre[i] = 0;
	}
	for (int i = 0; i < 26; i++)
	{
		slova[i] = 0;
	}

	char
		znak;
	while ((znak=getchar())!='\n')
	{

		if (isdigit(znak))
		{
			cifre[znak - '0']++;
		}
		if (islower(znak))
		{
			cifre[znak - 'a']++;
		}
		if (isupper(znak))
		{
			cifre[znak - 'A']++;
		}


	}

}


void permut1(int niz[], int n, int i, void (*f)(int[], int)) {

	if (i==n)
	{
		(*f)(niz, n);
	}

	else for (int j = i; j < n; j++)
	{
		int b = niz[i]; 
		niz[i] = niz[j];
		niz[j] = b;
		permut1(niz, n, i + 1, f);
		b = niz[i];
		niz[i] = niz[j];
		niz[j] = b;

	}


}

void pisi(int niz[], int n) {

	for (int i = 0; i < n; i++)
	{
		printf("%d ", niz[i]);
	}
	putchar("\n");

}



#define DA 1
#define NE 0


int nula(char niz[], int n) {

	return n == 1 && niz[0] == 0;

}


int uporedi(char niz1[], int n1, char niz2[], int n2) {

	if (n1!=n2)
	{
		return n1 - n2;
	}
	int i = n1 - 1;
	while (i>0 && niz1[i]==niz2[i])
	{
		i--;
	}
	return niz1[i] - niz2[i];

}


void kopiraj(char niz1[], int n1, char niz2[], int* n2) {

	for (int i = 0; i < n1; i++)
	{
		niz2[i] = niz1[i];
	}
	*n2 = n1;

}


_Bool zbir(char niz1[], int n1, char niz2[], int n2, char niz3[], int* n3) {

	int i = 0;
	int p = 0;
	while (i<n1 || i<n2)
	{
		int d = p;
		if (i<n1)
		{
			d += niz1[i];
		}
		if (i<n2)
		{
			d += niz2[i];
		}
		if (d>=10)
		{
			p = 1;
			d -= 10;
		}
		else
		{
			p = 0;
		}
		niz3[i] = d;

	}
	if (p)
	{
		niz3[i++] = p;
	}
	*n3 = i;

	return DA;

}


_Bool citaj(char niz[], int* n1) {

	char broj[80];
	scanf("%s", broj);
	int i = 0;
	while (broj[i])
	{
		if (!isdigit(broj[i++]))
		{
			return NE;
		}
		*n1 = i;
		for (int i = *n1 - 1, j = 0; i >= 0; niz[i--] = broj[j++] - '0');
		while (*n1>1 && niz[*n1-1]==0 )
		{
			(*n1)--;
		}

		return DA;

	}


}


void pisi1(char niz[], int n, int sir, _Bool grupe){

	printf("%*s", (sir - n - (n - 1) / 3 * grupe), "");
	for (int i = n-1; i >=0 ; i--)
	{
		putchar(niz[i] + '0');
		if (grupe && i%3==0)
		{
			putchar(' ');
		}

	}


}




int main(int bpar, const char *vpar[]) {
	
	char niz1[30];
	char niz2[30];
	int n1, n2;

	while (citaj(niz1, &n1) && citaj(niz2, &n2)) {

		printf("a=  ");
		pisi1(niz1, n1, 30, DA); putchar('\n');
		printf("b=  ");
		pisi1(niz2, n2, 30, DA); putchar('\n');

		char niz3[60];
		int n3;
		printf("a+b=  ");
		zbir(niz1, n1, niz2, n2, niz3, &n3);
		pisi1(niz3, n3, 30, DA); putchar('\n');




	}




	return 0;
}

