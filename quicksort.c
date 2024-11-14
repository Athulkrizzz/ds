#include<stdio.h>
int  partition(int a[30],int lb,int ub)
{
    int temp;
    int start=lb+1;
    int end=ub;
    int pivot=a[lb];
    while(start<end)
    {
        while(start<=ub && pivot>a[start])
        {
            start++;
        }
        while(end>=lb && a[end]>pivot)
        {
            end--;
        }
        if(start<end)
        {
            temp=a[start];
            a[start]=a[end];
            a[end]=temp;

        }

    }
    /*a[lb]=a[end];
    a[end]=pivot;
    return end;*/
    temp=a[end];
    a[end]=pivot;
    a[lb]=temp;
    return end;
}
void quicksort(int a[30],int lb,int ub)
{
    if(lb<ub)
    {
        int q=partition(a,lb,ub);
        quicksort(a,lb,q-1);
        quicksort(a,q+1,ub);
        

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
    quicksort(a,lb,ub);
        printf("Elements sorted are:");
        for(i=0;i<n;i++)
    {
        printf("%d",a[i]);
        printf("\n");
    }
 

}