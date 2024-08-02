#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>


typedef struct stanica {

	int broj;
	int zona;
	double lat;
	double lot;
	char naziv[256];

}Stanica;

typedef struct elem {

	Stanica* data;
	struct elem* prev;
	struct elem* next;

}Elem;


Stanica* dodaj_stanicu(int broj, char naziv, double lat, double lot, int zona) {

	Stanica* nova = malloc(sizeof(Stanica));
	nova->broj = broj;
	strcpy(nova->naziv, naziv);
	nova->lat = lat;
	nova->lot = lot;
	nova->zona = zona;

	return nova;
}


Stanica* readLine(FILE* in) { //cita se jedna linija
	int broj, zona;
	double lat, lot;
	char naziv[256];

	if (fscanf(in, "%d!%[^!]%lf!%lf!%d", &broj, naziv, &lat, &lot, &zona)!=EOF)
	{
		return dodaj_stanicu(broj, naziv, lat, lot, zona);
	}

	return NULL;

}




void pisi_stanicu(Stanica* stanica) {

	printf("%d!%s!%lf!%lf!%d\n", stanica->broj, stanica->naziv, stanica->lat, stanica->lot, stanica->zona);

}


Elem* noviElem(Stanica* stanica) {

	Elem* novi = malloc(sizeof(Elem));

	novi->data = stanica;
	novi->prev = NULL;
	novi->next = NULL;

	return novi;
}

Elem* dodaj(Elem* lst, Stanica* stanica){
	
	Elem* novi = noviElem(stanica);

	if (lst==NULL)
	{
		lst = novi;
	}
	else {

		novi->next = lst;
		lst->prev = novi;
		lst = novi;
	
	}


	return lst;
}

void readFile(FILE* in, Elem** lst) {

	Stanica* stanica = NULL;
	while ((stanica=readLine(in))!=NULL)
	{
		*lst = dodaj(*lst, stanica);
	}

}


void reverse(Elem** lst) {

	Elem* temp = NULL;
	Elem* trenutni = lst;
	while (trenutni!=NULL)
	{
		temp = trenutni->prev;
		trenutni->prev = trenutni->next;
		trenutni->next = temp;
		trenutni = trenutni->prev;

	}
	if (temp!=NULL)
	{
		*lst = temp->prev;
	}

}

void ispis(Elem* lst) {

	Elem* temp = lst;
	while (temp!=NULL)
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
	return abs(haversine(radijani(tmp->data->lat), radijani(tmp->data->lot), radijani(p_lat), radijani(p_lon)));
}





int main() {



	Elem* lst = NULL;


	FILE* in = fopen("7_dirA.txt", "r");
	readFile(in, &lst);
	reverse(&lst);



	return 0;
}
