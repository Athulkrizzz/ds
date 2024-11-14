#include<stdio.h>
#include<stdlib.h>
struct node
{
    int coeff;
    int exp;
    struct node*link;
}*pheader,*qheader,*pptr,*qptr,*newnode,*ptr,*ptr1,*rheader,*rptr;
void  addpoly( struct node*pheader, struct node*qheader);
int main()
{
    int n,i,m;
    printf("enter the  number of terms in first polynomial");
    scanf("%d",&n);
    pheader=(struct node*)malloc (sizeof(struct node));
    pheader->coeff=0;
    pheader->exp=0;
    pheader->link=NULL;
    ptr=pheader;
    printf("enter the  coefficients and exponenets in first  polynomial::");
    for(i=0;i<n;i++)
    {
        newnode=(struct node*)malloc (sizeof(struct node));
        scanf("%d%d",&newnode->coeff,&newnode->exp);
        newnode->link=NULL;
        ptr->link=newnode;
        ptr=newnode;
    }

      printf("enter the  number of terms in second polynomial");
    scanf("%d",&m);
    qheader=(struct node*)malloc(sizeof(struct node));
    qheader->coeff=0;
    qheader->exp=0;
    qheader->link=NULL;
    ptr=qheader;
    printf("enter the  coefficients and exponenets in second  polynomial");
    for(i=0;i<m;i++)
    {
        newnode=(struct node*)malloc (sizeof(struct node));
        scanf("%d%d",&newnode->coeff,&newnode->exp);
        newnode->link=NULL;
        ptr->link=newnode;
        ptr=newnode;
    }
    addpoly(pheader,qheader);
}
void  addpoly( struct node*pheader, struct node*qheader)
{
    pptr=pheader->link;
    qptr=qheader->link;
    rheader=(struct node*)malloc (sizeof(struct node));
    rheader->coeff=0;
    rheader->exp=0;
    rheader->link=NULL;
    rptr=rheader;
    while(pptr->link!=NULL && qptr->link!=NULL)
    {
        if(pptr->exp == qptr->exp)
        {
            newnode=(struct node*)malloc (sizeof(struct node));
             rptr->link=newnode;
              rptr=newnode;
            rptr->coeff=pptr->coeff+qptr->coeff;
        rptr->exp=pptr->exp;
            rptr->link=NULL;
            //rptr->link=newnode;
           // rptr=newnode;
            pptr=pptr->link;
            qptr=qptr->link;

        }
        else if(pptr->exp>qptr->exp)
        {
            newnode=(struct node*)malloc (sizeof(struct node));
            newnode->coeff=pptr->coeff;
            newnode->exp=pptr->exp;
            newnode->link=NULL;
            rptr->link=newnode;
            rptr=newnode;
            pptr=pptr->link;
        }
         else if(pptr->exp<qptr->exp)
         {
            newnode=(struct node*)malloc (sizeof(struct node));
            newnode->coeff=qptr->coeff;
            newnode->exp=qptr->exp;
            newnode->link=NULL;
            rptr->link=newnode;
            rptr=newnode;
            qptr=qptr->link;
         }
    }
    while(pptr!=NULL)
    {
        newnode=(struct node*)malloc (sizeof(struct node));
        newnode->coeff=pptr->coeff;
        newnode->exp=pptr->exp;
        newnode->link=NULL;
        rptr->link=newnode;
        rptr=newnode;
        pptr=pptr->link;
    }
    while(qptr!=NULL)
    {
        newnode=(struct node*)malloc (sizeof(struct node));
            newnode->coeff=qptr->coeff;
            newnode->exp=qptr->exp;
            newnode->link=NULL;
            rptr->link=newnode;
            rptr=newnode;
            qptr=qptr->link;
    }
    printf("the polynomial expression after additionn is ::\n");
    ptr1=rheader->link;
    while(ptr1->link!=NULL)
    {
        printf("%dx^%d",ptr1->coeff,ptr1->exp);
        ptr1=ptr1->link;
        if(ptr1->link!=NULL)
        {
            printf("+");
        }
        
    }
}