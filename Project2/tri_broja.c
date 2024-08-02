#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <time.h>
#define safeCalloc(pointer, count , size)\
	pointer=calloc(count , size);\
	if (pointer==NULL)\
	{\
	exit(-1);\
	}

typedef int (*CMP)(Point, Point);
typedef struct {

	float x, y;

}Point;

int closer(Point point0, Point point1) {

	float distance0 = point0.x * point0.x + point0.y * point0.y;
	float distance1 = point1.x * point1.x + point1.y * point1.y;

	if (distance0 == distance1)
	{
		return 0;
	}
	else if (distance0 > distance1) {
		return 1;
	}
	else
	{
		return -1;
	}

}

void selectionSort(Point* niz, int n, CMP uporedi) {//CMP ce nam biti pokazivac na funckiju closer
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (uporedi(niz[i], niz[j]) == 1)
			{
				Point t = niz[i];
				niz[i] = niz[j];
				niz[j] = t;

			}

		}

	}

}


void merge(Point* niz1, int n1, Point* niz2, int n2, CMP compare) {


	Point* temp = NULL;
	safeCalloc(temp, n1 + n2, sizeof(Point));

	int i = 0, j = 0, k = 0;

	for (; i < n1 && j<n2; k++)
	{
		if (compare(niz1[i], niz2[j])!=1)
		{
			temp[k] = niz1[i];
			i++;
		}
		else
		{
			temp[k] = niz2[j];
			j++;
		}

	}
	for (; i < n1; i++, k++)
	{
		temp[k] = niz1[i];
	}

	for (; j < n2; j++, k++)
	{
		temp[k] = niz2[j];
	}

	for ( i = 0; i < k; i++)
	{
		niz1[i] = temp[i];
	}

	free(temp);

}

void mergeSort(Point* niz, int n, CMP compare) {

	if (n>1)
	{
		int left = n / 2;
		int right = n - left;

		int* levi = niz;
		int* desni = niz + left;

		mergeSort(levi, left, compare);
		mergeSort(desni, right, compare);

		merge(levi, left, desni, right, compare);
	}

}

int compare(Point* niz1, Point* niz2, int n) {

	for (int i = 0; i < n; i++)
	{
		int x = niz1[i].x == niz2[i].x;
		int y = niz1[i].y == niz2[i].y;

		if (!x || !y)
		{
			return 0;
		}
	}

	return 1;
}

void iter(Point* niz, int lenght, CMP compare) {

	int chunk = 1;
	while (chunk < lenght)
	{
		for (int start = 0; start < lenght; start += 2 * chunk)
		{
			int end = start + 2 * chunk - 1;
			if (end > (lenght - 1))
			{
				end = lenght;
			}
			int middle = start + chunk - 1;
			if (middle > end)
			{
				middle = end;
			}
			merge(niz + start, middle - start + 1, niz + middle + 1, end - middle, compare);

		}
		chunk *= 2;
	}

}


int main() {
	int n;
	printf("Unesite duzinu niza:\n");
	scanf("%d", &n);
	printf("\n");

	int low = 0;
	int high = 10;

	Point* niz1 = NULL;
	Point* niz2 = NULL;
	Point* niz3 = NULL;


	safeCalloc(niz1, n, sizeof(Point));
	safeCalloc(niz2, n, sizeof(Point));
	safeCalloc(niz3, n, sizeof(Point));


	for (int i = 0; i < n; i++)
	{
		niz1[i].x = rand() / (double)RAND_MAX * (high - low) + low;
		niz1[i].y = rand() / (double)RAND_MAX * (high - low) + low;
		printf("(%f, %f)\n", niz1[i].x, niz1[i].y);
		niz2[i] = niz1[i];
		niz3[i] = niz1[i];

	}

	mergeSort(niz2, n, closer);

	selectionSort(niz1, n, closer);
	printf("\nSorted:\n");
	for (int i = 0; i < n; i++)
	{
		printf("(%f, %f)\n", niz1[i].x, niz1[i].y);
	
	}

	putchar('\n');
	for (int i = 0; i < n; i++)
	{
		printf("(%f, %f)\n", niz2[i].x, niz2[i].y);

	}

	iter(niz3, n, closer);

	putchar('\n');
	for (int i = 0; i < n; i++)
	{
		printf("(%f, %f)\n", niz3[i].x, niz3[i].y);

	}


	int same = compare(niz1, niz2, n);
	int same2 = compare(niz2, niz3, n);


	printf("\n%d", same);
	printf("\n%d", same2);



	return 0;

}
