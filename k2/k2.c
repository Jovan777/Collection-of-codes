#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

//matrica dimenzija n*2

char** loadMap(int n) { //unos matrice radi

	char** matrix = malloc(n * sizeof(char*));
	char c1, c2;
	for (int i = 0; i < n; i++)
	{
		matrix[i] = malloc(2 * sizeof(char));
		scanf("%c%c%c%c", &c1, &matrix[i][0], &c2, &matrix[i][1]);
	}


	return matrix;
}

char* readLine() {
	int brojac = 0;
	char* rec = malloc(50 * sizeof(char));
	char c;
	while ((c=getchar())!='\n')
	{
		rec[brojac++] = c;

	}

	rec = realloc(rec, brojac * sizeof(char));
	rec[brojac] = '\0';

	return rec;
}


int CharToDigit(char c, char** matrix, int n) {
	int broj;

	for (int i = 0; i < n; i++)
	{
		if (c==matrix[i][0])
		{
			broj = (int)matrix[i][1] - '0';
			return broj;

		}

	}

	return 0;
}


int StringToInt(char* word, char** matrix, int n) {
	int brojac = 0;
	int i = 0;
	int j = 0;

	while (word[i++]!='\0')
	{
		j++;
	}
	int p = pow(10, j-1);

	i = 0;
	while (word[i]!='\0')
	{
		brojac += CharToDigit(word[i], matrix, n)*p;
		i++;
		p = p / 10;
	}


	return brojac;
}

int main() {

	int rows;
	char c;
	scanf("%c", &c);

	rows = (int)c - '0';

	char** matrix=loadMap(rows);

	putchar('\n');

	


	getchar();

	char* prva = readLine();

	char* druga = readLine();

	char* treca = readLine();


	for (int i = 0; i < rows; i++)
	{
		printf("%c %c", matrix[i][0], matrix[i][1]);
		putchar('\n');
	}

	printf("%s\n", prva);
	printf("%s\n", druga);
	printf("%s\n", treca);

	//radi unos



	int s=CharToDigit('S', matrix, rows);//radi pretvaranje znaka u broj
	printf("\n%d\n", s);

	int broj3 = StringToInt(treca, matrix, rows);
	int broj1 = StringToInt(prva, matrix, rows);
	int broj2 = StringToInt(druga, matrix, rows);
	
	printf("%d %d %d", broj1, broj2, broj3);
	//sve radi 


	if ((broj1+broj2)==broj3)
	{
		printf("\nDA\n");
	}


	system("pause");
	return 0;
}