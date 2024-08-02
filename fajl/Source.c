#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct player{

	char name[31];
	int ftM;
	int ftA;
	int twoA;
	int twoM;
	int threeA;
	int threeM;
	int pts;


}Player;

typedef struct student {

	char id[10];
	char name[31];
	char mod[3];
	char group[3];
	float p1, p2, p3, p4, pts;
	int z;
	int grade;

}Student;

typedef struct user {
	char username[31], email[31];
	int time;
} User;
typedef struct node {
	User user;
	struct node* next;
} Node;

typedef struct elem {

	Student s;
	struct elem* next;

}Elem;

typedef struct school {
	int id, places;
	char name[31];
} School;

typedef struct pupil {
	int id, school;
	char name[31];
	double averageGrade;
} Pupil;



#define MAX_NUMBER_OF_SCHOOLS 400

void readSchools(School schools[MAX_NUMBER_OF_SCHOOLS]) {

	FILE* in = fopen("skole.txt", "r");
	for (int i = 0; fscanf(in, "%d %[^\n]\n", &schools[i].places, schools[i].name) == 2; i++) {
		schools[i].id = i;
	};


	fclose(in);
}

Node* readPupils() {
	Node* head = NULL, * last = NULL, * temp;
	FILE* in = fopen("zelje.pod", "rb");
	Pupil p;

	while (fread(&p, sizeof(p), 1, in)==1)
	{
		temp = malloc(sizeof(*temp));
		temp->pupil = p;
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


	fclose(in);
	return head;

}

Node* readUsers() {
	FILE* in = fopen("korisnici.txt", "r");
	Node* head = NULL, * last = NULL, * temp;
	User u;
	while (fscanf(in, "%s %s\n", u.username, u.email)==2)
	{
		temp = malloc(sizeof(*temp));
		temp->user = u;
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

	fclose(in);
	return head;
}


User updateTime(Node* head) {
	FILE* in = fopen("logs.txt", "r");
	char email[31], action;
	int time;
	User max = head->user;
	while (fscanf(in,"%s %c %d\n", email, &action, &time)==3)
	{
		Node* curr = head;
		while (curr && strcmp(curr->user.email, email))
		{
			curr = curr->next;
		}
		if (curr)
		{
			switch (action)
			{
			case 'p':
				curr->user.time -= time;
				break;
			case 'o':
				curr->user.time += time;
				break;
			}
			if (curr->user.time>max.time || curr->user.time==max.time && strcmp(curr->user.username, max.username)<0)
			{
				max = curr->user;
			}

		}


	}

	fclose(in);
	return max;

}



void sortPupils(Node* head) {
	for (Node* f = head; f; f = f->next)
		for (Node* s = f->next; s; s = s->next)
			if (f->pupil.averageGrade < s->pupil.averageGrade ||
				f->pupil.averageGrade == s->pupil.averageGrade && f->pupil.id < s->pupil.averageGrade)
			{
				Pupil temp = f->pupil;
				f->pupil = s->pupil;
				s->pupil = temp;

			}

}

void matchAndWrite(Node* head, School schools[MAX_NUMBER_OF_SCHOOLS]) {
	FILE* izlaz = fopen("upisi.txt", "w");
	for (Node* n = head; n ;n=n->next)
	{
		fprintf(izlaz, "%d %s %.6lf ", n->pupil.id, n->pupil.name, n->pupil.averageGrade );
		for (int i = 0; i < MAX_NUMBER_OF_SCHOOLS; i++)
		{
			if (n->pupil.school==schools[i].id)
			{
				if (schools[i].places>0)
				{
					fprintf(izlaz, "%s\n", schools[i].name);
					schools[i].places--;
					break;

				}
				else if (schools[i].places <= 0)
				{
					fprintf(izlaz, "NEUPISAN\n");
					break;
				}
			}

		}

	}

	fclose(izlaz);
}






Elem* createList() {
	FILE* file = fopen("ispit.csv", "r");
	Elem* head = NULL;
	Elem* tail = NULL;
	Elem* temp;
	Student s;
	char* format = "%[^,],%[^,],%[^,],%[^,],%f, %f, %f, %f, %d\n";
	//char* format1= "%[^,],%[^,],%[^,],%[^,], %f, %f, %f, %f, %d\n";

	while ((fscanf(file, format, s.id, s.name, s.mod, s.group, &s.p1, &s.p2, &s.p3, &s.p4, &s.z)==9))
	{
		int pitalice = s.p1 + s.p2 + s.p3 + s.p4;
		if (pitalice<0)
		{
			pitalice = 0;
		}
		s.pts = s.z + pitalice;

		s.grade = s.pts / 10;
		if (s.grade<5)
		{
			s.grade = 5;
		}
		else if (s.pts >s.grade*10)
		{
			s.grade++;
		}
		temp = malloc(1 * sizeof(*temp));
		temp->s = s;
		temp->next = NULL;
		if (head==NULL)
		{
			head = temp;
		}
		else
		{
			tail->next = temp;
		}
		tail = temp;
		
	}

	fclose(file);
	return head;

}

int cmp(Student s1, Student s2) {
	int m = strcmp(s1.mod, s2.mod);
	if (m)
	{
		return m;
	}
	else
	{
		int g = strcmp(s1.group, s2.group);
		if (g)
		{
			return g;
		}
		else
		{
			return strcmp(s1.id, s2.id);
		}

	}



}


void sort(Elem* head) {

	for (Elem* p = head; p!=NULL; p=p->next)
	{
		for (Elem* d = p->next; d!=NULL; d=d->next)
		{
			if (cmp(p->s, d->s)>0)
			{
				Student t = p->s;
				p->s = d->s;
				d->s = t;

			}
		}


	}


}


void write_and_free(Elem* head) {
	Elem* old;
	FILE* file = fopen("ocene.txt", "w");
	while (head)
	{
		fprintf(file, "%s %s %s %s %.2f %d\n",
			head->s.mod, head->s.group, head->s.id, head->s.name, head->s.pts, head->s.grade);
		old = head;
		head = head->next;
		free(old);

	}


	fclose(file);
}



int main() {

	Elem* head = createList();
	sort(head);
	write_and_free(head);



	return 0;
}