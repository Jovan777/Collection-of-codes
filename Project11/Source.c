#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define PI 3.141592
#include <math.h>
#include <string.h>

/*
char* readCity() {

	char* old_p = NULL, * new_p = NULL, c;
	int i = 0;

	while ((c = getchar()) != '\n')
	{
		if (i % 10 == 0);
		{
			new_p = realloc(old_p, (i + 10) * sizeof(char));
			if (!new_p)
			{
				printf("Realloc nije uspeo");
				break;
			}
			else
			{
				old_p = new_p;
			}
		}
		old_p[i++] = c;

	}

	new_p = realloc(old_p, (i + 1) * sizeof(char));
	if (!new_p)
	{
		printf("Realloc nije uspeo");
		i--;
	}
	else
	{
		old_p = new_p;
		old_p[i] = '\0';
	}

	
	return old_p;


}

int are_equal(int* niz1, int* niz2, int n) {
	
	for (int i = 0; i < n; i++)
	{
		if (niz1[i]!=niz2[i])
		{
			return 0;
		}
	}
	return 1;

}

void rotate(int* niz, int n) {

	int k = niz[n - 1];
	for (int i = n-1; i >=0 ; i--)
	{
		niz[i] = niz[i - 1];
	}
	niz[0] = k;

}

int is_rotation(int* niz1, int* niz2, int n) {

	for (int i = 0; i < n; i++)
	{
		if (are_equal(niz1, niz2, n))
		{
			return 1;
		}
		else
		{
			rotate(niz2, n);
		}

	}

	return 0;
}

char** str_split(char* s, char sep) {
	char** str = NULL;
	int size = 0;
	
	while (1)
	{
		char* p = s;
		
		while (*p && *p != sep)
		{
			p++;
		}
		int n = p - s;
		size++;
		str = realloc(str, sizeof(char*) * (size + 1));
		if (!str)
		{
			perror(NULL);
			exit(-1);
		}

		str[size - 1] = calloc(sizeof(char) ,  (n + 1));
		if (!str[size - 1])
		{
			perror(NULL);
			exit(-1);

		}
		strncpy(str[size - 1],s,  sizeof(char) * n);
		str[size] = NULL;
		
		s = p + 1;
		if (*p == '\0')
		{
			break;
		}

	}
	
	return str;
}


char** load_words1() {

	char* line = NULL, c;
	int len = 0;
	while ((c = getchar()) != '\n')
	{
		len++;
		line = realloc(line, sizeof(*line) * (len + 1));
		line[len - 1] = c;
		line[len] = '\0';

	}


	return str_split(line, ' ');
}


char** load_words() {

	char** words = NULL;
	int word_cnt=0, word_start = 1, pos = 0;
	char c;

	while (1)
	{
		c = getchar();
		if (c == '\n' && word_cnt == 0)
		{
			break;
		}
		if (word_start)
		{
			words = realloc(words, sizeof(char*) * (++word_cnt + 1));
			words[word_cnt - 1] = malloc(sizeof(char) * 101);
			words[word_cnt] = NULL;

			word_start = 0;
			pos = 0;

		}
		words[word_cnt - 1][pos++] = c;
		if (c == ' ' || c == '\n')
		{
			words[word_cnt - 1] = realloc(words[word_cnt - 1], sizeof(char) * pos);
			if (!words[word_cnt-1])
			{
				perror(NULL);
				exit(-1);
			}
			words[word_cnt-1][pos-1] = '\0';
			word_start = 1;
			if (c=='\n')
			{
				break;
			}

		}



	}


	return words;
}

char* shortest_word(char** s) {

	char* short_w = NULL;
	while (*s)
	{
		if (short_w == NULL || strlen(*s) < strlen(short_w))
		{
			short_w = *s;
		}
		s++;

	}

	if (short_w)
	{
		char* t = calloc(sizeof(char), strlen(short_w) + 1);
		strcpy(t, short_w);
		short_w = t;

	}



	return short_w;
}

char** rem_words(char** s, char* w) {
	char** old_s = s, ** pos = s;
	while (s && *s)
	{
		if (strcmp(*s, w))
		{
			*pos++ = *s;
		}
		else
		{
			free(*s);
		}
		s++;

	}

	old_s = realloc(old_s, sizeof(*old_s) * (pos - old_s + 1));
	if (!old_s)
	{
		perror(NULL);
		exit(-1);

	}

	return old_s;
}

int razliciti(int* niz, int n) {

	int r = 0;
	int k = 0;

	for (int i = 0; i < n; i++)
	{
		k = 0;
		for (int j = 0; j <=i ;j++)
		{
			if (niz[j] != niz[i])
			{
				k++;
			}

		}
		if (k==i)
		{
			r++;
		}


	}


	return r;
}


void obrni(int* niz, int n) {

	for (int i = 0, j = n - 1; i < j; i++, j--)
	{
		int t = niz[i];
		niz[i] = niz[j];
		niz[j] = t;

	}

}

void ostatak(int* niz1, int* niz2, int n, int k) {

	for (int i = 0; i < n; i++)
	{
		niz2[i] = 0;
	}
	for (int i = 0; i < n; i++)
	{
		niz2[niz1[i] % k]++;
	}


}


void skup(int* niz, int* n) {
	int j = 0;
	for (int i = 0; i < *n; i++)
	{
		int k = 0;
		while (k < j && niz[k]!=niz[j])
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
		if (niz[i]!=niz[j])
		{
			niz[++j] = niz[i];
		}

	}

	*n = j + 1;

}

void bit32(unsigned long k, char niz[]) {
	for (int i = 31; i >= 0; i--)
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

unsigned obrnuti(unsigned k) {

	unsigned i = 0;
	for (unsigned j = ~0; j != 0; j >>= 1)
	{
		i = (i << 1) | (k & 1);
		k >>= 1;

	}

	return i;
}

typedef struct {

	double re, im;
}Kompl;

Kompl zbir(Kompl a, Kompl b) {

	a.re += b.re;
	a.im += b.im;

	return a;
}

Kompl razlika(Kompl a, Kompl b) {

	a.re -= b.re;
	a.im -= b.im;

	return a;
}

Kompl proizvod(Kompl a, Kompl b) {
	Kompl c;
	c.re = a.re * b.re - a.im * b.im;
	c.im = a.re * b.im + a.im * b.re;


	return c;
}

Kompl kolicnik(Kompl a, Kompl b) {
	Kompl c;

	double d = pow(b.re, 2) + pow(b.im, 2);
	c.re = (a.re * b.re + a.im * b.im) / d;
	c.im = (a.im * b.re - a.re * b.im) / d;


	return c;
}

typedef struct {

	double a[21];
	int n;


}poli;

poli zbir_p(poli p1, poli p2) {
	poli p;
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

poli razlika_p(poli p1, poli p2) {
	poli p;
	p.n = (p1.n > p2.n) ? p1.n : p2.n;
	for (int i = 0; i <=p.n; i++)
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

	while (p.n >= 0 && p.a[p.n] == 0)
	{
		p.n--;
	}


	return p;
}

poli proizvod_p(poli p1, poli p2) {
	poli p;
	p.n = p1.n + p2.n;
	for (int i = 0; i <=p.n; i++)
	{
		p.a[i] = 0;
	}
	for (int i = 0; i <=p1.n; i++)
	{
		for (int j = 0; j <=p2.n; j++)
		{
			p.a[i + j] = p1.a[i] * p2.a[j];

		}

	}


	return p;
}


poli kolicnik_p(poli p1, poli p2, poli* ostatak) {
	poli p;
	p.n = p1.n - p2.n;
	for (int i = p.n; i >=0 ; i--)
	{
		p.a[i] = p1.a[p2.n + i] / p2.a[p2.n];
		for (int j = 0; j <= p2.n; j++)
		{
			p1.a[j + i] -= p2.a[j] * p.a[i];

		}


	}

	while (p1.n >= 0  && p1.a[p1.n]==0)
	{
		p1.n--;
	}
	*ostatak = p1;


	return p;
}


poli citaj() {
	poli p;
	scanf("%d", &p.n);
	for (int i = p.n; i >= 0; i--)
	{
		scanf("%lf", &p.a[i]);

	}

	return p;
}

void pisi(poli p, char f[]) {
	printf("p[");
	for (int i = p.n; i >= 0; i--)
	{
		printf(f, p.a[i]);
		if (i > 0)
		{
			putchar(',');
		}

	}

	putchar(']');
}

*/


