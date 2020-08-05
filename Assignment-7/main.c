#include"TreeStack.h"
int main()
{
    int ch;
    do
    {
	char str1[50],str[50]="(", post[50];
	int n;
	node * Chartop=NULL;
	ts *treetop=NULL;
	tree *root;
	printf("Enter the expression:\n");
	scanf(" %[^\n]",str1);
	strcat(str,str1);
	strcat(str,")");
	int f=postfix(Chartop,str,post);
	if(f==0)
	{
        n=strlen(post);
        for(int i=0;i<n;++i)
        {
            tree * tnode=malloc(sizeof(tree));
            if(!isop(post[i]))
            {
                tnode->exp=post[i];
                tnode->left=tnode->right=NULL;
            }
            else
            {
                tnode->exp=post[i];
                tnode->right=popTree(&treetop);
                tnode->left=popTree(&treetop);
            }
            treetop=pushTree(treetop,tnode);
        }
        root=popTree(&treetop);
        printf("\nPREORDER: ");
        preorder(root);
        printf("\nINORDER: ");
        inorder(root);
        printf("\nPOSTORDER: ");
        postorder(root);
        printf("\n");
	}
	printf("\nDo you want to continue?(1-yes/0-No): ");
    scanf(" %d",&ch);
    }while(ch!=0);
	return 0;
}
