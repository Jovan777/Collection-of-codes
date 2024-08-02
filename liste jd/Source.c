#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>


typedef struct node {

	float data;
	struct node* next;

}Node;


Node* formList(){

	float n;
	Node* head = NULL;
	Node* last = NULL;
	while ((scanf("%f",&n)==1))
	{

		if (n<=0)
		{
			break;
		}
		Node* node = calloc(1, sizeof(Node));
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

	if (head==NULL)
	{
		return;
	}
	for (Node *trenutni = head; trenutni!=NULL; trenutni=trenutni->next)
	{
		printf("%.2f->", trenutni->data);
	}
	printf("NULL\n");

}


void freeList(Node* head) {

	Node* trenutni = head;
	while (trenutni!=NULL)
	{
		Node* old = trenutni;
		trenutni = trenutni->next;
		free(old);

	}

}

int listCount(Node* head) {

	int brojac = 0;
	for (Node* trenutni = head; trenutni != NULL; trenutni = trenutni->next)
	{
		brojac++;
	}
	return brojac;

}

Node* searhFirst(Node* head, int n) {
	for (Node* trenutni = head; trenutni!=NULL ; trenutni=trenutni->next)
	{
		if (trenutni->data==n)
		{
			return trenutni;
		}

	}
	return NULL;

}

Node* searchLast(Node* head, int n) {
	Node* last = NULL;
	for (Node* curr = head; curr != NULL; curr=curr->next)
	{
		if (curr->data==n)
		{
			last = curr;
		}

	}

	return last;

}


Node* sortList(Node* head) {
	for (Node* i = head; i != NULL; i=i->next)
	{
		for (Node* j = i->next; j != NULL; j=j->next)
		{
			if (i->data>j->data)
			{
				int t = i->data;
				i->data = j->data;
				j->data = t;

			}

		}

	}
}


Node* removeNodes(Node* head, int n) {
	//izbacujemo elemente iz liste koji imaju vredsnost n

	for (Node* current  = head, *previous=NULL;  current!= NULL; )
	{
		if (current->data==n)
		{
			Node* old = current;
			current = current->next;
			free(old);
			
			if (previous==NULL)
			{
				head = current;
			}
			else
			{
				previous->next = current;
			}

		}
		else
		{
			previous = current;
			current = current->next;
		}

	}

	return head;



}


Node* mergeLists(Node* head1, Node* head2) {

	Node* head = NULL;
	Node* last = NULL;

	Node* trenutni1 = head1;
	Node* trenutni2 = head2;

	while (trenutni1!=NULL && trenutni2!=NULL)
	{
		//ovde pretpostavljamo da su liste uredjene pa dodajemo elemente po poretku
		Node* temp = NULL;
		if (trenutni1->data < trenutni2->data)
		{
			temp = trenutni1;
			trenutni1 = trenutni1->next;
		}
		else
		{
			temp = trenutni2;
			trenutni2 = trenutni2->next;
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

	if (trenutni1!=NULL)
	{

		if (last==NULL)
		{
			head = trenutni1;
		}
		else
		{
			last->next = trenutni1;
		}
	}
	if (trenutni2 != NULL)
	{

		if (last == NULL)
		{
			head = trenutni2;
		}
		else
		{
			last->next = trenutni2;
		}
	}

	return head;
	

}


void removeDuplicates(Node* head) {

	Node* start = head;
	while (start!=NULL)
	{
		Node* prethodni = start;
		Node* trenutni = start->next;

		while (trenutni!=NULL && trenutni->data==start->data)
		{
			prethodni = trenutni;
			trenutni = trenutni->next;
		}

		prethodni->next = NULL;
		freeList(start->next);
		start->next = trenutni;

		start = trenutni;


	}



}


Node* reverseList(Node* head) {

	Node* prethodni = NULL;
	Node* sledeci = head;
	Node* trenutni = NULL;

	while (sledeci!=NULL)
	{
		trenutni = sledeci;
		sledeci = sledeci->next;
		trenutni->next = prethodni;
		prethodni = trenutni;

	}
	
	return trenutni;


}

Node* getMid(Node* head) {
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


Node* getNthEnd(Node* head, int n) {

	Node* fast = head;
	for (int i = 0; i < n && fast != NULL; i++, fast = fast->next);
	Node* slow = head;
	for (; fast != NULL; fast = fast->next, slow = slow->next);
	

	return slow;
}

Node* insertSorted(Node* head, int n) {

	Node* node = calloc(1, sizeof(Node));
	if (node==NULL)
	{
		exit(-1);
	}
	node->data = n;
	node->next = NULL;

	for ( Node* trenutni=head, *prethodni=NULL;trenutni!=NULL; prethodni=trenutni, trenutni=trenutni->next)
	{
		if (n<trenutni->data)
		{
			if (prethodni==NULL)
			{
				node->next = head;
				head = node;
			}
			else
			{
				node->next = trenutni;
				prethodni->next = node;

			}
			break;
		}


	}

	return head;


}


int loop_exist(Node* head) {

	Node* fast = head;
	Node* slow = head;

	while (fast!=NULL)
	{
		slow = slow->next;
		fast = fast->next;
		if (fast!=NULL)
		{
			fast = fast->next;
		}

		if (fast==slow)
		{
			return 1;
		}

	}

	return 0;
}


void removeLoop(Node* head) {

	int loop = loop_exist(head);

	if (loop==1)
	{
		Node* fast = head;
		Node* slow = head;

		while (fast!=NULL)
		{
			slow = slow->next;
			fast = fast->next;
			if (fast!=NULL)
			{
				fast = fast->next;
			}
			if (fast==slow)
			{
				break;
			}
		}

		if (fast == head) {
			while (fast->next!=head)
			{
				fast = fast->next;
			}
		}
		else
		{
			slow = head;
			while (fast->next != slow->next)
			{
				slow = slow->next;
				fast = fast->next;
			}

		}
		fast->next = NULL;


	}


}


int main() {
	putchar('\n');
	Node* head1 = formList();
	printList(head1);
	putchar('\n');


	/*
	Node* head1 = formList();
	char c;
	scanf("%c", &c);
	Node* head2 = formList();

	sortList(head1);
	sortList(head2);

	printf("\nPRE SPAJANJA:\n");
	printList(head1);
	printList(head2);
	Node* head = mergeLists(head1, head2);

	printf("\nPOSLE SPAJANJA:\n");


	printList(head);

	



	//freeList(head);

	
	Node* head = formList();
	printList(head);
	//sortList(head);

	Node* middle = getMid(head);
	printf("\nSrednji element je:%d\n", middle->data);

	putchar('\n');

	Node* nth = getNthEnd(head, 3);
	printf("\element sa kraja je:%d\n", nth->data);


	//removeDuplicates(head);
	
	//head=reverseList(head);
	
	//printList(head);


	Node* head = formList();
	printList(head);
	putchar('\n');
	Node* last = getNthEnd(head, 1);
	last->next = head;
	removeLoop(head);
	printList(head);
	

	Node* head = formList();
	sortList(head);
	printList(head);

	char c;
	scanf("%c", &c);

	printf("\n");
	int n;
	printf("\nUnesite broj:\n");
	scanf("%d", &n);
	printf("\n");
	head = insertSorted(head, n);
	printList(head);



	freeList(head);
	*/


	return 0;
}


