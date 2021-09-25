#include <stdio.h>
void merge_sort(int i, int j, int a[], int temp[]) {
    if (j <= i)
        {
            return;
        }
    int mid = (i + j) / 2;
    merge_sort(i, mid, a, temp);
    merge_sort(mid + 1, j, a, temp);

    int left = i;
    int right = mid + 1;
    int k;
    for (k = i; k <= j; k++)
    {
        if (left == mid + 1)
            {
                temp[k] = a[right];
                right++;
            }
        else if (right == j + 1)
            {
                temp[k] = a[left];
                left++;
            }
        else if (a[left] < a[right])
            {
                temp[k] = a[left];
                left++;
            }
        else
            {
                temp[k] = a[right];
                right++;
            }
    }

    for (k = i; k <= j; k++)
        {
            a[k] = temp[k];
        }
}


int main() {
  int a[100], temp[100], n, i, d;

  printf("Enter the limit:\n");
  scanf("%d",&n);
  printf("Enter the numbers:\n");
  for (i = 0; i < n; i++)
    scanf("%d", &a[i]);
    merge_sort(0, n - 1, a, temp);

  printf("The sorted array is ");

  for (i = 0; i < n; i++)
     printf("%d ", a[i]);

  return 0;
  }