/*
typedef struct {
	int* a, n;

 }Din_niz;

Din_niz sastavi(int* a, int n) {
	
	Din_niz dn;
	dn.n = n;
	dn.a = malloc(n * sizeof(int));
	
	if (dn.a==NULL)
	{
		perror(NULL);
		exit(-1);
	}
	for (int i = 0; i < dn.n; i++)
	{
		dn.a[i] = a[i];

	}

	return dn;
}

Din_niz razlozi(Din_niz dn, int* a, int* n){
	
	for (int i = 0; i < dn.n; i++)
	{
		a[i] = dn.a[i];
	}

	*n = dn.n;
}

void obrni_niz(Din_niz dn) {

	for (int* i = dn.a, *j = i + dn.n - 1; i < j; i++, j--)
	{
		int t = *i;
		*i = *j;
		*j = t;

	}



}

void izostavi(Din_niz* dn, int k) {

	int j = 0;
	for (int i = 0; i < dn->n; i++)
	{
		if (dn->a[i] != k)
		{
			dn->a[j++] = dn->a[i];
		}

	}

	dn->n = j;
	dn->a = realloc(dn->a, j * sizeof(*dn->a)); //*dn->a je sustinski int

}

Din_niz citaj() {
	Din_niz dn;
	printf("Duzina niza: \n");
	scanf("%d", &dn.n);
	if (dn.n <= 0)
	{
		dn.a = NULL;
		return dn;
	}
	dn.a = malloc(dn.n * sizeof(int));
	printf("Elementi niza: \n");
	for (int i = 0; i < dn.n; i++)
	{
		scanf("%d", &dn.a[i]);

	}

	return dn;
}

void pisi(Din_niz dn) {
	for (int i = 0; i < dn.n; i++)
	{
		printf("%6d", dn.a[i]);

	}
	putchar('\n');

}

Din_niz kopiraj(Din_niz dn) {
	Din_niz dn2;
	dn2.n = dn.n;
	dn2.a = malloc(dn2.n * sizeof(int));
	for (int i = 0; i < dn.n; i++)
	{
		dn2.a[i] = dn.a[i];
	}

	return dn2;
}
*/


