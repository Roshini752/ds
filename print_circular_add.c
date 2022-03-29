//4.write fn for adding node at the head
// write fn to print node numbers and value if the value is odd 
#include<stdio.h>
#include<stdlib.h>
struct Node
{
    int data;
    struct Node* next;
    
};
typedef struct Node node;
node* head = NULL;
node* last = NULL;
void create(int ele)
{
    
    node* new =(node*)malloc(sizeof(node*));
    if(new == NULL)
    {
        printf("memory is not allocated");
        return;
    }
    else
    {
        new->data = ele;
        new->next = NULL;
        if(head == NULL)
        {
            head = new;
            last = new;
        }
        else{
            last->next = new;
            last = new;
        }
    }
    
}
void display()
{
    if(head == NULL)
    {
        printf("list is empty");
        exit(0);
    }
    else{
        node* temp = head;
        while(temp != NULL)
        {
            printf("%d\n",temp->data);
            temp = temp->next;
        }
    }
}
int add_node()
{
    int ele;
    printf("Enter the data to add in front of head :");
    scanf("%d",&ele);
    
    if(head == NULL)
    {
        printf("Empty list ");
        return 0;
    }
    else
    {
        node* new =(node*)malloc(sizeof(node*));
        if(new == NULL)
        {
            printf("memory is not allocated ");
            return 0;
        }
        else{
            node *temp = head;
            new->data = ele;
            new->next = temp;
            head = new;
        }
        
        
    }
    
}
void print_odd()
{
    int count=0;
    if(head == NULL)
    {
        printf("list is empty");
        exit(0);
    }
    else{
        node* temp = head;
        while(temp != NULL)
        {  
            count++;
            if(temp->data%2 != 0)
            {
            printf("%d - ",temp->data);
            printf("node no. is %d\n",count);
            }
            temp = temp->next;
        }
    }
}
int check_circular()
{
    if(head == NULL)
    {
        printf("list is empty");
        exit(0);
    }
    else{
        node* temp = head;
        while(temp!= NULL)
        {  
            if(temp->next == head)
            {
                printf("the ll is circular ");
            }
            temp=temp->next;
        }
        if(temp == NULL)
        {
            printf("ll is nor circular");
        }
    }
}
int main()
{
    create(3);
    create(8);
    create(10);
    display();
    add_node();
    display();
    printf("odd nodes \n");
    print_odd();
    check_circular();
    
}