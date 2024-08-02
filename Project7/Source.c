#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>



typedef struct drzava {
	int points;
	char name[20];


}Drzava;

typedef struct node {

	Drzava* drzava;
	struct node* next;

}Node;

typedef struct putnik {

	int let;
	char oznaka;
	char ime[20];
	char prezime[20];
	char drzava[20];

}Putnik;

typedef struct elem {
	Putnik* data;
	struct elem* next;

}Elem;








Putnik* readOneLine(FILE* input) {
	Putnik* putnik = NULL;
	putnik = malloc(sizeof(*putnik));
	int d;
	char c;
	char ime[20];
	char prezime[20];
	char drzava[20];
	if (fscanf(input, "%d %c %s %s %s\n",&putnik->let, &putnik->oznaka, putnik->ime, putnik->prezime, putnik->drzava )==5)
	{
		//putnik->let = d;
		//putnik->oznaka = c;
		//strcpy(putnik->ime, ime);
		//strcpy(putnik->drzava, drzava);
		//strcpy(putnik->drzava, drzava);
		return putnik;

	}
	else
	{
		free(putnik);
		putnik = NULL;
		return putnik;
	}


}



Drzava* readLine(FILE* input) {

	Drzava* drzava = NULL;
	drzava = malloc(sizeof(*drzava));
	int d;
	char ime[20];
	if (fscanf(input, "%s %d\n", ime, &d)==2)
	{
		drzava->points = d;
		strcpy(drzava->name, ime);
		return drzava;

	}
	else
	{
		free(drzava);
		drzava = NULL;
		return drzava;
	}


}

Elem* readFromFile(FILE* input) {

	Elem* head = NULL, * last = NULL, * temp;
	while (1)
	{
		temp = malloc(sizeof(*temp));
		Putnik* putnik = readOneLine(input);
		if (putnik==NULL)
		{
			break;
		}
		temp->data = putnik;
		temp->next = NULL;
		if (head==NULL)
		{
			head = temp;
		}
		else
		{
			last->next = temp;
		}
		last = temp;


	}

	return head;
}

Node* readFile(FILE* input) {
	Node* head = NULL, * last = NULL, * temp;
	while (1)
	{
		temp = malloc(sizeof(*temp));
		Drzava* data = readLine(input);
		if (data==NULL)
		{
			break;
		}
		temp->drzava = data;
		temp->next = NULL;
		if (head==NULL)
		{
			head = temp;
		}
		else
		{
			last->next = temp;
		}
		last = temp;


	}


	return head;
}

void printList(Node* head) {

	while (head)
	{
		printf("%s %d\n", head->drzava->name, head->drzava->points);
		head = head->next;

	}

}

void ispis(Elem* head) {

	while (head)
	{
		printf("%d %c %s %s %s\n", head->data->let, head->data->oznaka, head->data->ime, head->data->prezime, head->data->drzava);
		head = head->next;

	}

}

void obrada(FILE* out, Elem* head, char* country) {

	while (head)
	{
		if (strcmp(head->data->drzava, country)==0)
		{
			fprintf(out,"%d %c %s %s %s\n", head->data->let, head->data->oznaka, head->data->ime, head->data->prezime, head->data->drzava);
		}
		head = head->next;

	}
	//radi obrada
}


int readWord(char word[20]) {

	char c;
	int i = 0;
	while ((c=getchar())!='\n')
	{
		word[i++] = c;
	}
	word[i++] = '\0';
	if (i==1)
	{
		return 0;
	}

	return 1;
}

typedef struct team {
	char name[20];
	int att[2];
	int cnt[2];

}Team;

typedef struct tnode {
	Team team;
	struct tnode* next;

}TNode;

TNode* searchTeam(TNode* list, char name[]) {

	while (list)
	{
		if (strcmp(list->team.name, name) == 0)
		{
			return list;
		}
		list = list->next;

	}


	return NULL;
}

TNode* loadData(FILE* input) {
	TNode* head = NULL, * last = NULL, * temp;

	//Team tim1;
	//Team tim2;
	char tim1[20];
	char tim2[20];


	int broj;

	while (1)
	{
		if (fscanf(input, "%s %s %d\n", tim1, tim2, &broj) == 3)
		{
			//printf("%s %s %d\n", tim1.name, tim2.name, broj);
			//temp = malloc(sizeof(*temp));
			temp = searchTeam(head, tim1);
			if (temp != NULL)
			{
				temp->team.att[0] += broj;
				temp->team.cnt[0]++;

			}
			else
			{

				temp = malloc(sizeof(*temp));
				strcpy(temp->team.name, tim1);
				temp->team.att[0] = 0;
				temp->team.att[0] += broj;
				temp->team.cnt[0] = 1;
				temp->team.cnt[1] = 0;


				temp->team.att[1] = 0;
				temp->next = NULL;

				if (head == NULL)
				{
					head = temp;
				}
				else
				{
					last->next = temp;
				}
				last = temp;

			}
			temp = NULL;
			temp = searchTeam(head, tim2);
			if (temp != NULL)
			{
				temp->team.att[1] += broj;
				temp->team.cnt[1]++;

			}
			else
			{
				temp = malloc(sizeof(*temp));
				temp->team.att[0] = 0;
				temp->team.att[1] = 0;
				temp->team.att[1] += broj;
				temp->team.cnt[1] = 1;
				temp->team.cnt[0] = 0;


				strcpy(temp->team.name, tim2);
				temp->next = NULL;

				if (head == NULL)
				{
					head = temp;
				}
				else
				{
					last->next = temp;
				}
				last = temp;

			}
			//printf("%s %d %d\n", temp->team.name, temp->team.att[0], temp->team.att[1]);
			//printf("%s %d %d\n", temp->team.name, temp->team.att[0], temp->team.att[1]);



		}
		else  //nije dobio nista, izlazak iz while petlje
		{
			break;
		}
	}

	return head;
}

void obradi(TNode* head) {
	while (head)
	{
		if (head->team.cnt[0] > 0)
		{
			head->team.cnt[0] = head->team.att[0] / head->team.cnt[0];

		}
		if (head->team.cnt[1] > 0)
		{
			head->team.cnt[1] = head->team.att[1] / head->team.cnt[1];

		}
		head = head->next;
	}

}

void stampaj(TNode* head, FILE* out) {

	while (head)
	{
		fprintf(out, "%s %d %d\n", head->team.name, head->team.cnt[0], head->team.cnt[1]);
		head = head->next;
	}

}

int main() {


	/*
	char zemlje[20];
	while (readWord(zemlje)==1)
	{
		//printf("%s\n", zemlje);
		obrada(out, head, zemlje);

	}

	printf("Kraj");
	*/

	FILE* in = fopen("tekme.txt", "r");
	FILE* out = fopen("posecenost.txt", "w");
	TNode* head = loadData(in);
	obradi(head);
	stampaj(head, out);


	return 0;
}