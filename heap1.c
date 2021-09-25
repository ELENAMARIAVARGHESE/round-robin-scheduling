#include<stdio.h>
#include<stdlib.h>
void HeapSort(int a[],int n);
void Heapify(int a[],int n,int i);

void Heapify(int a[],int n,int i)
{
    int temp;
    //create heap.
    int largest=i;
    int l=2*i+1;
    int r=(2*i)+2;

    while(l<n && a[l]>a[largest])
    {
        largest=l;
    }
     while(r<n && a[r]>a[largest])
    {
        largest=r;
    }

    if(largest!=i)
    {
        temp=a[i];
        a[i]=a[largest];
        a[largest]=temp;
    }
}

void HeapSort(int a[],int n)
{
    int temp;
    int i;
    for(i=(n/2)-1;i>=0;i--)
    {
        Heapify(a,n,i);
    }
    for(i=n-1;i>=0;i--)
    {
        //remove max.
        temp=a[0];
        a[0]=a[i];
        a[i]=temp;


        //Rebuild heap.
        Heapify(a,i,0);
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
    HeapSort(a,n);
    printf("The sorted array is\n");
    for(i=0;i<n;i++)
    {
        printf("%d\t",a[i]);
    }






}
