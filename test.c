#include<stdio.h>
#include<stdlib.h>

struct node
{
    struct node* link;
    int data;
} *top = NULL, *ptr, *ptr1, *newnode;

void push(int X);
void pop();
void traversal();

int main()
{
    int ch, x;
    while (1)
    {
        printf("Enter the choice: 1)Push\n2)pop\n3)traversal\n4)exit\n");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("Enter the number to be inserted: ");
            scanf("%d", &x);
            push(x);
            break;
        case 2:
            pop();
            break;
        case 3:
            traversal();
            break;
        case 4:
            exit(0);
            break;
        }
    }
    return 0;
}
void push(int X)
{
     

    newnode=(struct node*)malloc (sizeof(struct node));
    
    if(top==NULL)
        {
        top=newnode;
        newnode->data=X;
        newnode->link=NULL;
        
        }
        else
        {
        newnode->data=X;
        newnode->link=top;
        top=newnode;
        }
}
/*void push(int X)
{
    newnode = (struct node*)malloc(sizeof(struct node));
    if (newnode == NULL)
    {
        printf("Memory allocation failed\n");
        exit(1);
    }

    if (top == NULL)
    {
        top = newnode;
        newnode->data = X;
        newnode->link = NULL;
    }
    else
    {
        newnode->data = X;
        newnode->link = top;
        top = newnode;
    }
}*/

/*void pop()
{
    if (top == NULL)
    {
        printf("Stack empty\n");
        return;
    }

    ptr = top;
    top = top->link;
    printf("Deleted element is %d\n", ptr->data);
    free(ptr);
}*/
void pop()
{
    
        if(top==NULL)
        {
            printf("Stack empty");
        }
        
//ptr1=ptr->link
        
            ptr=top;
           
            top=top->link;
             printf("Deleted element is %d",ptr->data);
            free(ptr);
        
}

void traversal()
{
    ptr = top;
    if (ptr == NULL)
    {
        printf("Stack empty\n");
        return;
    }

    printf("Stack is: ");
    while (ptr != NULL)
    {
        printf("%d ", ptr->data);
        ptr = ptr->link;
    }
    printf("\n");
}
