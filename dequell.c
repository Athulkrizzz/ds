#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node*link;
}*front=NULL,*rear=NULL,*newnode;
void insertionatrear(int x);
void deletionatfront();
void display();
void insertionatfront(int x);
void deletionatrear();
int main()
{
    int ch,X;
    while(1)
    {
        printf("Enter the choice1)insertion@rear\n2)deletion@front\n3)display\n4)insertion@front\n5)deletion@rear\n6)exit\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
            printf("Enter the element to be inserted");
            scanf("%d",&X);
            insertionatrear(X);
            break;
            case 2 :
            deletionatfront();
            break;
            case 3:
            display();
            break;
            case 4:
            printf("Enter the element to be inserted");
            scanf("%d",&X)  ;
            insertionatfront(X);
            break;
            case 5:
            deletionatrear();
            break;
            case 6:
            exit(0);
            break;
            default:
            printf("invalid entry");    
            }
        }
    }
    void insertionatrear(int x)
    {
    newnode=(struct node*)malloc (sizeof(struct node));
    if(front==NULL)
        {
        front=newnode;
        rear=newnode;
        newnode->data=x;
        }
        else
        {
        newnode->data=x;
        rear->link=newnode;
        rear=newnode;
        }
    }
    void deletionatfront()
    {
        struct node*ptr;
        if(front==0 && rear==0)
        {
            printf("queue empty");
        }
        else if(front==rear)
        {   
            front=0;
            rear=0; 
        }
        else
        {
            printf("%d is element to be deleted\n",front->data);    
            ptr=front;
            front=front->link;
            free(ptr);
        }
    }
    void display()
    {
       struct node*ptr=front;
        if(ptr==NULL)
        {
            printf("Queue empty");
        }
        else
        {
            printf("Queue is");
            while(ptr!=NULL)
            {
                printf("%d\n",ptr->data);
                ptr=ptr->link;
            }
        }
    }
    void insertionatfront(int x)
    {
        newnode=(struct node*)malloc (sizeof(struct node));
        if(front==NULL)
        {
            front=newnode;
            rear=newnode;
            newnode->data=x;
        }   
        else
        {
            newnode->data=x;
            newnode->link=front;
            front=newnode;
        }
    }
    void deletionatrear()
    {
        struct node*ptr1=front;
        struct node*ptr;
        if(front==0 && rear==0)
        {
            printf("queue empty");
        }
        else if(front==rear)
        {
            front=0;
            rear=0;
        }
//ptr1=ptr->link
        else    
        {
            while(ptr1->link!=rear)
//!=rear nook
            {
//ptr=ptr->link;
                ptr1=ptr1->link;
            }
            ptr=rear;
            printf("Deleted element is %d",rear->data);
            rear=ptr1;
            ptr1->link=NULL;
            free(ptr);
        }
}