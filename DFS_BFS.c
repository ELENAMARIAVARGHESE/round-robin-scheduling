#include <stdio.h>
#include <stdlib.h>
int V,E,time,visited[20],G[20][20],front=0,rear=-1;
char q[20],a[50];
void DFS(int i)
{
    int j;
    visited[i]=1;
    printf(" %c ",a[i]);
    for(j=0;j<V;j++)
    {
        if(G[i][j]==1&&visited[j]==0)
            DFS(j);
    }
}
void bfs(int v)
{
    int i;
    visited[v] = 1;
 for(i=1;i<=V;i++)
  if(G[v][i] && !visited[i])
   q[++rear]=i;
   if(front <= rear)
    bfs(q[front++]);

     for(i=0;i<V;i++)
         {
              if(visited[i])
               printf(" %c ",a[i]);

         }
 }
int main()
{
    int i,j;
    char v1,v2;
    int w,x,y,z;
    int flag=0;
    printf("Enter the no of edges:");
    scanf("%d",&E);
    printf("Enter the no of vertices:");
    scanf("%d",&V);
    printf("\nEnter the vertices");
    for(i=0;i<V;i++)
    {
        scanf(" %c",&a[i]);
    }
    for(i=0;i<V;i++)
    {
        visited[i]=0;
        for(j=0;j<V;j++)
            G[i][j]=0;
    }
    for(i=0;i<E;i++)
    {
        printf("Enter the edges (format: V1 V2) : ");
        scanf(" %c %c",&v1,&v2);
        for(x=0;x<V;x++)
        {
            if(a[x]==v1)
            {
                flag=1;
                break;

            }
        }
        if(x<V && flag==1)
            w=x;

        flag=0;

        for(y=0;y<V;y++)
        {
            if(a[y]==v1)
            {
                flag=1;
                break;

            }
        }
        if(y<V && flag==1)
            z=y;


        G[w][z]=1;

    }

    for(i=0;i<V;i++)
    {
        for(j=0;j<V;j++)
            printf(" %d ",G[i][j]);
        printf("\n");
    }
    printf("\nDepth First Search");

        DFS(0);
        printf("\nBreadth First Search");
         bfs(0);


    return 0;
}

