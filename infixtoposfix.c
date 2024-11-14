#include<stdio.h>
#include<string.h>
int top=0;
char st[20];
void push(char ch)
{
    top++;
    st[top]=ch;
}
char pop()
{
    char item;
    if(top<0)
    {
        return 0;
    }
    else
    {
        item=st[top];
        top--;
    }
    return item;
}
int priority(char ch)
{
    if(ch== '^')
    {
        return 4;
    }
    else if(ch=='*' || ch== '/')
    {
        return 3;
    }
    else if(ch=='+' || ch== '-')
    {
        return 2;
    }
    else 
    {
       return 1;
    }

}

int main()
{
    char  q[50],p[50],ch,temp;
    int n,i=0,j=0;
    printf("Enter the postfix Expression::");
    scanf("%s",q);
    n=strlen(q);
    q[n]=')';
    q[n+1]='\0';
    st[top]='(';


            while(i<n+1)
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
                    p[j++]=temp;
                    temp=pop();
                }
                break;
            case '^':
            case '*':
            case '/':
            case '+':
            case '-':
                while((priority(st[top-1])>=priority(ch)))
                {
                    //p[j]=pop();
                    //j++;
                    temp=pop();
                     p[j]=temp;
                
                j++;
                }
                push(ch);
                break;
            default :
                p[j]=ch;
                j++;
                break;
        }
        i++;
    }
       
    while(top>0)
    {
          temp=pop();
        p[j++]=temp;
       // p[j++]=pop();
    }
    //p[j]='\0';
   p[j] = '\0';
    printf("Postfix expression is :: %s",p);
    pop();
    return 0;



}

/*int priority(char ch) {
    if(ch == '^') {
        return 4;
    } else if(ch == '*' || ch == '/') {
        return 3;
    } else if(ch == '+' || ch == '-') {
        return 2;
    } else {
        return 1;
    }
}

int main() {
    char q[50], p[50], ch, temp;
    int n, i = 0, j = 0;
    printf("Enter the infix Expression: ");
    scanf("%s", q);
    n = strlen(q);
    q[n] = ')';
    q[n + 1] = '\0';
    st[top] = '(';

 while(i < n + 1) {
        ch = q[i];
        switch(ch) {
            case '(':
                push(ch);
                break;
            case ')':
                temp = pop();
                while(temp != '(') {
                    p[j++] = temp;
                    temp = pop();
                }
                break;
            case '^':
            case '*':
            case '/':
            case '+':
            case '-':
                while(priority(st[top]) >= priority(ch)) {
                    p[j++] = pop();
                }
                push(ch);
                break;
            default:
                p[j] = ch;
                j++;
                break;
        }
        i++;
    }



    p[j] = '\0';
    printf("Postfix expression is: %s\n", p);
    return 0;
}




#include<stdio.h>
#include<string.h>

int top = 0;
char st[20];

void push(char ch) {
    st[++top] = ch;
}

char pop() {
    char item;
    if(top < 0) {
        return 0;
    } else {
        item = st[top];
        top--;
    }
    return item;
}*/


