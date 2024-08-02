#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>





char** readWords(int n) {

	char** mat = (char**)malloc(n*sizeof(char*));
	
	char c;
	for (int i = 0; i < n; i++)
	{
		mat[i] = (char*)malloc(21 * sizeof(char));
		scanf("%s%c", mat[i], &c);
		mat[i] =(char*) realloc(mat[i], (strlen(mat[i]) + 1) * sizeof(char));

	}

	return mat;
}//upis radi


int isComplexNumber(char* word) {

	int re, im;
	char c;

	return sscanf(word, "%d%cj%d", &re, &c, &im)==3;
}

double absoluteValue(char* complexNumber) {

	int re, im;
	char c;
	if (isComplexNumber(complexNumber))
	{
		sscanf(complexNumber, "%d%cj%d", &re, &c, &im);
		return sqrt(re * re + im * im);

	}
	else
	{
		return -1;
	}


}


/*
2+j1
1-j3
dva
*/

int lenstr(char* word) {

	int cnt = 0;
	while (word[cnt++] != '\0');

	return cnt;
}


/*
izbaciti[6]sve␣sekvence[7]koje␣pocinju␣[18]uglastim␣zagradama.
*/

int main() {

	int n;
	char* word =(char*) malloc(100 * sizeof(char));
	scanf("%s", word);
	word = (char*)realloc(word, (lenstr(word) + 1) * sizeof(char));

	printf("%s", word);


	system("pause");
	return 0;
}