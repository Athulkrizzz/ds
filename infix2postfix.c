#include<stdio.h>
#include <ctype.h>
int  top=-1;
char stack[20];

void push(char item)
{
    stack[++top]=item;
}
char pop()
{
if(top==-1)
    {
        return-1;
    }
else
    {
        return stack[top--];
    }
}
int priority(char X)
{
    if(X=='(')
    {
        return 0;
    }
    else if(X=='^')
    {
        return 1;
    }
    else if(X=='*'||X=='/')
    {
        return 2;
    }
    else if(X=='+'||X=='-')
    {
        return 3;
    }
}
int main()
{
    char exp[20];
    char *e,x;
    printf("Enter the expression::");
    scanf("%s",exp);
    e=exp;
    while(*e!='\0')
    {
        if(isalnum(*e))
        {
            printf("%c",*e);
        }
        else if(*e=='(')
        {
            push(*e);
        }
        else if(*e==')')
        {
            while((x=pop())!='(')
            {
                printf("%c",x);
            }
        }
        else
        {
            while(priority(stack[top])>=priority(*e))
            {
                printf("%c",pop());
            }
                push(*e);
            
        }
        e++;
    }
    while(top!=-1)
    {
    printf("%c",pop());

    }


}