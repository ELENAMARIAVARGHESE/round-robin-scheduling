#include<stdio.h>
#include<stdlib.h>
void insert(struct node**head,int c,int e);
void traverse(struct node*head);
void poly_add(struct node **poly1,struct node **poly2,struct node**R);
void main()
{

}
void insert(struct node**head,int c,int e)
{
    struct node *temp,*prev,*current;
    temp=(struct node*)malloc(sizeof(struct node));
    if(temp==NULL)
    {
        printf("Memory Not Allocated\n");
        exit(0);
    }
    else
    {
        if(*head==NULL)
        {
            temp->coef=c;
            temp->exp=e;
            temp->link=NULL;
            *head=temp;
        }
        else
        {
            current=*head;
            while(current!=NULL)
            {
                prev=current;
                current=current->link;
            }
            if(current==NULL)
            {
                temp->coef=c;
                temp->exp=e;
                temp->link=NULL;
                prev->link=temp;
            }
        }
    }


}
void traverse(struct node*head)
{




}

void poly_add(struct node **poly1,struct node **poly2,struct node**R)
{
    int c,e;
    struct node *p1current,*p2current;
    p1current=*poly;
    p2current=*poly2;
    *R=NULL;
    while(p1current!=NULL &&p2current!=NULL)
    {
        if(p1current->exp==p2current->exp)
        {
            c=p1current->coef+p2current->coef;
            e=p1current->exp;
            insert(R,c,e);
            p1current=p1curret->link;
            p2current=p2current->link;
        }
        else
            {
              if(p1current->exp > p2current->exp)
            {
                c=p1current->coef;
                e=p1current->exp;
                insert(R,c,e);
                p1current=p1current->link;


            }
             else
            {
                c=p2current->coef;
                e=p2current->exp;
                insert(R,c,e);
                p2current=p2current->link;

            }
            }
    }
    while(p1current!=NULL)
    {
        c=p1current->coef;
            e=p1current->exp;
            insert(R,c,e);
            p1current=p1current->link;
    }
    while(p2current!=NULL)
    {
        c=p2current->coef;
            e=p2current->exp;
            insert(R,c,e);
            p2current=p2current->link;
    }

}
