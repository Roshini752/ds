/* main.c*/

#include<stdio.h>
#include<stdlib.h>
#include <stddef.h>
//#include"header.h"

struct node
{
	int data;
	struct node *next;
};
struct node* head = NULL;
struct node* last = NULL;

void detect(struct node** head)
{
	struct node *cn,*nn;
	cn = *head;
	nn = *head;
	while(cn != NULL && nn != NULL && nn->next != NULL)
	{
		cn = cn -> next;
		nn = nn->next->next;
		if(cn == nn)
		{
		printf("loop is detected");
		exit(0);
		}
	}
}

void create(struct node** head,int ele)
{
	struct node *new = (struct node*)malloc(sizeof(struct node));
	if((*head) == NULL)
	{
		new -> data = ele;
		new -> next = NULL;
		(*head)=last=new;
	}
	else
	{
		new->data = ele;
		new->next = NULL;
		last->next = new;
		last = new;
	}
}

/*void display(struct node* head)
{
	struct node*temp = head;
	while( temp != NULL)
	{
	printf("%d",temp->data);
	temp = temp->next;
	}
}*/

int main()
{
	create(&head,1);
	create(&head,2);
	create(&head,3);
	create(&head,4);
	create(&head,5);
	head->next->next->next = head->next;
	//printf("created elements are\n");
	//display(head);
	detect(&head);

}
