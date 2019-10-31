/*program for the conversion of
        1. Infix to it's postfix form
        2. Infix into it's prefix form
        3. Evaluation of postfix expression
        4. Evaluation of prefix expression
operators supported : +,-,*,/,%,^,(,)
operands supported--all single character operands*/
#include<stdio.h>
#include<conio.h>
#include<ctype.h>
#include<string.h>
#define MAX 50

typedef struct stack
{
    int data[MAX];
    int top;
}stack;

int evaluate(char x, int op1, int op2)
{
    if (x=='+') return (op1+op2);
    if (x=='-') return (op1-op2);
    if (x=='*') return (op1*op2);
    if (x=='/') return (op1/op2);
    if (x=='%') return (op1%op2);
    }

int precedence(char x)
{
    if(x=='(')
        return 0;
    if(x=='+' || x=='-')
        return 1;
    if(x=='*' || x=='/' || x=='%')
        return 2;
    return 3;
}

void push(stack *s,int x)
{
    s->top=s->top+1;
    s->data[s->top]=x;
}

void init(stack *s)
{
    s->top=-1;
}

void infix_to_postfix(char infix[],char postfix[])
{
    stack s;
    char x;
    int i,j;  //i-index for infix[],j-index for postfix[[]
    char token;
    init(&s);
    j=0;
    for(i=0;infix[i]!='\0';i++)
    {
        token=infix[i];
        if(isalnum(token))
            postfix[j++]=token;
        else
            if(token=='(')
               push(&s,'(');
            else
                if(token==')')
                    while((x=pop(&s))!='(')
                          postfix[j++]=x;
                else
                {
                    while(precedence(token)<=precedence(top(&s)) && !empty(&s))
                    {
                        x=pop(&s);
                        postfix[j++]=x;
                    }
                    push(&s,token);
                }
    }
    while(!empty(&s))
    {
        x=pop(&s);
        postfix[j++]=x;
    }
    postfix[j]='\0';
}


void infix_to_prefix(char infix[],char prefix[])
{
    int i,j;
    char temp,in1[30];
    //reverse the infix expression and store it in in1[]
    for(i=strlen(infix)-1,j=0;i>=0;i--,j++)
        in1[j]=infix[i];
    in1[j]='\0';
    //reverse the direction of brackets
    for(i=0;in1[i]!='\0';i++)
    {
        if(in1[i]=='(')
            in1[i]=')';
        else
            if(in1[i]==')')
                in1[i]='(';
    }
    //convert from infix to postfix
    infix_to_postfix(in1,prefix);
    //reverse the final expression
    for(i=0,j=strlen(prefix)-1;i<j;i++,j--)
    {
        temp=prefix[i];
        prefix[i]=prefix[j];
        prefix[j]=temp;
    }
}




void eval_postfix(char postfix[])
{
    stack s;
    char x;
    int op1,op2,val,i;
    init(&s);
    for(i=0;postfix[i]!='\0';i++)
    {
        x=postfix[i];
        if(isalpha(x))
        {
            printf("\n Enter value of %c : ",x);
            scanf("%d",&val);
            push(&s,val);
        }
        else
        {
            //pop to operands and evaluate
            op2=pop(&s);
            op1=pop(&s);
            val=evaluate(x,op1,op2);
            push(&s,val);
        }
    }
    val=pop(&s);
    printf("\n Value of expression = %d",val);
}

void eval_prefix(char prefix[])
{
    stack s;
    char x;
    int op1,op2,val,i;
    init(&s);
    for(i=strlen(prefix)-1;i>=0;i--)
    {
        x=prefix[i];
        if(isalpha(x))
        {
            printf("\nEnter the value of %c : ",x);
            scanf("%d",&val);
            push(&s,val);
        }
        else
        {
            //pop two operands and evaluate
            op1=pop(&s);
            op2=pop(&s);
            val=evaluate(x,op1,op2);
            push(&s,val);
        }
    }
    val=pop(&s);
    printf("\n Value of expression : %d",val);
}


int empty(stack *s)
{
    if(s->top==-1)
        return 1;
    return 0;
}

int full(stack *s)
{
    if(s->top==MAX-1)
        return 0;
}


int pop(stack *s)
{
    int x;
    x=s->data[s->top];
    s->top=s->top-1;
    return x;
}

int top(stack *p)
{
    return(p->data[p->top]);
}


void main()
{
    char infix[30],postfix[30],prefix[30];
    printf("\nEnter an infix expression : ");
    gets(infix);
    infix_to_postfix(infix,postfix);
    infix_to_prefix(infix,prefix);
    printf("\n Postfix : %s\n Prefix : %s",postfix,prefix);
    printf("\n Prefix evaluation : ");
    eval_prefix(prefix);
    printf("\n Postfix evaluaiton : ");
    eval_postfix(postfix);
    getchar();
}
