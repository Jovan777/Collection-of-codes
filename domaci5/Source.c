#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>



typedef struct stanica {

	int broj;
	int naziv[256];
	double lat;
	double lon;
	int zona;

}Stanica;

typedef struct elem {

	Stanica* data;
	struct elem* prev;
	struct elem* next;

}Elem;

/*
double haversine(double lat1, double lon1, double lat2, double lon2)
{
	lat1 = (lat1 * 3.14) / 180;
	lat2 = (lat2 * 3.14) / 180;
	lon1 = (lon1 * 3.14) / 180;
	lon1 = (lon1 * 3.14) / 180;

	double t1 = sin((lat1 - lat2) / 2) * sin((lat1 - lat2) / 2);
	double t2 = sin((lon1 - lon2) / 2) * sin((lon1 - lon2) / 2);
	double d = 2 * 6371 * 1000 * asin(sqrt(t1 + t2 * cos(lat1) * cos(lat2)));

	return d;
}
*/




Stanica* dodaj_stanicu(int broj, char* naziv, double lat, double lon, int zona) {

	Stanica* nova = malloc(1 * sizeof(Stanica));
	nova->broj = broj;
	nova->lat = lat;
	nova->lon = lon;
	nova->zona = zona;
	strcpy(nova->naziv, naziv);

	return nova;
}

Elem* newEle(Stanica* stanica) {

	Elem* novi = malloc(1 * sizeof(Elem));
	novi->data = stanica;
	novi->next = NULL;

	novi->prev = NULL;

	return novi;
}
Elem* dodaj2(Elem* head, Stanica* stanica)
{
	Elem* novi = newEle(stanica);
	if (head == NULL) head = novi;
	else
	{
		novi->next = head;
		head->prev = novi;
		head = novi;
	}
	return head;
}


Elem* dodaj(Elem* lst, Stanica* stanica) {

	Elem* novi = newEle(stanica);
	if (lst == NULL)
	{
		lst = novi;
	}
	else
	{
		novi->next = lst;
		lst->prev = novi;
		lst = novi;
	}

	return lst;
}

void pisi_stanicu(Stanica* stanica) {

	printf("%d!%s!%.9g!%.9g!%d\n", stanica->broj, stanica->naziv, stanica->lat,
		stanica->lon, stanica->zona);

}


Stanica* readLine(FILE* file)
{
	int broj, zona;
	char naziv[256];
	double lat, lot;

	if (fscanf(file, "%d!%[^!]!%lf!%lf!%d\n", &broj, naziv, &lat, &lot, &zona) != EOF)
		return dodaj_stanicu(broj, naziv, lat, lot, zona);

	return NULL;
}

void deallocate(Elem* lst)
{
	while (lst)
	{
		Elem* stari= lst;
		lst = lst->next;
		free(stari->data);
		free(stari);
	}
}

void reverse(Elem** lst) {

	Elem* temp = NULL;
	Elem* trenutni = *lst;
	while (trenutni != NULL)
	{
		temp = trenutni->prev;
		trenutni->prev = trenutni->next;
		trenutni->next = temp;
		trenutni = trenutni->prev;
	}
	if (temp != NULL)
	{
		*lst = temp->prev;
	}


}

void readFile(FILE* file, Elem** lst)
{
	Stanica* stanica = NULL;
	while ((stanica = readLine(file)) != NULL)
		*lst = dodaj(*lst, stanica);
}


void ispis(Elem* lst) {

	Elem* temp = lst;
	while (temp != NULL)
	{
		pisi_stanicu(temp->data);
		temp = temp->next;
	}
}

double haversine(double lat1, double lon1, double lat2, double lon2)
{
	double t1 = sin((lat1 - lat2) / 2) * sin((lat1 - lat2) / 2);
	double t2 = sin((lon1 - lon2) / 2) * sin((lon1 - lon2) / 2);
	double d = 2 * 6371 * 1000 * asin(sqrt(t1 + t2 * cos(lat1) * cos(lat2)));
	return d;
}

double radijani(double broj) { return (broj * 3.14) / 180; }

double rastojanje(Elem* tmp, double p_lat, double p_lon)
{
	return abs(haversine(radijani(tmp->data->lat), radijani(tmp->data->lon), radijani(p_lat), radijani(p_lon)));
}


void obrada(FILE* izlaz, Elem* lst, double lat1, double lon1, double lat2, double lon2) {

	double d;
	double y;
	int brojac = 0; 

	Elem* tmp = lst;
	for (tmp = lst; tmp != NULL; tmp = tmp->next)
	{
		d = rastojanje(tmp, lat1, lon1);
		y = rastojanje(tmp->next, lat1, lon1);
		if (d > y)
		{
			continue;
		}
		else
		{
			break;
		}

	}

	for (; tmp->next != NULL; )
	{
		d = rastojanje(tmp, lat2, lon2);
		y = rastojanje(tmp->next, lat2, lon2);
		//pisi_stanicu(tmp->data);
		fprintf(izlaz, "%d!%s!%.9g!%.9g!%d\n", tmp->data->broj, tmp->data->naziv,
			tmp->data->lat, tmp->data->lon, tmp->data->zona);

		if (d > y)
		{
			tmp = tmp->next;
		}
		else
		{
			break;
		}
		
	}


}



int main(int argc, char* argv[]) {

	Elem* lst = NULL;
	double lat1 = atof(argv[2]);
	double lon1 = atof(argv[3]);
	double lat2 = atof(argv[4]);
	double lon2 = atof(argv[5]);

	char* ime_fajla = (char*)malloc(10 * sizeof(char));
	FILE* izlaz = fopen(argv[1], "w");
	int a = 0;

	for (int i = 6; i < argc; i++)
	{
		strcpy(ime_fajla, argv[i]);
		strcat(ime_fajla, "_dirA.txt");
		FILE* in = fopen(ime_fajla, "r");
		readFile(in, &lst);
		reverse(&lst);
		
		int p = atoi(argv[i]);
		fprintf(izlaz, "%d!A\n", p);
		obrada(izlaz, lst, lat1, lon1, lat2, lon2);
		fclose(in);

		memset(ime_fajla, 0, sizeof(ime_fajla));


		strcpy(ime_fajla, argv[i]);
		strcat(ime_fajla, "_dirB.txt");
		in = fopen(ime_fajla, "r");
		readFile(in, &lst);
		reverse(&lst);
		fprintf(izlaz, "%d!B\n", p);
		obrada(izlaz, lst, lat1, lon1, lat2, lon2);
		memset(ime_fajla, 0, sizeof(ime_fajla));
		fclose(in);


	}


	lst = NULL;

	FILE* in = fopen("7_dirA.txt", "r");
	if (in == NULL)
	{
		printf("DAT_GRESKA");
		return 0;
	}
	readFile(in, &lst);
	reverse(&lst);

	ispis(lst);
	
	double d;
	double x;
	double y;
	

	fclose(in);
	fclose(izlaz);

	return 0;
}