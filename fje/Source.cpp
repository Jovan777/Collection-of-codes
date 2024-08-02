#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>



int prost(int n) {

	for (int i = 2; i*i <n ; i++)
	{
		if (n%i==0)
		{
			return 1;
		}
	}
	return 0;

}

int nzd(int a, int b) {

	while (b != 0)
	{
		int c = b;
		b = a % b;
		a = c;

	}

	return a;
}

int nzs(int a, int b) {
	int d = nzd(a, b);
	int p = (a * b) / d;

	return p;
}

int sekv(int* niz, int n, int b) {

	for (int i = 0; i < n; i++)
	{
		if (niz[i]==b)
		{
			return 1;
		}
	}
	return 0;

}


int sekv2(int* niz, int n, int b) {

	int i = 0;
	while (i<n && niz[i]<b)
	{
		i++;
	}

	int p;
	if (niz[i]==b)
	{
		p = 1;
	}
	else
	{
		p = 0;
	}
	return p;

}


int bin(int* niz, int n, int b) {

	int d = 0, g = n - 1;
	int p;
	while (d<=g)
	{
		int s = (d + g) / 2;
		if (niz[s]==b)
		{
			return 1;
		}
		else if (b<niz[s])
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

int razliciti(int* niz, int n) {

	int rez = 0;
	for (int i = 0; i < n; i++)
	{
		int j = 0;
		while (j<i && niz[j]!=niz[i])
		{
			j++;
		}
		if (j==i)
		{
			rez++;
		}

	}

	return rez;
}

void obrni(int* niz, int n) {

	for (int i = 0, j=n-1; i < j; i++, j--)
	{
		int t = niz[i];
		niz[i] = niz[j];
		niz[j] = t;
	}

}

void ostatak(int* niz, int* niz2, int n, int k) {

	for (int i = 0; i < k; i++)
	{
		niz2[i] = 0;
	}
	for (int i = 0; i < n; i++)
	{
		niz2[niz[i] % k]++;
	}

}

void skup(int* niz, int *n) {

	int j = 0;
	for (int i = 0; i < *n; i++)
	{
		int k = 0;
		while (k<j && niz[k]!=niz[i])
		{
			k++;
		}
		if (k==j)
		{
			niz[j++] = niz[i];
		}

	}
	*n = j;


}

void redukcija(int* niz, int* n) {

	int j = 0;
	for (int i = 1; i < *n; i++)
	{
		if (niz[j]!=niz[i])
		{
			niz[++j] = niz[i];
		}

	}
	*n = j + 1;

}


void bit32(unsigned long k, char niz[]) {

	for (int i = 31; i >=0 ; i--)
	{
		niz[i] = k & 1;
		k >>= 1;
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

int nula(unsigned long n) {

	return jedan(~n);

}

unsigned obrni(unsigned k) {
	unsigned i = 0;
	for (unsigned j = ~0; j!=0; j>>=1)
	{
		i = (i << 1) | (k & 1);
		k >>= 1;
	}

	return i;
}


int main() {
	
	unsigned long n;
	printf("Unesite broj: ");
	scanf("%lx", &n);
	printf("Procitani broj: %x\n", n);
	
	unsigned d = obrni(n);
	printf("\nObrnuti broj: %x", d);
	
	return 0;
}