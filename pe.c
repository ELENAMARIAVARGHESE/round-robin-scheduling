#include<stdio.h>
#include<ctype.h>
void push(int item);
int pop();
void EvalPostfix(char postfix[]);
int stack[100];
int top= -1;
int main()
{
    int i;
    char postfix[100];
    printf("Enter the expression:");
    scanf("%s",postfix);
    EvalPostfix(postfix);
    return 0;

}
void push(int item)
{
    if(top>=99)
    {
    printf("stack overflow");
    return;
    }
    else
    {
        stack[top++]=item;
    }
}
int pop()
{
    int item;
    if(top== -1)
    printf("stack underflow");
    else
    {
        item=stack[top];
        top--;
        return item;
    }
}
void EvalPostfix(char postfix[])
{
    int i=0;
    char a;
    int val,A,B;
    while(postfix[i]!='\0')
    {
        a =postfix[i];
        if(isdigit(a))
        {
            push(a-'0');
        }
        else if(a =='+'||a=='-'||a=='*'||a=='^'||a=='/')
        {
            A=pop();
            B=pop();
            switch(a)
            {
                case '*':
                    val=B*A;
                    break;
                case '/':
                    val =B/A;
                    break;
                case '+':
                    val=B+A;
                    break;
                case '-':
                    val=B-A;
                    break;
                case'^':
                    val=B^A;
                    break;
                default:
                    printf("%c is not a valid operator",a);
                    break;
            }
            push(val);
        }
        i++;

    }
    printf("\nThe result of the expression is %d",pop());



}
