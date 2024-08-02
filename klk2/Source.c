#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define WORD_LEN 50



typedef struct student {

	char* name;
	char* surname;
	char* smer;
	float prosek;
	struct student* next;

}Student;

/*
Elem* formiraj() {

	int n;
	char c;
	Elem* head = NULL;
	Elem* last = NULL;
	Elem* temp;

	while (1)
	{
		c = getchar();
		switch (c)
		{
		case '\n':
			c = getchar();
			if (c=='\n')
			{
				return head;
			}
		

		default:
			if (c==' ')
			{
				break;
			}
			n = c - '0';
			temp = malloc(sizeof(Elem));
			temp->broj = n;
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

			break;
		}
		

	}


	//return head;
}

void ispisListe(Elem* head) {

	while (head)
	{
		printf("%d->", head->broj);
		head = head->next;
	}
	printf("NULL\n");

}

void dodaj(Elem* head, int n) {

	Elem* novi = malloc(sizeof(int));
	novi->broj = n;
	novi->next = NULL;
	while (head->next!=NULL)
	{
		head = head->next;
	}
	head->next = novi;

}


int binar(int n) {

	int zero=0;
	int one=0;
	
	while (n)
	{
		if (n&1)
		{
			one++;
		}
		else
		{
			zero++;
		}
		n = n >> 1;

	}

	if (one>zero)
	{
		return 1;
	}
	else
	{
		return 0;
	}


}

int binar2(int n) {
	int one = 0;
	int zero = 0;

	for (int i = 0; i < 16; i++)
	{
		if (n % 2 == 1)
		{
			one++;
		}
		else
		{
			zero++;
		}
		n = n / 2;

	}
	if (one>zero)
	{
		return 1;
	}
	else
	{
		return 0;
	}



}



void ispis(int** matrix, int n, int m) {


	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			printf("%d ", matrix[i][j]);
		}
		putchar('\n');
	}

}


void freeMatrix(int** matrix, int n, int m) {

	for (int i = 0; i < n; i++)
	{
		free(matrix[i]);
	}

	free(matrix);
}

char** load_words() {

	char** words=NULL;
	int word_cnt = 0;
	int word_start = 1, pos;
	char c;

	while (1)
	{

		c = getchar();
		if (c == '\n' && word_cnt == 0)
		{
			break;
		}
		if (word_start)
		{
			//alokacija za novu rec
			words = realloc(words, sizeof(char*) * (++word_cnt + 1));
			if (!words)
			{
				perror(NULL);
				exit(-1);
			}
			words[word_cnt - 1] = malloc((WORD_LEN + 1) * sizeof(char));
			if (!words[word_cnt-1])
			{
				perror(NULL);
				exit(-1);
			}
			word_start = 0;
			pos = 0;
		}
		words[word_cnt - 1][pos++] = c;
		if (c == ' ' || c == '\n') {
			//realokacija za novu rec
			words[word_cnt - 1] = realloc(words[word_cnt - 1], sizeof(char) * pos);
			if (!words[word_cnt - 1])
			{
				perror(NULL);
				exit(-1);
			}
			words[word_cnt - 1][pos - 1] = '\0';
			word_start = 1;
			if (c=='\n')
			{
				break;
			}

		}

	}

	return words;
}

int samoglasnici(char* word) {
	int broj = 0;
	int i = 0;
	while (word[i]!=0)
	{
		
		if (word[i]=='a' || word[i]=='A')
		{
			broj++;
		}
		i++;
	}

	return broj;
}


int pecat(int** matrix, int m, int n) {
	int br;
	int v = 0;

	for (int i = 0; i < n-2; i++)
	{
		for (int j = 0; j < m-2; j++)
		{
			br = matrix[i][j] + matrix[i][j + 1] + matrix[i][j + 2] + matrix[i + 1][j + 1] + matrix[i + 2][j] + matrix[i + 2][j + 1] + matrix[i + 2][j + 2];
			if (br==4)
			{
				v++;
			}

		}

	}

	return v;
}

*/
Student* newNode(const char* im, const char* pre, const char* smer, float prosek) {
	Student* novi = malloc(sizeof(Student));
	novi->name = malloc(WORD_LEN * sizeof(char));
	strcpy(novi->name, im);
	novi->surname = malloc(WORD_LEN * sizeof(char));
	strcpy(novi->surname, pre);
	novi->smer = malloc(3 * sizeof(char));
	strcpy(novi->smer, smer);
	novi->prosek = prosek;
	novi->next = NULL;
	

	return novi;
}

