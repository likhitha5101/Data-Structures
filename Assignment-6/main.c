#include"queue.h"
int main()
{
    queue *f1=NULL,*r1=NULL,*f2=NULL,*r2=NULL;
    int n,bt,wt1=0,wt2=0,c1=0,c2=0,jno;
    float awt1=0,awt2=0;
    printf("Enter no. of jobs: ");
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        printf("Job Number: ");
        scanf("%d",&jno);
        printf("Burst Time: ");
        scanf("%d",&bt);
        if(wt1<=wt2)
        {
            enqueue(jno,bt,&f1,&r1);
            wt1+=bt;
            awt1+=wt1;
            c1++;
        }
        else
        {    
            enqueue(jno,bt,&f2,&r2);
            wt2+=bt;
            awt2+=wt2;
            c2++;
        }
 
        printf("\nWaiting time Q1:%d Q2:%d\n",wt1,wt2);
    }
    printf("\nQUEUE 1 : ");
    display(f1,r1);
    printf("\nAvg waiting time: %.2f\n",awt1/c1);
    printf("\nQUEUE 2 : ");
    display(f2,r2);
    printf("\nAvg waiting time: %.2f\n",awt2/c2);
}
