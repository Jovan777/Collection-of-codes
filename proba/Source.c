#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


char* readLine() {//

	int brojac = 0;
	char* rec = (char*)calloc((55 + brojac), sizeof(char));
	char c;
	int i = 0;
	brojac++;


	while (1)
	{
		c = getchar();
		if (c == '\n')
		{
			rec[i] = '\0';

			return rec;
		}
		rec[i++] = c;

	}


}


char** readLines(int* n) {//

	char** linije = calloc(55, sizeof(char*));
	char* reci;
	
	int i = 0;
	while (1)
	{
		linije[i] = calloc(55, sizeof(char));
		reci = readLine();
		if (reci[0]==0)
		{
			*n = i;
			free(linije[i]);
			free(reci);
			break;

		}
		for (int j = 0; j < 55; j++)
		{
			linije[i][j] = reci[j];
		}
		free(reci);
		i++;


	}

	return linije;

}
/*
* 
***
Pozovi Petrovica na 064 555 333
064/211-111 Mikin broj

scramble
063/111/5556
0 1 1 2 2 2 3 3 3


*/


char** changeNumber(char* zamena, char** stringovi, int n)
{
    char** ispis = calloc(55 ,sizeof(char*));
    for (int i = 0; i < n; i++)
    {
        int j = 0;
        int z = 0;
        int flag = 0;

        ispis[i] = calloc(55,sizeof(char));

        int brojac;
        int y;
       
        while (1)
        {
            if (stringovi[i][j] == '\0')
            {
                ispis[i][z] = '\0';
                break;
            }
            if (stringovi[i][j - 1] == '0' && stringovi[i][j] == '6')
            {

                if (flag == 0 && j > 0)
                {
                    brojac = 1;
                    flag = 1;

                }
            }


            if (flag!=0)
            {
                if (brojac < 9 )
                {
                    if (stringovi[i][j] == '/')
                    {
                        j++;
                        continue;
                    }
                    else if (stringovi[i][j] == ' ')
                    {
                        j++;
                        continue;
                    }
                    else if (stringovi[i][j] == '-')
                    {
                        j++;
                        continue;
                    }


                }
                brojac++;
                if (brojac >= 10 )
                {
                    if (stringovi[i][j] < '0' || stringovi[i][j] > '9')
                    {

                        flag = 0;
                        z = z - 3;
                        y = 0;
                        while (1)
                        {
                            if (zamena[y] == '\0')
                            {
                                break;
                            }
                            ispis[i][z++] = zamena[y++];


                        }

                    }

                }

            }


            ispis[i][z++] = stringovi[i][j++];



        }
        if (flag!=0)
        {
            y = 0;

            z = z - 3;

            while (1)
            {

                if (zamena[y] == '\0')
                {
                    break;
                }
                ispis[i][z++] = zamena[y++];


            }
            ispis[i][z] = '\0';
        }
    }

    return ispis;
}




int main() {
    int n;

	char* zamena = readLine();
	
	char** recenice = readLines(&n);


	if (n == 0)
	{
		printf("GRESKA\n");

        free(zamena);
		free(recenice);

	}
	
	char** glavni = changeNumber(zamena, recenice, n);
	for (int i = 0; i < n; i++)
	{
		printf("%s\n", glavni[i]);
	}


    for (int i = 0; i < n; i++)
    {
        free(recenice[i]);
        free(glavni[i]);

    }


    free(zamena);
    free(glavni);
    free(recenice);



	return 0;
}
