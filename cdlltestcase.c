#include<stdio.h>
#include<conio.h>
#include<malloc.h>
#include<stdlib.h>

typedef struct node
{
    int data;
    struct node *next,*prev;
}node;
node *create();
node *insert_b(node *head,int x);
node *insert_e(node *head,int x);
node *insert_in(node *head,int x);
node *delete_b(node *head);
node *delete_e(node *head);
node *delete_in(node *head);
node *reverse(node *head);
void search(node *head);
void print(node *head);
void main()
{
    int op,op1,x;
    node *head=NULL;
    do
    {
        fflush(stdin);
        printf("\n(1)Create:");
        printf("\n(2)Insert");
        printf("\n(3)Delete");
        printf("\n(4)Search");
        printf("\n(5)Print");
        printf("\n(6)Quit");
        printf("\nEnter your choice:");
        scanf("%d",&op);
        switch(op)
        {
            case 1: head=create();
                    break;

            case 2: printf("\n(1)Beginning\n(2)End\n(3)In between");
                    printf("\nEnter your choice:");
                    scanf("%d",&op1);
                    printf("\nEnter the data to be inserted:");
                    scanf("%d",&x);
                    switch(op1)
                    {
                        case 1: head=insert_b(head,x);
                                break;
                        case 2: head=insert_e(head,x);
                                break;
                        case 3: head=insert_in(head,x);
                                break;
                    }
                    break;
            case 3: printf("\n(1)Beginning\n(2)End\n(3)In between");
                    printf("\nEnter your choice:");
                    scanf("%d",&op1);
                    printf("\nEnter the data to be deleted:");
                    scanf("%d",&x);
                    switch(op1)
                    {
                        case 1: head=delete_b(head);
                                break;
                        case 2: head=delete_e(head);
                                break;
                        case 3: head=delete_in(head);
                                break;
                    }
                    break;
            case 4: search(head);
                    break;
            case 5: print(head);
                    break;
        }
    }while(op!=6);
}

node *create()
{
    node *head,*p;
    int i,n;
    head=NULL;
    printf("\nEnter no of data:");
    scanf("%d",&n);
    printf("\nEnter data: ");
    for(i=0;i<n;i++)
    {
       if(head==NULL)
       {
           head=(node*)malloc(sizeof(node));
           head->next=head->prev=head;
       }
       else
       {
           p=(node*)malloc(sizeof(node));
           p->next=head->next;
           p->prev=head;
           head->next->prev=p;
           head->next=p;
           head=p;
       }
       scanf("%d",&(head->data));
    }
    return (head);
}

node *insert_b(node *head,int x)
{
    node *p;
    p=(node*)malloc(sizeof(node));
    p->data=x;
    if(head==NULL)
    {
        head=p;
        head->next=head->prev=head;
    }
    else
    {
        p->next=head->next;
        p->prev=head;
        head->next->prev=p;
        head->next=p;
    }
    return (head);
}

node *insert_e(node *head,int x)
{
    node *p;
    p=(node*)malloc(sizeof(node));
    p->data=x;
    if(head==NULL)
    {
       head=p;
       head->next=head->prev=head;
    }
    else
    {
        p->next=head->next;
        p->prev=head;
        head->next->prev=p;
        head->next=p;
        head=p;
    }
    return (head);
}

node *insert_in(node *head,int x)
{
    node *p,*q;
    int y;
    p=(node*)malloc(sizeof(node));
    p->data=x;
    printf("\nInsert after which number?");
    scanf("%d",&y);
    q=head->next;
    do
    {
        if(y==q->data)
            break;
        q=q->next;
    }while(q!=head->next);
    if(q->data==y)
    {
        p->next=q->next;
        p->prev=q;
        p->next->prev=p;
        p->prev->next=p;
    }
    else
        printf("\n Data not found");
    return (head);
}

node *delete_b(node *head)
{
    node *p,*q,*prev;
    if(head==NULL)
    {
        printf("\nUnderflow....empty linked list");
        return (head);
    }
    if(head->next==head)
    {
        p=head;
        free(p);
        head=NULL;
    }
    else
    {
        p=head->next;
        p->prev->next=prev->next;
        free(p);
    }
    return(head);
}

node *delete_e(node *head)
{
    node *p,*q;
    if(head==NULL)
    {
        printf("\nUnderflow.......Empty linked list");
        return (head);
    }
    if(head->next==head)
    {
        p=head;
        free(p);
        head=NULL;
    }
    else
    {
        p=head;
    head=p->prev;
    p->prev->next=p->next;
    p->next->prev=p->prev;
    free(p);
    }
    return (head);
}

node *delete_in(node *head)
{
    node *p,*q;
    int x,i;
    if(head==NULL)
    {
        printf("\nUnderflow.......Empty linked list");
        return (head);
    }
    printf("\nEnter the data to be deleted: ");
    scanf("%d",&x);
    p=head->next;
    do
    {
        if(p->data==x)
            break;
        p=p->next;
    }while(p!=head->next);
    if(p->data!=x)
    {
        printf("\nUnderflow.......Empty linked list");
        return (head);
    }
    if(p==head)
        head=head->prev;
    if(p->next==p)
    {
        head=NULL;
        free(p);
    }
    else
    {
        p->prev->next=p->next;
        p->next->prev=p->prev;
        free(p);
    }
    return (head);
}

void search(node *head)
{
    node *p;
    int data,loc=1;
    printf("\nEnter the data to be searched:");
    scanf("%d",&data);
    p=head->next;
    do
    {
        if(p->data==data)
            break;
        p=p->next;
        loc++;
    }while(p!=head->next);
    if(p->data!=data)
        printf("\n_____Not found_____");
    else
        printf("\nFound at location %d",loc);
}

void print(node *head)
{
    node *p;
    printf("\n");
    if(head!=NULL)
    {
        p=head->next;
        do
        {
            printf("%d\t",p->data);
            p=p->next;
        }
        while(p!=head->next);
    }
}


