#define _USE_CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//funkcija za jednakost
int are_equal(int*, int*, int n);


//fja za rotaciju
int rotate_one(int*, int n);



//fja za proveru rotacija
int is_rotation(int*, int*, int n);



int main() {
	int i;
	int a[] = { 1,2,3,5 };
	int b[] = { 1,2,3,5 };
	//duzina nizova

	int n = sizeof(a) / sizeof(*a);
	
	int rez = is_rotation(a, b, n);
	if (rez==1)
	{
		printf("Moze se dobiti niz rotacijom");
	}
	else
	{
		printf("Ne moze se dobiti rotacijom");
	}

	return 0;
}

int are_equal(int* a, int* b, int n) {

	while (n-->=0)
	{
		if (*a++!=*b++)
		{
			return 0;
		}
	}
	return 1;

}


int rotate_one(int* a, int n) {
	int i;
	int last = a[n - 1];
	for (i = n-1; i >0; i--)
	{
		a[i] = a[i - 1];
	}
	a[0] = last;


}

int is_rotation(int *a, int *b, int n) {
	for (int i = 0; i < n; i++)
	{
		if (are_equal(a,b,n)) return 1;
		rotate_one(b, n);
	}
	return -1;
}
