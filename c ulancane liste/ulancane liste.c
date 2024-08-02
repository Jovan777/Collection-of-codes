#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main()
{
    char* arrstr[5] = { "prog","frog", "fr", "aba", "ana" };

    printf("%d", strcmp(arrstr[1], arrstr[4]));


    return 0;
}