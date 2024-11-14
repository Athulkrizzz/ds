#include<stdio.h>
#include<stdlib.h>
void enqueue(int a[20],int n);
void dequeue(int a[20],int n);
void traverse(int a[20],int n);
int front=-1,rear=-1;
int main()
{
    int A[20],N,ch;
    printf("enter the size of the array:\n");
    scanf("%d",&N);
   
    while(1)
    {
      printf("choose the operation:\t 1)inserting element\n2)deleting element\n3)displaying\n4)exit\n");
    scanf("%d",&ch);
    switch(ch)
    {
        case 1:
       
        enqueue(A,N);
        break;
        case 2:
       
        dequeue(A,N);
        break;
        case 3:
       
        traverse(A,N);
        break;
        case 4:
            exit(0);
            break;
       
        default:
        printf("invalid input");
        break;
    }
    }
}
void enqueue(int a[20],int n)
{
    int k;
   
    if(front==(rear+1)%n)
    {
        printf("queue overflow");
    }
    else
    {
     printf("enter the number to be inserted");
    scanf("%d",&k);
    if(front==-1 && rear==-1)
    {
        front=0;
        rear=0;
        a[rear]=k;
         //rear=(rear+1)%n;

    }
    else
        {
            rear=(rear+1)%n;
            a[rear]=k;
        }
    }
}
void dequeue(int a[20],int n)
{

if(front==-1&&rear==-1)
{
    printf("queue undwerflow");
}
else if(front==rear)
{
printf("Deleted item is %d",a[front]);
front=-1;
rear=-1;
}
else
{
printf("deleted item is %d",a[front]);
front=(front+1)%n;
}
}
void traverse(int a[20],int n)
{
int i;
printf("elements in circular queue is");
if(front==-1)
{
printf("queue underflow");
}
else
{

for(i=front;i!=rear;i=(front+1)%n)
{
printf("%d",a[i]);
}
printf("%d",a[rear]);
}
}



