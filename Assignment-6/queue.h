#include<stdio.h>
#include<stdlib.h>
typedef struct myQueue
{
    int jno,bt;
    struct myQueue *next;
}queue;
 
void enqueue(int jno,int bt,queue **front,queue **rear)
{
    queue *ptr = (queue*)malloc(sizeof(queue));
    ptr->jno=jno;
    ptr->bt=bt;
    ptr->next=NULL;
    if(*front==NULL)
        *front=*rear=ptr;
    else
    {
        (*rear)->next=ptr;
        *rear=ptr;
    }
}
 
void display(queue *front,queue *rear)
{
    if(front==NULL)
        printf("Queue empty\n");
    else
    {
        queue *temp=front;
        while(temp!=rear)
        {
            printf("(J%d : %d) ",temp->jno,temp->bt);
            temp=temp->next;
        }
        printf("(J%d : %d) ",temp->jno,temp->bt);
    }
}
