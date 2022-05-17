
#include <stdio.h>
#include<stdlib.h>
struct sll
{
    int data;
    struct sll* next;
};
typedef struct sll node;
node* create(node* head ,node* last )
{
    
    node *new =(node*)malloc(sizeof(node));
    int ele;
    printf("enter the value : ");
    scanf("%d",&ele);
    if(new == NULL)
    {
        printf("memory is not allocated");
        return 0;
    }
    else
    {
        new->data = ele;
        new->next = NULL;
        if(head == NULL)
        {
            head = last = new;
        }
        else
        {
            last -> next = new;
            last = new;
        }
    }
    int ch;
    printf("enter a positive value to continue : ");
    scanf("%d",&ch);
    if(ch)
    {
        
        create(head,last);
    }
    return head;
}
void display(node* h)
{
	node* temp = h;
	while (temp != NULL) 
	{
		printf("%d ", temp->data);
		temp = temp->next;
	}
	printf("\n");
}
node* merge(node* head1,node* head2)
{
    
   node* temp= head1;
   if(temp == NULL)
   {  
       printf("memory is not allocated");
   }
   else
   {
       while(temp->next != NULL)
       {
           
           temp = temp->next;
           
       }
       if(temp->next == NULL)
        {
            temp->next = head2;   
        }
   }
   return head1;
}
int main()
{
    node* head1 = NULL;
    node* head2 = NULL;
    node* last1 = NULL;
    node* last2 = NULL;
    head1=create(head1,last1);
    printf("1st linked list is : ");
    display(head1);
    head2=create(head2,last2);
    printf("2nd linked list is : ");
    display(head2);
    printf("merging");
    head1=merge(head1,head2);
    printf("After merging two linked list : ");
    display(head1);
    printf("second list is : ");
    display(head2);
   
}











