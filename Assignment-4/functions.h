#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct student
{
	char name[50];
	struct student *prev,*next;	
}node;
node * create()
{
	node *h=malloc(sizeof(node));
	node *t=malloc(sizeof(node));
	h->prev=t->next=NULL;
	h->next=t;
	t->prev=h;
	return h;
}
void front(node *h,node *t)
{
	node *ptr=malloc(sizeof(node));
	printf("\nEnter Name: ");
	scanf(" %[^\n]",ptr->name);
	ptr->next=h->next;
	ptr->prev=h;
	h->next->prev=ptr;
	h->next=ptr;
}
void last(node *h,node *t)
{
	node *ptr=malloc(sizeof(node));
	printf("\nEnter Name: ");
	scanf(" %[^\n]",ptr->name);
	ptr->next=t;
	ptr->prev=t->prev;
	t->prev->next=ptr;
	t->prev=ptr;
}
void display(node *h,node *t)
{
	if(h->next==t)
		printf("\nThe list is empty!!");
	node *temp=h->next;
	while(temp->next!=NULL)
	{
		printf("%s\n",temp->name);
		temp=temp->next;
	}
}
node * search(node *h,node *t)
{
	node *temp=h->next;
	char n[50];
	scanf(" %[^\n]",n);
	while(temp!=NULL)
	{
		if(strcmp(n,temp->name)==0)
			return temp;
		temp=temp->next;
	}
	return NULL;
}
void middle(node *h,node *t)
{
	//int flag=0;
	node *ptr=malloc(sizeof(node));
	printf("\nEnter Name after which you want to insert: ");
	node *temp=search(h,t);
	if(temp!=NULL)
	{
		printf("\nInsertion...");
		front(temp,t);
		printf("\nName inserted successfully!!!");
	}
	else
		printf("\nNo such name found");

}
void delet(node *h,node *t)
{
	node *temp,*ptr=h->next;
	printf("\nEnter Name to Delete: ");
	temp=search(h,t);
	if(temp!=NULL)
	{
		temp->prev->next=temp->next;
		temp->next->prev=temp->prev;
		printf("\nElement Deleted successfully!!!");
	}
	else
		printf("\nNo such name found");

}
void alpha(node *h,node *t)
{
	node *temp1=h->next,*temp2;
	char str[50];
	while(temp1!=t->prev)
	{
		temp2=temp1->next;
		while(temp2!=t)
		{
			if(strcmp(temp2->name,temp1->name)<0)
			{
				strcpy(str,temp2->name);
				strcpy(temp2->name,temp1->name);
				strcpy(temp1->name,str);
			}
			temp2=temp2->next;
		}
		temp1=temp1->next;
	}
	display(h,t);

}
