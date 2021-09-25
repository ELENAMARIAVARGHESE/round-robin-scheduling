#include<stdio.h>
#include<stdlib.h>
struct node
{
 int coef;
 int exp;
 struct node *link;
};
void insert_term(struct node **,int,int);
void traverse(struct node *);
void poly_pdt(struct node **,struct node **,struct node **);
void main()
{
 struct node *p1head=NULL,*p2head=NULL,*Rhead=NULL;
 int i,n,c,e;
 printf("Enter first polynomial.\n");
 printf("Enter no of terms-\n");
 scanf("%d",&n);
 for(i=0;i<n;i++)
 {
  printf("Enter %d term\n",i+1);
  printf("Enter coefficient\n");
  scanf("%d",&c);
  printf("Enter exponent\n");
  scanf("%d",&e);
  insert_term(&p1head,c,e);
 }
 printf("Enter second polynomial.\n");
 printf("Enter no of terms-\n");
 scanf("%d",&n);
 for(i=0;i<n;i++)
 {
  printf("Enter %d term\n",i+1);
  printf("Enter coefficient\n");
  scanf("%d",&c);
  printf("Enter exponent\n");
  scanf("%d",&e);
  insert_term(&p2head,c,e);
 }
 printf("First polynomial:\n");
 traverse(p1head);
 printf("second polynomial:\n");
 traverse(p2head);
 poly_pdt(&p1head,&p2head,&Rhead);
 printf("Product of the two polynomial:\n");
 traverse(Rhead);

}
void insert_term(struct node **head,int c,int e)
{
 struct node *temp,*current,*prev;
 if (*head==NULL)
 {
  temp=(struct node*)malloc(sizeof(struct node));
  if (temp==NULL)
   printf("Node is not created.Term cannot be inserted\n");
  else
  {
   temp->coef=c;
   temp->exp=e;
   temp->link=NULL;
   *head=temp;
  }
 }
 else
 {
  current=*head;
  while (current!=NULL && current->exp>e)
  {
   prev=current;
   current=current->link;
  }
  if(current==NULL)
  {
   temp=(struct node *)malloc(sizeof(struct node));
   if (temp==NULL)
    printf("Node is not created\n");
     else
   {
    temp->coef=c;
    temp->exp=e;
    temp->link=NULL;
    prev->link=temp;
   }
  }
  else
  {
   if(current->exp==e)
    current->coef=current->coef+c;
   else
   {
    if(current==*head)
    {
     temp=(struct node *)malloc (sizeof (struct node));
     if(temp==NULL)
      printf("Node is not created\n");
     else
     {
      temp->coef=c;
      temp->exp=e;
      temp->link=*head;
      *head=temp;
     }
    }
    else
    {
     temp=(struct node *)malloc(sizeof(struct node));
     if (temp==NULL)
      printf("node is not created\n");
     else
     {
      temp->coef=c;
      temp->exp=e;
      temp->link=current;
      prev->link=temp;
     }
    }
   }
  }
 }

}
void traverse(struct node *head)
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
void poly_pdt(struct node ** p1head,struct node **p2head,struct node** Rhead)
{
 int c,e;
 struct node *p1current,*p2current;
 *Rhead=NULL;
 p1current=*p1head;
 p2current=*p2head;
 if (*p1head==NULL && *p2head==NULL)
  printf("\n Multiplication of polynomial is not possible\n");
 else
 {
  while(p1current!=NULL)
  {
   p2current=*p2head;
   while(p2current!=NULL)
   {
    c=p1current->coef*p2current->coef;
    e=p1current->exp+p2current->exp;
    insert_term(Rhead,c,e);
    p2current=p2current->link;
   }
   p1current=p1current->link;
  }
 }
}
