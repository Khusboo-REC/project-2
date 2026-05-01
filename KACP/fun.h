#ifndef FU
#define FU
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct node
{
   int data;
   struct node*prev;
   struct node*next;
}dll;

typedef struct Node
{
   int data;
   struct Node*link;
}sll;

int add(dll **head1,dll **head2,dll **tail1,dll **tail2,dll **head,dll **tail);
int sub(dll **head1,dll **tail1,dll **head2,dll **tail2,dll **head,dll **tail);
int mul(dll **head1,dll **head2,dll **tail1,dll **tail2,dll **headr1,dll **tailr1,dll **headr2,dll **tailr2,dll **head,dll **tail);
int divi(dll **head1,dll **tail1,dll **head2,dll **tail2,sll **qhead,int a,int x);



#endif
