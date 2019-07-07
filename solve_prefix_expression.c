#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
struct numop
{
    char type;
    double numb;
    char op;
};
struct stack 
{
    struct numop * record;
    struct stack * next;
};
struct stack * head=NULL;
struct stack* Create_stack();
void push(struct stack *,struct numop*);
int isEmpty();
struct numop* top();
struct numop* pop(struct stack*);
void mainf(int );
void value(char arr[] ,int);
int main()
{
    char arr[500];
    scanf(" %[^\t\n]s",arr);
    int len=strlen(arr);
    value(arr,len-1);
    return 0;
}
void value(char arr[],int crt)
{
    if(crt<0)
    {
        struct numop * temp = top();
        temp = pop(head);
        return ;
    }
    else if(arr[crt]==' ')
      value(arr,crt-1);
    else if(isalnum(arr[crt]))
    {
        double num = arr[crt]-'0';
        struct numop* key = (struct numop*)malloc(sizeof(struct numop));
        key->type = 'n';
        key->numb = num;
        push(head,key);
        
        value(arr,crt-1);
    }
    else
    {
        struct numop * temp1 = pop(head);
        struct numop * temp2 = pop(head);
        double a = temp1->numb;
        //printf("value of temp1 %lf  ",a);
        double b = temp2->numb;
       // printf("value of temp1 %lf\n",a);
        char c = arr[crt];
        struct numop* key = (struct numop*)malloc(sizeof(struct numop)); 
        key->numb = ((c=='*')?(a*b):((c=='+')?(a+b):((c=='-')?(a-b):a/b)));
        key->type = 'n';
        push(head,key);
        value(arr,crt-1);
    }
}
struct stack* Create_stack()
{
    struct stack * temp=(struct stack*)malloc(sizeof(struct stack));
    temp->record =NULL;
    temp->next =NULL;
    return temp;
}
void push(struct stack* S,struct numop* key)
{
    struct stack *Snode = Create_stack();
    Snode->record = key;
    Snode->next =  NULL;
    
     if(head==NULL)
       head=Snode;
     else
     {
         Snode->next=head;
         head=Snode;
     }
     return ;
}
int isEmpty()
{
    return (head==NULL)?1:0;
}
struct numop* top()
{
    struct numop* temp = head->record;
    if(temp->type=='n')
        printf("%lf\n",temp->numb);
    else if(temp->type=='o')
        printf("%c\n",temp->op);
    return temp;   
}
struct numop* pop(struct stack * S)
{
    struct numop* temp=head->record;
    head=head->next;
    return temp;
}
