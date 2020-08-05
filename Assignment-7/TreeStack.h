#include"CharStack.h"
typedef struct mytree
{
	char exp;
	struct mytree *left, *right;
}tree;
typedef struct TreeStack
{
    tree *node;
    struct TreeStack * next;
}ts;
ts* pushTree(ts * top,tree * node)
{
    ts *newnode=malloc(sizeof(ts));
    newnode->node=node;
    newnode->next=top;
    top=newnode;
    return top;
}
tree * popTree(ts ** top)
{
    ts *temp=(*top);
    tree *sub=temp->node;
    (*top)=(*top)->next;
    free(temp);
    return sub;
}
void inorder(tree * root)
{
    if(root!=NULL)
    {
        inorder(root->left);
        printf(" %c",root->exp);
        inorder(root->right);
    }
}
void preorder(tree * root)
{
    if(root!=NULL)
    {
        printf(" %c",root->exp);
        preorder(root->left);
        preorder(root->right);
    }
}
void postorder(tree * root)
{
    if(root!=NULL)
    {
        postorder(root->left);
        postorder(root->right);
        printf(" %c",root->exp);
    }
}
