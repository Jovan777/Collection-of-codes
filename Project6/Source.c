#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>



int main() {

	//taberiranje polinoma
	int red;
	float max, min, korak;
	printf("Unesite red polinoma: ");
	scanf("%d", &red);
	putchar('\n');
	printf("Unesite max, min i korak: ");
	scanf("%f %f %f", &max, &min, &korak);

	int polinom[100];
	putchar('\n');
	putchar('\n');

	printf("Unesite koeficijente polinoma:\n");
	putchar('\n');

	for (int i = 0; i <= red; i++)
	{
		scanf("%d", &polinom[i]);
	}

	putchar("\n");

	for (int i = 0; i <= red; i++)
	{
		printf("%d ", polinom[i]);
	}








	return 0;
}