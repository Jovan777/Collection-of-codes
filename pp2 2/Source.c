#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <string.h>



int main() {

	char c;
	char** matrica;
	int m, n;
	printf("Unesite dimenzije matrice:\n");
	scanf("%d %d", &m, &n);

	matrica = (char**)malloc(m * sizeof(char*));
	for (int i = 0; i <m; i++)
	{
		matrica[i] = (char*)malloc(n * sizeof(char));
		for (int  j = 0; j <n;)
		{
			while ((c = getchar()) != '\n') {
				if (c==' ')
				{
					continue;
				}
				else
				{
					matrica[i][j++] = c;
				}
				if (j==n)
				{
					break;
				}

			}

		}
	}


	int max = 0;
	int count = 0;

	for (int i = 0; i <m; i++)
	{
		for (int j = 0; j <n; j++)
		{
			printf("%c ", matrica[i][j]);
		}
		printf("\n");

	}
	printf("\n");
	
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (matrica[i][j] == '*')
				count++;
		}
		if (count > max)
		{
			max = count;
		}
		count = 0;
		

	}
	int t=0;
	count = 0;
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (matrica[i][j]=='*')
			{
				count++;
			}
		}
		if (count==max)
		{
			t = i;
		}
		count = 0;
	}

	printf("%d\n", max);
	/*printf("%d ", t);
	for (int k = 0; k < n; k++)
	{
		if (matrica[t][k] != '*')
		{
			printf("%c ", matrica[t][k]);
		}
	}
	*/
	count = 0;
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (matrica[i][j]=='*')
			{
				count++;
			}
		}
		if (count==max)
		{
			printf("%d ", i);
			for (int k = 0; k < n; k++)
			{
				printf("%c ", matrica[i][k]);
			}
		}

	}


	return 0;
}
