//Implement a Stack using arrays with the operations: 1.Pushing elements to the Stack.
// 2.Popping elements from the Stack 3.Display the contents of the Stack after each operation.
#include<stdio.h>
#include<stdlib.h>
#define size 3
void push();
int pop();
void display();
int stack[size];
int top=-1;
void main()
{
    int choice;
    char ch;
    do
    {
        printf("\n 1.PUSH");
        printf("\n 2.POP");
        printf("\n 3.DISPLAY");
        printf("\n Enter Your Choice");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:push();
            break;
            case 2:printf( "\n The popped element is %d ",pop());
            break;
            case 3:display();
            break;
            default:printf("\nWrong Choice!!!Try Again... ");
            break;
        }
        printf("\nDo You Wish To Continue (y?n)");
    fflush(stdin);
        scanf(" %c",&ch);
    }
    while(ch=='Y'||ch=='y');
}
void push()
{
    int item;
    if(top>=size-1)
     {
        printf("\n The Stack Is Full");
        exit(0);
     }
     else
        {
        printf("\n Enter The Element To Be Inserted.");
        scanf("%d",&item);
        top=top+1;
        stack[top]=item;

        }
}
int pop()
{
    int item;
    if (top==-1)
    {
        printf("\n The Stack Is Empty");
        exit(0);
    }
    else
    {
       item=stack[top];
        top=top-1;
    }
    return item;

}
void display()
{
    int i;
    if(top==-1)
    {
        printf("\n The Stack Is Empty");
        exit(0);
    }
    else
    {
        for(i=top;i>=0;i--)
        {
            printf("\n%d",stack[i]);
        }
    }
}