void addNode(Student** head, const char* im, const char* pre, const char* smer, float prosek) {

	Student* novi = newNode( im,  pre,  smer,  prosek);

	if (*head==NULL)
	{
		*head = novi;
		return;
	}
	Student* curr = *head;
	
	if (novi->prosek < curr->prosek)
	{
		novi->next = *head;
		*head = novi;
		return;

	}

	while (curr->next != NULL && curr->next->prosek <= novi->prosek)
	{
		curr = curr->next;
	}
	novi->next = curr->next;
	curr->next = novi;

	return;
}

void printList(Student* head) {

	while (head!=NULL)
	{
		printf("%s %s %s %.2f\n", head->name, head->surname, head->smer, head->prosek);

		head = head->next;
	}


}


Student* dodajCvor(Student** head, char* im, char* pre, char* smer, float prosek) {
	Student* novi = malloc(sizeof(Student));
	novi->name = malloc(WORD_LEN * sizeof(char));
	strcpy(novi->name, im);
	novi->surname = malloc(WORD_LEN * sizeof(char));
	strcpy(novi->surname, pre);
	novi->smer = malloc(3 * sizeof(char));
	strcpy(novi->smer, smer);
	novi->prosek = prosek;
	novi->next = NULL;

	if (*head==NULL)
	{
		*head = novi;
	}
	else
	{
		Student* curr = *head;
		while (curr->next!=NULL)
		{
			curr = curr->next;
		}
		curr->next = novi;

	}


	return head;
}



typedef struct elem {
	int broj;
	struct elem* next;

}Elem;

Elem* napravi() {
	Elem* head = NULL, * last = NULL;

	int broj;
	while (scanf("%d", &broj)==1)
	{
		Elem* curr=malloc(sizeof(Elem));
		curr->broj = broj;
		curr->next = NULL;

		if (head==NULL)
		{
			head = curr;
		}
		else
		{
			last->next = curr;
		}
		last = curr;
	}


	return head;
}

void printElem(Elem* head) {
	while (head)
	{
		printf("%d->", head->broj);
		head = head->next;
	}
	printf("NULL");

}

Elem* dodajElem(Elem* head, int broj) {
	Elem* novi = malloc(sizeof(Elem));
	novi->broj = broj;
	novi->next = NULL;
	if (head==NULL)
	{
		head = novi;
	}
	else
	{
		Elem* curr = head;
		while (curr->next<=broj)
		{
			curr = curr->next;
		}
		novi->next = curr->next;
		curr->next = novi;

	}



	return head;
}


float obrada(Student* head, char* smer) {

	float suma = 0;
	int count=0;
	while (head!=NULL)
	{
		if ((strcmp(head->smer, smer))==0)
		{
			suma += head->prosek;
			count++;
		}
		head = head->next;
	}

	return suma;
}


int cifre(int n) {
	int zbir = 0;
	while (n)
	{
		zbir += n % 10;
		n /= 10;

	}

	return zbir;
}

float rastojanje(float x1, float y1, float x2, float y2) {
	return sqrt(pow(x2 + x2, 2) + pow(y1 + y2, 2));

}

int brisanje(float x1, float y1, float x2, float y2, float r1, float r2) {

	if (r1 + r2 >= rastojanje(x1, y1, x2, y2));
	{
		return 1;
	}
	
	return 0;
}



int main() {

	/*
	Student* head =NULL;
	
	
	while (1)
	{
		char* str = malloc(30 * sizeof(char));
		double pro;
		scanf("%s", str);
		//printf("%s PRVI\n", str);
		if (strcmp(str, "kraj")==0)
		{
			break;
		}
		char* str1 = malloc(30*sizeof(char));
		char* str2 = malloc(30*sizeof(char));
		
		scanf("%s %lf %s", str1, &pro, str2);

		/*
		scanf("%s", str1);
		//printf("%s DRUGI\n", str1);  // moze i ovako jedan po jedan
		scanf("%lf", &pro);
		//printf("%lf PROSEK\n", pro);
		scanf("%s", str2);
		//printf("%s TRECI\n", str2);

		addNode(&head,str, str1, str2, pro);


	}
		*/



	/*
	Jovan Jovovic 9.55 SI
	Jovan Jovovic 8.88 SI
	Jovan Jovovic 9.00 SI
	Jovan Jovovic 8.35 SI
	Jovan Jovovic 7.93 SI
	kraj
	
	*/


	/*
	addNode(&head, "Jovan", "Jovovic", "SI", 9.30);
	addNode(&head, "Jovan", "M", "SI", 9.00);
	addNode(&head, "Jovan", "A", "SI", 8.30);
	addNode(&head, "Jovan", "Z", "SI", 7.93);
	addNode(&head, "Jovan", "G", "SI", 5.30);


	//printf("%s %s %s %.2f\n", head->name, head->surname, head->smer, head->prosek);
	
	printList(head);
	float suma = obrada(head, "SI");
	printf("\n%.2f\n", suma);

	*/

	
	

	system("pause");
	return 0;

}