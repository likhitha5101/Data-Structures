#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct searchtree
{
    char name[50];
    struct searchtree *left, *right;
}bst;
bst * insert(char str[50],bst *t)
{
    if(t==NULL)
    {
        t=malloc(sizeof(bst));
        strcpy(t->name,str);
        t->left=NULL;
        t->right=NULL;
    }
    else if(strcmp(t->name,str)>0)
        t->left=insert(str,t->left);
    else if(strcmp(t->name,str)<0)
        t->right=insert(str,t->right);
    return t;
}
void inorder(bst *t)
{
    if(t!=NULL)
    {
        inorder(t->left);
        printf(" %s   ",t->name);
        inorder(t->right);
    }
}
void gp(char str[50],bst *t)
{
    if(t!=NULL)
    {
        if(t->left)
            if(t->left->left && strcmp(t->left->left->name,str)==0)
                {printf("\nGrandparent of %s is %s",str,t->name);
                return;}
            else if(t->left->right && strcmp(t->left->right->name,str)==0)
                {printf("\nGrandparent of %s is %s",str,t->name);
                return;}
            else
                gp(str,t->left);
        if(t->right)
            if(t->right->right && strcmp(t->right->right->name,str)==0)
                {printf("\nGrandparent of %s is %s",str,t->name);
                return;}
            else if(t->right->left && strcmp(t->right->left->name,str)==0)
                {printf("\nGrandparent of %s is %s",str,t->name);
                return;}
            else
                gp(str,t->right);
    }
}
void gc(char str[50],bst * t)
{
    if(t)
    {
        if(strcmp(str,t->name)==0)
        {
            if(t->left)
            {
                if(t->left->left)
                    printf("%s   ",t->left->left->name);
                if(t->left->right)
                   printf("%s   ",t->left->right->name);
            }
            if(t->right)
            {
                if(t->right->left)
                    printf("%s   ",t->right->left->name);
                if(t->right->right)
                   printf("%s   ",t->right->right->name);
            }
            return;
        }
        gc(str,t->left);
        gc(str,t->right);
    }
}
void sibling(char str[],bst *t)
{
    if(t)
    {
        if(t->left && strcmp(str,t->left->name)==0 && t->right)
            {printf("\n%s   ",t->right->name);return;}
        else if(t->right&& strcmp(str,t->right->name)==0 &&t->left)
            {printf("\n %s   ",t->left->name);return;}
        sibling(str,t->left);
        sibling(str,t->right);
    }
}
bst * findmin(bst * t)
{
    if(t!=NULL)
        while(t->left!=NULL)
            t=t->left;
    return t;
}
bst * del(char str[],bst *t)
{
    bst * temp;
    if(t==NULL)
        printf("\nName not found");
    else if(strcmp(str,t->name)<0)
        t->left=del(str,t->left);
    else if(strcmp(str,t->name)>0)
        t->right=del(str,t->right);
    else if(t->left &&t->right)
    {
        temp=findmin(t->right);
        strcpy(t->name,temp->name);
        t->right=del(t->name,t->right);
    }
    else
    {
        temp=t;
        if(t->left==NULL)
            t=t->right;
        else if(t->right==NULL)
            t=t->left;
        free(temp);
    }
    return t;
}
