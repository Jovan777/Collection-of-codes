#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct time {

	int hours, minutes;

} Time;


#define MAX_LENGTH 20

typedef struct patient {

	char forename[MAX_LENGTH + 1], surname[MAX_LENGTH + 1];

	int severity;

	Time sanitationTime;

} Patient;



typedef struct node {

	Patient patient;

	struct node* next;

} Node;



Patient readLine(FILE* input) {

	Patient data;
	if (fscanf(input, "%s %s %d %d:%d\n", data.forename, data.surname, &data.severity, &data.sanitationTime.hours, 
		&data.sanitationTime.minutes)==5)
	{
		return data;
	}

}

void deallocateList(Node* head) {

	while (head)
	{
		Node* old = head;
		head = head->next;
		free(old);

	}

}

int timeToint(Time t) {
	return t.hours * 60 + t.minutes;
}

void matchAndWrite(Node* head, Time startTime, Time endTime) {

	FILE* out = fopen("raspored.txt", "w");


	for (Node* curr = head; curr; curr = curr->next)
	{
		int start = timeToint(startTime);
		int end = timeToint(endTime);
		int razlika = end - start;
		int vreme = timeToint(curr->patient.sanitationTime);
		if (timeToint(curr->patient.sanitationTime) <=razlika)
		{
			fprintf(out, "%s %s %02d:%02d-%02d:%02d\n", curr->patient.forename, curr->patient.surname,
				startTime.hours, startTime.minutes,
				endTime.hours, endTime.minutes);
			startTime.hours += curr->patient.sanitationTime.hours;
			startTime.minutes += curr->patient.sanitationTime.minutes;

		}


	}


	fclose(out);
}
Node* readPatients() {

	Node* head = NULL, * last = NULL, * temp;
	Patient data;
	FILE* in = fopen("pacijenti.txt", "r");
	while (fscanf(in, "%s %s %d %d:%d\n", data.forename, data.surname, &data.severity, &data.sanitationTime.hours,
		&data.sanitationTime.minutes) == 5)
	{
		temp = malloc(sizeof(*temp));
		temp->patient = data;
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

	fclose(in);
	return head;
}



void sortPatients(Node* head) {

	for (Node* curr = head; curr; curr = curr->next)
	{
		for (Node* curr2 = curr->next; curr2; curr2 = curr2->next)
		{
			if (curr->patient.severity < curr2->patient.severity || (curr->patient.severity == curr2->patient.severity &&
				(curr->patient.sanitationTime.hours * 60 + curr->patient.sanitationTime.minutes) >
				(curr2->patient.sanitationTime.hours * 60 + curr2->patient.sanitationTime.minutes)))
			{
				Patient t = curr->patient;
				curr->patient = curr2->patient;
				curr2->patient = t;


			}

		}

	}

}

char** readWords() {

	char** words = malloc(sizeof(char*));
	char c;
	int i=0;
	while (1)
	{
		words[i] = malloc(sizeof(char));
		int duz = 0;
		while ((c=getchar())!='\n')
		{
			duz++;
			words[i] = realloc(words[i], (duz + 1) * sizeof(char));
			words[i][duz - 1] = c;
		}
		if (duz==0)
		{
			words[i] = NULL;
			break;
		}
		else
		{
			words[i][duz] = '\0';
			i++;
			words = realloc(words, (i + 1) * sizeof(char*));

		}


	}

	return words;
}

char** readWords2(int n) {

	char** mat = (char**)malloc(n * sizeof(char*));

	char c;
	for (int i = 0; i < n; i++)
	{
		mat[i] = (char*)malloc(21 * sizeof(char));
		scanf("%s%c", mat[i], &c);
		mat[i] = (char*)realloc(mat[i], (strlen(mat[i]) + 1) * sizeof(char));

	}

	return mat;
}//upis radi


int readWord(char word[20]) {

	char c;
	int i = 0;
	while ((c=getchar())!='\n')
	{
		word[i++] = c;
	}
	word[i] = '\0';
	if (i==0)
	{
		return 0;
	}
	else
	{
		return 1;
	}
	

}


int main() {
	char word[20];
	while (readWord(word)==1)
	{
		printf("%s\n", word);
	}



	printf("Kraj\n");
	system("pause");
	return 0;
}


