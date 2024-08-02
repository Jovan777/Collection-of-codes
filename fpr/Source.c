#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

struct stanica
{
    int br_stajalista;
    char naziv_stajalista[256];
    double glat, glon;
    int zona;
};
typedef struct stanica Stanica;

struct node
{
    Stanica* data;
    struct node* next;
    struct node* prev;
};
typedef struct node Node;

Stanica* newStanica(int brs, char* nst, double gla, double glo, int zo)
{
    Stanica* novi = malloc(sizeof(Stanica));
    novi->br_stajalista = brs;
    strcpy(novi->naziv_stajalista, nst);
    novi->glat = gla;
    novi->glon = glo;
    novi->zona = zo;
    return novi;
}

Node* newNode(Stanica* stanica)
{
    Node* novi = malloc(sizeof(Node));
    novi->data = stanica;
    novi->next = NULL;
    novi->prev = NULL;
    return novi;
}

Node* addNode(Node* head, Stanica* stanica)
{
    Node* novi = newNode(stanica);
    if (head == NULL) head = novi;
    else if (nasao(head, stanica) == 0)
    {
        novi->next = head;
        head->prev = novi;
        head = novi;
    }
    return head;
}

void ispis_stanice(Stanica* stanica)
{
    printf("%d %s %.9g %.9g %d", stanica->br_stajalista, stanica->naziv_stajalista, stanica->glat, stanica->glon, stanica->zona);
}

void ispisi(Node* head)
{
    Node* tmp = head;
    while (tmp != NULL)
    {
        ispis_stanice(tmp->data);
        printf("\n");
        tmp = tmp->next;
    }
}

int nasao(Node* head, Stanica* s)
{
    for (Node* tmp = head; tmp; tmp = tmp->next)
        if (tmp->data->br_stajalista == s->br_stajalista) return 1;
    return 0;
}


Stanica* citajRed(FILE * file)
    {
        int brs;
        char nst[256];
        double gla;
        double glo;
        int zo;
        char c;
        if (fscanf(file, "%d!%[^!]!%lf!%lf!%d\n", &brs, nst, &gla, &glo, &zo) != EOF) return newStanica(brs, nst, gla, glo, zo);
        return NULL;
    }
void citajFile(FILE * file, Node * *head)
    {
        Stanica* stanica = NULL;
        while ((stanica = citajRed(file)) != NULL)
            *head = addNode(*head, stanica);
    }



int main(int argc, char* argv[]) {

    Node* lst = NULL;
    //char* ime_fajla = strcat(argv[7], "_dirA.txt");
    FILE* in = fopen("7_dirA.txt", "r");
    if (in == NULL)
    {
        printf("DAT_GRESKA");
        return 0;
    }
    citajFile(in, &lst);
    printf("\n\n");
    ispisi(lst);
    printf("\n\n");

    fclose(in);







    return 0;
}
