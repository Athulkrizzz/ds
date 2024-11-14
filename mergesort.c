#include<stdio.h>
void merge(int a[30],int lb,int mid,int ub)
{
    int i=lb;
    int j=mid+1;
    int k=lb;
    int b[30];
    while(i<=mid &&j<=ub)
    {
        if(a[i]<=a[j])
        {
            b[k]=a[i];
            i++;
            k++;
        }
        else
        {
            b[k]=a[j];
            j++;
            k++;
        }
    }
      while(i<=mid)
        {
            b[k]=a[i];
            i++;
            k++;
        } 
        while(j<=ub)
        {
            b[k]=a[j];
            j++;
            k++;
        }
        for(i=lb;i<=ub;i++)
        {
            a[i]=b[i];
        }

} 
void mergesort(int a[30],int lb,int ub)
{
    if(lb<ub)
    {
        int mid=(lb+ub)/2;
        mergesort(a,lb,mid);
        mergesort(a,mid+1,ub);
        merge(a,lb,mid,ub);

    }

}
      
int main()
{
    int n,lb,ub,a[30],i;
    printf("Enter the no: of elements :\n");
    scanf("%d",&n);
    printf("Enter the elements");
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    lb=0;
    ub=n-1;
    mergesort(a,lb,ub);
        printf("Elements sorted are:");
        for(i=0;i<n;i++)
    {
        printf("%d",a[i]);
        printf("\n");
    }
 

}