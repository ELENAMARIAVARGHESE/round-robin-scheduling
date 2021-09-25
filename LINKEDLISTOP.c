#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node* link;

}*head,*ptr;
void Display();
void Insert_end();
void Insert_front();
void Insert_any();
void Delete_end();
void Delete_front();
void Delete_any();
int main()
{
    int n;
    while(1)
    {
        printf("1.Display\n2.Insert at Beginning\n3.Insert at End\n4.Insert at a specified Position\n 5.Delete from Beginning\n6.Delete from End\n7.Delete from a specified Position\n8.Exit\n");
        printf("Enter your choice\n");
        scanf("%d",&n);
        switch(n)
        {
            case 1 :
            {
                Display();
                break;
            }
            case 2 :
            {
                Insert_front();
                Display();
                break;
            }
            case 3 :
            {
                Insert_end();
                Display();
                break;
            }
            case 4 :
            {
                Insert_any();
                Display();
                break;
            }
            case 5 :
            {
                Delete_front();
                Display();
                break;
            }
            case 6 :
            {
                Delete_end();
                Display();
                break;
            }
            case 7 :
            {
                Delete_any();
                Display();
                break;
            }
            case 8 :
            {
                exit(0);
                break;
            }

        }
    }
     return 0;
}

    void Display()
    {
        if(head==NULL)
        {
            printf("The List Is Empty\n");
            exit(0);
        }
        else
        {
            printf("\nThe elements in the list are\n");
            ptr=head;
            while(ptr!=NULL)
            {
                printf("%d \n",ptr->data);
                ptr=ptr->link;

            }
        }

    }
    void Insert_end()
    {
        struct node* temp;
        temp=(struct node*)malloc(sizeof(struct node));
        int item;
        printf("Enter the item to be inserted\n");
        scanf("%d",&item);
        if(temp==NULL)
        {
            printf("Insufficient memory!No Insertion Possible.\n");
        }
        else
        {
            temp->data=item;
            temp->link=NULL;
            if(head==NULL)
            {
                head=temp;
            }
            else
            {
                ptr=head;
                while(ptr->link != NULL)
                {
                    ptr=ptr->link;
                }
                ptr->link=temp;


            }
        }


    }
    void Insert_front()
    {
        struct node* temp;
        temp=(struct node*)malloc(sizeof(struct node));
        int item;
        printf("Enter the item to be inserted\n");
        scanf("%d",&item);
        if(temp==NULL)
        {
            printf("Insufficient memory!No Insertion Possible.\n");
        }
        else
        {
            temp->data=item;
            temp->link=NULL;
            if(head==NULL)
            {
                head=temp;
            }
            else
            {
                temp->link=head;
                head=temp;
            }
        }
    }
    void Insert_any()
    {
        struct node* temp;
        temp=(struct node*)malloc(sizeof(struct node));
        int item,key;
        printf("Enter the item to be inserted\n");
        scanf("%d",&item);
        printf("Enter the key\n");
        scanf("%d",&key);
        if(temp==NULL)
        {
            printf("memory not allocated");
        }
        else
        {
            temp->data=item;
            temp->link=NULL;
        }
        if(head==NULL)
        {
            printf("List is Empty\n");
        }
        else
        {
            ptr=head;
            while(ptr!=NULL && ptr->data!=key)
            {
                ptr=ptr->link;
            }
            if(ptr==NULL)
            {
                printf("Key not found in the list\n");
                exit(0);
            }
            else
            {
                temp->link=ptr->link;
                ptr->link=temp;
            }
        }

    }
    void Delete_end()
    {
        struct node *prev;
        if(head==NULL)
        {
            printf("List is empty\n");
            exit(0);

        }
        ptr=head;
        if(head->link==NULL)//only one element.
        {
            printf("The deleted data is:%d\n",ptr->data);

        }
        else
        {
            while(ptr->link!=NULL)
            {
                prev=ptr;
                ptr=ptr->link;

            }
            printf("The deleted data is:%d\n",ptr->data);
            prev->link=NULL;
        }




    }
    void Delete_front()
    {
        if(head==NULL)
        {
            printf("List is empty\n");
            exit(0);

        }
        else
        {
            ptr=head;
            head=head->link;
            printf("The deleted data is:%d\n",ptr->data);

        }

    }
    void Delete_any()
    {
        struct node *temp,*prev;
        int key,item,flag=0;
        printf("Enter the key\n");
        scanf("%d",&key);
        if(head==NULL)
        {
            printf("List is empty\n");
            exit(0);

        }
        else if(head->data==key)
        {
            item=head->data;
            temp=head;
            head=head->link;
            printf("The deleted data is:%d\n",item);
            exit(0);

        }
        else
        {
            temp=head;
            while(temp->link!=NULL)
            {
                prev=temp;
                temp=temp->link;
                if(temp->data==key)
                {
                    flag=1;
                    break;
                }

            }
            if(flag==0)
            {
                printf("Key Not Found\n");
                exit(0);
            }
            else
            {
                item=temp->data;
                prev->link=temp->link;
                printf("The deleted data is:%d\n",item);
            }
        }


    }




