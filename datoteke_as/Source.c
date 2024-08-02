#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


//vezbe 10
/*
//typedef enum Stanje{code, com_s, com_l, com_b, com_e} stanje;

typedef struct player {

	char name[31];
	int ftA, ftM, twoA, twoM, thrA, thrM, pts;

}Player;


typedef struct student {

	char id[10];
	char name[31];
	char mod[3];
	char grupa[3];
	float p1, p2, p3, p4, pts;
	int z, grade;

}Student;



typedef struct elem {

	Student s;
	struct elem* next;

}Elem;


Elem* create_list() {
	Elem* head = NULL, * tail = head, * tmp;

	Student s;
	FILE* file = fopen("ispit.csv", "r");
	if (!file)
	{
		exit(-1);
	}


	char* format = "%[^,],%[^,],%[^,],%[^,], %f, %f, %f, %f, %d\n";

	while (fscanf(file, format, s.id, s.name, s.mod, s.grupa, 
		&s.p1, &s.p2, &s.p3, &s.p4, &s.z)==9)
	{

		float p = s.p1 + s.p2 + s.p3 + s.p4;
		s.pts = s.z + (p > 45 ? 45 : p < 0 ? 0 : p);

		s.grade = s.pts / 10;
		if (s.pts > s.grade * 10)
		{
			s.grade++;
		}
		else if (s.grade<5)
		{
			s.grade = 5;
		}

		tmp = malloc(sizeof(*tmp));
		if (!tmp)
		{
			exit(-1);
		}

		tmp->s = s;

		tmp->next = NULL;

		if (!head)
		{
			head = tmp;
		}
		else
		{
			tail->next = tmp;
		}
		tail = tmp;


	}



	fclose(file);
	return head;
}


void write_and_free(Elem* head) {
	//upisujemo u novu datoteku
	FILE* file = fopen("ocene.txt", "w");
	if (!file)
	{
		exit(-1);
	}

	Elem* old;

	while (head)
	{
		fprintf(file, "%s %s %s %s %.2f %d\n", head->s.id,  head->s.grupa,  head->s.grupa,  
			head->s.name,  head->s.pts , head->s.grade );

		old = head;
		head = head->next;
		free(old);

	}

	fclose(file);
}
*/

/*
typedef struct school {
	int id, places;
	char name[31];
} School;

typedef struct pupil {
	int id, school;
	char name[31];
	double averageGrade;
} Pupil;

typedef struct node {
	Pupil pupil;
	struct node* next;
} Node;

#define MAX_NUMBER_OF_SCHOOLS 400



void readSchools(School schools[MAX_NUMBER_OF_SCHOOLS]) {

	FILE* in = fopen("skole.txt", "r");
	for (int i = 0; fscanf(in,"%d [^\n]\n", &schools[i].places, schools[i].name )==2 ; i++)
	{
		schools[i].id = i;

	}

	fclose(in);
}


Node* readPupils() {

	Node* head = NULL, *last = NULL, *tmp;
	FILE* in = fopen("zelje.pod", "rb");
	Pupil p;
	while (fread(&p, sizeof(p), 1, in)==1)
	{
		tmp = malloc(1 * sizeof(Node));
		tmp->pupil = p;
		tmp->next = NULL;
		if (!head)
		{
			head = tmp;
		}
		else
		{
			last->next = tmp;
		}
		last = tmp;
	}

	fclose(in);
	return head;

}

void sortPupils(Node* head) {

	for (Node* p = head; p ; p=p->next)
	{
		for (Node* s = p->next; s ; s=s->next)
		{
			if (p->pupil.averageGrade<s->pupil.averageGrade || (p->pupil.averageGrade == s->pupil.averageGrade && p->pupil.id<s->pupil.id))
			{
				Pupil tmp = p->pupil;
				p->pupil = s->pupil;
				s->pupil = tmp;

			}
		}

	}

}


void matchAndWrite(Node* head, School schools[MAX_NUMBER_OF_SCHOOLS]) {
	FILE* out = fopen("upisi.txt", "w");
	for (Node* p = head; p ; p=p->next)
	{
		int found = 0;
		fprintf(out, "%d %s %.6lf ", p->pupil.id, p->pupil.name, p->pupil.averageGrade);
		for (int i = 0; i < MAX_NUMBER_OF_SCHOOLS; i++)
		{
			if (p->pupil.school==schools[i].id)
			{
				if (schools[i].places>0)
				{
					found = 1;
					schools[i].places--;
					fprintf(out, "%s\n", schools[i].name);
				}
				break;

			}
		}
		if (found==0)
		{
			fprintf(out, "NEUPISAN\n");
		}

	}

	fclose(out);

}

void deallocateList(Node* head) {
	while (head) {
		Node* old = head;
		head = head->next;
		free(old);
	}

}
*/

