#include<stdio.h>
#include<stdlib.h>
int t1[25][3],t2[25][3],sum[25][3];
int k=1,i=0,j=0,elem=0;
int n1,n2,row1,row2,col1,col2;

void readsparse()
{
    printf("Enter the matrix in its tuple form\n As the no.of columns remains 3 \n\nEnter the no.of non-zero elemnts of the first and the second matrix:\n");
    scanf("%d",&n1);
    scanf("%d",&n2);
    printf("Enter no.of rows of the original matrix 1:\n");
    scanf("%d",&row1);
    printf("Enter no.of columns of the original matrix 1:\n");
    scanf("%d",&col1);
    printf("Enter no.of rows of the original matrix 2:\n");
    scanf("%d",&row2);
    printf("Enter no.of columns of the original matrix 2:\n");
    scanf("%d",&col2);
    printf("Enter the triplets(row,column,value) for the first matrix:");
    for(int p=1;p<=n1;p++)
    {
        scanf("%d %d %d",&t1[p][0],&t1[p][1],&t1[p][2]);
    }
    t1[0][0]=row1;
    t1[0][1]=col1;
    t1[0][2]=n1;
    printf("Enter the triplets(row,column,value) for the second matrix:");
    for(int p=1;p<=n2;p++)
    {
        scanf("%d %d %d",&t2[p][0],&t2[p][1],&t2[p][2]);
    }
    t2[0][0]=row2;
    t2[0][1]=col2;
    t2[0][2]=n2;

}
void printsparse()
{
    printf("The matrices in its tuple form are:\n");
    printf("Matrix 1:\n");
    for(int p=0;p<(n1+1);p++)
    {
        for(int q=0;q<3;q++)
        {
            printf("%d\t",t1[p][q]);
        }
        printf("\n");


    }
    printf("Matrix 2:\n");
    for(int p=0;p<(n2+1);p++)
    {
        for(int q=0;q<3;q++)
        {
            printf("%d\t",t1[p][q]);
        }
        printf("\n");


    }

}
int main()
{
    readsparse();
    printsparse();
    i=1;
    j=1;
    if(row1==row2 || col1 ==col2)
    {
        while(i<n1 || j<n2)
        {
            if(t1[i][0]<t2[j][0])
            {
                sum[k][0]=t1[i][0];
                sum[k][1]=t1[i][1];
                sum[k][2]=t1[i][2];
                i=i+1;
                k=k+1;
                elem=elem+1;
            }
            else if(t1[i][0]>t2[j][0])
            {
                sum[k][0]=t2[j][0];
                sum[k][1]=t2[j][1];
                sum[k][2]=t2[j][2];
                j=j+1;
                k=k+1;
                elem=elem+1;
            }
            else if((t1[i][0]==t2[j][0])&& (t1[i][1] == t2[j][1]))
            {
                sum[k][0]=t2[i][0];
                sum[k][1]=t2[j][1];
                sum[k][2]= t1[i][2]+ t2[j][2];
                i=i+1;
                j=j+1;
                k=k+1;
                elem=elem+1;

            }
            else if((t1[i][0]==t2[j][0])&& (t1[i][1] > t2[j][1]) )
            {
                sum[k][0]=t2[j][0];
                sum[k][1]=t2[j][1];
                sum[k][2]=t2[j][2];
                j=j+1;
                k=k+1;
                elem=elem+1;

            }
            else if((t1[i][0]==t2[j][0])&& (t1[i][1] < t2[j][1]))
            {
                sum[k][0]=t1[i][0];
                sum[k][1]=t1[i][1];
                sum[k][2]=t1[i][2];
                i=i+1;
                k=k+1;
                elem=elem+1;

            }
            else
                {
                    while(i<n1)
                        {
                                sum[k][0]=t1[i][0];
                                sum[k][1]=t1[i][1];
                                sum[k][2]=t1[i][2];
                                i=i+1;
                                k=k+1;
                                elem=elem+1;

                        }
                    while(j<n2)
                        {
                                sum[k][0]=t2[j][0];
                                sum[k][1]=t2[j][1];
                                sum[k][2]=t2[j][2];
                                j=j+1;
                                k=k+1;
                                elem=elem+1;

                        }
                }

        }
        sum[0][0]=row1;
        sum[0][1]=col1;
        sum[0][2]=elem;
    for(int r=0;r<(elem+1);r++)
    {
        for(int t=0;t<3;t++)
        {
            printf("%d\t",sum[r][t]);
        }
        printf("\n");
    }
    }
    else{
        printf("addition not possible\n");
    }




    return 0;
}
