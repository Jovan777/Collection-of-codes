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

int nasao(Node* head, Stanica* s)
{
    for (Node* tmp = head; tmp; tmp = tmp->next)
        if (tmp->data->br_stajalista == s->br_stajalista) return 1;
    return 0;
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

Stanica* citajRed(FILE* file)
{
    int brs;
    char nst[256];
    double gla;
    double glo;
    int zo;
    char c;
    if (fscanf(file, "%d!%[^!]!%lf!%lf!%d\n", &brs, nst, &gla, &glo, &zo) == 5) return newStanica(brs, nst, gla, glo, zo);
    return NULL;
}
void citajFile(FILE* file, Node** head)
{
    Stanica* stanica = NULL;
    while ((stanica = citajRed(file)) != NULL)
        *head = addNode(*head, stanica);
}



double haversine(double lat1, double lon1, double lat2, double lon2)
{
    double t1 = sin((lat1 - lat2) / 2) * sin((lat1 - lat2) / 2);
    double t2 = sin((lon1 - lon2) / 2) * sin((lon1 - lon2) / 2);
    double d = 2 * 6371 * 1000 * asin(sqrt(t1 + t2 * cos(lat1) * cos(lat2)));
    return d;
}

double radijani(double broj) { return (broj * 3.14) / 180; }

double rastojanje(Node* tmp, double p_lat, double p_lon)
{
    return abs(haversine(radijani(tmp->data->glat), radijani(tmp->data->glon), radijani(p_lat), radijani(p_lon)));
}

Node* obrada(Node* head, double radius, double p_lat, double p_lon)
{
    Node* nhead = NULL;
    for (Node* tmp = head; tmp; tmp = tmp->next)
    {
        if (rastojanje(tmp, p_lat, p_lon) <= radius)
            nhead = addNode(nhead, newStanica(tmp->data->br_stajalista, tmp->data->naziv_stajalista, tmp->data->glat, tmp->data->glon, tmp->data->zona));
    }
    return nhead;
}

void ispis_sort(FILE* ofile, Node* head, double p_lat, double p_lon)
{
    for (Node* p = head; p->next; p = p->next)
    {
        for (Node* q = p->next; q; q = q->next)
        {
            if (rastojanje(p, p_lat, p_lon) > rastojanje(q, p_lat, p_lon))
            {
                Stanica* tmp = p->data;
                p->data = q->data;
                q->data = tmp;
            }
            else if (rastojanje(p, p_lat, p_lon) == rastojanje(q, p_lat, p_lon) && strcmp(p->data->naziv_stajalista, q->data->naziv_stajalista) > 0)
            {
                Stanica* tmp = p->data;
                p->data = q->data;
                q->data = tmp;
            }
        }
    }
    for (Node* p = head; p; p = p->next)
    {
        fprintf(ofile, "%d!%s!%.9g!%.9g!%d\n", p->data->br_stajalista, p->data->naziv_stajalista, p->data->glat, p->data->glon, p->data->zona);
    }
}

void dealociraj(Node* head)
{
    while (head)
    {
        Node* old = head;
        head = head->next;
        free(old->data);
        free(old);
    }
}
int main(int argc, char* argv[])
{
    int num_stanice = argc - 6;
    if (num_stanice < 1) { printf("ARG_GRESKA"); return 0; }
    Node* head = NULL;
    for (int i = 6; i < argc; i++)
    {
        char* fajl = malloc(200 * sizeof(char));
        strcpy(fajl, "ulaz/");
        char* ime_fajla = strcmp(argv[2], "dirA") == 0 ? strcat(argv[i], "_dirA.txt") : strcat(argv[i], "_dirB.txt");
        fajl = strcat(fajl, ime_fajla);
        FILE* ifile = fopen(fajl, "r");
        if (ifile == NULL) { printf("DAT_GRESKA"); return 0; }
        citajFile(ifile, &head);
        fclose(ifile);
    }
    Node* nhead = obrada(head, atof(argv[5]), atof(argv[3]), atof(argv[4]));
    FILE* ofile = fopen(argv[1], "w");
    if (ofile == NULL) { printf("DAT_GRESKA"); return 0; }
    ispis_sort(ofile, nhead, atof(argv[3]), atof(argv[4]));
    dealociraj(nhead);
    dealociraj(head);
    head = NULL;
    nhead = NULL;
    fclose(ofile);
    return 0;
}
