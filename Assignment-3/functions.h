#include<stdio.h>
#include<stdlib.h>
typedef struct mynode
{
	int exp,coeff;
	struct mynode *next;
}node;
node * createlist()
{
	node * h=malloc(sizeof(node));
	h->next=NULL;
	return h;
}
void getpolynomial(node * head)
{
	int ch;
	node * temp=head;
	do
	{
		node * nptr=malloc(sizeof(node));
		printf("Enter Exponent of x: \n");
		scanf("%d",&nptr->exp);
		printf("Enter Coefficient of x^%d: \n",nptr->exp);
		scanf("%d",&nptr->coeff);
		nptr->next=NULL;
		temp->next=nptr;
		temp=nptr;
		printf("Enter 1 to continue: \n");
		scanf("%d",&ch);
	}while(ch==1);
}
void output(node * head)
{
	node * temp=head->next;
	while(temp!=NULL)
	{
		printf(" %+dx^%d",temp->coeff,temp->exp);
		temp=temp->next;
	}
	printf("\n");
}
void add(node * h1,node * h2,node *res)
{
	node *t1,*t2,*t3;
	t1=h1->next;
	t2=h2->next;
	//node *res=createlist();
	t3=res;
	while(t1!=NULL&&t2!=NULL)
	{

		node *nptr=malloc(sizeof(node));
		if(t1->exp==t2->exp)
		{
			nptr->coeff=t1->coeff+t2->coeff;
			nptr->exp=t1->exp;
			t1=t1->next;
			t2=t2->next;
		}
		else if(t1->exp>t2->exp)
		{
			nptr->coeff=t1->coeff;
			nptr->exp=t1->exp;
			t1=t1->next;	
		}
		else
		{
			nptr->coeff=t2->coeff;
			nptr->exp=t2->exp;
			t2=t2->next;
		}
		nptr->next=NULL;
		t3->next=nptr;
		t3=nptr;
	}
	while(t1!=NULL)
	{
		node *nptr=malloc(sizeof(node));
		nptr->coeff=t1->coeff;
		nptr->exp=t1->exp;
		t1=t1->next;
		nptr->next=NULL;
		t3->next=nptr;
		t3=nptr;
	}
	while(t2!=NULL)
	{
		node *nptr=malloc(sizeof(node));
		nptr->coeff=t2->coeff;
		nptr->exp=t2->exp;
		t2=t2->next;
		nptr->next=NULL;
		t3->next=nptr;
		t3=nptr;
	}
}
void multipy(node * h1,node * h2,node *res)
{
	node *t1,*t2,*t3,*t4;
	//t1=h1->next;
	t2=h2->next;
	t3=res;
	
	while(t2!=NULL)
	{
		node * temp=createlist();
		t4=temp;
		t1=h1->next;
		while(t1!=NULL)
		{
			node * nptr=malloc(sizeof(node));
			nptr->coeff=t2->coeff*t1->coeff;
			nptr->exp=t2->exp+t1->exp;
			nptr->next=NULL;
			t4->next=nptr;
			t4=nptr;
			
			t1=t1->next;
		}

		add(res,temp,res);
		t2=t2->next;
	}
}
