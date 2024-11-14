#include<stdio.h>
void addsparse(int sa[30][10],int sb[30][10]);
//void multisparse(int sa[30][10],int sb[30][10]);
int main()
{
    int r1,c1,A[20][10],B[20][10],SA[20][10],SB[20][10],r2,c2,i,j,k=0,ch;
   
    printf("enter the number of rows and coloumns of 1st matrix");
    scanf("%d%d",&r1,&c1);
    printf("enter the elements in first matrix");;
    for(i=0;i<r1;i++)
    {
        for(j=0;j<c1;j++)
        {
            scanf("%d",&A[i][j]);
        }
    }
     printf("enter the number of rows and coloumns of 2nd matrix");
    scanf("%d%d",&r2,&c2);
    printf("enter the elements in second matrix");;
    for(i=0;i<r2;i++)
    {
        for(j=0;j<c2;j++)
        {
            scanf("%d",&A[i][j]);
        }
    }
    for(i=0;i<r1;i++)
    {
        for(j=0;j<c1;j++)
        {
            if(A[i][j]!=0)
            {
                k++;
                SA[k][0]=i;
                SA[k][1]=j;
                SA[k][2]=A[i][j];
            }
        }
    }
    SA[0][2]=r1;
    SA[0][1]=c1;
    SA[0][2]=k;
    k=0;
    for(i=0;i<r2;i++)
    {
        for(j=0;j<c2;j++)
        {
            if(B[i][j]!=0)
            {
                k++;
                SB[k][0]=i;
                SB[k][1]=j;
                SB[k][2]=B[i][j];
            }
        }
    }
    SB[0][0]=r2;
    SB[0][1]=c2;
    SB[0][2]=k;
    
    /* for (int z= 0;z<3;z++)
    {
        for(int x=0;x<=k; x++)
        {
            printf("%d\t",SA[z][x]);
        }
       printf("\n"); 
    }*/
    printf("\nenter the choice 1)sparse addition \n 2)sparse multiplication\n");
    scanf("%d",&ch);
    switch (ch)
    {
    case 1:
        addsparse(SA,SB);
        break;
    //case 2:
        //multisparse(SA,SB);
        //break;
    default:
        printf("Invalid input");
        break;
    }
    return 0;
}
void addsparse(int a[30][10],int b[30][10])
{
    int m,n,p,q,na,nb,i=1,j=1,k=1,c[30][10];
    m=a[0][0];
    n=a[0][1];
    p=b[0][0];
    q=b[0][1];
    na=a[0][2];
    nb=b[0][2];
   
    
    if(m==p && n==q)
    {
        printf("addition possible");
        while(i<na && i<nb)
        {
            
            if(a[i][0]>b[j][0])
            {
                c[k][0]=a[i][0];
                c[k][1]=a[i][1];
                c[k][2]=a[i][2];
                k++;
                i++;
            }
            else if (a[i][0]<b[j][0])
            {
                c[k][0]=b[j][0];
                c[k][1]=b[j][1];
                c[k][2]=b[j][2];
                k++;
                j++;
            }
            else
            {
                if(a[i][1]>b[j][1])
                {
                    c[k][0]=a[i][0];
                    c[k][1]=a[i][1];
                    c[k][2]=a[i][2];
                    k++;
                    i++;
                }
                else if (a[i][1]<b[j][1])
                {
                    c[k][0]=b[j][0];
                    c[k][1]=b[j][1];
                    c[k][2]=b[j][2];
                    k++;
                    j++;
                    
                }
                else
                {
                    c[k][0]=a[i][0];
                    c[k][1]=a[i][1];
                    c[k][2]=a[i][2]+b[j][2];
                    k++;
                    j++;
                    i++;
                }
            }            

        }
         while(i<na)
         {
            c[k][0]=a[i][0];
            c[k][1]=a[i][1];
            c[k][2]=a[i][2];
            i++;
            k++;

         }
         while(j<nb)
         {
            c[k][0]=b[j][0];
            c[k][1]=b[j][1];
            c[k][2]=b[j][2];
            k++;
            j++;


         }
         c[0][0]=a[0][0];
         c[0][1]=a[0][1];
         c[0][2]=k;
         for(i=0;i<k;i++)
         {
            for(j=0;j<=2;j++)
            {
            printf("%d\t",&c[i][j]);
            }
            printf("\n");
         }
    }
    else
    {
        printf("addition not possible");
    }

}