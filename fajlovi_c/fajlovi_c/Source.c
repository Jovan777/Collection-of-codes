#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


/*
typedef struct player {

	char name[31];
	int ftM, ftA, twoM, twoA, thrM, thrA, pts;

}Player;

*/ 
//Kosarkasi

typedef struct student {

	char id[10], name[31], mod[3], group[3];
	float p1, p2, p3, p4, pts;
	int z, grade;

}Student;

typedef struct elem {
	Student s;
	struct elem* sled;

}Elem;


Elem* create_list() {

	Elem* head = NULL, * tail = head, * temp;
	Student s;
	FILE* file = fopen("ispit.csv", "r");
	if (!file)
	{
		exit(1);
	}
	char* format = "%[^,],%[^,],%[^,],%[^,],%f,%f,%f,%f,%d\n";
	while ((fscanf(file, format, s.id, s.name, s.mod, s.group,
		&s.p1, &s.p2, &s.p3, &s.p4, &s.z)) == 9) {

		float p = s.p1 + s.p2 + s.p3 + s.p4;
		if (p<0)
		{
			p = 0;
		}
		else if (p>45)
		{
			p = 45;
		}

		s.pts = s.z + p;
		s.grade = s.pts / 10;
		if (s.grade < 5)
		{
			s.grade = 5;
		}
		else if (s.pts > s.grade*10)
		{
			s.grade++;
		}
		temp = malloc(sizeof(Elem));
		temp->s = s;
		temp->sled = NULL;
		if (tail==NULL)
		{
			head = temp;
		}
		else
		{
			tail->sled = temp;
		}
		tail = temp;



	}

	fclose(file);
	return head;

}

void write_and_free(Elem* head) {
	Elem* old;
	FILE* file = fopen("ocene.txt", "w");
	if (!file)
	{
		exit(1);
	}
	while (head)
	{
		fprintf(file, "%s %s %s %s %.2f %d\n", head->s.mod, head->s.group, head->s.id, head->s.name,
			 head->s.pts, head->s.grade);

		old = head;
		head = head->sled;
		free(old);


	}

	fclose(file);

}

int cmp(Student s1, Student s2) {

	int m = strcmp(s1.mod, s2.mod);
	if (m)
	{
		return m;
	}
	else
	{
		int k = strcmp(s1.group, s2.group);
		if (k)
		{
			return k;
		}
		else
		{
			int z = strcmp(s1.id, s2.id);
			return z;
		}

	}


}


void sort(Elem* head) {

	for (Elem* p = head; p; p = p->sled)
	{
		for (Elem* i = p->sled; i ; i=i->sled)
		{
			int k = cmp(p->s, i->s);
			if (k > 0) //ako je k>0 onda menjamo mesta studentima
			{
				Student s = p->s;
				p->s = i->s;
				i->s = s;

			}

		}

	}



}


typedef struct school {

	int id, places;
	char name[31];

}School;

typedef struct pupil {

	int id, school;
	char name[31];
	double averageGrade;

}Pupil;

typedef struct node {
	Pupil pupil;
	struct node* next;

}Node;

void readSchools(School schools[400]) {

	FILE* in = fopen("skole.txt", "r");
	for (int i = 0; fscanf(in, "%d %[^\n]\n",schools[i].places, schools[i].name)==2; i++)
	{
		schools[i].id = i;
	}
	fclose(in);
}

Node* readPupils() {

	FILE* in = fopen("zelje.pod", "rb");
	Node* head = NULL, * last = head, * temp;
	Pupil p;
	
	while (fread(&p, sizeof(p), 1, in) == 1)
	{
		temp = malloc(sizeof(*temp));
		temp->pupil = p;
		temp->next = NULL;
		if (!head)
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

void sortPupils(Node* head) {
	for (Node* i = head; i; i = i->next)
	{
		for (Node* j = i->next; j; j = j->next)
		{
			if (i->pupil.averageGrade < j->pupil.averageGrade || 
				i->pupil.averageGrade == j->pupil.averageGrade && i->pupil.id < j->pupil.id);
			{
				Pupil temp = i->pupil;
				i->pupil = j->pupil;
				j->pupil = temp;

			}


		}

	}

}

void matchAndWrite(Node* head, School schools[400]) {

	FILE* out = fopen("upisi.txt", "w");
	for (Node* n = head; n ; n=n->next)
	{
		int found = 0;
		fprintf(out, "%d %s %.6lf ", n->pupil.id, n->pupil.name, n->pupil.averageGrade);
		for (int s = 0; s < 400; s++)
		{
			if (n->pupil.id==schools[s].id)
			{
				if (schools[s].places > 0)
				{
					found = 1;
					schools[s].places--;
					fprintf(out, "%s\n", schools[s].name);

				}
				break;

			}

		}
		if (!found)
		{
			fprintf(out, "NEUPISAN\n");
		}


	}
	fclose(out);

}


int main() {

	/*
	FILE* stats = fopen("stats.txt", "r");
	FILE* points = fopen("points.txt", "w");
	if (!stats)
	{
		exit(1);
	}
	char c;
	char* name;
	Player curr, max;
	max.pts = -1;

	while (1)
	{
		name = curr.name;
		while ((c = fgetc(stats)) != ';')
		{
			if (c==EOF)
			{
				break;
			}
			
			*name++ = c;

		}
		if (c == EOF)
		{
			break;
		}
		*name = '\0';
		fscanf(stats, "%d", &curr.ftM);
		fgetc(stats);
		fscanf(stats, "%d", &curr.ftA);

		fscanf(stats, "%d", &curr.twoM);
		fgetc(stats);
		fscanf(stats, "%d", &curr.twoA);

		fscanf(stats, "%d", &curr.thrM);
		fgetc(stats);
		fscanf(stats, "%d", &curr.thrA);
		fgetc(stats);

		curr.pts = curr.ftM + curr.twoM * 2 + curr.thrM * 3;
		if (curr.pts>max.pts)
		{
			max = curr;
		}

		fprintf(points, "%s %d/%d %d\n", curr.name, (curr.twoM + curr.thrM), (curr.twoA + curr.thrA), curr.pts);



	}

	putchar('\n');
	fprintf(points, "MVP: %s %d/%d %d\n", max.name, (max.twoM + max.thrM), (max.twoA + max.thrA), max.pts);



	fclose(stats);

	*/
	//kosarkasi
	/*
	Elem* head = create_list();
	sort(head);

	write_and_free(head);
	*/

	int n = strcmp("prz", "abc");
	printf("%d", n);



	return 0;
}