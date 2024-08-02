#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct node {

	int data;
	struct node* next;

}Node;


Node* formList() {

	int n;
	Node* head = NULL;
	Node* last = NULL;
	while (scanf("%d", &n)==1)
	{
		Node* node = malloc(1 * sizeof(Node));
		node->data = n;
		node->next = NULL;

		if (last==NULL)
		{
			head = node;
		}
		else
		{
			last->next = node;
		}
		last = node;


	}

	return head;

}


void printList(Node* head) {

	for (Node* curr = head; curr!=NULL; curr=curr->next)
	{
		printf("%d->", curr->data);
	}
	printf("NULL");

}

void freeList(Node* head) {
	Node* curr = head;

	while (curr!=NULL)
	{
		Node* old = curr;
		curr = curr->next;
		free(old);

	}

}

int listSize(Node* head) {
	Node* curr = head;
	int count = 0;
	while (curr!=NULL)
	{
		count++;
		curr = curr->next;
	}

	return count;
}

Node* searchFirst(Node* head, int n) {

	for (Node* curr = head; curr!=NULL; curr=curr->next)
	{
		if (curr->data==n)
		{
			return curr;
		}

	}
	return NULL;

}

Node* searchLast(Node* head, int n) {

	Node* last = NULL;
	for (Node* curr = head; curr!=NULL; curr=curr->next)
	{
		if (curr->data==n)
		{
			last = curr;
		}

	}

	return last;
}

Node* sortList(Node* head) {

	for (Node* i = head; i!=NULL ; i=i->next)
	{
		for (Node* j = i->next; j!=NULL; j=j->next)
		{
			if (i->data>j->data)
			{
				int t = i->data;
				i->data = j->data;
				j->data=t;
			}

		}

	}

}

Node* insertSorted(Node* head, int n) {
	Node* elem = malloc(1 * sizeof(Node));
	elem->data = n;
	elem->next = NULL;
	for (Node* curr = head, *previous=NULL; curr!=NULL ;previous=curr, curr=curr->next)
	{
		if (n<curr->data)
		{
			if (previous==NULL)
			{
				elem->next = head;
				head = elem;
			}
			else
			{
				elem->next = curr;
				previous->next = elem;

			}
			break;


		}

	}


	return head;
}

Node* removeNodes(Node* head, int n){
	for (Node* curr = head, *prev=NULL; curr !=NULL; curr=curr->next)
	{
		if (curr->data==n)
		{
			Node* old = curr;
			curr = curr->next;
			free(old);
			if (prev==NULL)
			{
				head = curr;
			}
			else
			{
				prev->next = curr;
			}

		}
		else
		{
			prev = curr;
		}

	}

	return head;
}


Node* mergeList(Node* head1, Node* head2) {
	Node* head = NULL;
	Node* last = NULL;

	Node* curr1 = head1;
	Node* curr2 = head2;

	while (curr1!=NULL && curr2!=NULL)
	{
		Node* temp = NULL;
		if (curr1->data < curr2->data)
		{
			temp = curr1;
			curr1 = curr1->next;
		}
		else
		{
			temp = curr2;
			curr2 = curr2->next;
		}

		temp->next = NULL;

		if (last==NULL)
		{
			head = temp;
		}
		else
		{
			last->next = temp;
		}
		last = temp;

	}

	if (curr1!=NULL)
	{
		if (last==NULL)
		{
			head = curr1;
		}
		else
		{
			last->next = curr1;
		}

	}

	if (curr2 != NULL)
	{
		if (last == NULL)
		{
			head = curr2;
		}
		else
		{
			last->next = curr2;
		}

	}

	return head;
}


void removeDuplicate(Node* head) {

	Node* start = head;
	while (start!=NULL)
	{
		Node* prev = start;
		Node* curr = start->next;

		while (curr!=NULL && curr->data==start->data)
		{
			prev = curr;
			curr = curr->next;
		}

		prev->next = NULL;
		freeList(start->next);
		start->next = curr;


		start = curr;
	}



}

Node* reverse(Node* head) {

	Node* prev = NULL;
	Node* next = head;
	Node* curr = NULL;

	while (next!=NULL)
	{
		curr = next;
		next = next->next;
		curr->next = prev;
		prev = curr;

	}

	return curr;
}


Node* getMiddle(Node* head) {

	Node* fast = head;
	Node* slow = head;

	while (fast!=NULL)
	{
		fast = fast->next;
		if (fast!=NULL)
		{
			fast = fast->next;
			slow = slow->next;
		}

	}

	return slow;
}

Node* getNthfromEnd(Node* head, int n) {

	Node* fast = head;
	Node* slow = head;
	for (int i = 0; i < n && fast != NULL; i++, fast = fast->next);
	for (; fast != NULL; fast = fast->next, slow = slow->next);

	return slow;
}


/*
int main() {
	printf("Unesite elemente liste: \n");

	Node* elem = formList();
	char c = getchar();
	putchar('\n');
	printList(elem);
	putchar('\n');

	/*
	printList(elem);
	int count = listSize(elem);

	printf("\nBroj elemenata u listi je: %d", count);
	putchar('\n');
	Node* elem2 = searchFirst(elem, 3);
	printList (elem2);
	putchar('\n');
	elem2 = searchLast(elem, 3);
	printList(elem2);
	putchar('\n');
	
	sortList(elem);
	printList(elem);
	

	int n;
	printf("Unesite broj: ");
	scanf("%d", &n);

	insertSorted(elem, n);
	printList(elem);

	putchar('\n');
	removeNodes(elem, 2);
	printList(elem);
	putchar('\n');

	Node* elem2 = formList();
	char c1 = getchar();
	putchar('\n');
	printList(elem2);
	putchar('\n');

	Node* elem3 = mergeList(elem, elem2);
	printList(elem3);
	putchar('\n');

	removeDuplicate(elem3);
	printList(elem3);
	putchar('\n');

	elem3 = reverse(elem3);
	printList(elem3);
	putchar('\n');

	Node* elem4 = getMiddle(elem3);
	printList(elem4);
	putchar('\n');


	freeList(elem);
	//freeList(elem2);

	system("pause");
	return 0;
	
}
*/