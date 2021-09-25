#include<stdio.h>
#include<stdlib.h>
struct node
{
    int coef;
    int exp;
    struct node * link;
};
void traverse(struct node*);
void insert(struct node**,int,int);
void poly_sum(struct node**,struct node**,struct node**);
int main()
{
    int n,c,e,i;
    struct node* poly1=NULL,*poly2=NULL,*R=NULL;
    printf("Enter the first polynomial-\n");
    printf("Enter the no.of terms:\n");
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        printf("Enter the %d term-\n",i);
        printf("Enter the coefficient:\n");
        scanf("%d",&c);
        printf("Enter the exponent:\n");
        scanf("%d",&e);
        insert(&poly1,c,e);
    }
    printf("Enter the second polynomial-\n");
    printf("Enter the no.of terms:\n");
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        printf("Enter the %d term-\n",i);
        printf("Enter the coefficient:\n");
        scanf("%d",&c);
        printf("Enter the exponent:\n");
        scanf("%d",&e);
        insert(&poly2,c,e);
    }
     printf("First polynomial:-\n");
     traverse(poly1);
     printf("Second polynomial:-\n");
     traverse(poly2);
     poly_sum(&poly1,&poly2,&R);
     printf("Sum of the two polynomials:-\n");
     traverse(R);
     return 0;
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
void traverse(struct node* head)
{
    struct node *temp;
    temp=head;
    if (temp==NULL)
    printf("Empty polynomial\n");
    else
    {
        while(temp!=NULL)
        {
        printf("%d",temp->coef);
        if(temp->exp>0)
        {
            printf("X");
            if(temp->exp>1)
            {
                printf("^%d",temp->exp);
            }
        }
        printf("+");
        temp=temp->link;
        }
        printf("\b ");
        printf("\n");
    }

}
void poly_sum(struct node**poly1,struct node**poly2,struct node**R)
{
    struct node*p1current,*p2current,*Rcurrent,*Rprev;
    p1current=*poly1;
    p2current=*poly2;
    *R=NULL;
    Rcurrent=NULL;
    Rprev=NULL;
    int c,e;

        while(p1current!=NULL&&p2current!=NULL)
        {
            if(p1current->exp==p2current->exp)
            {
                c=p1current->coef+p2current->coef;
                e=p1current->exp;
                insert(R,c,e);
                p1current=p1current->link;
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

