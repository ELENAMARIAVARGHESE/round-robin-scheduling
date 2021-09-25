#include<stdio.h>
#include<stdlib.h>
void QuickSort(int a[],int lb,int ub);
int partition(int a[],int lb,int ub);
void QuickSort(int a[],int lb,int ub)
{
    if(lb<ub)
    {
        int loc=partition(a,lb,ub);
        QuickSort(a,lb,loc-1);
        QuickSort(a,loc+1,ub);


    }
}
int partition(int a[],int lb,int ub)
{
    int temp;
    int pivot=lb;
    int start=lb;
    int end=ub;




    while(start<end)
    {
        while(a[start]<=a[pivot] &&start<ub)
            start++;
        while(a[end]>a[pivot])
            end--;
        if(start<end)
        {
            temp=a[start];
            a[start]=a[end];
            a[end]=temp;
        }
    }

    temp=a[pivot];
    a[pivot]=a[end];
    a[end]=temp;
    return end;

}
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
    QuickSort(a,0,n-1);
    printf("The sorted array is\n");
    for(i=0;i<n;i++)
    {
        printf("%d\t",a[i]);
    }
    return 0;
}
