#include"functions.h"
int main()
{
    int op;
    do{
	printf("\nEnter no of Vertices: ");
	scanf("%d",&n);
	node * v[10];
	stack *top=NULL;
	for(int i=0;i<n;++i)
	{	v[i]=create();
		Strrev(v[i]->adj);}
	dfs(v[0],top,v);
	for(int i=0;i<n;++i)
	{	v[i]->visit=0;
		Strrev(v[i]->adj);
		}

	bfs(v[0],v);
	printf("\n\nDo you want to continue(1-yes/0-no): ");
	scanf("%d",&op);
    }while(op==1);
	return 0;
}
