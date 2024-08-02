#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//fja koja razdvaja  reci u recenici

char** str_split(char* s, char sep) {// znaci imamo nas recenicu kao pokazivac i separator

    if (s == NULL)
    {
        return NULL;
    }
    char** str = 0;
    int size = 0;

    while (1)
    {
        //pronalazimo novu rec
        char* p = s; //jedna po jedna rec
        
        while (*p && *p != sep)
        {
            p++;//prelazak sa slova na slovo u reci
        }
        int n = p - s;
        size++;
        str = (char**)realloc(str, sizeof(char*) * (size + 1));
        if (str == NULL)
        {
            perror("MEM_GRESKA");
            exit(-1);
        }
        str[size - 1] = (char*)calloc(sizeof(char), n + 1);
        if (str[size - 1] == NULL)
        {
            perror("MEM_GRESKA");
            exit(-1);
        }
        strncpy(str[size - 1], s, sizeof(char) * n);
        str[size] = NULL;
        s = p + 1;
        if (*p == '\0')//
        {
            break;
        }

    }

    return str;

}

char** load_words() {
    //ucitavanje jedne linije sa ulaza

    char* line = NULL, c;

    int len = 0;
    while ((c = getchar()) != '\n')
    {
        len++;
        line = (char*)realloc(line, sizeof(*line) * (len+1));
        line[len - 1] = c;
        line[len] = '\0';
    }
    return str_split(line, ' ');


}

char** ucitaj_reci() {

    char** words=NULL;
    int word_count = 0;
    int word_start = 1;//flag za pocetak reci
    int position;
    char c;

    while (1)
    {
        c = getchar();
        if (c=='\n' && word_count==0)
        {
            break;
        }
        if (word_start)
        {
            words = (char**)realloc(words, (++word_count+1) * sizeof(char*));
            words[word_count - 1] = (char*)malloc(101 * sizeof(char));//
            words[word_count] = NULL;
            word_start = 0;
            position = 0;
        }

        words[word_count-1][position++] = c;
        if (c == ' ' || c == '\n')
        {
            words[word_count-1] = (char*)realloc(words[word_count-1], position * sizeof(char));
            if (words[word_count-1]==NULL)
            {
                perror("MEM_LOCK");
                exit(-1);
            }
            words[word_count-1][position-1] = '\0';
            word_start = 1;

            if (c=='\n')
            {
                break;
            }
        }
    }
    return words;

}

char* shortest_word(char** s) {//pretraga za najduzu rec u nizu reci

    char* short_word = NULL;

    while (s && *s)
    {
        if (short_word==NULL || strlen(*s)< strlen(short_word))
        {
            short_word=*s;
        }
        s++;
    }
    //treba nam kopija najkrace reci

    if (short_word)
    {
        char* t = (char*)calloc(sizeof(char),strlen(short_word)+1);
        if (!t)
        {
            perror("Memorijska greska");
            exit(-1);
        }
        strcpy(t, short_word);
        short_word = t;

    }
    return short_word;


}

char** rem_words(char** s, char* w) {//fja koja uklanja reci w iz datog niza reci
    if (s==NULL)
    {
        return NULL;
    }
    if (w==NULL)
    {
        return s;
    }
    char** old_s = s;
    char** pos=s;//pokazivac koji se pomera po nizu

    while (*s)
    {
        if (strcmp(*s, w))
        {
            *pos++ = *s;
        }
        else
        {
            free(*s);
        }
        s++;
    }
    *pos = NULL;
    old_s =(char**) realloc(old_s, sizeof(char*) * (pos - old_s + 1));//
    if (!old_s)
    {
        perror(NULL);
        exit(-1);
    }

    return old_s;


}

char* readLine() {

    char* rec = NULL;
    int pos = 0;
    char c;
    rec = (char*)malloc(10 * sizeof(char));


    while ((c = getchar()) != '\n' || (c = getchar()) != ' ')
    {
        rec[pos++] = c;
        rec = realloc(rec, (pos + 1) * sizeof(char));

    }
    rec = realloc(rec, (pos + 1) * sizeof(char));

    rec[pos] = '\0';



    return rec;

}




int main() {

    
    char* words[5];
    words[0] = (char*)"prva";
    words[1] = (char*)"druga";
    words[2] = (char*)"treca";
    words[3] = (char*)"prva";
    int n = sizeof(words) / sizeof(char*);
    char** reci = (char**)malloc(n * sizeof(char*));
    for (int i = 0; i < n-1; i++)
    {
        reci[i] = (char*)malloc((strlen(words[i]) + 1) * sizeof(char));
        strcpy(reci[i], words[i]);
    }

    reci[n - 1] = NULL;

    char* w = "prva";
    reci = rem_words(reci, w);
    for (char** curr_word = reci; *curr_word !=NULL; curr_word++)
    {
        printf("%s\n", *curr_word);

    }
    
    char** str = load_words(), ** p = str;

    while (str && *str)
    {
        puts(*str);
        free(*str);
        str++;

    }
    free(p);

    //char* k = shortest_word(words);
    //printf("\n%s\n", k);



    return 0;
}