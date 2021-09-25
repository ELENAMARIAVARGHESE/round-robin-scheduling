#include<stdio.h>
#include<stdlib.h>
int i,j,k,m1[20][20],m2[20][20],t1[12][3],t2[12][3],sum[24][3];
int r1,r2,c1,c2;
int c=0,p=0;
void readsparse();
void printsparse();

int main()
{
    int i=1,j=1;
    int k=1;
    int el=0;

    readsparse();
    printsparse();
    if(r1==r2&&c1==c2)
    {
        while(i<=c && j<=p)
        {
            if(t1[i][0]<t2[j][0])
            {
                sum[k][0]=t1[i][0];
                sum[k][1]=t1[i][1];
                sum[k][2]=t1[i][2];
                i++;
                k++;
                el++;
            }
            else if(t1[i][0]>t2[j][0])
            {
                sum[k][0]=t2[j][0];
                sum[k][1]=t2[j][1];
                sum[k][2]=t2[j][2];
                j++;
                k++;
                el+=1;

            }
            else if(t1[i][0]==t2[j][0] && t1[i][1]==t2[j][1])
            {
                sum[k][0]=t1[i][0];
                sum[k][1]=t1[i][1];
                sum[k][2]=t1[i][2]+t2[j][2];
                i++;
                j++;
                k++;
                el+=1;

            }
            else if(t1[i][0]==t2[j][0] && t1[i][1]<t2[j][1])
            {
                sum[k][0]=t1[i][0];
                sum[k][1]=t1[i][1];
                sum[k][2]=t1[i][2];
                i++;
                k++;
                el+=1;

            }
            else if(t1[i][0]==t2[j][0] && t1[i][1]>t2[j][1])
            {
                sum[k][0]=t2[j][0];
                sum[k][1]=t2[j][1];
                sum[k][2]=t2[j][2];
                j++;
                k++;
                el+=1;

            }

        }
          while(i<c)
        {
            sum[k][0]=t1[i][0];
                sum[k][1]=t1[i][1];
                sum[k][2]=t1[i][2];
                i++;
                k++;
                el+=1;
        }
        while(j<p)
        {
             sum[k][0]=t1[j][0];
                sum[k][1]=t2[j][1];
                sum[k][2]=t2[j][2];
                j++;
                k++;
                el+=1;
        }
        sum[0][0]=r1;
        sum[0][1]=c1;
        sum[0][2]=el;
        printf("\nThe sum of the two matrices:\n");
        for(i=0;i<(el+1);i++)
    {
        for(j=0;j<3;j++)
        {
            printf("%d ",sum[i][j]);
        }
        printf("\n");
    }


    }
    else
    {
        printf("\n addition of matrices not possible");
    }




    return 0;
}
void readsparse()
{
    int i,j;
    int k=1;

    printf("\nEnter no.of rows of matrix 1:\n");
    scanf("%d",&r1);
    printf("\nEnter no.of columns of matrix 1:\n");
    scanf("%d",&c1);
    printf("\nEnter the elements of matrix 1:\n");
    for(i=0;i<r1;i++)
    {
        for(j=0;j<c1;j++)
        {
            printf("m1[%d][%d]: ",i,j);
            scanf("%d",&m1[i][j]);
        }

    }

     printf("\nEnter no.of rows of matrix 2:\n");
     scanf("%d",&r2);
    printf("\nEnter no.of columns of matrix 2:\n");
    scanf("%d",&c2);
     printf("\nEnter the elements of matrix 2:\n");
    for(i=0;i<r2;i++)
    {
        for(j=0;j<c2;j++)
        {
            printf("m2[%d][%d]: ",i,j);
            scanf("%d",&m2[i][j]);
        }

    }
    for(i=0;i<r1;i++)
    {
        for(j=0;j<c1;j++)
        {
            if(m1[i][j]!=0)
            {
                t1[k][0]=i;
                t1[k][1]=j;
                t1[k][2]=m1[i][j];
                k=k+1;
                c=c+1;
            }

        }
    }
    t1[0][0]=r1;
    t1[0][1]=c1;
    t1[0][2]=c;
    k=1;
    for(i=0;i<r2;i++)
    {
        for(j=0;j<c2;j++)
        {
            if(m2[i][j]!=0)
            {
                t2[k][0]=i;
                t2[k][1]=j;
                t2[k][2]=m2[i][j];
                k=k+1;
                p=p+1;
            }

        }
    }
     t2[0][0]=r2;
    t2[0][1]=c2;
    t2[0][2]=p;

}

void printsparse()
{
    int i,j;
    printf("\nTuple Matrix 1:\n");
    for(i=0;i<c+1;i++)
    {
        for(j=0;j<3;j++)
        {
            printf("%d ",t1[i][j]);
        }
        printf("\n");
    }

    printf("\nTuple Matrix 2:\n");
     for(i=0;i<p+1;i++)
    {
        for(j=0;j<3;j++)
        {
            printf("%d ",t2[i][j]);
        }
        printf("\n");
    }
}
