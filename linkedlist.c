#include<stdio.h>
#include<stdlib.h>
void display();
void InsertFront();
void InsertEnd();
void InsertAny();
void DeleteFront();
void DeleteAny();
void DeleteEnd();
struct node
{
    int data;
    struct node*next;

}*head,*ptr;
void main()
{
    int choice;
    while(1)
    {
    printf("1.Insert to front\n");
    printf("2.Insert to end\n");
    printf("3.Insert to a particular position\n");
    printf("4.Delete from front\n");
    printf("5.Delete from end\n");
    printf("6.Delete from a particular position\n");
    printf("7.Display\n");
    printf("8.Exit\n");

    printf("Enter your choice:\n");
    scanf("%d",&choice);

    switch(choice)
    {
    case 1:
        {
            InsertFront();
            display();
            break;

        }
    case 2:
        {
            InsertEnd();
            display();
            break;

        }
    case 3:
        {
            InsertAny();
            display();
            break;

        }
    case 4:
        {
            DeleteFront();
            display();
            break;

        }
    case 5:
        {
            DeleteEnd();
            display();
            break;

        }
    case 6:
        {
            DeleteAny();
            display();
            break;

        }
    case 7:
        {
            display();
            break;

        }
    case 8:
        {
            exit(0);
            break;

        }






    }


    }
}

void InsertFront()
{
    int item;
    struct node*temp;
    temp=(struct node*)malloc(sizeof(struct node));
    printf("Enter the item to be inserted\n");
    scanf("%d",&item);
    if(temp==NULL)
    {
        printf("Memory Allocation Failed\n");
    }
    else
    {
        temp->data=item;
        temp->next=NULL;
        if(head==NULL)
        {
            head=temp;
        }
        else
        {
            temp->next=head;
            head=temp;
        }
    }

}
void InsertEnd()
{
    int item;
    struct node*temp;
    temp=(struct node*)malloc(sizeof(struct node));
    printf("Enter the item to be inserted\n");
    scanf("%d",&item);
    if(temp==NULL)
    {
        printf("Memory Allocation Failed\n");
    }
    else
    {
        temp->data=item;
        temp->next=NULL;
        if(head==NULL)
        {
            head=temp;
        }
        else
        {
           ptr=head;
           while(ptr->next!=NULL)
           {
               ptr=ptr->next;
           }
           ptr->next=temp;




    }

}
}
void InsertAny()
{
    int key,item;
    printf("Enter the item\n");
    scanf("%d",&item);
    printf("Enter the key\n");
    scanf("%d",&key);

    struct node*temp;
    temp=(struct node*)malloc(sizeof(struct node));
    if(temp==NULL)
    {
        printf("Memory allocation failed\n");
    }
    else
    {
        temp->data=item;
        temp->next=NULL;
    }
    if(head==NULL)
    {
        printf("The list is empty\n");
        return;
    }
    else
    {
        struct node*pt;
        pt=head;
        while(pt!=NULL && pt->data==key)
        {

            pt=pt->next;
        }
        if(pt==NULL)
        {
            printf("Key not Found\n");
            exit(0);
        }
        else
        {
            temp->next=pt->next;
            pt->next=temp;
        }
    }



}
void DeleteFront()
{
    if(head==NULL)
    {
        printf("The list is empty\n");
        return;
    }
    else
    {
        ptr=head;
        head=head->next;
        printf("Deleted item is %d",ptr->data);

    }
}
void DeleteAny()
{
    int key;
    struct node *temp,*prev;
    printf("Enter the key to delete\n");
    scanf("%d",&key);
    if(head==NULL)
    {
        printf("The list is empty\n");
        exit(0);
    }
    else if(head->data==key)
    {
        temp=head;
        printf("Deleted item is %d",temp->data);
        head=head->next;

    }
    else
    {
        temp=head;
        while(temp!=NULL&&temp->data!=key)
        {
            prev=temp;
            temp=temp->next;
        }
        if(temp==NULL)
        {
            printf("Key not Found\n");
            return;
        }
        else{
                 printf("Deleted item is %d",temp->data);
            prev->next=temp->next;
        }

    }
}
void DeleteEnd()
{
    struct node *prev;
    if(head==NULL)
    {
        printf("The list is empty\n");
        exit(0);
    }
    ptr=head;
    if(head->next==NULL)
    {
        printf("Deleted item is %d",ptr->data);
    }
    else
    {
        while(ptr->next!=NULL)
        {
            prev=ptr;
            ptr=ptr->next;
        }
         printf("Deleted item is %d",ptr->data);
         prev->next=NULL;

    }
}
void display()
{

if(head==NULL)
{
    printf("Head is empty\n");
    exit(0);
}
else
    {
      ptr=head;
      while(ptr!=NULL)
      {
        printf("%d\n",ptr->data);
        ptr=ptr->next;
      }
    }
}