typedef struct user {
	char username[31], email[31];
	int time;
} User;
typedef struct node {
	User user;
	struct node* next;
} Node;



Node* readUsers() {
	FILE* in = fopen("korisnici.txt", "r");
	Node* head = NULL, * last = head, * tmp;
	User u;
	while (fscanf(in, "%s %s\n",u.username, u.email )==2)
	{
		tmp = malloc(1 * sizeof(Node));
		tmp->user = u;
		tmp->next = NULL;

		if (!head)
		{
			head = tmp;
		}
		else
		{
			last->next = tmp;
		}
		last = tmp;

	}

	fclose(in);
	return head;


}

User updateTime(Node* head) {

	char email[31], action;
	int vreme;
	FILE* in = fopen("logs.txt", "r");

	User max = head->user;
	while (fscanf(in, "%s %c %d",email, &action, &vreme )!=EOF)
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
					curr->user.time -= vreme;
					break;
				case 'o':
					curr->user.time += vreme;
					break;

			}
			if (curr->user.time > max.time || (curr->user.time==max.time && strcmp(curr->user.username, max.username)<0))
			{
				max = curr->user;
			}

		}


	}


	fclose(in);
	return max;

}


void deallocateList(Node* head) {
	while (head) {
		Node* old = head;
		head = head->next;
		free(old);
	}
}




//uklanjanje komentara
int main() {
	
	/*
	Elem* head = create_list();
	write_and_free(head);
	//as 10 1.1 uklanjanje komentara
	/*
	FILE* stats = fopen(argv[1], "r");
	FILE* out = fopen(argv[2], "w");

	if (!stats)
	{
		return 1;
	}
	 
	char c;

	enum state s = code;

	while ((c = fgetc(stats))!=EOF)
	{
		switch (s)
		{
			
		case code:
			if (c=='/')
			{
				s = com_s;
			}
			else
			{
				fputc(c, out);
			}
			break;
		case com_s:
			if (c=='/')
			{
				s = com_l;
			}
			else if (c=='*')
			{
				s = com_b;
			}
			else
			{
				fputc('/', out);
				fputc(c, out);
				s = code;
			}
			break;

		case com_l:
			if (c=='\n')
			{
				fputc(c, out);
				s = code;
			}
			break;
		case com_b:
			if (c=='*')
			{
				s = com_e;
			}
			break;
		case com_e:
			if (c=='/')
			{
				s = code;
			}
			else if (c!='*')
			{
				s = com_b;
			}
			break;

		}
	}

	fclose(stats);
	fclose(out);
	*/
	/*
	/*
	//as 10 2 kosarkasi
	/*
	FILE* stats = fopen("stats.txt", "r");
	FILE* players = fopen("players.txt", "w");
	if (!stats)
	{
		return 1;
	}

	char c;
	char* name;
	Player curr, max; // da bi negde smestili podatke o max poenima
	max.pts = 0;

	while (1)
	{
		name = curr.name;
		while ((c=fgetc(stats))!=';')
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
		fgetc(stats);//citamo nepotreban znak /
		fscanf(stats, "%d", &curr.ftA);

		//prazan red ne se preskace jer su u pitanju dec brojevi

		fscanf(stats, "%d", &curr.twoM);
		fgetc(stats);//citamo nepotreban znak /
		fscanf(stats, "%d", &curr.twoA);

		fscanf(stats, "%d", &curr.thrM);
		fgetc(stats);//citamo nepotreban znak /
		fscanf(stats, "%d", &curr.thrA);

		fgetc(stats);//citamo znak za novi red

		curr.pts = curr.ftM + curr.twoM * 2 + curr.thrM * 3;

		if (curr.pts>max.pts)
		{
			max = curr;
		}

		fprintf(stdout, "%s %d/%d %d\n", curr.name, (curr.twoA + curr.thrA), (curr.twoM + curr.thrM), curr.pts);
		fprintf(players, "%s %d/%d %d\n", curr.name, (curr.twoA + curr.thrA), (curr.twoM + curr.thrM), curr.pts);


	}


	fprintf(stdout, "\nMVP:%s %d/%d %d\n", max.name, (max.twoA + max.thrA), (max.twoM + max.thrM), max.pts);
	fprintf(players, "\nMVP:%s %d/%d %d\n", max.name, (max.twoA + max.thrA), (max.twoM + max.thrM), max.pts);


	fclose(players);
	fclose(stats);
	*/
	
/*
School schools[MAX_NUMBER_OF_SCHOOLS];
Node* pupils;

readSchools(schools);
pupils = readPupils();
sortPupils(pupils);
matchAndWrite(pupils, schools);
deallocateList(pupils);
*/


Node* users = readUsers();
User userMax = updateTime(users);
deallocateList(users);
printf("%s %s %d", userMax.username, userMax.email, userMax.time);



	return 0;
}