#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct stack
{
	char exp;
	struct stack * next;
}node;
char pop(node **top)
{
	char c;
	node * ptr=*top;
	if(ptr!=NULL)
	{
		*top=(*top)->next;
		c=(ptr->exp);
		ptr->next=NULL;
		free(ptr);
	}
	return c;
}
char checktop(node * top)
{
    return (top->exp);
}
int precedence(node * top,char c)
{
    char op=(checktop(top));
    if(c=='*'&&(op=='*'||op=='/'))
        return 1;
    else if(c=='/'&&(op=='*'||op=='/'))
        return 1;
    else if(c=='+'&&(op=='-'||op==c||op=='*'||op=='/'))
        return 1;
    else if(c=='-'&&(op=='+'||op==c||op=='*'||op=='/'))
        return 1;
    return 0;
}
int isop(char c)
{
    if(c=='+'||c=='-'||c=='*'||c=='/')
        return 1;
    return 0;
}
node * push(node * top,char c)
{
	node* ptr=(node *)malloc(sizeof(node));
	if(ptr!=NULL)
	{
		ptr->exp=c;
		ptr->next=top;
		top=ptr;
	}
	return top;
}
int postfix(node * top,char str[],char post[])
{
    int k=0;
    int f;
    for(int i=0;str[i]!='\0';++i)
    {
        f=0;
        if(str[i]>='0'&&str[i]<='9')
        {
            post[k]=str[i];
            k++;
        }
        else if(str[i]==')')
        {
            char c;
            do
            {
                if(top!=NULL)
                {
                    c=(pop(&top));
                    if(c!='(')
                    {
                        post[k]=c;
                        k++;
                    }
                }
                else
                {
                    f=1;
                    break;
                }
            }while(c!='(');
        }
        else if(isop(str[i]))
        {
            while(precedence(top,str[i]))
            {
                post[k]=(pop(&top));
                k++;
            }
           top=push(top,str[i]);
        }
        else
            top=push(top,str[i]);
    }
    if(top!=NULL)
    {
        f=1;
    }
	post[k]='\0';
	if(f==1)
        printf("Unbalanced Expression");
    else
        printf("Postfix form: %s",post);
	return f;
}
