#include <stdio.h>
#include<stdlib.h>
#define MAX 100
void insert();
void del();
void display();
int queue_array[MAX];
int rear = - 1;
int front = - 1;
int main()
{
    int c;
    while (1)
    {
        printf("1.Insert\n");
        printf("2.Delete\n");
        printf("3.Display\n");
        printf("4.Exit \n");
        printf("Enter your choice : ");
        scanf("%d", &c);
        switch (c)
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
                    display();

                }
                break;

            case 3:
            display();
            break;
            case 4:
            exit(1);
            default:
            printf("Wrong choice \n");
        } /* End of switch */
    }
     /* End of while */
     return 0;
}

void insert()
{
    int add_item;
    if (rear == MAX - 1)
    printf("Queue is full \n");
    else
    {
        if (front == - 1 && rear==-1){
        /*If queue is initially empty */
        front = 0;
        }

        printf("Enter the element to be inserted:");
        scanf("%d", &add_item);
        rear = rear + 1;
        queue_array[rear] = add_item;
    }
} /* End of insert() */

void del()
{
    int item;
    if (front == - 1 )
    {
        return ;
    }
    else
    {
        item= queue_array[front];
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
} /* End of del() */
//To Dispaly the elements in the queue after each operation-display()
void display()
{
    int i;
    if (front == - 1)
    {
        return;
    }
    else
    {
        printf("The queue elements are:\n");
        for (i = front; i <= rear; i++)
            printf("%d \n", queue_array[i]);
    }
}//End of display function.
