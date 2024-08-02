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

int main(int argc, char* argv[]) {
	
	double lat1 = atof(argv[2]);
	double lon1 = atof(argv[3]);
	double lat2 = atof(argv[4]);
	double lon2 = atof(argv[5]);
	char* ime_fajla = (char*)malloc(10 * sizeof(char));

	for (int i = 6; i < argc; i++)
	{
		strcpy(ime_fajla, argv[i]);
		strcat(ime_fajla, "_dirB.txt");
		printf("%s\n\n", ime_fajla);

		Elem* lst = NULL;

		FILE* in = fopen(ime_fajla, "r");
		if (in == NULL)
		{
			printf("DAT_GRESKA");
			return 0;
		}
		readFile(in, &lst);
		reverse(&lst);

		Elem* temp = lst;

		//ispis(temp);

		while (rastojanje(temp,lat1, lon1)>rastojanje(temp->next, lat1, lon1))
		{
			//printf("%.9g %.9g\n", rastojanje(temp, lat1, lon1)- rastojanje(temp->next, lat1, lon1));
			//reverse(temp);
			pisi_stanicu(temp->data);
			temp = temp->next;
		}

		pisi_stanicu(temp->data);


		while (rastojanje(temp, lat2, lon2)<rastojanje(temp, lat2,lon2))
		{
			//printf("%d!%s!%.9g!%.9g!%d\n", temp->data->broj, temp->data->naziv, temp->data->lat, temp->data->lon, temp->data->zona);
			pisi_stanicu(temp->data);
			temp = temp->next;
		}


		putchar('\n');

		fclose(in);

		memset(ime_fajla, 0, sizeof(ime_fajla));

		/*
		strcpy(ime_fajla, argv[i]);
		strcat(ime_fajla, "_dirB.txt");
		printf("\n\n%s\n\n", ime_fajla);
		lst = NULL;
		in = fopen(ime_fajla, "r");
		if (in==NULL)
		{
			printf("DAT_GRESKA");
			return 0;
		}
		readFile(in, &lst);

		ispis(lst);
		putchar('\n');


		fclose(in);

		memset(ime_fajla, 0, sizeof(ime_fajla));
		*/
	}
	putchar('\n');

	/*
	Elem* lst = NULL;

	FILE* in = fopen("309_dirA.txt", "r");
	if (in==NULL)
	{
		printf("DAT_GRESKA");
		return 0;
	}
	readFile(in, &lst);

	ispis(lst);

	fclose(in);
	*/

	/*
	int prov = argc - 5;
	if (prov<1)
	{
		printf("ARG_GRESKA");
		return 0;
	}
	for (int i = 6; i < argc; i++)
	{
		int broj_stanice = atoi(argv[i]);
		printf("%d!", broj_stanice);
		Elem* lst = NULL;
		char* ime_fajla = strcat(argv[i], "_dirA.txt");
		FILE* in = fopen(ime_fajla, "r");
		if (in == NULL)
		{
			printf("DAT_GRESKA");
			return 0;
		}
		readFile(in, &lst);
		printf("\n\n");
		ispis(lst);
		printf("\n\n");

		fclose(in);


	}
	*/

	/*
	Elem* lst = NULL;
	//char* ime_fajla = strcat(argv[7], "_dirA.txt");
	FILE* in = fopen("7_dirA.txt", "r");
	if (in == NULL)
	{
		printf("DAT_GRESKA");
		return 0;
	}
	readFile(in, &lst);
	printf("7a");
	printf("\n\n");
	ispis(lst);
	printf("\n\n");

	in = fopen("309_dirA.txt", "r");
	lst = NULL;
	readFile(in, &lst);
	printf("309a");
	printf("\n\n");
	ispis(lst);
	printf("\n\n");


	in = fopen("46_dirA.txt", "r");
	lst = NULL;
	readFile(in, &lst);
	printf("46a");
	printf("\n\n");
	ispis(lst);
	printf("\n\n");

	in = fopen("7_dirB.txt", "r");
	lst = NULL;
	readFile(in, &lst);
	printf("7b");
	printf("\n\n");
	ispis(lst);
	printf("\n\n");

	in = fopen("309_dirB.txt", "r");
	lst = NULL;
	readFile(in, &lst);
	printf("309b");
	printf("\n\n");
	ispis(lst);
	printf("\n\n");


	in = fopen("46_dirB.txt", "r");
	lst = NULL;
	readFile(in, &lst);
	printf("46b");
	printf("\n\n");
	ispis(lst);
	printf("\n\n");

	fclose(in);


	radi ucitavanje svih
	fclose(in);

	*/
	/*
	Elem* lst = NULL;
	char* ime_fajla;
	char* ime_fajla2;

	FILE* in;
	int broj_stanice;


	for (int i = 6; i < argc; i++)
	{
		int t = argv[i];
		broj_stanice = atoi(argv[i]);
		printf("%d!\n", broj_stanice);
		lst = NULL;
		ime_fajla = strcat(argv[i], "_dirA.txt");

		in = fopen(ime_fajla, "r");
		if (in == NULL)
		{
			printf("DAT_GRESKA");
			return 0;
		}
		readFile(in, &lst);
		printf("\n\n");
		ispis(lst);
		printf("\n\n");
		memset(ime_fajla, 0, sizeof(ime_fajla));
		ime_fajla2 = strcat(argv[i], "_dirB.txt");


		in = fopen(ime_fajla2, "r");
		if (in == NULL)
		{
			printf("DAT_GRESKA");
			return 0;
		}

		readFile(in, &lst);
		printf("\n\n");
		ispis(lst);
		printf("\n\n");



		zeza argv[i]
		fclose(in);
	*/

	/*
	Elem* lst = NULL;

	FILE* in = fopen("46_dirA.txt", "r");
	if (in == NULL)
	{
		printf("DAT_GRESKA");
		return 0;
	}
	readFile(in, &lst);
	reverse(&lst);

	ispis(lst);
	double lat1 = atof(argv[2]);
	double lon1 = atof(argv[3]);
	double lat2 = atof(argv[4]);
	double lon2 = atof(argv[5]);


	double d;
	double x;

	printf("%.9g %.9g %.9g %.9g\n", lat1, lon1, lat2, lon2);
	putchar('\n');
	for (Elem* tmp = lst; tmp != NULL; tmp = tmp->next)
	{
		//printf("%s %.9g %.9g\n",tmp->data->naziv, tmp->data->lat, tmp->data->lon);
		d = rastojanje(tmp, lat1, lon1);
		printf("%.9g\n", d);

	}
	printf("\n\n");

	for (Elem* tmp = lst; tmp != NULL; tmp = tmp->next)
	{
		//printf("%s %.9g %.9g\n",tmp->data->naziv, tmp->data->lat, tmp->data->lon);
		x = rastojanje(tmp, lat2, lon2);
		printf("%.9g\n", x);

	}


	fclose(in);

	putchar('\n');

	char* ime_fajla = (char*)malloc(10 * sizeof(char));

	for (int i = 6; i < argc; i++)
	{
		strcpy(ime_fajla, argv[i]);
		strcat(ime_fajla, "_dirA.txt");
		printf("%s\n", ime_fajla);
		memset(ime_fajla, 0, sizeof(ime_fajla));

		strcpy(ime_fajla, argv[i]);
		strcat(ime_fajla, "_dirB.txt");
		printf("%s\n", ime_fajla);
		memset(ime_fajla, 0, sizeof(ime_fajla));

	}
	putchar('\n');


	printf("%.7lf\n", lat1);
	printf("%.7lf\n", lon1);


	double hav = haversine(44.777633, lat1, 20.5045231, lon1);
	double hav2 = haversine(lat1, 44.7569219, lon1, 20.5519362);

	printf("%.7lf\n", hav);
	printf("%.7lf\n", hav2);
	*/




	return 0;
}