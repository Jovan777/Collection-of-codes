#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

struct node
{
    int id; 
    int nivo, magicni;
    int* used; 
    int** matrix;
    struct node* otac; 
    struct node** potomci;
};
typedef struct node Cvor;
struct element
{
    Cvor* value;
    struct element* next;
};
typedef struct element el;
int* brojevi;
el* newE(Cvor* x)
{
    el* novi = malloc(sizeof(el));
    //if(novi == NULL) exit(1);
    novi->value = x;
    novi->next = NULL;
    return novi;
}
Cvor* noviNode(int n)
{
    Cvor* novi = malloc(sizeof(Cvor));
    novi->matrix = malloc(n * sizeof(int*));
    novi->potomci = malloc(n * n * sizeof(Cvor*));
    novi->used = calloc(n * n, sizeof(int));
    novi->otac = NULL;
    novi->id = 0;
    novi->nivo = 0;
    novi->magicni = -1;
    return novi;
}
void dodaj(el** prvi, Cvor* broj) 
{
    el* novi = newE(broj);
    if (*prvi == NULL)
    {
        *prvi = novi;
        return;
    }
    novi->next = *prvi;
    *prvi = novi;
    return;
}
Cvor* vadjenje_iz_steka(el** prvi)
{
    if ((*prvi) == NULL) return NULL;
    Cvor* tmp = (*prvi)->value;
    (*prvi) = (*prvi)->next;
    return tmp;
}
Cvor* vadjenje_iz_reda(el** prvi)
{
    if ((*prvi) == NULL) return NULL;
    if ((*prvi)->next == NULL)
    {
        Cvor* t = (*prvi)->value;
        *prvi = NULL;
        return t;
    }
    el* tail = *prvi;
    while (tail->next->next != NULL) tail = tail->next;
    el* t = (tail->next)->value;
    tail->next = tail->next->next;
    return t;
}

