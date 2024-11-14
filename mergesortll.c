#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node*link;
}*pheader,*qheader,*newnode,*pptr,*qptr,*pptr1,*qptr1,*ptr,*rheader,*rptr,*rptr1,*pptr2,*qptr2;
void merge(struct node*pheader,struct node*qheader);
int main()
{
    int i,n,m,temp,temp1;
    printf("Enter the number of terms in first LL");
    scanf("%d",&n);
    pheader=(struct node*)malloc(sizeof(struct node));
    pheader->data=0;
    pheader->link=NULL;
    pptr=pheader;
    printf("Enter the Elements of first LL");
    for(i=0;i<n;i++)
    {
        newnode=(struct node*)malloc(sizeof(struct node));
        scanf("%d",&newnode->data);
        newnode->link=NULL;
        pptr->link=newnode;
        pptr=newnode;

    }
    printf("Enter the number of terms in second LL");
    scanf("%d",&m);
    qheader=(struct node*)malloc(sizeof(struct node));
    qheader->data=0;
    qheader->link=NULL;
    qptr=qheader;
    printf("Enter the Elements of second LL");
    for(i=0;i<m;i++)
    {
        newnode=(struct node*)malloc(sizeof(struct node));
        scanf("%d",&newnode->data);
        newnode->link=NULL;
        qptr->link=newnode;
        qptr=newnode;
    }
    /*aheader=(struct node*)malloc(sizeof(struct node));
    aheader->link=NULL;
    aheader->data=0;*/
    /*pptr2=pheader->link;
    while(pptr2!=NULL)
    {
        if(pptr2->data>=pptr2->link->data)
        {
            /*newnode=(struct node*)malloc(sizeof(struct node));
            newnode->data=pptr2->data ;
            newnode->link=NULL;
            aptr->link=newnode;
            aptr=newnode;
            pptr2=pptr2->link;*/
          /*  temp=pptr2->data;
            pptr->data=pptr2->link->data;
            pptr2->link->data=temp;
        }
        pptr2=pptr2->link;*/
        /*else
        {
            newnode=(struct node*)malloc(sizeof(struct node));
            newnode->data=qptr2->data ;
            newnode->link=NULL;
            aptr->link=newnode;
            aptr=newnode;
            pptr2=pptr2->link;
        } */
        

   /* }
    qptr2=qheader->link;
    while (qptr2!=NULL)
    {
        if(qptr2->data>=qptr2->link->data)
        {
            temp1=qptr->data;
            qptr2->data=qptr2->link->data;
            qptr2->link->data=temp;
        }
        qptr2=qptr2->link;
        
    }*/
    

    merge(pheader,qheader);
}
void merge(struct node*pheader,struct node*qheader)
{
    rheader=(struct node*)malloc(sizeof(struct node));
    rheader->link=NULL;
    rheader->data=0;
    rptr=rheader;
    pptr1=pheader->link;
    qptr1=qheader->link;

    while(pptr1!=NULL && qptr1!=NULL)
    {
        if(pptr1->data <= qptr1->data)
        {
               newnode=(struct node*)malloc(sizeof(struct node));
               newnode->data=pptr1->data;
               newnode->link=NULL;
               rptr->link=newnode;
               rptr=newnode; 
               pptr1=pptr1->link;
              // qptr1=qptr1->link;
        }
        else
        {
            newnode=(struct node*)malloc(sizeof(struct node));
            newnode->data=qptr1->data;
            newnode->link=NULL;
            rptr->link=newnode;
            rptr=newnode; 
            //pptr1=pptr1->link;
            qptr1=qptr1->link;
        }
    }
    while(pptr1!=NULL)
    {

        newnode=(struct node*)malloc(sizeof(struct node));
        newnode->data=pptr1->data;
        newnode->link=NULL;
        rptr->link=newnode;
        rptr=newnode; 
        pptr1=pptr1->link;
    }
    while(qptr1!=NULL)
    {
        newnode=(struct node*)malloc(sizeof(struct node));
        newnode->data=qptr1->data;
        newnode->link=NULL;
        rptr->link=newnode;
        rptr=newnode;
        qptr1=qptr1->link;
    }
    rptr1=rheader->link;
    printf("ELments after sorting and merging 2 linked list is:");
    while(rptr1!=NULL)
    {
        printf("%d",rptr1->data);
        rptr1=rptr1->link;
        printf("\t");
    }
    /*rptr2=rheader->link;
    while(rptr2!=NULL)
    {
        temp=rptr2->data;
        for(rptr3=rptr2;rptr3!=rheader->link && ;)
    }*/


}

