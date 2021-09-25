#include<stdio.h>
void partition(int list[], int low, int high);
void mergesort(int list[], int low, int mid, int high);
int main()
{
    int list[50], i, size;
    printf("Enter the limit: ");
    scanf("%d", &size);
    printf("Enter the numbers: ");
    for(i = 0; i < size; i++)
    {
         scanf("%d", &list[i]);
    }
    partition(list, 0, size - 1);
    printf("The sorted array is ");
    for(i = 0;i < size; i++)
    {
         printf("%d   ",list[i]);
    }
    return 0;
}
void partition(int list[], int low, int high)
{
    int mid;
    if(low < high)
    {
        mid = (low + high) / 2;
        partition(list, low, mid);
        partition(list, mid + 1, high);
        mergesort(list, low, mid, high);
    }
}
void mergesort(int list[], int low, int mid, int high)
{
    int i, m, k, l, temp[50];

    l = low;
    i = low;
    m = mid + 1;
    while ((l <= mid) && (m <= high))
    {
        if (list[l] <= list[m])
        {
            temp[i] = list[l];
            l++;
        }
        else
        {
            temp[i] = list[m];
            m++;
        }
        i++;
    }
    if (l > mid)
    {
        for (k = m; k <= high; k++)
        {
            temp[i] = list[k];
            i++;
        }
    }
    else
    {
        for (k = l; k <= mid; k++)
        {
             temp[i] = list[k];
             i++;
        }
    }

    for (k = low; k <= high; k++)
    {
        list[k] = temp[k];
    }
}