int check(int n, int** tmp) 
{
    int sum = magicna_suma(n);
    int suma = 0;
    int flag = 0;
    int flag1 = 0;
    for (int i = 0; i < n; i++)
    {
        suma = 0;
        flag1 = 0;
        for (int j = 0; j < n; j++)
        {
            suma += tmp[i][j];
            if (tmp[i][j] == 0)
            {
                flag = 1;
                flag1 = 1;
            }
        }
        if (suma > sum || (!flag1 && suma != sum)) return 0;
    }
    for (int i = 0; i < n; i++)
    {
        suma = 0;
        flag1 = 0;
        for (int j = 0; j < n; j++)
        {
            suma += tmp[j][i];
            if (tmp[j][i] == 0) flag1 = 1;
        }
        if (suma > sum || (!flag1 && suma != sum)) return 0;
    }
    
    return flag == 1 ? -1 : 1;
}
Cvor* start(int* n, Cvor* root)
{
    printf("Unesite dimenzije magicnog kvadrata(n):\n");
    scanf("%d", n);
    brojevi = calloc((*n) * (*n), sizeof(int));
    printf("Unesite brojeve koji treba da se nalaze u magicnom kvadratu:\n");
    for (int i = 0; i < (*n) * (*n); i++) scanf("%d", &brojevi[i]);
    root = noviNode(*n);
    printf("Unesite pocetno stanje magicnog kvadrata:\n");
    for (int i = 0; i < *n; i++)
    {
        (root->matrix)[i] = malloc((*n) * sizeof(int));
        for (int j = 0; j < *n; j++)
        {
            scanf("%d", &((root->matrix)[i][j]));
            for (int k = 0; k < (*n) * (*n); k++)
            {
                if (brojevi[k] == (root->matrix)[i][j])
                {
                    root->used[k] = 1;
                    break;
                }
            }
        }
    }
    root->magicni = check(*n, root->matrix);
    if (root->magicni == 0) { remove(root, *n); root = NULL; }
    return root;
}
void preorder(Cvor* root, int n, int op)
{
    el* stek = NULL;
    dodaj(&stek, root);
    while (stek != NULL)
    {
        Cvor* next = vadjenje_iz_steka(&stek);
        if (op == 1) indentovanje(next, n);
        else ispis(next, n);
        for (int i = n * n - 1; i >= 0; i--)
            if (next->potomci[i] != NULL)
                dodaj(&stek, next->potomci[i]);
    }
}
int magicna_suma(int n)
{
    int suma = 0;
    for (int i = 0; i < n * n; i++) suma += brojevi[i];
    return suma / n;
}
int remove(Cvor* tmp, int n)
{
    free(tmp->used);
    if (tmp->matrix != NULL)
        for (int i = n - 1; i >= 0; i--)
            free((tmp->matrix)[i]);
    free(tmp->matrix);
    free(tmp->potomci);
    free(tmp);
}
int ispis(Cvor* tmp, int n)
{
    if (tmp == NULL) return;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            printf("%d ", tmp->matrix[i][j]);
        printf("\n");
    }
}
int indentovanje(Cvor* tmp, int n)
{
    if (tmp == NULL) return;
    for (int i = 0; i < n; i++)
    {
        for (int i = 0; i < tmp->nivo; i++)
            for (int j = 0; j < n; j++) printf(" ");
        for (int j = 0; j < n; j++)
            printf("%d ", tmp->matrix[i][j]);
        printf("\n");
    }
}
int find(int* i, int* j, int n, int** mat) 
{
    for ((*i) = 0; (*i) < n; (*i)++)
    {
        for ((*j) = 0; (*j) < n; (*j)++)
        {
            if (mat[*i][*j] == 0) return 1;
        }
    }
    return 0;
}
void make(Cvor* root, int n)
{
    if (root == NULL) return;
    el* red = NULL;
    dodaj(&red, root);
    el* stek = NULL;
    while (red != NULL)
    {
        Cvor* t = vadjenje_iz_reda(&red);
        t->magicni = check(n, t->matrix);
        if (t->magicni == 0) continue; 
        int i = 0, j = 0;
        int flag = find(&i, &j, n, t->matrix); 
        for (int k = 0; k < n * n; k++) 
        {
            if (t->used[k] == 0)
            {
                t->potomci[k] = noviNode(n);
                t->potomci[k]->id = k;
                t->potomci[k]->otac = t;
                for (int id = 0; id < n * n; id++) t->potomci[k]->used[id] = t->used[id];
                t->potomci[k]->used[k] = 1;
                for (int k1 = 0; k1 < n; k1++)
                {
                    ((t->potomci[k])->matrix)[k1] = calloc(n, sizeof(int));
                    for (int k2 = 0; k2 < n; k2++)
                        ((t->potomci[k])->matrix)[k1][k2] = (t->matrix)[k1][k2];
                }
                t->potomci[k]->matrix[i][j] = brojevi[k];
                t->potomci[k]->magicni = -1;
                t->potomci[k]->nivo = t->nivo + 1;
                dodaj(&red, t->potomci[k]);
                dodaj(&stek, t->potomci[k]);
            }
            else t->potomci[k] = NULL;
        }
    }
    while (stek != NULL)
    {
        Cvor* t = vadjenje_iz_steka(&stek);
        if (t->magicni == 0)
        {
            Cvor* old = t;
            t->otac->potomci[t->id] = NULL;
            remove(old, n);
        }
        else if (t->magicni == -1)
        {
            for (int k = 0; k < n * n; k++)
                if (t->potomci[k] != NULL && t->potomci[k]->magicni == 1)
                    t->magicni = 1;
            if (t->magicni != 1)
            {
                Cvor* old = t;
                t->otac->potomci[t->id] = NULL;
                remove(old, n);
            }
        }
    }
}
int main()
{
    int n;
    Cvor* root = start(&n, NULL);
    make(root, n);
    printf("\n");
    preorder(root, n, 1);
    printf("Magicna suma je:%d\n", magicna_suma(n));
    Cvor* second = noviNode(n);
    for (int i = 0; i < n; i++)
    {
        (second->matrix)[i] = malloc(n * sizeof(int));
        for (int j = 0; j < n; j++)
            (second->matrix)[i][j] = j;
    }
    el* stek = NULL;
    dodaj(&stek, root);
    dodaj(&stek, second);
    Cvor* el = vadjenje_iz_reda(&stek);
    //obidji(stek, n);
    return 0;
}