#include<stdio.h>
#include<stdlib.h>
#define max 100
int front=-1;
int rear=-1;
int a[max],item;
void InsertFront();
void InsertRear();
void DeleteFront();
void DeleteRear();
void Display();
int main()
{
    int c;
    while(1)
    {
        printf("1.Insert To Front.\n");
        printf("2.Insert To Rear.\n");
        printf("3.Delete From Front.\n");
        printf("4.Delete From Rear.\n");
        printf("5.Display.\n");
        printf("6.Exit.\n");
        printf("Enter your choice:");
        scanf("%d",&c);
        switch(c)
        {
            case 1:
            {
                InsertFront();
                Display();
            }
            break;
            case 2:
            {
                InsertRear();
                Display();
            }
            break;
            case 3:
            {
                DeleteFront();
                Display();
            }
            break;
            case 4:
            {
                DeleteRear();
                Display();
            }
            break;
             case 5:

                Display();
                break;
             case 6:
                exit(0);
            break;
            default:
            printf("Enter a valid choice");
            break;


        }
    }
    return 0;
}
void InsertFront()
{
    int item,i;
    printf("Enter the item to be inserted:\n");
    scanf("%d",&item);
   if(front==0&& rear==max-1)
   {
       printf("Sorry!!...Queue is full\n");
       exit(1);
   }
   if(front==-1)
   {
       rear=0;
       front=0;
       a[front]=item;

   }
   else if(front>0)
   {
       front=front-1;
       a[front]=item;
   }
   else
   {
      i=rear;
      while(i>=front)
      {
          a[i+1]=a[i];
          i=i-1;
      }
      a[front]=item;
      rear=rear+1;
   }
}
void InsertRear()
{
    int item,i;
    printf("Enter the item to be inserted:\n");
    scanf("%d",&item);
    if(front==0&& rear==max-1)
   {
       printf("Sorry!!...Queue is full\n");
       exit(0);
   }
   if(front==-1)
   {
       rear=0;
       front=0;
       a[front]=item;

   }
   else if(rear<max-1)
   {
       rear=rear+1;;
       a[rear]=item;
   }
   else
   {
      i=front;
      while(i<=rear)
      {
          a[i-1]=a[i];
          i=i+1;
      }
      a[rear]=item;
      front=front-1;
   }


}
void DeleteFront()
{
    int item;
    if(front==-1&&rear==-1)
    {
        printf("Queue is Empty!!\n");
        exit(0);
    }
    item=a[front];
    if(front==rear)
    {
        front=-1;
        rear=-1;
    }
    else
    {
        front=front+1;
    }
    printf("The item deleted from the front is %d\n",item);

}
void DeleteRear()
{
    int item;
    if(front==-1&&rear==-1)
    {
        printf("Queue is Empty!!\n");
        exit(0);
    }
    item=a[rear];
    if(front==rear)
    {
        front=-1;
        rear=-1;
    }
    else
    {
        rear=rear-1;
    }
    printf("The item deleted from the rear is %d\n",item);


}

void Display()
{
    printf("The elemnts of the queue are:\n");
    for(int i=front;i<=rear;i++)
    {
        printf("%d\n",a[i]);
    }
}
