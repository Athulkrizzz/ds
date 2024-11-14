#include<stdio.h>
#include<stdlib.h>
void polyadd(int a[20][3],int b[20][3],int m,int n);
void polymulti(int a[20][3],int b[20][3],int m,int n);
int main()
{
    int i,j,A[20][3],B[20][3],ch,M,N;
    printf("Enter the number of coefficients and exponents of first equation ");
    scanf("%d",&M);
    printf("Enter the coefficients and exponents of 1st eq");
    for(i=0;i<M;i++)
    {
        scanf("%d,%d",&A[i][0],&A[i][1]);
    }
    for(i=0;i<M;i++)
    {
        printf("%d,%d",A[i][0],A[i][1]);
    }
     printf("Enter the number pf coefficienrts and exponenentients of second equation ");
    scanf("%d",&N);
     printf("Enter the coefficients and exponents of 2nd eq");
    for(j=0;j<N;j++)
    {
        scanf("%d,%d",&B[j][0],&B[j][1]);
    }
    for(j=0;j<N;j++)

    {
        printf("%d,%d",B[j][0],B[j][1]);
    }
    printf("Enter the choice: 1)polynomial addtion\n 2)polynomial multiplication\n 3)exit\n");
    scanf("%d",&ch);
    switch (ch)
    {
    case 1:
        polyadd(A,B,M,N);
        break;
    case 2:
    polymulti(A,B,M,N);
    break;
    case 3:
    exit(0);
    break;
    default:
        break;
    }
    
    return 0;
}
void polyadd(int a[20][3],int b[20][3],int m,int n)
{
    int i=0,j=0,z,c[20][3],k=0;
    while (i<m && j<n)
    {
        if(a[i][1]==b[j][1])
        {
            c[k][0]=a[i][0]+b[j][0];
            c[k][1]=a[i][1];
            i++;
            j++;
            k++;
        }
        else if(a[i][1]>b[j][1])
        {
            c[k][1]=a[i][1];
            c[k][0]=a[i][0];
            i++;
            k++;
        }
        else if(a[i][1]<b[j][1])
        {
            c[k][0]=b[j][0];
            c[k][1]=b[j][1];
            k++;
            j++;
        }

    }
    while(i<m)
    {
        c[k][0]=a[i][0];
        c[k][1]=a[i][1];
        k++;
        i++;

    }
    while(j<n)
    {
        c[k][0]=b[j][0];
        c[k][1]=b[j][1];
        k++;
        j++;
    }
    printf("after addition\n");
    for(i=0;i<k;i++)
    {
    printf("%dx^%d",c[i][0],c[i][1]);
    if(i<k-1)
        {
        printf("+");
        }
    }
}
void polymulti(int a[20][3],int b[20][3],int m,int n)
{
    int i,j,k=0,exist=0,c[20][3],t,newex,newco;
   for(i=0;i<m;i++)
    {
        printf("%d,%d",a[i][0],a[i][1]);
    }
    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        {
            newex=a[i][1]+b[j][1];
            newco=a[i][0]*b[j][0];
            for(t=0;t<k;t++)
            {
                if(c[t][1]==newex)
                {
                    exist=1;
                    break;

                }
            }
            if(exist)
            {
                c[t][0]=newco+c[t][0];
            }
            else
            {
                c[k][1]=newco;
                c[k][1]=newex;
                k++;
            }
        
        }

    }

    for(i=0;i<k;i++)
    {
    printf("%dx^%d",c[i][0],c[i][1]);
    if(i<k-1)
        {
        printf("+");
        }
    }
}