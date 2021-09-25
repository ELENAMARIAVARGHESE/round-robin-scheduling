#include <stdio.h>
#include <stdlib.h>
int V,E,time,visited[20],G[20][20],q[20],a[50],front=1,rear=0;
void DFS(int i)
{
    int j;
    visited[i]=1;
    printf(" %d->",a[i]);
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
               printf("%d->",a[i]);
         }
 }
int main()
{
    int i,j,v1,v2;
    printf("Enter the no of edges:");
    scanf("%d",&E);
    printf("Enter the no of vertices:");
    scanf("%d",&V);
    printf("\nEnter the vertices");
    for(i=0;i<V;i++)
    {
        scanf("%d",&a[i]);
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
        scanf("%d%d",&v1,&v2);
        G[v1-1][v2-1]=1;

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