typedef struct {

	float** a;
	int m, n;

}Din_Mat;

Din_Mat stvori(int m, int n) {
	Din_Mat dm;
	dm.m = m;
	dm.n = n;

	dm.a = malloc(m * sizeof(float*));
	for (int i = 0; i < m; i++)
	{
		dm.a[i] = malloc(n * sizeof(float));
	}

	return dm;
}

void unisti(Din_Mat dm) {

	for (int i = 0; i < dm.m; i++)
	{
		free(dm.a[i]);
	}

	free(dm.a);
}

Din_Mat kopiraj(Din_Mat dm) {
	Din_Mat dm2=stvori(dm.m, dm.n);
	for (int i = 0; i < dm.m; i++)
	{
		for (int j = 0; j < dm.n; j++)
		{
			dm2.a[i][j] = dm.a[i][j];

		}
	}

	return dm2;
}

void pisi(Din_Mat dm) {

	for (int i = 0; i < dm.m; i++)
	{
		for (int j = 0; j < dm.n; j++)
		{
			printf("%8.2f", dm.a[i][j]);

		}
		putchar('\n');
	}

}

Din_Mat citaj(int m, int n) {

	Din_Mat dm = stvori(m, n);
	printf("Unesite elemente matrice: \n");
	for (int i = 0; i < dm.m; i++)
	{
		for (int j = 0; j < dm.n; j++)
		{
			scanf("%f", &dm.a[i][j]);
		}

	}

	return dm;
}

Din_Mat transpon(Din_Mat dm) {
	Din_Mat dm2 = stvori(dm.n, dm.m);

	for (int i = 0; i < dm.m; i++)
	{
		for (int j = 0; j < dm.n; j++)
		{
			dm2.a[j][i] = dm.a[i][j];

		}
	}

	return dm2;
}


Din_Mat saberi(Din_Mat dm1, Din_Mat dm2) {

	Din_Mat dm3 = stvori(dm1.m, dm1.n);
	for (int i = 0; i < dm1.m; i++)
	{
		for (int j = 0; j < dm1.n; j++)
		{
			dm3.a[i][j] = dm1.a[i][j] + dm1.a[i][j];
		}
	}


	return dm3;
}

