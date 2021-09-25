#include<stdio.h>
#include<stdlib.h>
#define  MAX 10
void insert();
void del();
void display();

int i,choice,rear,front,q[MAX],items;
void main()
{

    front=-1;
    rear=-1;
    while(1)
    {
        printf("1.Insert \n2.Delete \n3.Display \n4.Exit \n");
        printf("Enter your choice:");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
                {

                    insert();
                    display();
                }
                    break;
            case 2:
                {

                del();
                printf("The queue elements are: \n\n");

                }
                    break;
            case 3: display();
                    break;
            case 4: exit(0);


        }
    }
}
void insert()
{
    if(rear>=MAX-1)
        printf("Queue is full!!\n");
    else
    {
        if(front==-1&&rear==-1)
        {
            front=0;
        }
        printf("Enter the element to be inserted: \n");
        scanf("%d",&items);
        rear++;
        q[rear]=items;
    }

}
void del()
{
     int item;
    if (front == - 1 )
    {
        return ;
    }
    else
    {
        item= q[front];
         printf("The deleted element:%d\n",item);
        if(front==rear)
        {
            rear=-1;
            front=-1;
        }
        else{
            front=front+1;
        }

    }
}
void display()
{
    int i;
    if(front==-1)
    {
        printf("The Queue is Empty!!");
        return;
    }
    else
    {
        printf("The queue elements are: \n");
        for(i=front;i<=rear;i++)
        printf("%d\n",q[i]);

    }
}


