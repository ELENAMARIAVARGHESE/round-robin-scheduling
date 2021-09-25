#include<stdio.h>
#include<stdlib.h>
void print(int n,int p[][2])
{
    int i;

    for(i=0;i<n;i++)
    {


    printf("%d",p[i][0]);
    if(p[i][1]>0)
    {
        printf("X");
        if(p[i][1]>1)
        {
            printf("^%d",p[i][1]);
        }

    }
    printf("+");
    }
    printf("\b ");
}


void main()
{
    int p1[12][2],p2[12][2],p[24][2],t1,t2,i,j,k;
    printf("Enter the number of terms in first polynomial:\n");
    scanf("%d",&t1);
    printf("Enter the number of terms in second polynomial:\n");
    scanf("%d",&t2);
    printf("Enter the coefficient and exponent of the first polynomial :\n");
    for(i=0;i<t1;i++)
    {
        scanf("%d %d",&p1[i][0],&p1[i][1]);
    }
    printf("Enter the coefficient and exponent of the second polynomial :\n");
    for(i=0;i<t2;i++)
    {
        scanf("%d %d",&p2[i][0],&p2[i][1]);
    }
    print(t1,p1);
    printf("\n");
    print(t2,p2);
    printf("\n");
    printf("The resultant polynomial after addition: \n");
    i=0,j=0,k=0;

    while(i<t1 && j<t2)
    {
        if(p1[i][1]==p2[j][1])
        {
           p[k][0]=p1[i][0]+p2[j][0];
           p[k][1]=p1[i][1];
           i++;
           j++;
           k++;
        }
        else if(p1[i][1] > p2[j][1])
        {


            p[k][0]=p1[i][0];
           p[k][1]=p1[i][1];
           i++;
           k++;

        }
        else if(p1[i][1] < p2[j][1])
        {
           p[k][0]=p2[j][0];
           p[k][1]=p2[j][1];
           j++;
           k++;
        }




    }
    while(i<t1)
    {

        p[k][1]=p1[i][1];
        p[k][0]=p1[i][0];
        i++;
        k++;




    }
    while(j<t2)
    {
         p[k][1]=p2[j][1];
        p[k][0]=p2[j][0];
        j++;
        k++;



    }
    print(k,p);







}
