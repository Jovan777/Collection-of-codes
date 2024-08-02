#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
    Node* head = NULL, * last = head, * temp;

    User u;
    while (fscanf(in, "%s %s\n",u.username, u.email)==2)
    {
        temp = malloc(sizeof(*temp));
        temp->user = u;
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




int main() {


    char niz[] = "abcd";
    char niz2[] = "rbgf";

    printf("%d", strcmp(niz2, niz));



	return 0;
}



