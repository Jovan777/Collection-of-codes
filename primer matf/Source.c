#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>



int main() {

	char c;
	char** matrica;
	int m, n;
	//printf("Unesite dimenzije matrice:\n");
	scanf("%d %d", &m, &n);

	matrica = (char**)malloc(m * sizeof(char*));
	if (matrica==NULL)
	{
		printf("MEM_GRESKA");
		exit(-1);
	}
	for (int i = 0; i < m; i++)
	{
		matrica[i] = (char*)malloc(n * sizeof(char));// sredi za neuspeli malloc
		if (matrica[i] == NULL) {
			printf("MEM_GRESKA");
			exit(-1);
		}

		for (int j = 0; j < n;)
		{
			while ((c = getchar()) != '\n') {
				if (c == ' ')
				{
					continue;
				}
				else
				{
					matrica[i][j++] = c;
				}
				if (j == n)
				{
					break;
				}

			}

		}
	}


	int max = 0;
	int count = 0;

	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (j == n - 1)
			{
				printf("%c", matrica[i][j]);
				break;

			}
			printf("%c ", matrica[i][j]);
			
		}
		printf("\n");

	}

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
	int t = 0;
	count = 0;
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (matrica[i][j] == '*')
			{
				count++;
			}
		}
		if (count == max)
		{
			t = i;
		}
		count = 0;
	}

	printf("%d\n", max);

	//vrste
	count = 0;
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (matrica[i][j] == '*')
			{
				count++;
			}
		}
		if (count == max)
		{
			printf("%d", i);
			if (matrica[i][0] != '*' || matrica[i][1] != '*') {
				printf(" ");
			}

			for (int k = 0; k < n; k++)
			{
				if (matrica[i][k]=='*')
				{
					continue;
				}
				else
				{
					if (k < n - 1)
					{


						if (matrica[i][k + 1] == '*' && k < n - 2)
						{
							printf("%c", matrica[i][k]);
							printf(" ");
						}
						else
						{
							printf("%c", matrica[i][k]);

						}
					}
					else {
						if (k == n - 1 && matrica[i][k] == '*')
						{
							printf("\n");
						}
						else
						{
							printf("%c\n", matrica[i][k]);//
						}
					}

				}
				

			}
			break;
		}
		count = 0;
	}

	printf("\n");
	//kolone

	count = 0;
	max = 0;

	for (int j = 0; j < n; j++)
	{
		for (int i = 0; i < m; i++)
		{
			if (matrica[i][j] == '*')
			{
				count++;
			}
		}
		if (count > max)
		{
			max = count;
		}
		count = 0;
	}
	//imamo max kolona

	printf("%d\n", max);
	
	int i=0;
	count = 0;
	for (int j = 0; j < n; j++)
	{
		for ( i = 0; i < m; i++)
		{
			if (matrica[i][j] == '*')
			{
				count++;
			}
		}
		for (int i = 0; i < m; i++)
		{

		
			if (count == max)
			{
				printf("%d ", j);
				for (int k = 0; k < m; k++)
				{
					if (matrica[k][j] == '*')
					{
						continue;
					}
					else
					{
						if (k < m - 1)
						{
							if (matrica[k + 1][j] == '*' && k < m-2) {
								if (matrica[k + 1][j] == '*' && k < m - 2 && matrica[m-2][j] == '*' && matrica[m - 1][j] == '*')
								{
									printf("%c\n", matrica[k][j]);//
									break;

								}
								printf("%c", matrica[k][j]);//
								if (k<m-3)
								{
									printf(" ");

								}
								//printf(" ");
							}
							else
							{//
								if (matrica[k][j]=='*' && matrica[m-1][j]=='*')//k==m-2
								{
									printf("\n");
									break;//

								}
								else
								{
								printf("%c", matrica[k][j]);//
								}

							}


						}
						//if (k == m - 1 && matrica[k][j] != '*')
						else
						{
							if (matrica[k][j]=='*')
							{
								printf("\n");
							}
							else
							{
								printf("%c\n", matrica[k][j]);
							}
						}
						{
							//printf("%c\n", matrica[k][j]);

						}

					}
				}
				break;
			}
		}
		count = 0;
	}



	for (int i = 0; i < m; i++)
	{
		free(matrica[i]);
	}

	free(matrica);

	return 0;
}
