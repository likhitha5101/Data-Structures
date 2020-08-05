#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct vertex
{
	char v;
	char adj[10];
	int visit;
}node;
typedef struct stack
{
	node *ver;
	struct stack *next;
}stack;
typedef struct queue
{
	node *ver;
	struct queue *next;
}queue;
int n;
stack * push(node * v,stack * top)
{
	stack *ptr=malloc(sizeof(stack));
	ptr->ver=v;
	ptr->next=top;
	top=ptr;
	return top;
}
node * pop(stack **top)
{
	if(*top!=NULL)
	{
		node *ptr=(*top)->ver;
		stack *temp =(*top);
		(*top)=(*top)->next;
		temp->next=NULL;
		free(temp);
		return ptr;
	}
	return NULL;
}
void enqueue(node * v,queue **front,queue **rear)
{
	queue *ptr = (queue*)malloc(sizeof(queue));
	ptr->ver=v;
	ptr->next=NULL;
	if(*front==NULL)
		*front=*rear=ptr;
	else
	{
		(*rear)->next=ptr;
		*rear=ptr;
	}
}
node * dequeue(queue **front,queue **rear)
{
	queue *temp=(*front);
	node * ptr=(*front)->ver;
	(*front)=(*front)->next;
	free(temp);
	return ptr;
}
void dfs(node *v,stack *top,node *gp[10])
{
	if(v== NULL)
		return;
	printf("\nDepth first search \n");
	top=push(v,top);
	while(top!=NULL)
	{
		node * temp=pop(&top);
		if(temp->visit==0)
		{
			temp->visit=1;
			printf("%c\t",temp->v);
		}
		for(int i=0;temp->adj[i];++i)
		{
			for(int j=0;j<n;++j)
			{
				if((temp->adj[i]==gp[j]->v)&&gp[j]->visit==0)
					top=push(gp[j],top);
			}
		}
	}
}
node * unvisit(node *gp[])
{
	for(int i=0;i<n;++i)
		if(gp[i]->visit==0)
			return gp[i];
	return  NULL;
}
void bfs(node *v,node *gp[10])
{
	queue *front,*rear;
	front=NULL;
	rear=NULL;
	printf("\n\nBreadth first search \n");
	while(unvisit(gp)!=NULL)
	{
		node * vnode=unvisit(gp);
		if(vnode){
		printf("%c\t",vnode->v);
		vnode->visit=1;
		enqueue(vnode,&front,&rear);
		}
		while(front!=NULL)
		{
			node *temp=dequeue(&front,&rear);
			for(int i=0;temp->adj[i];++i)
			{
				for(int j=0;j<n;++j)
				{
					if((temp->adj[i]==gp[j]->v)&&gp[j]->visit==0)
					{
						printf("%c\t",gp[j]->v);
						gp[j]->visit=1;
						enqueue(gp[j],&front,&rear);

					}
				}
			}
		}
	}

}
node * create()
{
	char c;
	int i=0;
	node *newv=malloc(sizeof(node));
	printf("\nEnter vertex: ");
	scanf(" %c",&newv->v);
	newv->visit=0;
	printf("\nEnter Adjacency list of %c (*-stop): \n",newv->v);
	scanf(" %c",&c);
	while(c!='*')
	{
		newv->adj[i]=c;
		i+=1;
		scanf(" %c",&c);
	}
	newv->adj[i]='\0';
	return newv;
}
char *Strrev(char *str)
{
      char *p1, *p2;

      if (! str || ! *str)
            return str;
      for (p1 = str, p2 = str + strlen(str) - 1; p2 > p1; ++p1, --p2)
      {
            *p1 ^= *p2;
            *p2 ^= *p1;
            *p1 ^= *p2;
      }
      return str;
}
