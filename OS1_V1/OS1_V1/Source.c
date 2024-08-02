#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>


int main() {

	printf("Dobro dosli na OS%d\n", 1);
	putc('R', stdout);
	putc('\n', stdout);


	FILE* file = fopen("novi.txt", "r"); // takodje, sve funkcije za rad sa fajlovima koriste sistemske pozive
	char buff[6];
	fread(&buff, sizeof(char), 6, file);
	buff[6] = '\0';
	printf("%s", buff);
	printf("\n");
	fclose(file);



	/*
	FILE* file = fopen("novi.txt", "r");
	char buff[10];
	fread(&buff, sizeof(char), 6, file);
	buff[6] = '\0';
	printf("%s", buff);
	printf("\n");

	fclose(file);
	*/




}