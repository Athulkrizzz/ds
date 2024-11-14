#include<stdio.h>
#include<stdlib.h>
void binarysearch(int a[],int m,int z);
int main()
{
    int x,i,A[10],n;
    printf("enter the number of elements");
    scanf("%d",&n);
    printf("enter the elements");
    for (i=0;i<n;i++)
    {
        scanf("%d",&A[i]);
    }
    printf("enter the element need to be searched");
    scanf("%d",&x);
    binarysearch(A,n,x);
}
void binarysearch(int a[10],int m,int z)
{
    int l=0,u=m,mid,flag=0;
    while(l<=u)
   

            {
             mid=(l+u)/2;
                if(z==a[mid])
                {
                    printf("%d is found at %d position",z,mid+1);
                    flag=1;
                   exit(0);
                }
                else if(z<a[mid])
                {
                    u=mid-1;
                
                   
                }
                else if(z>a[mid])
                {
                    l=mid+1;
                   
                    
                }
        
                else
                {
                    printf("element not found");
                }
            

            }    
            if(flag==0)
            {
                printf("Element not found");
            }
}                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                              
