#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int cntr = 0;
char* readLine()
{
    char* input = malloc((1000 + cntr) * sizeof(char));
    cntr++;
    char in;
    int i = 0;
    while (1)
    {
        scanf("%c", &in);
        if (in == '\n')
        {
            input[i] = 0;
            return input;
        }
        input[i] = in;
        i++;
    }
}

char** readLines(int* n)
{
    char** input = malloc(1000 * sizeof(char*));
    char* in;
    int i = 0, j;
    while (1)
    {
        input[i] = malloc(1000 * sizeof(char));
        in = readLine();
        if (in[0] == 0)
        {
            *n = i;
            free(input[i]);
            free(in);
            break;
        }
        for (j = 0; j < 1000; j++)
        {
            input[i][j] = in[j];
        }
        free(in);
        //printf("%d %s\n",i,input[0]);
        i++;
    }
    return input;
}

char** changeNumber(char* replace, char** strings, int n)
{
    //printf("%s\n",replace);
    char** res = malloc(1000 * sizeof(char*));
    int k, i, j, cnt, m;
    int mode;
    for (k = 0; k < n; k++)
    {
        res[k] = malloc(1000 * sizeof(char));
        i = 0;
        j = 0;
        mode = 0;
        while (1)
        {
            if (strings[k][i] == 0)
            {
                res[k][j] = 0;
                break;
            }
            if (!mode && i != 0 && strings[k][i] == '6' && strings[k][i - 1] == '0')
            {
                mode = 1;
                cnt = 1;
            }
            if (mode)
            {
                if (cnt < 9 && (strings[k][i] == ' ' || strings[k][i] == '-' || strings[k][i] == '/'))
                {
                    i++;
                    continue;
                }
                cnt++;
                if (cnt >= 10 && (strings[k][i] > '9' || strings[k][i] < '0'))
                {
                    mode = 0;
                    j -= 3;
                    m = 0;
                    while (1)
                    {
                        if (replace[m] == 0)
                        {
                            break;
                        }
                        res[k][j] = replace[m];
                        m++;
                        j++;
                    }
                }
            }
            res[k][j] = strings[k][i];
            j++;
            i++;
        }
        if (mode)
        {
            j -= 3;
            m = 0;
            while (1)
            {
                if (replace[m] == 0)
                {
                    break;
                }
                res[k][j] = replace[m];
                m++;
                j++;
            }
            res[k][j] = 0;
        }
    }

    return res;
}

int main()
{
    char* replace = readLine();
    int n, i, j;
    char** redovi = readLines(&n);
    if (n == 0)
    {
        printf("GRESKA\n");
        free(redovi);
        free(replace);
        return 0;
    }
    char** resenje = changeNumber(replace, redovi, n);
    for (i = 0; i < n; i++)
    {
        printf("%s\n", resenje[i]);
    }
    for (i = 0; i < n; i++)
    {
        free(resenje[i]);
        free(redovi[i]);
    }
    free(resenje);
    free(redovi);
    free(replace);
    return 0;
}