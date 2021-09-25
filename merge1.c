#include<stdio.h>
#include<stdlib.h>
void mergeSort(int a[],int lb,int ub);
void merge(int a[],int lb,int mid,int ub);

int b[25];
int main()
{


    int n,i,a[25];
    printf("Enter the limit\n");
    scanf("%d",&n);
    printf("Enter the elements\n");
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    mergeSort(a,0,n-1);
    printf("The sorted array is\n");
    for(i=0;i<n;i++)
    {
        printf("%d\t",a[i]);
    }
    return 0;
}
void merge(int a[],int lb,int mid,int ub)
{
    int i=lb;
    int k=lb;
    int j=mid+1;
    while(i<=mid && j<=ub)
    {
        if(a[i]<=a[j])
        {
            b[k]=a[i];
            i++;
        }
        else
        {
            b[k]=a[j];
            j++;
        }
        k++;
    }
    if(i>mid)
    {
        while(j<=ub)
        {
            b[k]=a[j];
            j++;
            k++;
        }
    }
    else
    {

         while(i<=mid)
         {
             b[k]=a[i];
             i++;
             k++;
         }
    }
    for (k = lb; k <= ub; k++)
        {
            a[k] = b[k];
        }
}
void mergeSort(int a[],int lb,int ub)
{
    if(lb<ub)
    {
    int mid;
    mid=(lb+ub)/2;
    mergeSort(a,lb,mid);
    mergeSort(a,mid+1,ub);
    merge(a,lb,mid,ub);
    }
}





