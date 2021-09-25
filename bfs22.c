#include<stdio.h>
#include<stdlib.h>
void bfs();
void dfs();
int A[10][10], vertices, i, j, top=-1, front =-1,rear=-1, Q[20],S[20];
void enqueue(int num){
  if(rear == 19)
    return;
  if(rear==-1){
    front =0;
    rear=0;
  }
  else
    rear++;
  Q[rear] = num;


}
int dequeue(){
  int num = Q[front];
  if(front==rear)
    front=rear = -1;
  else
    front++;
  return num;
}
void push(int num){
  if(top != 19){
   top++;
   S[top] = num;
 }
}
int pop(){
  if(top !=-1)
    return S[top--];
}
void main()
{
    printf("Enter number of vertices in the graph :");
    scanf("%d",&vertices);
    printf("\nEnter the adjacency matrix of the graph :");
    for(i=0 ;i<vertices; i++)
    {
        for(j=0; j<vertices; j++)
            scanf("%d",&A[i][j]);
    }
    int choice;
    printf("\n1. Breadth first search");
    printf("\n2. Depth first search");
    printf("\nEnter your choice :");
    scanf("%d",&choice);
    switch(choice){
        case 1:bfs();
            break;
        case 2:dfs();
            break;
  }

}

void dfs()
{
    push(1);
    while(top!=-1)
    {
        int x=pop();
        printf("%d",x);
        for(int i=0;i<vertices;i++)
        {
            if(A[x-1][i]==1)
            {
                push(i+1);
                A[x-1][i]=0;
                A[i][x-1]=0;
            }
        }
    }
}
void bfs()
{
    enqueue(1);
    while(rear!=-1)
    {
        int x=dequeue();
        printf("%d",x);
        for(int i=0;i<vertices;i++)
        {
            if(A[x-1][i]==1)
            {
                enqueue(i+1);
                A[x-1][i]=0;
                A[i][x-1]=0;
            }
        }
    }
}
