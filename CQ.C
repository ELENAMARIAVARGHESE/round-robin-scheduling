#include<stdio.h>
#include<stdlib.h>
#define MAX 100
int CQ[MAX];
int front,rear=-1;
int c;
void Insert();
void Delete();
void Display();
int main()
{
    while(1)
    {
        printf("1.Insert\n2.Delete\n3.Display\n4.Exit\nEnter Your Choice:");
        scanf("%d",&c);
        switch(c)
        {
            case 1:
            {
                Insert();
                Display();
            }
                break;
            case 2:
            {
                Delete();
                Display();
            }
                break;
            case 3:
            {
                Display();
            }
                break;
            case 4:
                exit(0);
                break;
            default:
                 printf("Please Enter A Valid No.");
                 break;

          }
    }
     return 0;

}
void Insert()
{
    int next,item;
    printf("Enter the item to be inserted:\n");
    scanf("%d",&item);
    if(front==-1)
    {
        front=0;
        rear=0;
        CQ[rear]=item;
    }
    else
    {
        next=(rear+1)%MAX;
        rear=next;
        CQ[rear]=item;


    }


}
void Delete()
{
    int item;
    if(front==-1)
    {
        printf("Queue is empty\n");
        exit(0);
    }
    else
    {
        item=CQ[front];
        if(front==rear)
        {
            front=-1;
            rear=-1;
        }
        else
        {
            front=(front+1)%MAX;
        }
    }
    printf("The deleted element is %d\n",item);

}
void Display()
{
    int i=front;
    printf("The elements of the Queue are:\n");
    do{
        printf("%d\n",CQ[i]);
        i=(i+1)%MAX;
    }
    while(i!=(rear+1)%MAX);

}
