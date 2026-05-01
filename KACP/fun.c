#include "fun.h"

void first(dll **head,dll **tail,int data)
{
    dll *new=malloc(sizeof(dll));
    if(new==NULL)
    return;
    new->next=new->prev=NULL;
    new->data=data;
    if(*head==NULL)
    *head=*tail=new;
    else
    {
        new->next=*head;
        (*head)->prev=new;
        *head=new;
    } 
}

int add(dll **head1,dll **head2,dll **tail1,dll **tail2,dll **head,dll **tail)
{
    dll *t1=*tail1;
    dll *t2=*tail2;
    int c=0,res;
    while(t1!=NULL || t2!=NULL)
    {
        int d1=(t1)?t1->data:0;
        int d2=(t2)?t2->data:0;
        
        res=d1+d2+c;
        if(res>9)
        {
            c=1;
            res=res%10;
        }
        else
        c=0;
        first(head,tail,res);
        if(t1)
        t1=t1->prev;
        if(t2)
        t2=t2->prev;
    }
    
    if(c==1)
    first(head,tail,c);
    while(*head && (*head)->data==0 && (*head)->next)
    {
        dll *t=*head;
        *head=(*head)->next;
        (*head)->prev=NULL;
        free(t); 
    }
    return 1;
}

int sub(dll **head1,dll **tail1,dll **head2,dll **tail2,dll **head,dll **tail)
{
    dll *t1=*tail1;
    dll *t2=*tail2;
    int r,c=0;
    while(t1!=NULL)
    {
        int d1=(t1)?t1->data:0;
        int d2=(t2)?t2->data:0;
        r=d1-c-d2;
        if(r<0)
        {
            r=r+10;
            c=1;
        }
        else 
        c=0;
        first(head,tail,r);
        if(t1)
        t1=t1->prev;
        if(t2)
        t2=t2->prev;
    }
    while(*head && (*head)->data==0 && (*head)->next)
    {
        dll *t=*head;
        *head=(*head)->next;
        (*head)->prev=NULL;
        free(t); 
    }
    return 1;
}

void delete_list(dll **head,dll **tail)
{
    if(*head==NULL)
    return;
    while((*head)->next!=NULL)
    {
        *head=(*head)->next;
        free((*head)->prev);
    }
    free(*head);
    *head=*tail=NULL;
}

int mul(dll **head1,dll **head2,dll **tail1,dll **tail2,dll **headr1,dll **tailr1,dll **headr2,dll **tailr2,dll **head,dll **tail)
{
    if(((*head1)->data==0 && *head1==*tail1) || ((*head2)->data==0 && *head2==*tail2))
    {
        first(head,tail,0);
        return 1;
    }
    dll *t1=*tail1;
    dll *t2=*tail2;
    int c=0;
    while(t2)
    {
        t1=*tail1;
        int ca=0;
        for(int i=0;i<c;i++)
        first(headr2,tailr2,0);
        while(t1)
        {
            int r=t2->data * t1->data+ca;
            ca=r/10;
            if(c==0)
            first(headr1,tailr1,r%10);
            else
            first(headr2,tailr2,r%10);
            t1=t1->prev;
        }
        if(ca)
        {
           if(c==0)
           first(headr1,tailr1,ca);
           else
           first(headr2,tailr2,ca);
        }
        c++;
        if(c>=2)
        {
            add(headr1,headr2,tailr1,tailr2,head,tail);
            delete_list(headr1,tailr1);
            *headr1=*head;
            *tailr1=*tail;
            *head=*tail=NULL;
            delete_list(headr2,tailr2);
        }
        t2=t2->prev;
    }
    *head=*headr1;
    *tail=*tailr1;
    return 1;
}

int compd(dll **head1,dll **head2,int a,int x)
{
    if(a>x)
    return 1;
    else if(a<x)
    return -1;
    dll *t1=*head1;
    dll *t2=*head2;
    while(t1 && t2 && t1->data==t2->data)
    {
        t1=t1->next;
        t2=t2->next;
    }
    if(!t1 && !t2)
    return 0;
    if(t1->data>t2->data)
    return 1;
    else
    return -1;
}

void inc(sll **q)
{
    sll *t=*q;
    sll *p=NULL;
    int c=1;
    while(t)
    {
        int s=t->data+c;
        t->data=s%10;
        c=s/10;
        p=t;
        t=t->link;
    }
    if(c)
    {
        sll *n=malloc(sizeof(sll));
        n->data=c;
        n->link=NULL;
        p->link=n;
    }
}

int nodecount(dll *head)
{
    int c=0;
    while(head)
    {
        c++;
        head=head->next;
    }
    return c;
}

void reverse(sll **head)
{
   sll *p=NULL;
   sll *c=*head;
   sll *n=NULL;
   while(c)
   {
        n=c->link;
        c->link=p;
        p=c;
        c=n;
   }
   *head=p;
}

int divi(dll **head1,dll **tail1,dll **head2,dll **tail2,sll **qhead,int a,int x)
{
    if (*head2 == NULL || (*head2)->data == 0)
    return 0; 
    *qhead=malloc(sizeof(sll));
    (*qhead)->data=0;
    (*qhead)->link=NULL;
    dll *head=NULL;dll *tail=NULL;
    while(compd(head1,head2,a,x)>=0)
    {
        sub(head1,tail1,head2,tail2,&head,&tail);
        delete_list(head1,tail1);
        *head1=head;
        *tail1=tail;
        a=nodecount(*head1);
        inc(qhead);
        head=tail=NULL;
    }
    reverse(qhead);
    while (*qhead && (*qhead)->data == 0 && (*qhead)->link)
    {
        sll *t = *qhead;
        *qhead=(*qhead)->link;
        free(t);
    }
    return 1;
}