#include<stdio.h>
#include<stdlib.h>
int n,i,j,temp,a[20];
int main()
{
  printf("Enter the Limit:\n");
  scanf("%d",&n);
  printf("Enter the numbers:\n");
  for(i=0;i<n;i++)
  {
      scanf("%d",&a[i]);
  }
  printf("The sorted array is ");
  for(i=1;i<=n;i++)
  {
      temp=a[i];
      j=i-1;
      while(j>=0 && a[j]>temp)
      {
          a[j+1]=a[j];
          j=j-1;
      }
      a[j+1]=temp;

  }
  for(i=0;i<n;i++)
  {
      printf("%d ",a[i]);
  }
  return 0;
}