Din_Mat oduzmi(Din_Mat dm1, Din_Mat dm2) {

	Din_Mat dm3 = stvori(dm1.m, dm1.n);
	for (int i = 0; i < dm1.m; i++)
	{
		for (int j = 0; j < dm1.n; j++)
		{
			dm3.a[i][j] = dm1.a[i][j] - dm2.a[i][j];
		}
	}


	return dm3;
}

Din_Mat proizvod(Din_Mat dm1, Din_Mat dm2) {

	Din_Mat dm3 = stvori(dm1.m, dm2.n);
	for (int i = 0; i < dm3.m; i++)
	{
		for (int j = 0; j < dm3.n; j++)
		{
			dm3.a[i][j] = 0;
			for (int k = 0; k < dm2.n; k++)
			{
				dm3.a[i][j] += dm1.a[i][k] * dm2.a[k][j];
			}


		}

	}

	return dm3;
}


int main() {

	/*
	Kompl x, y, z;
	printf("Unesite prvi kompleksan broj: \n");
	scanf("%lf %lf", &x.re, &x.im);

	printf("Unesite drugi kompleksan broj: \n");
	scanf("%lf %lf", &y.re, &y.im);

	putchar('\n');
	printf("x=%lf + j%lf\n", x.re, x.im);
	printf("y=%lf + j%lf\n", y.re, y.im);

	z = zbir(x, y);
	printf("x+y=%lf + %lf\n", z.re, z.im);
	z = razlika(x, y);
	printf("x-y=%lf + %lf\n", z.re, z.im);
	z = proizvod(x, y);
	printf("x*y=%lf + %lf\n", z.re, z.im);
	z = kolicnik(x, y);
	printf("x/y=%lf + %lf\n", z.re, z.im);
	*///Kompleksni brojevi
	//Kompleksni brojevi

	/*
	poli p1 = citaj();
	poli p2 = citaj();

	printf("P1=       ");
	pisi(p1, "%.2f");
	putchar('\n');
	printf("P2=       ");
	pisi(p2, "%.2f");
	putchar('\n');
	poli p3 = zbir_p(p1, p2);
	poli p4 = razlika_p(p1, p2);
	poli p5 = proizvod_p(p1, p2);
	printf("P1+P2=      ");
	pisi(p3, "%.2f");
	putchar('\n');
	printf("P1-P2=      ");
	pisi(p4, "%.2f");
	putchar('\n');
	printf("P1*P2=      ");
	pisi(p5, "%.2f");
	putchar('\n');
	poli p6 = kolicnik_p(p1, p2, &p3);
	printf("P1/P2=      ");
	pisi(p6, "%.2f");
	putchar('\n');
	printf("P1%P2=      ");
	pisi(p3, "%.2f");
	*/
	// Polinomi


	/*
	5
	1 2 3 4 5
	

	Din_niz dn = citaj();
	
	printf("Procitan niz: ");
	pisi(dn);
	
	printf("Obrnut niz: ");
	obrni_niz(dn);
	pisi(dn);
	Din_niz dn2 = kopiraj(dn);
	printf("Kopiran niz: ");
	pisi(dn2);
	obrni_niz(dn);
	izostavi(&dn, 4);
	printf("Redukovan niz: ");
	pisi(dn);
	*/
	//Dinamicki nizovi


	/*
	3 3
	1 2 3
	4 5 6
	7 8 9
	
	*/



	int m, n;
	printf("Unesite dimenzije matrice: \n");
	scanf("%d %d", &m, &n);
	Din_Mat dm1 = citaj(m, n);

	printf("\nIspis prve matrice: \n");
	pisi(dm1);

	Din_Mat dm2 = transpon(dm1);
	printf("\nIspis transponovane matrice: \n");
	pisi(dm2);

	Din_Mat dm3 = saberi(dm1, dm2);
	Din_Mat dm4 = oduzmi(dm1, dm2);

	printf("Ispis zbira matrica: \n");
	pisi(dm3);
	printf("Ispis razlike matrica:\n");
	pisi(dm4);
	printf("Ispis proizvoda matrica: \n");
	Din_Mat dm5 = proizvod(dm1, dm3);
	pisi(dm5);



	putchar('\n');
	system("pause");
	return 0;
}