#include<stdio.h>
#include<stdlib.h>
#define SIZE 10
void initialize();
void insert(int );
void print();
struct node
{
  int data;
  struct node*next;
};
struct node*chain[SIZE];
int main()
{
    int i,n,num;
    initialize();
    printf("Enter the limit:\n");
    scanf("%d",&n);
    printf("Enter the numbers:\n");
    for(i=0;i<n;i++)
    {
        scanf("%d",&num);
        insert(num);
    }
    print();
    return 0;
}
void initialize()
{
    int i;
    for(i=0;i<SIZE;i++)
    {
        chain[i]=NULL;
    }

}
void insert(int value)
{
    int key;
    struct node*newnode=malloc(sizeof(struct node));
    newnode->data=value;
    newnode->next=NULL;
    key=value%SIZE;
    if(chain[key]==NULL)
    {
        chain[key]=newnode;
    }
    else
    {
        struct node *temp=chain[key];
        while(temp->next!=NULL)
        {
            temp=temp->next;
        }
        temp->next=newnode;
    }
}
void print()
{
    int i;
    for(i=0;i<SIZE;i++)
    {
        struct node*temp=chain[i];
        printf("chain[%d]-->",i);
        while(temp!=NULL)
        {
            printf("%d-->",temp->data);
            temp=temp->next;
        }
        printf("NULL\n");
    }

}
