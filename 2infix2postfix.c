#include<stdio.h>
#include <string.h>
int  top=0;
char st[20];

void push(char x)
{
    st[++top]=x;
}
char pop()
{
char item;
if(top==-1)
    {
       // printf("stack empty");
       return '\0';
    }
else
    {
        item=st[top];
        top--;
    }
    return item;
}
int priority(char X)
{
     if(X=='^')
    {
        return (3);
    }
    else if(X=='*'||X=='/')
    {
        return (2);
    }
    else if(X=='+'||X=='-')
    {
        return (1);
    }

    else
    {
        return(0);
    }
}
int main()
{
    char q[50],p[50],temp,ch;
    int n,i=0,j=0;
    printf("Enter the infix expression::");
    scanf("%s",q);
    n=strlen(q);
   q[n]=')';
    q[n+1]='\0';
    st[0]='(';
    while(i<n)
    {
        ch=q[i];
        switch(ch)
        {
            case '(':
            
            push(ch);
            break;
            case ')':
            temp=pop();
            while(temp!='(')
            {
               // p[j++]=pop();
                p[j]=temp;
                temp=pop();
                j++;
            }
            break;
            case '^':
            case '*':
            case '/':
            case '+':
            case '-':
             while(priority(st[top])>=priority(ch))
             {
               // p[j++]=pop();
                p[j]=temp;
                temp=pop();
                j++;
             } 
             push(ch);
             break;
            default:
             p[j++]=ch;
             break;          
        }
        i++;
    }
    while (top>=0)
    {
        temp=pop();
        p[j++]=temp;
       // p[j++]=pop();
    }
    p[j++]='\0';
    printf("Postfix form is %s",p);
    pop();
    return 0;
}