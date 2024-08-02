#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct korisnik {

	char* ime;
	char* email;
	int vreme;

}Korisnik;

typedef struct node {

	Korisnik* data;
	struct node* next;


}Node;



Korisnik* readLine(FILE* input) {

	char* ime = calloc(50, sizeof(char));
	char* email = calloc(50, sizeof(char));
	Korisnik* novi = malloc(sizeof(*novi));
	novi->ime = malloc(50 * sizeof(char));
	novi->email = malloc(50 * sizeof(char));


	if (fscanf(input, "%s %s\n", ime, email) != EOF)
	{
		strcpy(novi->ime, ime);
		strcpy(novi->email, email);

		return novi;
	}
	else
	{
		free(novi->ime);
		free(novi->email);
		free(novi);
		novi = NULL;

		return novi;

	}


}

Node* readFile(FILE* input) {
	Node* head = NULL, * last = NULL, * temp;

	while (1)
	{
		temp = malloc(sizeof(*temp));
		Korisnik* novi = readLine(input);
		if (novi == NULL)
		{
			break;
		}
		temp->data = novi;
		temp->next = NULL;
		if (head == NULL)
		{
			head = novi;
		}
		else
		{
			last->next = novi;
		}
		last = novi;

	}

	return head;
}

void freeList(Node* head) {
	while (head)
	{
		Node* old = head;
		head = head->next;
		free(old->data->ime);
		free(old->data->email);
		free(old->data);
		free(old);

	}


}

void ispis(Node* head) {

	while (head)
	{
		printf("%s %s\n", head->data->ime, head->data->email);
		head = head->next;
	}

}


int main() {

	FILE* in = fopen("korisnici.txt", "r");
	Node* head = readFile(in);
	printf("%s %s", head->data->ime, head->data->email);

	return 0;
}

