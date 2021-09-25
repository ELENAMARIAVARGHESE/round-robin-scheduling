#include<stdio.h>
#include<stdlib.h>
int n,i,j,k,min,loc,temp,a[20];
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
  k=0;
  while(k<n)
  {
      min=a[k];
      loc=k;
      j=k+1;
      while(j<n)
      {
          if(min > a[j])
          {
              min=a[j];
              loc=j;

          }
          j++;

      }
      temp=a[k];
      a[k]=a[loc];
      a[loc]=temp;
      k++;
  }



  for(i=0;i<n;i++)
  {
      printf("%d ",a[i]);
  }
  return 0;
}
