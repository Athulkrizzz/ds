#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node*link;
}*newnode,*ptr,*front=NULL,*rear=NULL,*ptr1,*ptr2,*pheader,*qheader,*pptr,*qptr,*ptr5;
void insertion(int x);
void deletion();
void display();
void search();
void selection();
int main()
{
    int X,ch;
    while(1)
    {
        printf("Enter the choice:\n 1)Insertion\n2)Deletion\n3)Dislay\n4)Search\n5)exit\n6)selection\n");
        scanf("%d",&ch);
        switch (ch)
        {
            case 1:
            printf("Enter the element to be inserted:");
            scanf("%d",&X);
            insertion(X);
            break;
            case 2:
            deletion();
            break;
            case 3:
            display();
            break;
            case 4:
            search();
            break;
            case 5:
           exit(0);
            break;
            case 6:
            selection();
            break;
            default:
            printf("Invalid input");
            break;
        }

    }
    

}
void insertion(int x)
{
    newnode=(struct node*)malloc(sizeof(struct node));
    if(front==NULL)
    {
        front=newnode;
        rear=newnode;
        newnode->data=x;
        newnode->link=NULL;
    }
    else
    {
        newnode->data=x;
        newnode->link=NULL;
        rear->link=newnode;
        rear=newnode;
    }
}
void deletion()
{
    ptr=front;
    if(front==NULL && rear==NULL)
    {
        printf("Queue empty");

    }
    else if(front==rear)
    {
        front=NULL;
        rear=NULL;
        free(ptr);
    }
    else
    {
        while(ptr->link!=rear)
        {
            ptr=ptr->link;
        }
        ptr1=rear;
        printf("Element to be deleted is %d",ptr1->data);
        rear=ptr;
        ptr->link=NULL;
        free(ptr1);
    }
}
void display()
{
    struct node*ptr3=front;
    if(front==NULL && rear==NULL)
    {
        printf("Queue empty");

    }
    printf("Elements are:");
    while(ptr3->link!=NULL)
    {
        printf("%d\n",ptr3->data);
        ptr3=ptr3->link;
    }
    printf("%d\n",rear->data);
}
void  search()
{
    int key,flag=0,count=1;
      printf("Enter the element to be searched:");
        scanf("%d",&key);
        ptr2=front;
        while(ptr2->link!=NULL)
        {
            if(ptr2->data==key)
            {
                flag=1;
                printf("%d is found at %d position\n",key,count);
                break;
            }
            else
            {
                count++;
            }
            ptr2=ptr2->link;
        }
        if(ptr2->data==key)
        {
            printf("%d is found at %d position\n",key,count);
            flag=1;
        }
        if(flag==0)
        {
            printf("Element not found\n");
        }
}
void selection()
{
    int num;
    pheader=(struct node*)malloc(sizeof(struct node));
    //header illathe use aakan nook
    pheader->data=0;
    pheader->link=NULL;
    qheader=(struct node*)malloc(sizeof(struct node));
    qheader->data=0;
    qheader->link=NULL;
    pptr=pheader;
    qptr=qheader;
    ptr5=front;
    while(ptr5->link!=NULL)
    {
        num=ptr5->data;
        if(num%2==0)
        {
          newnode=(struct node*)malloc(sizeof(struct node));
          newnode->data=num;
          newnode->link=NULL;
          pptr->link=newnode;
          pptr=newnode;

        }
        else
        {
            newnode=(struct node*)malloc(sizeof(struct node));
            newnode->data=num;
            newnode->link=NULL;
            qptr->link=newnode;
            qptr=newnode;   
        }
        ptr5=ptr5->link;
    }
    printf("Even numbers in the list are:");
    while(pptr->link!=NULL)
    {
        printf("%d",pptr->data);
        pptr=pptr->link;

    }
    printf("Odd numbers in the list are:");
     while(qptr->link!=NULL)
    {
        printf("%d",qptr->data);
        qptr=qptr->link;
        
    }
}