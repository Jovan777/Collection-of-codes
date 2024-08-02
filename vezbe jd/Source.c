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




typedef struct {

	float x, y;

}point;


typedef int (*CMP)(point, point);


typedef void (*SF)(point*, int, CMP);

int closer(point point0, point point1) {

	float distance0 = point0.x * point0.x + point0.y * point0.y;
	float distance1 = point1.x * point1.x + point1.y * point1.y;

	if (distance0==distance1)
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


void selectionSort(point* niz, int n, CMP uporedi) {//CMP ce nam biti pokazivac na funckiju closer
	for (int i = 0; i < n-1; i++)
	{
		for (int j = i+1; j < n; j++)
		{
			if (uporedi(niz[i], niz[j])==1)
			{
				point t = niz[i];
				niz[i] = niz[j];
				niz[j] = t;

			}

		}

	}


}

//fja za spajanje nizova
void merge(point* niz1, int n1, point* niz2, int n2, CMP uporedi) {


	point* temp = NULL;

	safeCalloc(temp, n1 + n2, sizeof(point));

	int i = 0;
	int j = 0;
	int k = 0;

	for (; i < n1 && j<n2; ++k)
	{
		if ((uporedi(niz1[i], niz2[j])!=1))
		{
			temp[k]=niz1[i];
			++i;
		}
		else
		{
			temp[k] = niz2[j];
			++j;
		}

	}

	for (; i <n1 ;++i, ++k)
	{
		temp[k] = niz1[i];
	}
	for (; j < n2;++j, ++k)
	{
		temp[k] = niz2[j];

	}

	for ( i = 0; i < k; ++i)
	{
		niz1[i] = temp[i];

	}


}



void merge_rek(point* array, int length, CMP uporedi) {
	
	if (length>1)
	{
		int leftLenght = length / 2;
		int rightLength = length - leftLenght;

		int* left = array;
		int* right = array + leftLenght;


		merge_rek(left, leftLenght, uporedi);
		merge_rek(right, rightLength, uporedi);


		merge(left, leftLenght, right, rightLength, uporedi);
	}


}

int compare(point* niz1,point* niz2, int n1) {

	for (int i = 0; i < n1; i++)
	{
		int xSame = niz1[i].x == niz2[i].x;
		int ySame = niz1[i].y == niz2[i].y;


		if (!xSame || !ySame)
		{
			return 0;
		}


	}

	return 1;

}


void mergeSI(point* niz,int n, CMP uporedi) {

	int chunk = 1;
	while (chunk<n)
	{
		for (int start = 0; start < n; start+=2*chunk)
		{
			int end = start + 2 * chunk - 1;
			if (end>n-1)//
			{
				end = n;
			}
			int middle = start + chunk - 1;
			if (middle>end)
			{
				middle = end;
			}
			merge(niz + start, middle - start + 1, niz + middle + 1, end - middle, uporedi);

		}
		chunk = chunk * 2;

	}


}



void sortArray(SF sortFunction, char* name, point* niz, int n, CMP uporedi) {

	clock_t start = clock();
	sortFunction(niz, n, uporedi);
	clock_t end = clock();

	double miliseconds = (double)(end - start) / CLOCKS_PER_SEC * 1000;

	printf("Algorithm: %s, time: %lf\n", name, miliseconds);

}


int main() {

	int n;
	printf("Unesite duzinu niza:\n");
	scanf("%d", &n);
	printf("\n");

	int low = 0;
	int high = 10;

	point* niz1 = NULL;
	point* niz2 = NULL;
	point* niz3 = NULL;



	safeCalloc(niz1, n, sizeof(point));
	safeCalloc(niz2, n, sizeof(point));
	safeCalloc(niz3, n, sizeof(point));



	printf("NESORTIRAN NIZ:\n");
	for (int i = 0; i < n; i++)
	{
		niz1[i].x = rand() / (double)RAND_MAX * (high - low) + low;
		niz1[i].y = rand() / (double)RAND_MAX * (high - low) + low;


		niz3[i].x=niz2[i].x = niz1[i].x;
		niz3[i].y=niz2[i].y = niz1[i].y;
		//printf("(%f, %f)\n", niz1[i].x, niz1[i].y);

	}

	printf("\n");
	/*
	for (int i = 0; i < n; i++)
	{
		printf("(%f, %f)\n", niz2[i].x, niz2[i].y);


	}

	printf("\n");

	for (int i = 0; i < n; i++)
	{
		printf("(%f, %f)\n", niz3[i].x, niz3[i].y);


	}

	*/

	printf("\n");

	sortArray(selectionSort, "selection",niz1, n, closer);

	sortArray(merge_rek, "Recursive", niz2, n, closer);

	sortArray(mergeSI, "Iterativno" ,niz3, n, closer);


	int isti12 = compare(niz1, niz2, n);
	int isti23 = compare(niz2, niz3, n);


	/*
	printf("\nSORTIRAN NIZ:\n");
	for (int i = 0; i < n; i++)
	{
		printf("(%f, %f)\n", niz1[i].x, niz1[i].y);

	}




	printf("\n");

	for (int i = 0; i < n; i++)
	{
		printf("(%f, %f)\n", niz2[i].x, niz2[i].y);

	}

	printf("\n");

	for (int i = 0; i < n; i++)
	{
		printf("(%f, %f)\n", niz3[i].x, niz3[i].y);

	}


	if (isti12==1 &&  isti23==1)
	{
		printf("NIZOVI SU ISTI\n");
	}
	else
	{
		printf("NISU\n");
	}
	*/


	system("pause");
	return 0;
}