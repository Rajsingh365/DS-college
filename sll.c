#include<stdio.h>
#include<stdlib.h>

struct node
{
    int item;
    struct node *next;
};
void insert_at_beginning(struct node **s,int data);
void insert_at_end(struct node **s,int data);
void insert_after_a_specific_node(struct node **s,int pos, int data);
void delete_at_beginning(struct node **s);
void delete_at_end(struct node **s);
void delete_after_a_specific_node(struct node **s,int pos);
void printSLL(struct node *start);
void main()
{
    struct node *head=NULL;
    int choice,num,pos;
    while(1)
    {
        printf("\n\nEnter your choice : \n");
        printf("1. Insert at Beginning\n");
        printf("2. Insert at End\n");
        printf("3. Insert after a specific position\n");
        printf("4. Delete an Element from front\n");
        printf("5. Delete an Element from End\n");
        printf("6. Delete a Specific Node\n");
        printf("7. Print the list\n");
        printf("8. Exit");
        printf("\n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1: 
                printf("Enter a number : ");
                scanf("%d",&num);
                insert_at_beginning(&head,num);
                break;
            case 2: 
                printf("Enter a number : ");
                scanf("%d",&num);
                insert_at_end(&head,num);
                break;
            case 3:
                printf("Enter a number : ");
                scanf("%d",&num);
                printf("Enter desired position : ");
                scanf("%d",&pos);
                insert_after_a_specific_node(&head,pos,num);
                break;
            case 4: 
                delete_at_beginning(&head);
                break;
            case 5: 
                delete_at_end(&head);
                break;
            case 6:
                printf("Enter desired position : ");
                scanf("%d",&pos);
                delete_after_a_specific_node(&head,pos);
                break;
            case 7:
                printSLL(head);
                break;
            case 8:
                exit(0);
        }
    }
}

void insert_at_beginning(struct node **s,int data)
{
    struct node *new_node;
    new_node=(struct node*)malloc(sizeof(struct node));
    new_node->item=data;
    new_node->next=*s;
    *s=new_node;
}
void insert_at_end(struct node **s,int data)
{
    struct node *new_node,*ptr;
    new_node=(struct node*)malloc(sizeof(struct node));
    new_node->item=data;
    new_node->next=NULL;
    if(*s==NULL)
    {
        *s=new_node;
    }
    else
    {
        ptr=*s;
        while(ptr->next!=NULL)
            ptr=ptr->next;
        ptr->next=new_node;
    }
}
void insert_after_a_specific_node(struct node **s,int pos, int data)
{
    struct node *new_node,*ptr;
    new_node=(struct node*)malloc(sizeof(struct node));
    new_node->item=data;
    if(pos==1)
    {
        new_node->next=*s;
        *s=new_node;
    }
    else 
    {
        ptr=*s;

        while(pos>2)
        {
            ptr=ptr->next;
            pos--;
        }
        new_node->next=ptr->next;
        ptr->next=new_node;
    }
}
void delete_at_beginning(struct node **s)
{
    struct node *ptr; 
    if(*s==NULL)
        printf("Deletion not possible");
    else
    {
        ptr=*s;
        *s=ptr->next;
        free(ptr);
    }
}
void delete_at_end(struct node **s)
{
    struct node *ptr; 
    if(*s==NULL)
        printf("Deletion not possible");
    else
    {
        ptr=*s;
        while(ptr->next->next!=NULL)
            ptr=ptr->next;
            free(ptr->next);
            ptr->next=NULL;
    }
}
void delete_after_a_specific_node(struct node **s,int pos)
{
    struct node *ptr,*store;
    if(*s==NULL)
        printf("Deletion not possible");
    else if(pos==1)
    {
        ptr=*s;
        *s=ptr->next;
        free(ptr);
    }
    else
    {
        ptr=*s;
        while(pos>2)
            ptr=ptr->next;
        store=ptr->next;
        ptr->next=ptr->next->next;
        free(store);
    }
}
void printSLL(struct node *start)
{
    while(start->next!=NULL)
    {
        printf("%d ",start->item);
        start=start->next;
    }
    printf("%d ",start->item);
}
