
#include <stdio.h>
#include <stdlib.h>

/* Link list node */
struct node {
	int data;
	struct node* next;
};


void insert(struct node** head)
{
    int ele;
    printf("\nenter the element to be inserted : ");
    scanf("%d",&ele);
    if((*head)== NULL)
    {
        printf("list is empty");
        return ;
    }
    else{
        struct node* new = (struct node*)malloc(sizeof(struct node));
        if(new == NULL)
        {
            printf("memory is not allocated for new node ");
            return ;
        }
        else{
            new->data = ele;
            struct node* temp = (*head)->next;
            new->next = temp;
            (*head)->next = new;
        }
    }
	
}

/* Function to push a node */
void create(struct node** head,struct node** last, int ele)
{
	struct node* new
		= (struct node*)malloc(sizeof(struct node));
        if((*head)==NULL)
        {
            new->data = ele;
            new -> next = NULL;
            (*head)=(*last)=new;
        }
           else{
               
          
                    new->data=ele;
	                new->next=NULL;
	                (*last)->next=new;
	                (*last)=new;
           }
        
}

/* Function to print linked list */
void display(struct node* head)
{
	struct node* temp = head;
	while (temp != NULL) {
		printf("%d ", temp->data);
		temp = temp->next;
	}
}

/* Driver code*/
int main()
{
	/* Start with the empty list */
	struct node* head = NULL;
    struct node* last = NULL;

	create(&head,&last, 20);
	create(&head,&last, 4);
	create(&head,&last, 15);
	create(&head,&last, 85);

	printf("Given linked list\n");
	display(head);
	
	insert(&head);
	printf("\nAfter inserting a element at 2nd node :");
	display(head);

	
}







