#include "fun.h"

void print(dll *head)
{
    if(head==NULL)
    {
        printf("0\n");
        return;
    }
    else
    {
        while(head)
        {
            printf("%d",head->data);
            head=head->next;
        }
    }
    printf("\n\n");
}

void last(dll **head,dll **tail,int data)
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
        new->prev=*tail;
        (*tail)->next=new;
        *tail=new;
    }
}

void convo1(char *argv[],dll **head,dll **tail)
{
    int i=0;
    char t[2];
    t[1]='\0';
    while(argv[1][i]!='\0')
    {
        t[0]=argv[1][i];
        last(head,tail,atoi(t));
        i++;
    }
}

void convo2(char *argv[],dll **head,dll **tail)
{
    int i=0;
    char t[2];
    t[1]='\0';
    while(argv[3][i]!='\0')
    {
        t[0]=argv[3][i];
        last(head,tail,atoi(t));
        i++;
    }
}

int comp(dll **head1,dll **head2,dll **tail1,dll **tail2,dll **head,dll **tail,int a,int x)
{
    if(a>x)
    {
        sub(head1,tail1,head2,tail2,head,tail);
        return 1;
    }
    else if(a<x)
    {
        sub(head2,tail2,head1,tail1,head,tail);
        return -1;
    }
    else
    {
        dll *temp1=*head1;
        dll *temp2=*head2;
        while(temp1 && temp2 &&(temp1->data)==(temp2->data))
        {temp1=temp1->next;
        temp2=temp2->next;}
        if(!temp1 && !temp2)
        return 1;
        if(temp1->data>temp2->data)
        {
            sub(head1,tail1,head2,tail2,head,tail);
            return 1;
        }
        else
        {
            sub(head2,tail2,head1,tail1,head,tail);
            return -1;
        }
    }
    return 0;
}

void prin(sll *head)
{
    if(head==NULL)
    {
        printf("0\n");
        return;
    }
    else
    {
        while(head)
        {
            printf("%d",head->data);
            head=head->link;
        }
    }
    printf("\n\n");
}

int main(int argc,char *argv[])
{
    if(argc<4)
    {
       printf("Please provide arguments correctly\n");
       printf("USAGE : %s <operand1> <operator> <operand2>\n",argv[0]);
       return 1;
    }
    int a=strlen(argv[1]);
    int x=strlen(argv[3]);
    dll *head1=NULL;
    dll *tail1=NULL;
    dll *head2=NULL;
    dll *tail2=NULL;
    dll *head=NULL;
    dll *tail=NULL;
    dll *headr1=NULL;
    dll *tailr1=NULL;
    dll *headr2=NULL;
    dll *tailr2=NULL;
    sll *qhead=NULL;
    convo1(argv,&head1,&tail1);
    convo2(argv,&head2,&tail2);
    int ret;
    printf("\n\t\t\tARBITARY PRECISION CALCULATOR\n");
    char op=argv[2][0];
    switch(op)
        {
            case '+':
            ret=add(&head1,&head2,&tail1,&tail2,&head,&tail);
            if(ret)
            {
                printf("\t\t\tAddition Result :");
                print(head);
            }
            else
            printf("Addition operation failed");
            break;
            case '-':
            ret=comp(&head1,&head2,&tail1,&tail2,&head,&tail,a,x);
            if(ret)
            {
                printf("\t\t\tSubtraction Result :");
                if(ret==-1)
                printf("-");
                print(head);
            }
            else
            printf("Subtraction operation failed");
            break;
            case 'x':
            ret=mul(&head1,&head2,&tail1,&tail2,&headr1,&tailr1,&headr2,&tailr2,&head,&tail);
            if(ret)
            {
                printf("\t\t\tMultiplication Result :");
                print(head);
            }
            else
            printf("Multiplication operation failed");
            break;
            case '/':
            ret=divi(&head1,&tail1,&head2,&tail2,&qhead,a,x);
            if(ret)
            {
                printf("\t\t\tDivision Result :");
                prin(qhead);
            }
            else
            printf("\t\t\tDivision operation failed\n\n");
            break;
            default:
            printf("Unsupported operator\n");
        }return 0;
}
