#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
void SelectionSort(int a[],int n)
{
    int i,j,min,temp;
    for(i=0;i<n-1;i++)
    {
    min=i;
    for(j=i+1;j<n;j++)
    {
        if(a[j]<a[min])
        {
            min=j;
        }
    }
    if(min!=i)
    {
        temp=a[i];
        a[i]=a[min];
        a[min]=temp;
    }
    }


}
void main()
{
    int n,i,a[25];
    printf("Enter the limit\n");
    scanf("%d",&n);
    printf("Enter the elements\n");
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    SelectionSort(a,n);
    printf("The sorted array is\n");
    for(i=0;i<n;i++)
    {
        printf("%d\t",a[i]);
    }
}
