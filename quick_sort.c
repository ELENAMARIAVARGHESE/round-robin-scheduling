#include<stdio.h>
void quicksort(int number[25],int first,int last)
{
    int i, j, pivot, temp;
    if(first<last)
        {
            pivot=first;
            i=first;
            j=last;
            while(i<j)
            {
                while(number[i]<=number[pivot]&&i<last)
                    i++;
                while(number[j]>number[pivot])
                    j--;
                if(i<j)
                {
                    temp=number[i];
                    number[i]=number[j];
                    number[j]=temp;
                }
            }
            temp=number[pivot];
            number[pivot]=number[j];
            number[j]=temp;
            quicksort(number,first,j-1);
            quicksort(number,j+1,last);
        }
}
int main()
{
    int i,n, a[25];
    printf("Enter the limit:\n");
    scanf("%d",&n);
    printf("Enter the numbers:\n");
    for(i=0;i<n;i++)
    scanf("%d",&a[i]);
    quicksort(a,0,n-1);
    printf("The sorted array is ");
    for(i=0;i<n;i++)
    printf("%d ",a[i]);
    return 0;
}
