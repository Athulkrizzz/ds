#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node*link;
}*header,*ptr,*newnode,*pheader,*qheader,*ptr1,*ptr2;
int main()
{
    int flag=1,ch,item,num;
    header=(struct node*)malloc(sizeof(struct node));
    header->link=NULL;
    header->data=0;
    pheader=(struct node*)malloc(sizeof(struct node));
    pheader->link=NULL;
    pheader->data=0;
    qheader=(struct node*)malloc(sizeof(struct node));
    qheader->link=NULL;
    qheader->data=0;
    ptr=header;
    while(flag==1)
    {
        printf("enter the choice 1.insert 2.exit");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
                 newnode=(struct node*)malloc(sizeof(struct node));
                printf("enter element");
                scanf("%d",&item);
                newnode->data=item;
                ptr->link=newnode;
                ptr=newnode;
                break;
            case 2:
                flag=0;
                break;
        }
    }
    ptr=header->link;
    ptr1=pheader;
    ptr2=qheader;
    while(ptr!=NULL)
    {
        num=ptr->data;
        if((num%2)==0)
        {
            newnode=(struct node*)malloc(sizeof(struct node));
            newnode->data=ptr->data;
            ptr1->link=newnode;
            ptr1=newnode;
        }
        else
        {
            newnode=(struct node*)malloc(sizeof(struct node));
            newnode->data=ptr->data;
            ptr2->link=newnode;
            ptr2=newnode;
        }
        ptr=ptr->link;
    }
    printf("list of even numbers");
    ptr1=pheader->link;
    while(ptr1!=NULL)
    {
        printf("%d",ptr1->data);
        ptr1=ptr1->link;
    }
    printf("list of odd numbers");
    ptr2=qheader->link;
    while(ptr2!=NULL)
    {
        printf("%d",ptr2->data);
        ptr2=ptr2->link;
    }
}